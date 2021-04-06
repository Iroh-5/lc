#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> arguments(int argc, char** argv)
{
	std::vector<std::string> res;
	for (int i = 0; i < argc; ++i)
	{
		res.push_back(argv[i]);
	}

	return res;
}

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

int main(int argc, char** argv)
{
	std::vector<std::string> files;

	if (argc > 1)
	{
		files = arguments(argc, argv);
	}
	else
	{
		for (std::string line; std::getline(std::cin, line);)
		{
			files.push_back(line);
		}
	}

	if (files[0] != std::string(argv[0]))
	{
		count_lines(files[0]);
	}

	for (size_t i = 1; i < files.size(); ++i)
	{
		count_lines(files[i]);
	}

	return 0;
}
