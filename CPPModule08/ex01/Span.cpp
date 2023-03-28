#include "Span.hpp"

Span::Span(): size(0), vec(0,0){
}

Span::Span(const unsigned int N): size(N), vec(0,0){
}

Span::Span(const Span& src): size(src.getSize()), vec(src.vec){
	*this = src;
}

Span::~Span(){
}

Span &Span::operator=(const Span &src) 
{
	if (&src != this)
	{
		this->size = src.getSize();
		this->vec = src.vec;
	}
	return *this;
}

const unsigned int	&Span::getSize() const{
	return this->size;
}

void Span::addNumber(const int nb) 
{
	if (vec.size() == this->size)
		throw Full();
	vec.push_back(nb); //adds new element to the end of vector
}

int Span::shortestSpan()
{
	std::sort(this->vec.begin(), this->vec.end());
	std::vector<int>::iterator v1 = vec.begin();
	std::vector<int>::iterator v2;
	int	SSpan = INT_MAX;

	if (!this->vec.size())
        throw Empty();
	else if (vec.size() == 1)
        throw OneVar();
	for(v2 = this->vec.begin() + 1; v2 != this->vec.end(); v2++){
		if (abs(*v1 - *v2) < SSpan)
			SSpan = abs(*v1 - *v2);
		v1++;
	}
	if (SSpan == 0)
		throw NoSpan();
	return SSpan;
}

int Span::longestSpan()
{
	std::sort(this->vec.begin(), this->vec.end());

	if (!this->vec.size())
        throw Empty();
	else if (this->vec.size() == 1)
        throw OneVar();
	if ((this->vec.back() - this->vec.front()) == 0)
		throw NoSpan();
	return this->vec.back() - this->vec.front();
}


void Span::numGenerator(unsigned int to_add) 
{
	if (this->vec.size() + to_add > this->size)
		throw Full();
	std::vector<int>temp(to_add);
	std::generate(temp.begin(), temp.end(), std::rand);
	this->vec.insert(this->vec.end(), temp.begin(), temp.end());
}
