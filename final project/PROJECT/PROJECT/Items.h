#pragma once
#include"Price.h"
#include<iostream>
using namespace std;
class Items
{
protected:
	char* name;
	char* id;
	char* manufacturer;
	Price price;
	

public:
	virtual void display();
	
	void setName(char*);
	void setID(char*);
	char* getID();
	void setManf(char*);
	char* getManf();
	char* getName();
	void getPrice(float&, float&,  float&, float&);
	void setPrice(float,float,float);
	Items();
	virtual ~Items();
};

