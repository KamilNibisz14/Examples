#include "Questions.h"

#include <iostream>
#include <fstream>
#include <string>

void Questions::set(std::string question, std::string category, std::string ansA, std::string ansB, std::string ansC, std::string ansD, int goodAns)
{
	this->question = question;
	this->category = category;
	this->ansA = ansA;
	this->ansB = ansB;
	this->ansC = ansC;
	this->ansD = ansD;
	this->goodAns = goodAns;
}

void Questions::show()
{
	std::cout << question << std::endl;
	std::cout << category << std::endl;
	std::cout << ansA << " " << ansB << " " << ansC << " " << ansD << " " << std::endl;
	std::cout << goodAns << std::endl;
}
void Questions::showCategory()
{
	std::cout << category << std::endl;
}
void Questions::showQnA()
{
	std::cout << question << std::endl;
	std::cout << std::endl;
	std::cout <<"A."<< ansA << std::endl;
	std::cout <<"B." << ansB << std::endl;
	std::cout <<"C." << ansC << std::endl;
	std::cout <<"D." << ansD << std::endl;
	std::cout << std::endl;
}
int Questions::gn()
{
	return goodAns;
}

void addQ(Questions* q, int size)
{
	std::fstream plik;
	plik.open("Baza.txt");

	for (int i = 0; i < size; ++i) 
	{
		std::string question;
		std::string category;
		std::string ansA;
		std::string ansB;
		std::string ansC;
		std::string ansD;
		int goodAns;
		std::string z;

		std::getline(plik, question);
		plik >> category;
		plik >> ansA;
		plik >> ansB;
		if (i < 70)
		{
			plik >> ansC;
			plik >> ansD;
		}
		else
		{
			ansC = "0";
			ansD = "0";
		}
		plik >> goodAns;
		std::getline(plik, z);

		q[i].set(question, category, ansA, ansB, ansC, ansD, goodAns);
	}

}