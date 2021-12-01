#pragma once
#include <iostream>
class Questions
{
	std::string question;
	std::string category;
	std::string ansA;
	std::string ansB;
	std::string ansC;
	std::string ansD;
	int goodAns;
public:
	void show();
	void showCategory();
	void showQnA();
	int gn();
	void set(std::string question, std::string category, std::string ansA, std::string ansB, std::string ansC, std::string ansD, int goodAns);
};

void addQ(Questions* q, int size);