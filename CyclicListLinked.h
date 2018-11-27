#pragma once


#include "ListLinked.h"

template<typename T>
class CyclicListLinked : public ListLinked<T>
{
	using ListLinked<T>::length;
	using ListLinked<T>::head;
	using ListLinked<T>::getNode;

public:
	void pushBack(T value);
	void popBack();
	void pushFront(T value);
	void popFront();
	T getElememtMetchingCriterion(bool(*criterion)(T));
};


template<typename T>
void CyclicListLinked<T>::pushBack(T value)
{
	Node<T>  *newNode = new Node<T>(value);
	if (length == 0)
	{
		head = newNode;
		head->next = head;
	}
	else
	{
		Node<T> *node = getNode(length - 1);

		node->next = newNode;
		newNode->next = head;
	}
	++length;
}

template<typename T>
void CyclicListLinked<T>::popBack()
{
	if (length != 0)
	{
		Node<T> *node = getNode(length - 2);
		Node<T> *oldNode = node->next;

		node->next = head;
		delete oldNode;
		--length;
	}
}

template<typename T>
void CyclicListLinked<T>::pushFront(T value)
{
	Node<T> *newNode = new Node<T>(value);
	if (length == 0)
	{
		head = newNode;
		head->next = head;
	}
	else
	{
		Node<T> *node = getNode(length - 1);
		node->next = newNode;
		newNode->next = head;
		head = newNode;
	}
	++length;
}

template<typename T>
void CyclicListLinked<T>::popFront()
{
	if (length != 0)
	{
		Node<T> *node = getNode(length - 1);
		Node<T> *oldNode = head;
		node->next = head->next;
		head = head->next;
		delete oldNode;
		--length;
	}
}


template<typename T>
T CyclicListLinked<T>::getElememtMetchingCriterion(bool(*criterion)(T))
{
	if (length > 0)
	{
		Node<T> *node = head;
		while (node->next != head)
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
