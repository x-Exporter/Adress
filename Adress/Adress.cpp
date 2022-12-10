#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

class Adress
{
private:
	string* mass_adress;
public:
	Adress(int amount)
	{
		mass_adress = new string[amount * 4];
	}
	void take_adress(string adress,int i)
	{
		mass_adress[i] = adress;
	}
	void cout_to_file(ofstream &ofile)
	{
		for (int i = 0; i < 4; i++)
		{
			ofile << mass_adress[i];
			if (i != 3)
			{
				ofile << ", ";
			}
		}
		ofile << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(CP_UTF8);
	ifstream ifile("in.txt");
	ofstream ofile("out.txt");
	int amount;
	string something;
	ifile >> amount;

	Adress adress1(amount);
	for (int i = 0; i < 4; i++)
	{
		ifile >> something;
		adress1.take_adress(something, i);
	}

	Adress adress2(amount);
	for (int i = 0; i < 4; i++)
	{
		ifile >> something;
		adress2.take_adress(something, i);
	}

	Adress adress3(amount);
	for (int i = 0; i < 4; i++)
	{
		ifile >> something;
		adress3.take_adress(something, i);
	}
	ofile << amount << endl;

	adress3.cout_to_file(ofile);
	adress2.cout_to_file(ofile);
	adress1.cout_to_file(ofile);
}
