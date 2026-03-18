// Inventory.h

#pragma once
#include <algorithm>
#include <iostream>
#include "Item.h"

template <typename T> 

class Inventory
{
public:
	~Inventory()
	{
		delete[] pItems_;
		pItems_ = nullptr;
	}

	Inventory(int capacity = 10)
	{
		if (capacity <= 0)
		{
			capacity_ = 1;
		}
		else
		{
			capacity_ = capacity;
		}

		size_ = 0;
		pItems_ = new T[capacity_];
	}

	void AddItem(const T& item)
	{
		if (size_ >= capacity_)
		{
			Resize(capacity_ * 2);
		}

		pItems_[size_] = item;
		++size_;
	}

	void RemoveLastItem()
	{
		if (size_ <= 0)
		{
			std::cout << "인벤토리가 비어있습니다!" << std::endl;
			return;
		}

		--size_;
	}

	int GetSize() const
	{
		return size_;
	}

	int GetCapacity() const
	{
		return capacity_;
	}

	void PrintAllItems() const
	{
		if (size_ == 0)
		{
			std::cout << "비어 있다!" << std::endl;
			return;
		}

		for (int i = 0; i < size_; ++i)
		{
			pItems_[i].PrintInfo();
		}
	}

	void Resize(int newCapacity)
	{
		if (newCapacity <= capacity_)
		{
			return;
		}

		T* pNewItems = new T[newCapacity];

		for (int i = 0; i < size_; ++i)
		{
			pNewItems[i] = pItems_[i];
		}

		delete[] pItems_;
		pItems_ = pNewItems;
		capacity_ = newCapacity;
	}

	void SortItems()
	{
		std::sort(pItems_, pItems_ + size_, compareItemsByPrice);
	}

	Inventory(const Inventory<T>& other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];

		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = other.pItems_[i];
		}
	}

	void Assign(const Inventory<T>& other)
	{
		if (this == &other)
		{
			return;
		}

		delete[] pItems_;

		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];

		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = other.pItems_[i];
		}
	}

private:
	T* pItems_;
	int capacity_;
	int size_;
};