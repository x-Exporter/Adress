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

	void set_adress(string something, int i)
	{
		mass_adress[i] = something;
	}
	void print_adress(int amount,ofstream &ofile)
	{
		string inf;
		ofile << amount << endl;
		for (int i = 0; i < amount; i++)
		{
			for (int k = amount * 4 - (i + 1) * 4; k < amount * 4 - i * 4; k++)
			{
				
				inf = mass_adress[k];
				ofile << inf;
				if (k +1 != amount * 4 - i * 4)
				{
					ofile << ", ";
				}
			}
			ofile << endl;
		}
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
	Adress adress(amount);

	for (int i = 0; i < amount * 4; i++)
	{
		ifile >> something;
		adress.set_adress(something, i);
	}
	adress.print_adress(amount,ofile);

	
}
