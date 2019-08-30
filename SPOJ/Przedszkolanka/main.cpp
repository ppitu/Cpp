#include <iostream>

int NWD(int a, int b)
{
	int pom;

	while(b != 0)
	{
		pom = b;
		b = a%b;
		a = pom;
	}

	return a;
}

int main()
{

	int a, b, n;

	std::cin >> n;

	for(int i = 0; i < n; i++)
	{
		std::cin >> a >> b;

		std::cout << a/NWD(a, b) * b << std::endl;
	}

	return 0;
}
