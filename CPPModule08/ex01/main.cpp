#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	Span sa(10000);
	Span sb;
	Span sc(1);
	Span sd(2);
	sp.addNumber(1);
	sp.addNumber(5);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(12);
	sc.addNumber(34767);
	sd.addNumber(3);
	sd.addNumber(3);
	Span se(sp);
	
    try
    {
		sa.numGenerator(10000);
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl;
	}
	try
    {
		sa.numGenerator(1);
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl;
	}
	try
    {
		std::cout << sa.longestSpan() << std::endl;
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl;
	}
	try
    {
		sb.longestSpan();
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl;
	}
	try
    {
		sc.shortestSpan();
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl;
	}
	try
    {
		sd.shortestSpan();
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl;
	}
	try
    {
		sd.longestSpan();
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << se.shortestSpan() << std::endl;
	std::cout << se.longestSpan() << std::endl;
return(0);
}
