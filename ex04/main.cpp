#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main(int ac, char **av)
{
	std::fstream	fs;
	int				pos;
	size_t			word_len;
	std::string		buffer;

	if (ac != 4 || !*av[2])
	{
		std::cout << "Error: arguments" << std::endl;
		return (1);
	}

	word_len = std::strlen(av[2]);
	fs.open(av[1], std::fstream::in | std::fstream::out);
	if (fs.fail())
		return (std::cout << "Error: file" << std::endl, 1);
    
    std::ofstream outfile((std::string(av[1]) + ".replace").c_str());
	if (outfile.fail())
		return (std::cout << "Error : failed to created new file" << std::endl, 1);
	
    while (std::getline(fs, buffer))
	{
		pos = 0;
		while (pos != (int)std::string::npos)
		{
			pos = buffer.find(av[2]);
			if (pos >= 0)
			{
				buffer.erase(pos, word_len);
				buffer.insert(pos, av[3]);
			}
		}
		outfile << buffer << std::endl;
		buffer.clear();
	}
	outfile.close();
	fs.close();
}

