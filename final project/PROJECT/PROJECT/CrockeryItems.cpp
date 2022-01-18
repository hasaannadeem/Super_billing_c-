#include "CrockeryItems.h"

void CrockeryItems::display()
{
	float p, t, g, d, n;
	getPrice(p, t, d, n);
	cout << id << "\t\t " << name << "\t\t " << manufacturer << "\t\t Crockery\t\t" << p << "\t\t" << t << "\t\t"  << d << "\t\t" << n << endl;
}

CrockeryItems::CrockeryItems()
{
}


CrockeryItems::~CrockeryItems()
{
}
