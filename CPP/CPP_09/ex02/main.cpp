#include <cmath>
#include <iostream>

long	getJacobb(int n)
{
	return round((pow(2, n) - pow(-1, n)) /3);
}
int	main()
{
	for (size_t i = 0; i < 13; ++i)
		std::cout << getJacobb(i) << std::endl;
}
