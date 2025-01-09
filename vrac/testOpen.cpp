#include <iostream>
#include <fstream>
int main()
{
	std::ifstream file;

	file.open("todo", std::ifstream::in);
//	file.open("todo", std::ios::binary | std::ios::ate);
	if (!file.is_open())
	{
		std::cout << "failed to open file" << std::endl;
		return 1;
	}
	char buffer[4096];
	while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0)
		std::cout << buffer << std::endl;
//		std::cout.write(buffer, file.gcount());
	file.close();
	return 0;
}
