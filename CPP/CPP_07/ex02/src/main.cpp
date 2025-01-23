#include <iostream>
#include <cstdlib>
#include <Array.hpp>

#define MAX_VAL 5
int main()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
	std::cout << "all good go !" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
		// valgrind error: unitialized value
		std::cout << "et avant ?" << std::endl;
		std::cout << "number [" << i << "] = " << numbers[i] << std::endl;
		std::cout << "mirror [" << i << "] = " << mirror[i] << std::endl;
	}
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
			std::cout << "test [" << i << "] = " << test[i] << std::endl;
			std::cout << "number [" << i << "] = " << numbers[i] << std::endl;
			test[i] *= 100;
			std::cout << "After multiplication:" << std::endl;
			std::cout << "test [" << i << "] = " << test[i] << std::endl;
			std::cout << "number [" << i << "] = " << numbers[i] << std::endl;
			std::cout << std::endl;
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
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Array<std::string> strings(MAX_VAL);
	std::string* mirrorS = new std::string[MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++)
    {
		std::cout << "strings [" << i << "] = " << strings[i] << std::endl;
		std::cout << "mirror [" << i << "] = " << mirrorS[i] << std::endl;
	}
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    delete [] mirrorS;//
    return 0;
}
