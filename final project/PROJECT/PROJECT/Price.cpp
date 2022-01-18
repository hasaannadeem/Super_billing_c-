#include "Price.h"

void Price::set(float p, float t,  float d)
{
	price = p; 
	tax = t;  
	dis = d; 
	calculate();
}
void Price::calculate()
{
	gross = price + (price*(tax / 100));
	netamt = (gross - (gross*(dis / 100)));
}
void Price::get(float &p, float &t, float &g, float &d, float &n)
{
	p = price;
	t = tax;
	g = gross;
	d = dis;
	n = netamt;
}
Price::Price()
{
}


Price::~Price()
{
}
