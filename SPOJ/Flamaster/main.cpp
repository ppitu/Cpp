#include <iostream>
#include <string>

int main()
{
	int test;
	int licznik;
	std::string napis;

	std::cin >> test;

	for(std::size_t i = 0; i < test; i++)
	{
		napis = "";
		std::cin >> napis;
		licznik = 1;
		
		for(std::size_t j = 1; j <= napis.length(); j++)
		{
			if(napis[j] != napis[j-1])
			{
				if(licznik > 2)
					std::cout << napis[j - 1] << licznik;
				else if(licznik == 2)
					std::cout << napis[j - 1] << napis[j - 1];
				else 
					std::cout << napis[j - 1];
				licznik = 1;
			}
			else
				licznik++;
		}

		std::cout << std::endl;
			
	}

	return 0;
}
