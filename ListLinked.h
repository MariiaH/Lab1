#pragma once


#include "BaseList.h"


template<typename T>
struct Node
{
	T value;
	Node *next = nullptr;
	Node(T value) : value(value) {}
};


template<typename T>
class ListLinked : public List<T>
{
protected:
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;
	int length;

	Node<T> *getNode(int position);

public:
	ListLinked();

	void pushBack(T value);
	void popBack();
	void pushFront(T value);
	void popFront();
    void showAll();
	void addElement(T value, int position);
	void deleteElement(int position);
	T getElement(int position);
	int getIndex(T value);
	void clear();
	int getSize();
	T getElememtMetchingCriterion(bool(*criterion)(T));
};


template<typename T>
Node<T> *ListLinked<T>::getNode(int position)
{
	Node<T> *node = head;
	for (int i = 0; i < position; ++i)
	{
		node = node->next;
	}
	return node;
}

template<typename T>
ListLinked<T>::ListLinked()
{
	length = 0;
}

template<typename T>
void ListLinked<T>::showAll()
{
	Node<T> *node = head;
	for (int i = 0; i < length; ++i)
	{
		cout << node->value << ' ';
		node = node->next;
	}
	cout << '\n';
}

template<typename T>
void ListLinked<T>::pushBack(T value)
{
	Node<T>  *newNode = new Node<T>(value);
	if (length == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	++length;
}

template<typename T>
void ListLinked<T>::popBack()
{
	if (length != 0)
	{
		Node<T> *node = getNode(length - 2);
		tail = node;
		node = node->next;
		tail->next = nullptr;
		delete node;
		--length;
	}
}

template<typename T>
void ListLinked<T>::pushFront(T value)
{
	Node<T> *newNode = new Node<T>(value);
	if (length == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	++length;
}

template<typename T>
void ListLinked<T>::popFront()
{
	if (length != 0)
	{
		Node<T> *node = head;
		head = head->next;
		delete node;
		--length;
	}
}

template<typename T>
void ListLinked<T>::addElement(T value, int position)
{
	if (position < 0 || position > length)
	{
		return;
	}
	else if (position == 0)
	{
		pushFront(value);
	}
	else if (position == length)
	{
		pushBack(value);
	}
	else
	{
		Node<T> *node = getNode(position - 1);
		Node<T> *newNode = new Node<T>(value);
		newNode->next = node->next;
		node->next = newNode;
		++length;
	}
}

template<typename T>
void ListLinked<T>::deleteElement(int position)
{
	if (position < 0 || position >= length)
	{
		return;
	}
	else if (position == 0)
	{
		popFront();
	}
	else if (position == length - 1)
	{
		popBack();
	}
	else
	{
		Node<T> *node = getNode(position - 1);
		Node<T> *newNode;
		newNode = node->next;
		node->next = node->next->next;
		delete newNode;
		--length;
	}
}

template<typename T>
T ListLinked<T>::getElement(int position)
{
	if (position < 0 || position >= length)
	{
		return T();
	}
	else
	{
		Node<T> *node = getNode(position);
		return node->value;
	}
}

template<typename T>
int ListLinked<T>::getIndex(T value)
{
	int index = 0;

	Node<T> *node = head;
	while (node->value != value)
	{
		if (node->next == nullptr)
		{
			return -1;
		}
		node = node->next;
		++index;
	}
	return index;
}

template<typename T>
void ListLinked<T>::clear()
{
	while (length > 0)
	{
		popFront();
	}
}

template<typename T>
int ListLinked<T>::getSize()
{
	return length;
}

template<typename T>
T ListLinked
<T>::getElememtMetchingCriterion(bool(*criterion)(T))
{
	if (length > 0)
	{
		Node<T> *node = head;
		while (node->next != nullptr)
		{
			if (criterion(node->value))
			{
				return node->value;
			}
			node = node->next;
		}
		if (criterion(node->value))
		{
			return node->value;
		}
	}
	return T();
}
