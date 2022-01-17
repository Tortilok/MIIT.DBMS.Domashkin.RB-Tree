#pragma once

#include <iostream>

using namespace std;

/*!
\brief Класс звена списка.

В данном классе реализована структура элемента списка.
В нем присутствуют приватные поля :
- int data - значение звена(элемента) списка
- Node * next - указатель типа Node на следующее элемента списка
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
\brief Класс реализации списка.

В данном классе описана реализация односвязного линейного списка.
В нем присутствуют приватные поля :
- size_t size_list - значение типа size_t количества элементов списка
- Node* first, last - указатель типа Node на первое и последнее элемента списка
*/

class ols {
	node* first;
	node* last;
	size_t size_list;

private:

	ols(const ols&) = delete;


	ols& operator=(const ols&) = delete;


	ols(ols&&) = delete;


	ols& operator=(const ols&&) = delete;

	friend ostream& operator <<(ostream& out, ols& l);


public:
	/*!
	 \brief Конструктор по умолчанию.

	 В данном конструкторе присваиваются указателям
	 first и last  nullptr (нулевые значения).
	*/
	ols();

	/*!
	 \brief Деструктор по умолчанию.

	  В деструкторе присваиваются указателям элементам списка nullptr (нулевые значения)
	 и освобождается память.
	*/

	~ols();

	/*!
	 \brief Метод проверки на пустоту списка.
	 \return first - возвращает true или false, есть первый элемент пустой
	 то и списка не существует.

	*/

	const bool empty();
	/*!
	 \brief Метод добавления элемента в список.
	 \param[in] const int data - значение,  которое будет хранить добавленный элемент

	 При присутствии элементов новый элемент добавляется в конце
	 При отсутствии он становится первым элементом

	*/
	void add(const int data);

	/*!
	 \brief Метод чтения элемента из списка.
	 \return item - Переменная типа int данные элемента списка

	*/

	const int read(const int index);
	/*!
	 \brief Метод удаления элемента из списка.
	 \param[in] const int data - номер элемента который нужно удалить

	 Сначала проверяет, есть ли список вообще
	 Проверяет первый ли это элемент, если да то удаляет его
	 Проверяет последний элемент, если да то то удаляет его
	 Если не выполняются верхние условия, то ищет внутри списка
	*/

	void remove(const int index);

	/*!
	 \brief Метод поиска элемента в списке.
	 \param[in] const int data - значение по которому будет произведен поиск  элемента
	 \return - возвращает индекс элемента

	*/

	const int search(const int data);

	/*!
	 \brief Метод обновления значения в списке.
	 \param[in] const size_t index - индекс элемента которому нужно изменить значение
	 \param[in] const int data - значение,  которое будет хранить  элемент

	*/

	void update(const size_t index, const int data);

	/*!
	 \brief Метод получения размера списка.
	 \return size_list - возвращение длинны списка
	 Выводит размер списка

	*/
	const size_t size();

	int& operator[] (int index);

	const int& operator[] (const int index) const;
};