#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int	is_alpha( std::string str )
{
	size_t	i = 0;

	while (i < str.length())
	{
		if (isalpha(str[i]) || str[i] == '-')
			i++;
		else
			return 0;
	}
	return 1;
}

int	is_numeric( std::string str )
{
	size_t	i = 0;
	while (i < str.length())
	{
		if (isdigit(str[i]))
			i++;
		else
			return 0;
	}
	return 1;
}

std::string	truncate_infos( std::string str )
{
	std::string	new_str;
	if (str.length() > 10)
	{
		new_str = str.substr(0, 9);
		new_str += ".";
	}
	else
		return str;
	return new_str;
}

void	addContact( Contact *contact )
{
	std::string	info;
	name:
	std::cout << "First name?: ";
	getline(std::cin, info);
	if (std::cin.eof())
		return ;
	if (is_alpha(info) == 0)
	{
		std::cout << "All characters must be alpha" << std::endl;
		goto name;
	}
	if (info.length() < 1)
	{
		std::cout << "All fields must be filled, try again" << std::endl;
		goto name;
	}
	contact->firstname(info);
	lastname:
	std::cout << "Last name?: ";
	getline(std::cin, info);
	if (std::cin.eof())
		return ;
	if (is_alpha(info) == 0)
	{
		std::cout << "All characters must be alpha" << std::endl;
		goto lastname;
	}
	if (info.length() < 1)
	{
		std::cout << "All fields must be filled, try again" << std::endl;
		goto lastname;
	}
	contact->lastname(info);
	nickname:
	std::cout << "Nickname?: ";
	getline(std::cin, info);
	if (std::cin.eof())
		return ;
	if (info.length() < 1)
	{
		std::cout << "All fields must be filled, try again" << std::endl;
		goto nickname;
	}
	contact->nickname(info);
	number:
	std::cout << "Phone number?: ";
	getline(std::cin, info);
	if (std::cin.eof())
		return ;
	if (is_numeric(info) == 0)
	{
		std::cout << "Phone number must be all digits" << std::endl;
		goto number;
	}
	if (info.length() < 1)
	{
		std::cout << "All fields must be filled, try again" << std::endl;
		goto number;
	}
	contact->phonenumber(info);
	secret:
	std::cout << "Darkest secret?: ";
	getline(std::cin, info);
	if (std::cin.eof())
		return ;
	if (info.length() < 1)
	{
		std::cout << "All fields must be filled, try again" << std::endl;
		goto secret;
	}
	contact->secret(info);
}

void	print_infos( Contact contacts )
{
	std::cout << contacts.get_firstname() << std::endl;
	std::cout << contacts.get_name() << std::endl;
	std::cout << contacts.get_nickname() << std::endl;
	std::cout << contacts.get_phonenumber() << std::endl;
	std::cout << contacts.get_secret() << std::endl;
}

void	searchContact( PhoneBook repertoire, int nb_contacts )
{
	Contact	*contact;
	int	i = 0, index = i + 1;
	std::string	contact_index;
	std::string	infos[5];
	std::string	cmd;
	std::cout << "*-------------------------------------------*" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|" << "First Name" << "|" << std::setw(10) << "Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "*-------------------------------------------*" << std::endl;
	while (i < nb_contacts)
	{
		contact = repertoire.getContact(i);
		infos[0] = index + '0';
		infos[1] = truncate_infos(contact->get_firstname());
		infos[2] = truncate_infos(contact->get_name());
		infos[3] = truncate_infos(contact->get_nickname());
		std::cout << "|" << std::setw(10) << infos[0] << "|" << std::setw(10) << infos[1] << "|" << std::setw(10) << infos[2] << "|" << std::setw(10) << infos[3] << "|" << std::endl;
		std::cout << "*-------------------------------------------*" << std::endl;
		i++;
		index++;
	}
	std::cout << "Enter the contact's index to get his infos" << std::endl;
	back:
	getline(std::cin, cmd);
	if (std::cin.eof())
		return ;
	if (!isdigit(cmd[0]) || cmd.length() != 1)
	{
		std::cout << "Entry must be a digit between 1 and 8" << std::endl;
		goto back;
	}
	index = stoi(cmd);
	if (index > 8 || index < 1 || index > nb_contacts)
	{
		std::cout << "This contact doesn't exist, please try again" << std::endl;
		goto back;
	}
	contact = repertoire.getContact(index - 1);
	print_infos( *contact );
}

int	main()
{
	PhoneBook	repertoire;
	std::string	input;
	int	i = 0;
	int	nb_contacts = 0;
	while (!std::cin.eof())
	{
		std::cout << "What do you want to do?: " << std::endl;
		std::cout << "*---------------------*" << std::endl;
		std::cout << "| ADD | SEARCH | EXIT |" << std::endl;
		std::cout << "*---------------------*" << std::endl;
		getline(std::cin, input);
		if (std::cin.eof())
			return 0;
		if (input == "ADD")
		{
			addContact(repertoire.getContact(i));
			i++;
			if (nb_contacts != 8)
				nb_contacts++;
			if (i == 8)
				i = 0;
		}
		else if (input == "SEARCH")
			searchContact( repertoire, nb_contacts );
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Not a valid action, please try again" << std::endl;
	}
}