#include <iostream>
#include <string>
#include <vector>

int main()
{
	int n;
	
	std::cin >> n;

	std::vector<std::string> niedowaga;
	std::vector<std::string> good;
	std::vector<std::string> nadwaga;

	std::string imie;
	int masa;
	double wzrost;
	double BMI;

	for(int i = 0; i < n; i++)
	{
		std::cin >> imie >> masa >> wzrost;
		
		wzrost = wzrost/100;

		BMI = masa/(wzrost*wzrost);

		if(BMI < 18.5)
			niedowaga.push_back(imie);
		else if (BMI < 25.0)
			good.push_back(imie);
		else
			nadwaga.push_back(imie);
	}	

	std::cout << "niedowaga" << std::endl;
	for(int i = 0; i < niedowaga.size(); i++)
	{
		std::cout << niedowaga.at(i) << std::endl;
	}
	std::cout << "waga prawidlowa" << std::endl;
	for(int i = 0; i < good.size(); i++)
	{
		std::cout <<good.at(i)  <<std::endl;
	}
	std::cout << "nadwaga" << std::endl;
	for(int i = 0; i < nadwaga.size(); i++)
	{
		std::cout <<nadwaga.at(i) << std::endl;
	}

	return 0;
}
