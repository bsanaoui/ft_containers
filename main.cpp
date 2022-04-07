#include "utils/AvlTree.hpp"
#include "utils/pair.hpp"
#include "utils/MapIterator.hpp"
#include <map>
#include <vector>
#include "map.hpp"
#include "utils/pair.hpp"

template <class T>
void    display(T first, T last, int i)
{
    std::cout << "<< ------ Display Map : " << i << " -------->>"<< std::endl;
    while (first != last)
    {
        std::cout << first->first << " => " << first->second << '\n';
        first++;
    }
}

int main()
{
    std::cout << "\n|-----------------------------------------------------------|"<<std::endl;
    std::cout << "|------------------------- FT : ----------------------------|"<<std::endl;
    std::cout << "|-----------------------------------------------------------|\n"<<std::endl;
    {

        std::map<int, std::string> m1;
        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m2;
        ft::map<int, std::string> ft_m1;
        for (int i = 0; i < 10; ++i)
        {
            m2.insert(std::make_pair(i, "string2"));
            ft_m2.insert(ft::make_pair(i, "string2"));
        }

        m1 = m2;
        ft_m1 = ft_m2;
        m2.begin()->second = "hello";
        ft_m2.begin()->second = "hello";
        ft_m2.erase(9);

        display(ft_m2.begin(), ft_m2.end(), 2);
        display(ft_m1.begin(), ft_m1.end(), 1);

        display(m2.begin(), m2.end(), 2);
        display(m1.begin(), m1.end(), 1);


    }
    std::cout << "\n|-----------------------------------------------------------|"<<std::endl;
    std::cout << "|------------------------- STD : ---------------------------|"<<std::endl;
    std::cout << "|-----------------------------------------------------------|\n"<<std::endl;
    {





    }
    std::cout << "\n------------------------- END TESTs -----------------------\n"<<std::endl;
    return (0);                          
}