#include "Questions.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <time.h>

Questions questions[80];
void state(int i)
{
	std::cout << std::endl;
	std::cout << "\t\t\t\t";
	for (int j = 0; j < i + 1; ++j)
	{
		std::cout << "* ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

int Ans(int w[], int saldo, int choice, int i)
{
	int ch[4];
	int s = saldo;
	int f = 0;

	while (true)
	{
		for (int q = 0; q < 3; ++q)
		{
			system("CLS");
			state(i);
			questions[w[choice]].showQnA();

			std::cout << s << " zl" << std::endl;
			std::cout << std::endl;
			do {
				std::cout << char(65 + q) << ": ";
				std::cin >> ch[q];
			} while (ch[q] > s);
			s -= ch[q];
			if (ch[q] > 0)
				f++;
		}
		if (f == 3 && s > 0)
		{
			system("CLS");
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "\t\t Jedna odpowiedz musi byc pusta " << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			s = saldo;
			Sleep(1000);
			f = 0;
		}
		else
		{
			ch[3] = s;
			break;
		}
	}
	return ch[questions[w[choice]].gn() - 1];

}


int main()
{
	srand(time(NULL));
	
	addQ(questions, 80);
	int saldo = 1000000;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\t\t\tPostaw na milion" << std::endl;
	Sleep(000);
	for (int i = 0; i < 8; ++i)
	{
		system("CLS");
		state(i);
		int w[2];
		w[0] = rand() % 10 + (i * 10);
		do{
			w[1] = rand() % 10 + (i * 10);
		} while (w[1] == w[0]);
		std::cout << "Kategorie:" << std::endl;
		std::cout << "1.";
		questions[w[0]].showCategory();
		std::cout << "2.";
		questions[w[1]].showCategory();
		int choice;
		do 
		{
			std::cin >> choice;
		} while (choice != 2 && choice != 1);
		choice -= 1;
		system("CLS");
		int s = saldo;
		saldo = Ans(w,s,choice, i);

		if (saldo ==  0)
		{
			system("CLS");
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Przegrales" << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		}
		if (i == 7 && s > 0)
		{
			system("CLS");
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Wygrana: " << s << "zl" << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}

	}
}