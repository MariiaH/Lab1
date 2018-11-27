#pragma once


#include <list>
#include "BaseList.h"


template<typename T>
class ListLibrary : public List<T>
{
	list<T> list;

public:
	ListLibrary();

	void showAll();
	void pushBack(T value);
	void popBack();
	void pushFront(T value);
	void popFront();
	void addElement(T value, int position);
	void deleteElement(int position);
	T getElement(int position);
	int getIndex(T value);
	void clear();
	int getSize();
	T getElememtMetchingCriterion(bool(*criterion)(T));
};


template<typename T>
ListLibrary<T>::ListLibrary() {}

template<typename T>
void ListLibrary<T>::showAll()
{
	for (auto i = list.begin(); i != list.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << '\n';
}

template<typename T>
void ListLibrary<T>::pushBack(T value)
{
	list.push_back(value);
}

template<typename T>
void ListLibrary<T>::popBack()
{
	list.pop_back();
}

template<typename T>
void ListLibrary<T>::pushFront(T value)
{
	list.push_front(value);
}

template<typename T>
void ListLibrary<T>::popFront()
{
	list.pop_front();
}

template<typename T>
void ListLibrary<T>::addElement(T value, int position)
{
	if (position < 0 || position > list.size())
	{
		return;
	}
	else if (position == 0)
	{
		pushFront(value);
	}
	else if (position == list.size())
	{
		pushBack(value);
	}
	else
	{
		auto i = list.begin();
		for (int j = 0; j < position; ++j)
		{
			++i;
		}
		list.insert(i, value);
	}
}

template<typename T>
void ListLibrary<T>::deleteElement(int position)
{
	if (position < 0 || position >= list.size())
	{
		return;
	}
	else if (position == 0)
	{
		popFront();
	}
	else if (position == list.size() - 1)
	{
		popBack();
	}
	else
	{
		auto i = list.begin();
		for (int j = 0; j < position; ++j)
		{
			++i;
		}
		list.erase(i);
	}
}

template<typename T>
T ListLibrary<T>::getElement(int position)
{
	if (position < 0 || position >= list.size())
	{
		return T();
	}
	else
	{
		auto i = list.begin();
		for (int j = 0; j < position; ++j)
		{
			++i;
		}
		return *i;
	}
}

template<typename T>
int ListLibrary<T>::getIndex(T value)
{
	int index = 0;

	for (auto i = list.begin(); i != list.end(); ++i)
	{
		if (*i == value)
		{
			return index;
		}
		++index;
	}
	return -1;
}

template<typename T>
void ListLibrary<T>::clear()
{
	list.clear();
}


template<typename T>
int ListLibrary<T>::getSize()
{
	return int(list.size());
}

template<typename T>
T ListLibrary<T>::getElememtMetchingCriterion(bool(*criterion)(T))
{
	if (list.size() > 0)
	{
		auto i = list.begin();

		while (i != list.end())
		{
			if (criterion(*i))
			{
				return *i;
			}
			++i;
		}
	}
	return T();
}
