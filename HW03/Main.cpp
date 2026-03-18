// Main.cpp

#include "Inventory.h"
#include "Item.h"

struct ItemData
{
	std::string name;
	int price;
};

ItemData itemList[] =
{
	{"철검", 1000},
	{"철방패", 800},
	{"생명력 포션", 50},
	{"마나 포션", 80},
	{"스태미나 포션", 50},
	{"공격력 증가 포션", 200},
	{"고블린의 귀", 10},
	{"고블린의 눈", 15},
	{"고블린의 가죽", 15},
	{"오크의 가죽", 100},
	{"고블린의 조잡한 돌검", 1},
	{"오크의 대검", 2000},
	{"거미줄", 2},
	{"양털", 2},
	{"우유", 3},
	{"빵", 5},
	{"숙소 열쇠", 0},
	{"손질이 필요한 갑옷", 3000},
	{"손질이 필요한 건틀렛", 2000},
	{"손질이 필요한 그리브", 2000}
};

int main(void)
{
	Inventory<Item>* itemInventory = new Inventory<Item>();

	for (int i = 0; i < 11; ++i)
	{
		itemInventory->AddItem(Item(itemList[i].name, itemList[i].price));
	}
	
	std::cout << "\n==== 필수 과제 인벤토리 ====\n";
	itemInventory->PrintAllItems();
	std::cout << "\nItemCapacity : " << itemInventory->GetCapacity() << std::endl;

	itemInventory->Resize(25);
	for (int i = 0; i < 20; ++i)
	{
		itemInventory->AddItem(Item(itemList[i].name, itemList[i].price));
	}
	
	std::cout << "\n==== 도전 과제 인벤토리 ====\n";
	itemInventory->PrintAllItems();
	std::cout << "\nItemCapacity : " << itemInventory->GetCapacity() << std::endl;

	std::cout << "\n==== 정렬 후 인벤토리 ====\n";
	itemInventory->SortItems();
	itemInventory->PrintAllItems();

	std::cout << "\n==== 복사된 인벤토리 ====\n";
	Inventory<Item>* itemInventory2 = new Inventory<Item>(*itemInventory);
	itemInventory2->PrintAllItems();

	delete itemInventory;
	itemInventory = nullptr;

	delete itemInventory2;
	itemInventory2 = nullptr;

	return 0;
}
