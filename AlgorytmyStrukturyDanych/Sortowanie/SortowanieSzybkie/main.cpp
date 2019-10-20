#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std::chrono;

int dzielenie(int tab[], int p, int r)
{
	int x = tab[p];
	
	int i = p;
	int j = r;
	int w;

	while(1)
	{
		while(tab[j] > x)
			j--;
		while(tab[i] < x)
			i++;
		
		if(i < j)
		{
			w = tab[i];
			tab[i] = tab[j];
			tab[j] = w;
			i++;
			j--;
		}
		else
			return j;
	}
}

void sortowanieSzybkie(int tab[], int p, int r)
{
	int q;
	
	if(p < r)
	{
		q = dzielenie(tab, p, r);
		sortowanieSzybkie(tab, p, q);
		sortowanieSzybkie(tab, q+1, r);
	}
}

void wypelnijTablice(int tab[], int ile)
{
	for(size_t i = 0; i < ile; i++)
	{	
		tab[i] = rand();
	}	
}

int main()
{
	srand(time(NULL));

	int ileelementow;

	std::cout << "Podaj liczbe elementow:" << std::endl;
	std::cin >> ileelementow;

	int * tab = new int[ileelementow];

	wypelnijTablice(tab, ileelementow);

	//for(size_t i = 0; i < ileelementow; i++)
	//	std::cout << tab[i] << " ";
	//std::cout << std::endl;

	auto start = high_resolution_clock::now();

	sortowanieSzybkie(tab, 0, ileelementow - 1);

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << "Czas trwania programu w mikrosekundach: " << duration.count() << std::endl;

	std::cout << "Czas trwania programu w sekundach: " << duration.count()/1000000  << std::endl;
	//for(size_t i = 0; i < ileelementow; i++)
	//	std::cout << tab[i] << " ";
	//std::cout << std::endl;

}
