#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#pragma once
#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdio>
#include <exception>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string db2);
		~BitcoinExchange();
		
		void	do_op();
	private:
		std::string	datab1_file;
		std::string	datab2_file;
		std::list<std::pair<std::string, std::string> >	data1;
		std::list<std::pair<std::string, std::string> >	data2;
		std::ifstream	datab1;
		std::ifstream	datab2;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		
		bool				file_check_error();
		bool				date_check_error(std::string date);
		bool				isValidDate(int year, int month, int day);
		bool				isLeapYear(int year);
		bool				value_check_error(std::string value);
		void				split_n_create(std::string str, std::list<std::pair<std::string, std::string> > *dbase, char del, bool no_space);
		bool				Container_init();
};

#endif
