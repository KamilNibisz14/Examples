#include <iostream>
#include <vector>

int main()
{
	std::vector<int> diags;
	std::vector<int> numbers;
	std::vector<int> out;
	const char* pi =
		"3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067"
		"9821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819"
		"6442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127"
		"3724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609";
	int number;
	std::cout << "Podaj n (mniejsze niz 20): ";
	std::cin >> number;
	for (int i = 0; i < number * number; ++i)
	{
		if (i % number == 0)
			std::cout << std::endl;
		std::cout << pi[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < number; ++i)
	{
		diags.push_back(i);
		numbers.push_back(number - i);
	}
	int sum = number;
	for (int i = 0; i < ((2 * number - 1) - (number)); ++i)
	{
		diags.push_back(sum);
		sum += number;
		numbers.push_back(number - i - 1);
	}
	for (int i = 0; i < diags.size(); ++i)
	{
		int sum = 0;
		int pos = diags[i];
		for (int j = 0; j < numbers[i]; j++)
		{
			sum += int(pi[pos]) - 48;
			pos += (number + 1);
		}
		out.push_back(sum);
	}
	std::cout << std::endl;
	for (int i = number - 1; i >= 0; --i)
	{
		std::cout << out[i] << " ";
	}
	for (int i = number; i < out.size(); ++i)
	{
		std::cout << out[i] << " ";
	}

	return 0;
}
