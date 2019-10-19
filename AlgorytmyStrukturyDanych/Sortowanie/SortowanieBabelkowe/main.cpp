#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std::chrono;

void swap(int &x, int &y)
{
	int z = x;
	x = y;
	y = z;
}

void sortowanieBabelkowe(int tab[], int ileelementow)
{
	int n = ileelementow;

	do
	{
		for(size_t i = 0; i < n - 1; i++)
		{
			if(tab[i] > tab[i + 1])
				swap(tab[i], tab[i + 1]);
		}
		n--;
	}
	while(n > 1);
}

void wypelnijTablice(int tab[], int ileelementow)
{
	for(size_t i = 0; i < ileelementow; i++)
	{
		tab[i] = std::rand();
	}
}

int main()
{
	srand(time(NULL));

	int ileelementow;

	std::cout << "Podaj ile elementow" << std::endl;
	std::cin >> ileelementow;

	int * tab = new int[ileelementow];

	wypelnijTablice(tab, ileelementow);

	//Poczatek mierzenia czasu
	auto start = high_resolution_clock::now();

	sortowanieBabelkowe(tab, ileelementow);

	//Koniec mierzenia czasu
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << "Czas sortowania to: " << duration.count() << " mikrosekund." << std::endl;
	std::cout << "Czas w sekundach to: " << (duration.count() / 1000000) << std::endl;
	delete [] tab;
}
