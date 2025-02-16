#include <cctype>
#include <iostream>
#include <cstdlib>
#include <Array.hpp>
#include <sstream>

#define MAX_VAL 5
#define GREEN "\033[1;92m"
#define RED "\033[1;91m"
#define YELLOW "\033[1;93m"
#define BLUE "\033[1;94m"
#define RESET "\033[0;m"

int main()
{

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
		const int value = rand() / 100;
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		try
		{
			for (size_t i = 0; i < MAX_VAL; i++)
			{
				std::cout << GREEN << "test [" << i << "] = " << test[i] << "\n" << RESET;
				std::cout << YELLOW << "number [" << i << "] = " << numbers[i] << "\n";
				std::cout << "tmp [" << i << "] = " << tmp[i] << "\n" << RESET;
				test[i] *= 100;
				std::cout << BLUE << "After multiplication:" << "\n" << RESET;
				std::cout << GREEN << "test [" << i << "] = " << test[i] << "\n" << RESET;
				std::cout << YELLOW << "number [" << i << "] = " << numbers[i] << "\n";
				std::cout << "tmp [" << i << "] = " << tmp[i] << "\n" << RESET;
				std::cout << "\n";
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		std::cout << RED << "try number[-2] = 0\n" << RESET;
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	try
	{
		std::cout << RED << "\ntry number[MAX_VAL] = 0\n" << RESET;
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}

	Array<std::string> strings(MAX_VAL);
	std::string* mirrorS = new std::string[MAX_VAL];
	std::cout << BLUE << "\nDisplay both empty:" << "\n" << RESET;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << GREEN << "strings [" << i << "] = " << strings[i] << "\n" << RESET;
		std::cout << YELLOW << "mirror [" << i << "] = " << mirrorS[i] << "\n" << RESET;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::ostringstream oss;
		oss << "string no." << i + 1;
		mirrorS[i] = oss.str();
		strings[i] = oss.str();
	}
	std::cout << BLUE << "\nDisplay both filled:" << "\n" << RESET;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << GREEN << "strings [" << i << "] = " << strings[i] << "\n" << RESET;
		std::cout << YELLOW << "mirror [" << i << "] = " << mirrorS[i] << "\n" << RESET;
	}
	{
		std::cout << BLUE << "\nCopy and append different:\n" << RESET;
		Array<std::string>	tmp = strings;
		Array<std::string>	copy(tmp);
		for (int i = 0; i < MAX_VAL; i++)
		{
			copy[i].append(" but different", 14);
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << GREEN << "tmp [" << i << "] = " << tmp[i] << "\n" << RESET;
			std::cout << YELLOW << "copy [" << i << "] = " << copy[i] << "\n" << RESET;
		}
	}
	delete [] mirror;//
	delete [] mirrorS;//
	/*
	// !!! VALGRIND ERROR: unitialized value
	Array<int>	jump(1);
	int*		mjump = new int[1];
	std::cout << "jump = " << jump[0] << "\n";
	std::cout << "mjump = " << *mjump << "\n";
	delete [] mjump;
	*/
	return 0;
}
