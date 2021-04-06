#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void count_lines(const std::string& fname)
{
	std::ifstream ofs{ fname };
	if (!ofs.is_open())
	{
		std::cerr << "Couldn't open a file \'" << fname << "\'" << std::endl;
		return;
	}

	size_t count = 0;
	for (std::string line; std::getline(ofs, line); ++count);
	std::cout << "File \'" << fname << "\' has " << count << " lines" << std::endl;
}

int main()
{
	std::vector<std::string> files;
	for (std::string line; std::getline(std::cin, line);)
	{
		files.push_back(line);
	}

	for (size_t i = 0; i < files.size(); ++i)
	{
		count_lines(files[i]);
	}

	return 0;
}
