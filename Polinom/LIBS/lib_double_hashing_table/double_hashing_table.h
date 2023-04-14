// Copyright 2023 Filatov Maxim
#ifndef INCLUDE_DOUBLE_HASHING_TABLE_H_
#define INCLUDE_DOUBLE_HASHING_TABLE_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include "../../LIBS/lib_interface_table/interface_table.h"

template <class T>
struct DoubleHashingObject {
    std::pair<std::string, T> pair;
    bool m_state;
    DoubleHashingObject(const std::string& key, const T tbl_obj) {
        pair.first = key;
        pair.second = tbl_obj;
        m_state = true;
    }
};

template <class T>
class DoubleHashingTable : public ITable<T> {
    constexpr static const double rehash_size = 0.75;
    DoubleHashingObject<T>** obj_array;
    int m_size;
    int m_buffer_size;
    int m_size_with_nullptr;

    int hash_function_horner(const std::string& s, int table_size, const int key) {
        int hash_result = 0;
        for (int i = 0; i < s.size(); ++i) {
            hash_result = (key * hash_result + s[i]) % table_size;
        }
        hash_result = (hash_result * 2 + 1) % table_size;
        return hash_result;
    }

    int hash_func_first(const std::string& s, int table_size) {
        return hash_function_horner(s, table_size, table_size - 1);
    }

    int hash_func_second(const std::string& s, int table_size) {
        return hash_function_horner(s, table_size, table_size + 1);
    }

    void resize() {
        int past_buffer_size = m_buffer_size;
        m_buffer_size *= 2;
        m_size_with_nullptr = 0;
        m_size = 0;
        DoubleHashingObject<T>** arr2 = new DoubleHashingObject<T>*[m_buffer_size];
        for (int i = 0; i < m_buffer_size; ++i) {
            arr2[i] = nullptr;
        }
        std::swap(obj_array, arr2);
        for (int i = 0; i < past_buffer_size; ++i) {
            if (arr2[i] && arr2[i]->m_state) {
                insert(arr2[i]->pair.first, arr2[i]->pair.second);
            }
        }
        for (int i = 0; i < past_buffer_size; ++i) {
            if (arr2[i]) {
                delete arr2[i];
            }
        }
        delete[] arr2;
    }

    void rehash() {
        m_size_with_nullptr = 0;
        m_size = 0;
        DoubleHashingObject<T>** arr2 = new DoubleHashingObject<T>*[m_buffer_size];
        for (int i = 0; i < m_buffer_size; ++i) {
            arr2[i] = nullptr;
        }
        std::swap(obj_array, arr2);
        for (int i = 0; i < m_buffer_size; ++i) {
            if (arr2[i] && arr2[i]->m_state) {
                insert(arr2[i]->pair.first, arr2[i]->pair.second);
            }
        }
        for (int i = 0; i < m_buffer_size; ++i) {
            if (arr2[i]) {
                delete arr2[i];
            }
        }
        delete[] arr2;
    }

public:
    DoubleHashingTable() {
        m_buffer_size = DEFAULT_SIZE;
        m_size = 0;
        m_size_with_nullptr = 0;
        obj_array = new DoubleHashingObject<T>*[m_buffer_size];
        for (int i = 0; i < m_buffer_size; ++i) {
            obj_array[i] = nullptr;
        }
    }
    ~DoubleHashingTable() {
        for (int i = 0; i < m_buffer_size; ++i) {
            if (obj_array[i]) {
                delete obj_array[i];
            }
        }
        delete[] obj_array;
    }
    void insert(std::string key, T tbl_obj) override {
        if (m_size + 1 > std::floor(rehash_size * m_buffer_size)) { 
            resize(); 
        }
        else if (m_size_with_nullptr > 2 * m_size) { 
            rehash(); 
        }
        int h1 = hash_func_first(key, m_buffer_size);
        int h2 = hash_func_second(key, m_buffer_size);
        int first_deleted = -1;
        for (int i = 0; obj_array[h1] != nullptr && i < m_buffer_size; h1 = (h1 + h2) % m_buffer_size, i++) {
            if (obj_array[h1]->pair.first == key && obj_array[h1]->m_state) {
                throw std::logic_error("The table already has an instance with the same name, error in insert method!");
            }
            if (!obj_array[h1]->m_state && first_deleted == -1) {
                first_deleted = h1;
            }
        }
        if (first_deleted == -1) {
            obj_array[h1] = new DoubleHashingObject(key, tbl_obj);
            ++m_size_with_nullptr;
        }
        else {
            obj_array[first_deleted]->pair.first = key;
            obj_array[first_deleted]->pair.second = tbl_obj;
            obj_array[first_deleted]->m_state = true;
        }
        m_size++;
    }
    void remove(std::string key) override {
        int h1 = hash_func_first(key, m_buffer_size);
        int h2 = hash_func_second(key, m_buffer_size);
        for (int i = 0; obj_array[h1] != nullptr && i < m_buffer_size; h1 = (h1 + h2) % m_buffer_size, i++) {
            if (obj_array[h1]->pair.first == key && obj_array[h1]->m_state) {
                obj_array[h1]->m_state = false;
                m_size--;
            }
        }
    }
    int find(std::string key) override {
        int h1 = hash_func_first(key, m_buffer_size);
        int h2 = hash_func_second(key, m_buffer_size);
        for (int i = 0; obj_array[h1] != nullptr && i < m_buffer_size; h1 = (h1 + h2) % m_buffer_size, i++) {
            if (obj_array[h1]->pair.first == key && obj_array[h1]->m_state) {
                return i;
            }
        }
        return NOT_FOUND;
    }
    int size() override {
        return m_size;
    }
    T get(int idx) override {
        return obj_array[idx]->pair.second;
    }
    int size_with_deleted() {
        return m_size_with_nullptr;
    }
    int size_buffer() {
        return m_buffer_size;
    }
    void update(std::string key, T tbl_obj) override {
        int idx = find(key);
        if (idx == NOT_FOUND) { throw std::logic_error("The specified element was not found, error in update method!"); }
        remove(key);
        insert(key, tbl_obj);
    }
    void print() override {
        for (int i = 0; i < m_buffer_size; i++) {
            if (obj_array[i] == nullptr || !obj_array[i]->m_state) { continue; }
            std::cout << obj_array[i]->pair.first << " | " << obj_array[i]->pair.second << "\n";
        }
    }
};

#endif  // INCLUDE_DOUBLE_HASHING_TABLE_H_
