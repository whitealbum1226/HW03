// Item.h

#pragma once
#include <iostream>
#include <string>

class Item
{
public:
	Item();
	Item(const std::string& name, int price);

	const std::string& GetName() const;
	int GetPrice() const;
	void PrintInfo() const;

private:
	std::string name_;
	int price_;
};

inline bool compareItemsByPrice(const Item& a, const Item& b)
{
	return a.GetPrice() < b.GetPrice();
}