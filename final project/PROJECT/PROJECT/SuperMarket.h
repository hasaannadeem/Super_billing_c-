#pragma once
#include"Items.h"
#include <fstream>
#include"CrockeryItems.h"
#include"FoodItems.h"
#include"HouseholdItems.h"

class SuperMarket
{
	Items *obj[100];
	int count;
public:
	void addCrockeryItem();
	void addFoodItem();
	void addHouseholdItem();
	int menu1();
	int menu2();
	void display();
	void display1();
	void edit();
	void invoice();
	void write();
	void read();
	void deleteI();
	void writeC();
	void readC();
	void writeF();
	void readF();
	void writeH();
	void readH();
	SuperMarket();
	~SuperMarket();
};

