#include <iostream>

int main()
{
	int n, m, suma;

	std::cin >> n;

	for(int i = 0; i < n; i++)
	{
		std::cin >> m;
		
		suma = 0;

		int *tab = new int[m];

		for(int j = 0; j < m; j++)
			std::cin >> tab[j];

		for(int j = 0; j < m; j++)
			suma += tab[j];

		std::cout << suma << std::endl;

		delete [] tab;
	}
}
