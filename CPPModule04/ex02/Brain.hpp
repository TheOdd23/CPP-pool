#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#pragma once

class Brain
{
public:
    Brain();
    Brain( Brain const &src );
    ~Brain();
    Brain &operator=( Brain const &src );

    const std::string get_ideas(int i) const;
    void set_ideas(std::string idea, int i);
protected:
    std::string ideas[100];
};

#endif