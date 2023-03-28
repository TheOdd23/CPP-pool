#ifndef ARRAY_HPP
#define ARRAY_HPP

#pragma once
#include <iostream>

template <typename T> class Array
{
public:
     Array(): array(new T[0]), a_size(0){
    };

    Array(unsigned int n): array(new T[n]), a_size(n){
    };
    
    Array(Array const &src): array(new T[src.size()]), a_size(src.size()){
    unsigned int i;

    for(i = 0; i < src.size(); i++)
        this->array[i] = src.getElement(i);
    };

    ~Array(){
        delete[] this->array;
    };

    Array &operator=( Array const &src ){
        unsigned int i;

        delete[] this->array;
        this->array = new T[src.size()];
        this->a_size = src.size();
        for(i = 0; i < src.size(); i++)
            this->array[i] = src.getElement(i);
        return *this;
    }

    T &operator[](unsigned int index) const{
         if (index >= this->a_size || index < 0)
            throw (IndexOOB());
        return this->array[index];
    };

    unsigned int size() const{
        return this->a_size;
    }

    T getElement(unsigned int index) const{
        return this->array[index];
    }

    class IndexOOB : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "Array index is out of bound!";
        }
    };

private:
    T *array;
    unsigned int a_size;
};

#endif
