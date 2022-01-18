#include "SuperMarket.h"

int SuperMarket::menu2()
{
	int op;
	system("cls");
	cout << "1: Add Crockery Item\n"
		<< "2: Add Food Item\n"
		<< "3:Add Household Item\n"
		<< "4:Back to Main menu\n"
		<< "Enter option: ";
	cin >> op;
	if (op == 4)
	{
		menu1();
	}
	if (op >= 1 && op <= 3)
	{
		return op;
	}
	else
		menu2();
}
int SuperMarket::menu1()
{
	int op;
	system("cls");
	cout << "1: Add Item\n"
		<< "2: Edit Item\n"
		<< "3: Show Item Details\n"
		<< "4: Generate Invoice\n"
		<< "5: Read from file\n"
		<< "6: Delete Item\n"
		<< "Enter option: ";
	cin >> op;
	if (op == 1)
	{
		return 6 + menu2();
		
	}
	if (op >= 2 && op <= 6)
	{
		return op;
	}
	else
		menu1();
}
void SuperMarket::deleteI()
{
	char n[100];
	cout << "Enter Item ID to Delete: ";
	cin >> n;
	int x = 0;
	for (int i = 0; i < count; i++)
	{
		if (obj[i]->getID() == n)
		{
			x = i;
		}
	}
	obj[x]->display();
	cout << "\n DELETED";
	delete obj[x];
	count--;
}
void SuperMarket::edit()
{
	char n[100];
	cout << "Enter Item ID to Edit Details: ";
	cin >> n;
	int x = 0;
	for (int i = 0; i < count; i++)
	{
		if (obj[i]->getID() == n)
		{
			x = i;
			break;
		}
	}
	cout << "Enter new details of : ";
	obj[x]->display();
	cout << endl;
	cout << "Enter item ID: ";
	cin >> n;
	obj[x]->setID(n);
	cout << "Enter item Name: ";
	cin >> n;
	obj[x]->setName(n);
	cout << "Enter item Manufacturer: ";
	cin >> n;
	obj[x]->setManf(n);
	float a, b, c;
	cout << "Price: ";
	cin >> a;
	cout << "Tax percent: ";
	cin >> b;
	cout << "Discount percent: ";
	cin >> c;
	obj[x]->setPrice(a,b,c);

}
void SuperMarket::invoice()
{
	char n[100];
	int x = 0,t=0;
	float bill=0;
	float a, b, c,d;
	char m='y';
	do
	{
		cout << "Enter Item ID: ";
		cin >> n;
		for (int i = 0; i < count; i++)
		{
			if (obj[i]->getID() == n)
			{
				x = i;
				break;
			}
		}
		obj[x]->display();
		cout << endl;
		cout << "Enter Quantity of " << obj[x]->getName();
		cin >> t;
		obj[x]->getPrice(a, b, c,d);
		bill = t*d + bill;
		cout << "Add item (y/n):"; cin >> m;
	}while (m == 'y' || m == 'Y');
	cout << "Total amount to be paid: " << bill;
}
void SuperMarket::addCrockeryItem()
{
	if (count < 100)
	{
		obj[count] = new CrockeryItems;  //polymorphism
		char n[100];
		cout << "Enter item ID: ";
		cin >> n;
		obj[count]->setID(n);
		cout << "Enter item Name: ";
		cin >> n;
		obj[count]->setName(n);
		cout << "Enter item Manufacturer: ";
		cin >> n;
		obj[count]->setManf(n);
		float a, b, c;
		cout << "Price: ";
		cin >> a;
		cout << "Tax percent: ";
		cin >> b;
		cout << "Discount percent: ";
		cin >> c;
		obj[count]->setPrice(a, b, c);
		writeC();
		count++;
	}
}
void SuperMarket::addFoodItem()
{
	if (count < 100)
	{
		obj[count] = new FoodItems;
		char n[100];
		cout << "Enter item ID: ";
		cin >> n;
		obj[count]->setID(n);
		cout << "Enter item Name: ";
		cin >> n;
		obj[count]->setName(n);
		cout << "Enter item Manufacturer: ";
		cin >> n;
		obj[count]->setManf(n);
		float a, b, c;
		cout << "Price: ";
		cin >> a;
		cout << "Tax percent: ";
		cin >> b;
		cout << "Discount percent: ";
		cin >> c;
		obj[count]->setPrice(a, b, c);
		writeF();
		count++;
	}
}
void SuperMarket::addHouseholdItem()
{
	if (count < 100)
	{
		obj[count] = new HouseholdItems;
		char n[100];
		cout << "Enter item ID: ";
		cin >> n;
		obj[count]->setID(n);
		cout << "Enter item Name: ";
		cin >> n;
		obj[count]->setName(n);
		cout << "Enter item Manufacturer: ";
		cin >> n;
		obj[count]->setManf(n);
		float a, b, c;
		cout << "Price: ";
		cin >> a;
		cout << "Tax percent: ";
		cin >> b;
		cout << "Discount percent: ";
		cin >> c;
		obj[count]->setPrice(a, b, c);
		writeH();
		count++;
	}

}

