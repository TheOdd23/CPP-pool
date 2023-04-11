#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Wrong number of arguments, please add one file to the arguments" << std::endl;
        return (1);
    }
    BitcoinExchange btc(av[1]);
    btc.do_op();
    return (0);
}