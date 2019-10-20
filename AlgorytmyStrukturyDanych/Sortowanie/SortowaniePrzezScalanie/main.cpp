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

void sortowanie(int tab[], int pocz, int sr, int koniec, int ile)
{
	int * tabpom = new int[ile];

	int i, j, q;

	for(i = 0;  i <= koniec; i++)
		tabpom[i] = tab[i];

	i = pocz;
	j = sr + 1;
	q = pocz;

	while(i <= sr && j <= koniec)
	{
		if(tabpom[i] < tabpom[j])
			tab[q++] = tabpom[i++];
		else
			tab[q++] = tabpom[j++];
	}

	while(i <= sr)
		tab[q++] = tabpom[i++];

	delete [] tabpom;
}

void sortowaniePrzezScalanie(int tab[], int pocz, int koniec, int ile)
{
	int sr;

	if(pocz < koniec)
	{
		sr = ((pocz + koniec)/2);
		sortowaniePrzezScalanie(tab, pocz, sr, ile);
		sortowaniePrzezScalanie(tab, sr + 1, koniec, ile);
		sortowanie(tab, pocz, sr, koniec, ile);
	}
}

void wypelnijTablice(int tab[], int ileelementow)
{
	for(size_t i = 0; i < ileelementow; i++)
		tab[i] = rand();
}

int main()
{
	srand(time(NULL));

	int ileelementow;

	std::cout << "Podaj ile elementow posortowac: " << std::endl;
	std::cin >> ileelementow;

	int * tab = new int[ileelementow];

	wypelnijTablice(tab, ileelementow);
	
	//for(size_t i = 0 ; i < ileelementow; i++)
	//	std::cout << tab[i] << " ";
	//std::cout << std::endl;

	auto start = high_resolution_clock::now();

	sortowaniePrzezScalanie(tab, 0, ileelementow - 1, ileelementow);

	auto stop = high_resolution_clock::now();

	//for(size_t i = 0; i < ileelementow; i++)
	//	std::cout << tab[i] << " ";
	//std::cout << std::endl;
	
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << "Czas trwania sortowania w microsekundach to: " << duration.count() << std::endl;
	std::cout << "Czas trewania w sekundach: " << duration.count()/1000000 << std::endl;

	delete [] tab;
}
