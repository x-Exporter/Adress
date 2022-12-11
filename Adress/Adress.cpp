#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

class Adress
{
private:
	string city = "City";
	string street = "Street";
	int house_num = 0;
	int apartments_num = 0;
public:
	void set_info(ifstream &ifile)
	{
		ifile >> city;
		ifile >> street;
		ifile >> house_num;
		ifile >> apartments_num;
	}
	void get_info(ofstream& ofile)
	{
		ofile << city << ", " << street << ", " << house_num << ", " << apartments_num << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(CP_UTF8);
	ifstream ifile("in.txt");
	ofstream ofile("out.txt");
	int amount;
	ifile >> amount;
	Adress* addresses = new Adress[amount];
	for (int i = 0; i < amount; i++)
	{
		addresses[i].set_info(ifile);
	}
	ofile << amount << endl;
	for (int i = amount-1; i >= 0; i--)
	{
		addresses[i].get_info(ofile);
	}
	delete[] addresses;
}
