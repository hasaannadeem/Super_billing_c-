#pragma once
class Price
{
protected:
	float price, tax, gross, dis, netamt;
public:
	void calculate();
	
	void set(float, float, float);
	void get(float&, float&, float&, float&, float&);
	Price();
	~Price();
};

