#pragma once

#include <iostream>

using namespace std;

/*!
\brief ����� ����� ������.

� ������ ������ ����������� ��������� �������� ������.
� ��� ������������ ��������� ���� :
- int data - �������� �����(��������) ������
- Node * next - ��������� ���� Node �� ��������� �������� ������
*/

class node {
public:
	int data;
	node* next;

	
	node(int data) {
		this->data = data;
	};
};
/*!
\brief ����� ���������� ������.

� ������ ������ ������� ���������� ������������ ��������� ������.
� ��� ������������ ��������� ���� :
- size_t size_list - �������� ���� size_t ���������� ��������� ������
- Node* first, last - ��������� ���� Node �� ������ � ��������� �������� ������
*/

class ols {
	node* first;
	node* last;
	size_t size_list;

public:
	/*!
	 \brief ����������� �� ���������.

	 � ������ ������������ ������������� ����������
	 first � last  nullptr (������� ��������).
	*/
	ols();

	/*!
	 \brief ���������� �� ���������.

	  � ����������� ������������� ���������� ��������� ������ nullptr (������� ��������)
	 � ������������� ������.
	*/
		
	~ols();

	/*!
	 \brief ����� �������� �� ������� ������.
	 \return first - ���������� true ��� false, ���� ������ ������� ������
	 �� � ������ �� ����������.
	
	*/

	bool empty();
	/*!
	 \brief ����� ���������� �������� � ������.
	 \param[in] const int data - ��������,  ������� ����� ������� ����������� �������

	 ��� ����������� ��������� ����� ������� ����������� � �����
	 ��� ���������� �� ���������� ������ ���������

	*/
	void add(const int data);

	/*!
	 \brief ����� ���������� �������� � ������.
	 \param[in] const int data - �������� �� �������� ����� ������ ������� �� ������

	 ������� ���������, ���� �� ������ ������
	 ��������� ������ �� ��� �������, ���� �� �� ������� ���
	 ��������� ��������� �������, ���� �� �� �� ������� ���
	 ���� �� ����������� ������� �������, �� ���� ������ ������
	 �� ���� ���� ������ �������� ������ ������� ��������� NO
	*/

	void remove(const int data);

	/*!
	 \brief ����� ������ �������� � ������.
	 \param[in] const int data - �������� �� �������� ����� ���������� �����  ��������
	 \return - ���������� ������ ��������

	*/

	size_t search(const int data);

	/*!
	 \brief ����� ���������� �������� � ������.
	 \param[in] const size_t index - ������ �������� �������� ����� �������� ��������
	 \param[in] const int data - ��������,  ������� ����� �������  �������

	*/
	
	void update(const size_t index, const int data);

	/*!
	 \brief ����� ������ ����� ������.
	 ������� ���� ������

	*/

	void output();
	/*!
	 \brief ����� ��������� ������� ������.
	 \return size_list - ����������� ������ ������
	 ������� ������ ������
	 
	*/
	const size_t size();
};