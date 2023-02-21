// Copyright 2022 Filatov Maxim
#ifndef INCLUDE_LIST_H_
#define INCLUDE_LIST_H_

#include <iostream>
#include <ostream>
template <class T> class iterator;
template <class T> class CNode;
template <class T> class CList;

template <class T>
class iterator {
public:
	iterator();
	iterator(CNode<T>* ptr);
	~iterator();

	iterator operator++();
	bool operator!=(const iterator& other) const;
	CNode<T>& operator*();

private:
	CNode<T>* ptr;
};

template <class T>
iterator<T>::iterator() {}

template <class T>
iterator<T>::iterator(CNode<T>* ptr) : ptr(ptr) {};

template <class T>
iterator<T>::~iterator() {}

template <class T>
iterator<T> iterator<T>::operator++() {
	ptr = ptr->get_next_node();
	return *this;
}

template <class T>
bool iterator<T>::operator!=(const iterator<T>& other) const {
	return ptr != other.ptr;
}

template <class T>
CNode<T>& iterator<T>::operator*() {
	return *ptr;
}


template <class T>
class CList {
	friend class CNode<T>;
private:
	CNode<T>* head;
	CNode<T>* tail;
public:
	CList();
	CList(std::initializer_list<T> init_list);
	~CList();
	void push_back(T value);
	void push_front(T value);
	void pop_front();
	void pop_back();
	void clearHeadAndTail();
	void insert(T _data, int index);
	void erase(int index);
	void reverse();
	void clear();
	bool isEmpty() const;
	size_t size();
	CNode<T>* front();
	CNode<T>* back();
	CNode<T>* operator[] (int index);
	iterator<T> begin() const;
	iterator<T> end() const;
};

template <class T>
class CNode {
	friend class CList<T>;
private:
	T data;
	CNode<T>* next;
public:
	CNode(T value);
	~CNode();
	void set_next(CNode<T>* next_node);
	CNode<T>* get_next_node();
	void set_data(T _data);
	T get_data();
	T check_data() const;
	void print();
	void del_next();
	void operator = (CNode<T>* node);
};

#pragma region Realization

template <class T>
CList<T>::CList() : head(nullptr), tail(nullptr) {}

template <class T>
CList<T>::CList(std::initializer_list<T> init_list) {
	head = nullptr;
	tail = nullptr;
	for (auto element : init_list) {
		this->push_back(element);
	}
}

template <class T>
CList<T>::~CList() {}

template <class T>
size_t CList<T>::size() {
	if (head == nullptr) {
		return 0;
	}
	int size = 0;
	CNode<T>* tmp = head;
	for (; tmp != NULL && tmp != nullptr; tmp = tmp->get_next_node()) { ++size; }
	return size;
}

template <class T>
void CList<T>::push_back(T value) {
	CNode<T>* new_node = new CNode<T>(value);
	if (!isEmpty()) {
		tail->next = new_node;
		tail = new_node;
	}
	else {
		head = new_node;
		tail = new_node;
	}
}

template <class T>
void CList<T>::push_front(T value) {
	CNode<T>* new_node = new CNode<T>(value);
	CNode<T>* tmp = head;
	if (!isEmpty()) {
		head = new_node;
		head->next = tmp;
	}
	else {
		head = new_node;
		tail = new_node;
	}
}

template <class T>
void CList<T>::pop_back() {
	if (head == tail) { throw std::logic_error("Head = tail"); }
	else if (isEmpty()) { throw std::logic_error("List is empty"); }
	CNode<T>* tmp = (*this)[size() - 2];
	tmp->del_next();
	tail = tmp;
}

template <class T>
void CList<T>::clearHeadAndTail() {
	//delete head;
	//delete tail;
	head = nullptr;
	tail = nullptr;
}


template <class T>
void CList<T>::pop_front() {
	if (head != tail) {
		CNode<T>* tmp = head;
		head = head->next;
		delete tmp;
		tmp = nullptr;
	}
	else {
		clearHeadAndTail();
	}
}

template <class T>
CNode<T>* CList<T>::front() {
	return head;
}

template <class T>
CNode<T>* CList<T>::back() {
	return tail;
}

template <class T>
void CList<T>::insert(T _data, int index) {
	if (index < 0) {
		throw std::out_of_range("out of range");
	}
	if (index == 0) {
		push_front(_data);
		return;
	}
	if (index == size()) {
		push_back(_data);
		return;
	}
	if (index > size()) {
		throw std::out_of_range("out of range");
	}
	CNode<T>* tmp = new CNode<T>(_data);
	CNode<T>* post = (*this)[index];
	CNode<T>* pre = (*this)[index - 1];
	pre->set_next(tmp);
	tmp->set_next(post);
}

template <class T>
void CList<T>::erase(int index) {
	if (index < 0) {
		throw std::out_of_range("out of range");
	}
	if (index == 0) {
		pop_back();
		return;
	}
	if (index == size() - 1) {
		pop_back();
		return;
	}
	if (index >= size() - 1) {
		throw std::out_of_range("out of range");
	}
	CNode<T>* del_elem = (*this)[index];
	CNode<T>* pre = (*this)[index - 1];
	CNode<T>* post = (*this)[index + 1];
	pre->set_next(post);
	delete del_elem;
	del_elem = nullptr;
}

template <class T>
void CList<T>::reverse() {
	CList<T>* temp = new CList<T>();
	for (; !isEmpty(); temp->push_front(front()->get_data()), this->pop_front());
	(*this) = *temp;
}

template <class T>
CNode<T>* CList<T>::operator[] (int index) {
	CNode<T>* tmp = head;
	int tmp_index = 0;
	for (; tmp_index < index; tmp = tmp->get_next_node()) {
		++tmp_index;
	}
	return tmp;
}

template <class T>
void CList<T>::clear() {
	for (CNode<T>* node = head, *del_node = head; node != nullptr;
		node = node->get_next_node(),
		(*del_node).set_next(nullptr),
		del_node = node);
	clearHeadAndTail();
}

template <class T>
bool CList<T>::isEmpty() const {
	return head == nullptr;
}

template <class T>
iterator<T> CList<T>::begin() const {
	return iterator<T>(head); 
}

template <class T>
iterator<T> CList<T>::end() const {
	return iterator<T>(tail->get_next_node());
}

template <class T>
CNode<T>::CNode(T value) : data(value), next(nullptr) {}

template <class T>
CNode<T>::~CNode() {}

template <class T>
void CNode<T>::set_next(CNode<T>* next_node) {
	next = next_node;
}

template <class T>
CNode<T>* CNode<T>::get_next_node() {
	return next;
}

template <class T>
void CNode<T>::set_data(T _data) {
	data = _data;
}

template <class T>
T CNode<T>::check_data() const {
	return data;
}

template <class T>
T CNode<T>::get_data() {
	return data;
}

template <class T>
void CNode<T>::print() {
	std::cout << data;
}

template <class T>
void CNode<T>::del_next() {
	delete next;
	next = nullptr;
}

template <class T>
void CNode<T>::operator = (CNode<T>* node) {
	data = node->get_data();
	next = node->get_next_node();
}

#pragma endregion

#endif  // INCLUDE_LIST_H_