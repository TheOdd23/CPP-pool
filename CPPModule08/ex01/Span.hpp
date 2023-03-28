#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cstdlib>

class Span{
	public:
		Span();
		Span(const unsigned int N);
		Span(const Span& src);
		~Span();
		Span &operator=(const Span& src);
		
		void				addNumber(const int nb);
		void				numGenerator(unsigned int to_add);
		int					shortestSpan();
		int					longestSpan();
		const unsigned int	&getSize() const;
		
		class Empty: public std::exception{
			public:
					virtual const char* what() const throw(){
						return "No numbers stocked";
					}
			};
		class Full: public std::exception{
			public:
					virtual const char* what() const throw(){
						return "Not enough space to stock numbers";
					}
			};
		class NoSpan: public std::exception{
			public:
					virtual const char* what() const throw(){
						return "No span can be found, the span is 0";
					}
			};
		class OneVar: public std::exception{
			public:
					virtual const char* what() const throw(){
						return "No span can be found, because there's only one number";
					}
			};
	private:
		unsigned int size;
		std::vector<int> vec;
};

#endif