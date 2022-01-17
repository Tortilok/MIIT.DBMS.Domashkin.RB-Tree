#include "ols.h"

ols::ols() : first(nullptr), last(nullptr), size_list(0) {}

ols::~ols()
{
	while (this->size() != 0) {
		node* temp = first->next;
		if (first != nullptr) {
			delete first;
			first = nullptr;
		}
		first = temp;
		size_list -= 1;
	}
};

const bool ols::empty() {
	return first == nullptr;
};

void ols::add(const int data)
{
	node* temp = new node(data);
	if (empty()) {
		first = temp;
		last = temp;
		size_list += 1;
		return;
	}
	last->next = temp;
	last = temp;
	size_list += 1;
};

const int ols::read(const int index)
{
	node* temp = first;
	for (size_t i = 0; i < index; i++) {
		temp = temp->next;
	}
	int item = temp->data;
	return item;
};

void ols::remove(const int index) {
	if (empty()) {
		return;
	}
	if (index >= size_list)
		return;
	else if (index == size_list - 1) {
		int i = 0;
		node* temp = first;
		while (temp != nullptr) {
			if (i == index - 1) {
				node* temp2 = temp->next;
				delete temp2;
				temp->next = nullptr;
				break;
			}
			temp = temp->next;
			i += 1;
		}
		size_list--;
	}
	else if (index == 0) {
		node* firstNext = first->next;
		delete first;
		first = firstNext;
		size_list--;
	}
	else {
		node* temp = first;
		int i = 0;
		while (temp != nullptr) {
			if (i == index - 1) {
				node* temp2 = temp->next;
				node* temp3 = temp2->next;
				temp->next = temp3;
				delete temp2;
				break;
			}
			temp = temp->next;
			i += 1;
		}
		size_list--;
	}
};

const size_t ols::search(const int data) {
	node* temp = first;
	for (size_t i = 1; i < this->size(); i++)
	{
		if (temp->data == data)
			return i;
		temp = temp->next;
	}

};

void ols::update(const size_t index, const int data)
{
	node* temp = first;
	size_t num = index;
	const size_t begin = 1;
	while (num != begin)
	{
		temp = temp->next;
		num--;
	}
	temp->data = data;
};

const size_t ols::size()
{
	return size_list;
};


ostream& operator <<(ostream& out, ols& l) {
	for (int i = 0; i < l.size(); i++)
		out << l[i] << " ";
	return out;
};

int& ols::operator[] (const int index) {
	node* cur = first;
	int i = 0;
	while (cur != nullptr) {
		if (i == index) {
			return cur->data;
		}
		else i++;
		cur = cur->next;
	}
};

const int& ols::operator[] (const int index) const {
	node* cur = first;
	int i = 0;
	while (cur != nullptr) {
		if (i == index) {
			return cur->data;
		}
		else i++;
		cur = cur->next;
	}
};