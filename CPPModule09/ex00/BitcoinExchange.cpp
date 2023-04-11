#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string db2): datab1_file("data.csv"), datab2_file(db2), datab1("data.csv"), datab2(db2){}

BitcoinExchange::~BitcoinExchange()
{
	if (datab1.is_open())
		datab1.close();
	if (datab2.is_open())
		datab2.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	datab1_file = other.datab1_file;
	datab2_file = other.datab2_file;
	data1 = other.data1;
	data2 = other.data2;
	datab1.close(); 
	datab1.open(other.datab1_file);
	datab2.close(); 
	datab2.open(other.datab2_file);
	return *this;
}

bool	BitcoinExchange::file_check_error()
{
	if (datab1.is_open() == false || datab2.is_open() == false)
	{
		std::cerr << "Error: file non-existant or couldn't open it" << std::endl;
		return true;
	}
	return false;
}

bool BitcoinExchange::isLeapYear(int year)
{
    if (year % 4 != 0)
        return false;
	else if (year % 100 != 0)
        return true;
    else if (year % 400 != 0)
        return false;
    else
        return true;
}

bool BitcoinExchange::isValidDate(int year, int month, int day)
{
    if (month < 1 || month > 12 || day < 1)
        return false;
    else if (month == 2 && day > 29)
        return false;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    else if (day > 31)
        return false;
    else if (month == 2 && day == 29 && !isLeapYear(year))
        return false;
    else
        return true;
}

bool BitcoinExchange::date_check_error(std::string date)
{
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    bool isValid = isValidDate(year, month, day);
	if (!isValid)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return true;
	}
	return false;
}

bool BitcoinExchange::value_check_error(std::string value)
{
	bool Is_float = false;
	try
	{
		float temp = std::stof(value);
		if (temp < 0)
		{
			std::cerr << "Error: not a positive number" << std::endl;
			return true;
		}
		if (temp > 1000)
		{
			std::cerr << "Error: too large number" << std::endl;
			return true;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "=> " << "value not an integer or float" << std::endl;
		return true;
	}
	for (size_t i = 0; i < value.size(); i++)
	{
		if ((!isdigit(value[i]) && (value[i] != '.' && value[i] != ',')) || ((value[i] == '.' || value[i] ==',') && Is_float == true))
		{
			std::cerr << "Error: value not an integer or float" << std::endl;
			return true;
		}
		if (value[i] == '.' || value[i] == ',')
			Is_float = true;
	}
	return false;
}

void	BitcoinExchange::split_n_create(std::string str, std::list<std::pair<std::string, std::string> > *dbase, char del, bool no_space)
{
	std::string	val;
	std::string	date;
	size_t delimiter;
	
	delimiter = str.find(del);
	if (no_space == true)
	{
		date = str.substr(0, delimiter - 1);
		val = str.substr(delimiter + 2, str.size());
	}
	else
	{
		date = str.substr(0, delimiter);
		val = str.substr(delimiter + 1, str.size());
	}
	dbase->push_back(std::make_pair(date, val));
}

bool	BitcoinExchange::Container_init()
{
	std::string line;
	std::string	empty("Empty line");
	int	i = 0;

	if (file_check_error())
		return true;
	while(std::getline(datab1, line))
	{
			split_n_create(line, &data1, ',', false);
	}
	while(std::getline(datab2, line))
	{
		if (line == "date | value" && i == 0)
			continue;
		if (line.empty())
			split_n_create(empty, &data2, '|', true);
		else
			split_n_create(line, &data2, '|', true);
		i++;
	}
	return false;
}

void	BitcoinExchange::do_op()
{
	if (Container_init())
	{
		return ;
	}
	for(std::list<std::pair<std::string, std::string> >::iterator data_to_find = data2.begin(); data_to_find != data2.end(); data_to_find++)
	{
		if (date_check_error(data_to_find->first))
			continue;
		else if (value_check_error(data_to_find->second))
			continue;
		else
		{
			std::list<std::pair<std::string, std::string> > temp;
			for(std::list<std::pair<std::string, std::string> >::iterator find_data = data1.begin(); find_data != data1.end();)
			{
				//Set la date la plus proche de la date à chercher au cas où elle n'existe pas
				if (data_to_find->first > find_data->first)
				{
					if (!temp.empty())
					{
						if (temp.begin()->first < find_data->first)
						{
							temp.clear();
							temp.insert(temp.begin(), std::make_pair(find_data->first, find_data->second));
						}
					}
					else
					{
						temp.insert(temp.begin(), std::make_pair(find_data->first, find_data->second));
					}
				}
				//Si la date à trouver n'existe pas et qu'on atteint une date ultérieure
				if (find_data->first > data_to_find->first && !temp.empty())
				{
					find_data--;
					std::cout << data_to_find->first << " => " << data_to_find->second << " = " << std::fixed << std ::setprecision(2) << (std::stof(data_to_find->second) * std::stof(find_data->second)) << std::endl; 
					break ;
				}
				//Date à trouver existe
				else if(find_data->first == data_to_find->first)
				{
					std::cout << data_to_find->first << " => " << data_to_find->second << " = " << std::fixed << std ::setprecision(2) << (std::stof(data_to_find->second) * std::stof(find_data->second)) << std::endl; 
					break ;
				}
				find_data++;
				//Si la date n'existe pas
				if (find_data == data1.end())
				{
					//S'il n'y a pas de date ultérieure
					if (!temp.empty())
						std::cout << data_to_find->first << " => " << data_to_find->second << " = " << std::fixed << std ::setprecision(2) << (std::stof(data_to_find->second) * std::stof(temp.begin()->second)) << std::endl; 
					//S'il n'y a pas de date antérieure
					else
						std::cerr << "Date precedes bitcoins, cannot find value" << std::endl;
				}
			}
		}
	}
	
}
