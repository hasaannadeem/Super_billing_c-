#include "FoodItems.h"

void FoodItems::display()
{
	float p, t, g, d, n;
	getPrice(p, t,  d, n);
	cout << id << "\t\t " << name << "\t\t " << manufacturer << "\t\t Food\t\t" << p << "\t\t" << t << "\t\t" << d << "\t\t" << n << endl;

}

FoodItems::FoodItems()
{
}


FoodItems::~FoodItems()
{
}
