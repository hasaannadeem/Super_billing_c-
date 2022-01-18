#include<iostream>
using namespace std;
#include"CrockeryItems.h"
#include"FoodItems.h"
#include"HouseholdItems.h"
#include "SuperMarket.h"


int main()
{
	SuperMarket obj;
	int op;
	while (true)
	{
		system("cls");
		
		op = obj.menu1();
		if (op == 7)//crockery
		{
			system("cls");
			obj.addCrockeryItem();
			
		}
		else if (op == 8)//food
		{
			system("cls");
			obj.addFoodItem();
			
		}
		else if (op == 9)//household
		{
			system("cls");
			obj.addHouseholdItem();
			
		}
		else if (op == 2)
		{
			obj.edit();
		}
		else if (op == 3)
		{
			obj.display();
			system("pause");
		}
		else if (op == 4)
		{
			obj.invoice();
			system("pause");

		}
		else if (op == 5)
		{
			obj.read();
		}
		else if (op == 6)
		{
			obj.deleteI();
		}


	};
	


	return 0;
}