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
        ft::map<int, std::string> my_m;
            for (int i = 0; i < 1e6; ++i)
                my_m.insert(ft::make_pair(i, "fill constructor test"));
    }
    std::cout << "\n|-----------------------------------------------------------|"<<std::endl;
    std::cout << "|------------------------- STD : ---------------------------|"<<std::endl;
    std::cout << "|-----------------------------------------------------------|\n"<<std::endl;
    {
         std::map<int, std::string> m;
            for (int i = 0; i < 1e6; ++i)
                m.insert(std::make_pair(i, "fill constructor test"));
    }
    std::cout << "\n------------------------- END TESTs -----------------------\n"<<std::endl;
    return (0);                          
}