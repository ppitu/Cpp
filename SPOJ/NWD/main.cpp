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
	int n, a, b;

	std::cin >> n;

	for(int i = 0; i < n; i++)
	{
		std::cin >> a >> b;

		std::cout << NWD(a, b) << std::endl;
	}

}
