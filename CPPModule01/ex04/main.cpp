#include <iostream>
#include <fstream>
#include <string>

std::string	destroy_and_replace( size_t pos, std::string text,
	std::string S1, std::string S2 ){
	size_t	len;

	len = S1.length();
	text.erase(pos, len);
	text.insert(pos, S2);
	while (text.find(S1) != std::string::npos)
	{
		pos = text.find(S1);
		len = S1.length();
		text.erase(pos, len);
		text.insert(pos, S2);
	}
	return text;
}

int	main( int ac, char **av )
{
	if (ac != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 0;
	}
	std::string		name = av[1];
	std::ifstream	file;
	file.open(av[1]);
	if (!file)
	{
		std::cerr << "Error: file could not open" << std::endl;
		return 0;
	}
	std::ofstream	new_file(name + ".replace");
	std::string		S1;
	std::string		S2;
	std::string		text;
	std::size_t		pos;

	S1 = av[2];
	S2 = av[3];
	std::getline(file, text);
	while (!file.eof())
	{
		pos = text.find(S1);
		if (pos != std::string::npos)
			new_file << destroy_and_replace(pos, text, S1, S2);
		else
			new_file << text;
		new_file << std::endl;
		std::getline(file, text);
	}
	file.close();
	new_file.close();
	return 0;
}