#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

Contact *PhoneBook::getContact(int index){
	return &this->contacts[index];
}