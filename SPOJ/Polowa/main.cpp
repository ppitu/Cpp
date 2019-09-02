#include <iostream>
#include <string>

int main()
{
	int n;
	std::string str, nstr;

	std::cin >> n;

	for(int i = 0; i < n; i++)
	{
		std::cin >> str;
		nstr = "";

		for(int j = 0; j < (str.length()/2); j++)
		{
			nstr += str.at(j);
		}

		std::cout << nstr << std::endl;

	}

	return 0;
}
