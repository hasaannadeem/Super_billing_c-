#include "Items.h"

void Items::display()
{

}
void Items::setManf(char* a)
{
	int len = strlen(a);
	manufacturer = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		manufacturer[i] = a[i];
	}
	manufacturer[len] = '\0';
}
char* Items::getManf()
{
	return manufacturer;
}
void Items::setName(char* a)
{
	int len = strlen(a);
	name = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		name[i] = a[i];
	}
	name[len] = '\0';


}
void Items::setID(char* a)
{
	int len = strlen(a);
	id = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		id[i] = a[i];
	}
	id[len] = '\0';
}
char* Items::getID()
{
	return id;
}
char* Items::getName()
{
	return name;
}
void Items::getPrice(float &p1, float &t1, float &d1, float &n1 )
{
	float p, t, g, d, n;
	price.get(p, t, g, d, n);
	p1 = p;
	t1 = t;
	
	d1 = d;
	n1 = n;

	
}
void Items::setPrice(float p,float t,float d)
{
	
	price.set(p,t,d);
	
}
Items::Items()
{
	
}


Items::~Items()
{
	delete[]name;
	delete[]id;
	delete[]manufacturer;
	name = nullptr;
	id = nullptr;
	manufacturer = nullptr;
}
