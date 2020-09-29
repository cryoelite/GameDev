
#include<iostream>
#include<math.h>

int main()
{
	double pp{std::pow(10,-9)};
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout.setf(std::ios::showbase);
	std::cout <<22 << std::endl;
	std::cout.unsetf(std::ios::showbase);
	std::cout << 22 << std::endl;
	return 0;
}