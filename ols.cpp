#include "ols.h"

ols::ols()
{
	first = nullptr;
	last = nullptr;
	size_list = 0;
};

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

bool ols::empty() {
	return first == nullptr;
};

void ols::add(const int data)
{
	node* temp = new node(data);
	if (empty()) {
		first = temp;
		last = temp;
		return;
	}
	last->next = temp;
	last = temp;
	size_list += 1;
};

void ols::remove(const int data) {
	if (empty()) return;
	if (first->data == data) {
		node* temp = first;
		first = temp->next;
		delete temp;
		return;
	}
	else if (last->data == data) {
		if (first == last) {
			node* temp = first;
			first = temp->next;
			delete temp;
			return;
		}
		node* temp = first;
		while (temp->next != last) temp = temp->next;
		temp->next = nullptr;
		delete last;
		last = temp;
		return;
	}
	node* slow = first;
	node* fast = first->next;
	while (fast && fast->data != data) {
		fast = fast->next;
		slow = slow->next;
	}
	if (!fast) {
		cout << "NO" << endl;
		return;
	}
	slow->next = fast->next;
	delete fast;
};

size_t ols::search(const int data) {
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

void ols::output()
{
	if (empty()) return;
	node* temp = first;
	while (temp) { 
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
};

const size_t ols::size()
{
	return size_list;
};
