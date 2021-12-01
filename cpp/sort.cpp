#include <cmath>
#include <iostream>

void bubble_sort(int* t, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (t[j - 1] > t[j]) {
				std::swap(t[j], t[j - 1]);
			}
		}
	}
}

void quick_sort(int* t, int left, int right)
{
	if (right <= left) {
		return;
	}

	int i = left - 1;
	int j = right + 1;
	int pivot = t[(left + right) / 2];

	while (true)
	{
		while (pivot > t[++i]);
		while (pivot < t[--j]);

		if (i <= j) {
			std::swap(t[i], t[j]);
		}
		else
			break;
	}

	if (j > left) {
		quick_sort(t, left, j);
	}
	if (i < right) {
		quick_sort(t, i, right);
	}
}

int main()
{
	srand(time(NULL));

	int size = 30;
	int quick_clock[30];
	int bubble_clock[30];

	for (int k = 0; k < size; k++)
	{
		int t1[20000];
		int t2[20000];
		for (int i = 0; i < 20000; ++i)
		{
			int x = rand() % 1000 + 1;
			t1[i] = x;
			t2[i] = x;
		}
		clock_t start1 = clock();
		bubble_sort(t1, 20000);
		bubble_clock[k] = clock() - start1;
		clock_t start2 = clock();
		quick_sort(t2, 0, 20000 - 1);
		quick_clock[k] = clock() - start2;
	}

	double average_bubble = 0;
	double average_quick = 0;

	for (int i = 0; i < size; ++i)
	{
		average_bubble += bubble_clock[i];
		average_quick += quick_clock[i];
	}

	average_bubble /= size;
	average_quick /= size;

	double standard_deviation_bubble = 0;
	double standard_deviation_quick = 0;
	for (int i = 0; i < size; ++i)
	{
		standard_deviation_bubble += pow(bubble_clock[i] - average_bubble, 2);
		standard_deviation_quick += pow(quick_clock[i] - average_quick, 2);
	}
	standard_deviation_bubble /= size;
	standard_deviation_quick /= size;

	standard_deviation_bubble = sqrt(standard_deviation_bubble);
	standard_deviation_quick = sqrt(standard_deviation_quick);

	for (int i = 0; i < size; ++i)
	{
		std::cout << i << ": " << bubble_clock[i] << " " << quick_clock[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Zostalo wykonene " << size << " pomiarow" << std::endl << std::endl;
	std::cout << "Sortowanie babelkowe: " << std::endl;
	std::cout << "Srednia: " << average_bubble << " ms" << std::endl;
	std::cout << "Odchylenie standardowe: " << standard_deviation_bubble << std::endl;

	std::cout << std::endl;
	std::cout << "Quick_sort: " << std::endl;
	std::cout << "Srednia: " << average_quick << " ms" << std::endl;
	std::cout << "Odchylenie standardowe: " << standard_deviation_quick << std::endl;

	return 0;
}