void SuperMarket::read()
{
	readC();
	readF();
	readH();
}


void SuperMarket::writeC()
{
	ofstream fout;
	fout.open("fileC.txt",  ios::app);
	char *a;
	a=obj[count]->getID();
	fout << a<<"\t";
	a = obj[count]->getName();
	fout << a << "\t";
	a = obj[count]->getManf();
	fout << a << "\t";
	float a1, b, c, d;
	obj[count]->getPrice(a1, b, c, d);
	fout << a1 << "\t" << b << "\t" << c << "\t" << d << "\n";


	
	//fout.write((char *)&obj[count], sizeof(obj[count]));
	fout.close();
}
void SuperMarket::readC()
{
	ifstream fin;
	fin.open("fileC.txt");
	cout << fin.eof();
	
	if (count < 100 )
	{
		obj[count] = new CrockeryItems;
		char n[100];
		fin >> n;

		obj[count]->setID(n);

		fin >> n;

		obj[count]->setName(n);

		fin >> n;

		obj[count]->setManf(n);

		float a, b, c;

		fin >> a;

		fin >> b;

		fin >> c;
		obj[count]->setPrice(a, b, c);
		count++;
	}
	
	
	//fin.read((char*)&obj[count], sizeof(obj[count]));
	fin.close();
}
void SuperMarket::writeF()
{
	ofstream fout;
	fout.open("fileF.txt", ios::app);
	char *a;
	a = obj[count]->getID();
	fout << a << "\t";
	a = obj[count]->getName();
	fout << a << "\t";
	a = obj[count]->getManf();
	fout << a << "\t";
	float a1, b, c, d;
	obj[count]->getPrice(a1, b, c, d);
	fout << a1 << "\t" << b << "\t" << c << "\t" << d << "\n";



	//fout.write((char *)&obj[count], sizeof(obj[count]));
	fout.close();
}
void SuperMarket::readF()
{
	ifstream fin;
	fin.open("fileF.txt");
	
	if (count < 100 )
	{
		obj[count] = new FoodItems;
		char n[100];
		fin >> n;
		obj[count]->setID(n);

		fin >> n;
		obj[count]->setName(n);

		fin >> n;
		obj[count]->setManf(n);

		float a, b, c;

		fin >> a;

		fin >> b;

		fin >> c;
		obj[count]->setPrice(a, b, c);
		count++;
	}
	
}
void SuperMarket::writeH()
{
	ofstream fout;
	fout.open("fileH.txt", ios::app);
	char *a;
	a = obj[count]->getID();
	fout << a << " ";
	a = obj[count]->getName();
	fout << a << " ";
	a = obj[count]->getManf();
	fout << a << " ";
	float a1, b, c, d;
	obj[count]->getPrice(a1, b, c, d);
	fout << a1 << " " << b << " " << c << " " << d << "\n";



	//fout.write((char *)&obj[count], sizeof(obj[count]));
	fout.close();
}
void SuperMarket::readH()
{
	ifstream fin;
	fin.open("fileH.txt");
	if (count < 100 && !fin.eof())
	{
		obj[count] = new HouseholdItems;
		char n[100];
		fin >> n;

		obj[count]->setID(n);

		fin >> n;

		obj[count]->setName(n);

		fin >> n;

		obj[count]->setManf(n);

		float a, b, c;

		fin >> a;

		fin >> b;

		fin >> c;
		obj[count]->setPrice(a, b, c);
		count++;
	}
	
	
}


void SuperMarket::display()
{
	cout << "ID \t\t Name \t\t Manufacturer \t\t\t Type \t\t Price \t\t Tax% \t\t Discount% \t\t Net Total\n";
	for (int i = 0; i < count; i++)
	{
		obj[i]->display();
		cout << endl;
	}
}
SuperMarket::SuperMarket()
{
	count = 0;
}


SuperMarket::~SuperMarket()
{
}
