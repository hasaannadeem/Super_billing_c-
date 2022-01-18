#include "HouseholdItems.h"

void HouseholdItems::display()
{
	float p, t, g, d, n;
	getPrice(p, t, d, n);
	cout << id << "\t\t " << name << "\t\t " << manufacturer << "\t\t Household\t\t" << p << "\t\t" << t << "\t\t"  << d << "\t\t" << n << endl;

}

HouseholdItems::HouseholdItems()
{
}


HouseholdItems::~HouseholdItems()
{
}
