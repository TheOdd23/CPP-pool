#include "Array.hpp"

int main(void)
{
    Array<int> num(6);
    Array<std::string> str(2);
    str[0] = "Salut";
    str[1] = "mon ami";
    Array<std::string> str2(str);
    int *a = new int(9);
    unsigned int i;

    for (i = 0; i < 9; i++)
    {
        a[i] = rand();
    }
    for (i = 0; i < num.size(); i++)
    {
        num[i] = rand();
    }
    try
    {
        num[21] = a[1];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    num[1] = a[4];
    std::cout <<std::endl;
    
    std::cout << "a[4]: " << a[4] << " num[1]: " << num[1] << std::endl;
    if (num[1] == a[4])
        std::cout << "num[1] et a[4] sont égaux" << std::endl;
    std::cout <<std::endl;
    
    std::cout << "a[4]: " << a[4] << " num[2]: " << num[2] << std::endl;
    if (num[2] == a[4])
        std::cout << "num[2] et a[4] sont égaux" << std::endl;
    else
        std::cout << "num[2] et a[4] ne sont pas égaux" << std::endl;
    std::cout <<std::endl;
    
    std::cout << "str[0]: " << str[0] << " str2[0]: " << str2[0] << std::endl;
    str[0] = "Bye bye";
    str[1] = "et a la prochaine";
    std::cout << "str[0]: " << str[0] << " str2[0]: " << str2[0] << std::endl;
    a[0] = 42;
    str2[1] = a[0];
    std::cout <<std::endl;
    
    std::cout << "str2[1]: " << str2[1] << " a[0]: " << a[0] << std::endl;
    std::cout <<std::endl;
    
    std::cout << "size de num:" << num.size() << std::endl;
    std::cout <<std::endl;
    
    for (i = 0; i < num.size(); i++)
        std::cout << "num[" << i << "] " << num[i] << std::endl;
    delete a;
}

/* #include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
 */
