#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std::chrono;

void swap(int &x, int &y)
{
	int z = x;
	x = y;
	y = z;
}

void sortowaniePrzezWstawianie(int tab[], int ileelementow)
{
	int j, elem;

	for(size_t i = 1; i < ileelementow; i++)
	{
		elem = tab[i];
		j = i - 1;
		
		while((j > 0) && (tab[j] > elem))
		{
			tab[j + 1] = tab[j];
			j = j - 1;
		}
		tab[j + 1] = elem;
	}
}

void wypelnijTablice(int tab[], int ileelementow)
{
	for(size_t i = 0; i < ileelementow; i++)
	{
		tab[i] = rand();
	}
}

void wypisz(int tab[], int ileelementow)
{
	for(size_t i = 0; i < ileelementow; i++)
		std::cout << tab[i] << " ";
	std::cout << std::endl;
}

int main()
{
	srand(time(NULL));

	int ileelementow;

	std::cout << "Ile elementow: " << std::endl;
	std::cin >> ileelementow;

	int * tab = new int[ileelementow];

	wypelnijTablice(tab, ileelementow);
	
	//wypisz(tab, ileelementow);

	auto start = high_resolution_clock::now();

	sortowaniePrzezWstawianie(tab, ileelementow);
	
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	
	std::cout << "Czas trwania sortowania to: " << duration.count() << " mikrosenund" << std::endl;
	std::cout << "Czas w sekundach: " << (duration.count()/1000000) << std::endl;

	//wypisz(tab, ileelementow);

	delete [] tab;
}
