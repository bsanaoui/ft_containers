#include "utils/AvlTree.hpp"
#include "utils/pair.hpp"
#include "utils/MapIterator.hpp"
#include <map>
#include <vector>
#include "map.hpp"
#include "utils/pair.hpp"


int main()
{
    std::cout <<"\n------------------------- FT : ----------------------------\n"<<std::endl;
    {
        ft::pair<int, float> p1(1, 5.8);
        ft::pair<int, float> p2(2, 20.2);
        ft::pair<int, float> p3(3, 30.3);
        ft::pair<int, float> p4(4, 40.4);

        ft::map<int, float> map2;
        map2.insert(p2);
        map2.insert(p3);
        map2.insert(p4);

        std::cout << "<<  -------------- Reverse -------------- >>" << std::endl;
        ft::map<int, float>::reverse_iterator r_it = map2.rend();
        r_it--;
        std::cout << "Reverse Iterator = " <<(*r_it).first << std::endl;

        std::cout << "<< -------------- Element access -------- >>" << std::endl;
        map2[2] = 99.5;
        std::cout << "Map [2] " << map2[7] << std::endl;
        std::cout << "size() = " << map2.size() << std::endl;


        std::cout << "<< -------------- Modifiers:  ------------ >>" << std::endl;
        std::cout << "insert (1,5.8) " << map2.insert(p1).second << std::endl;
        std::cout << "insert (1,5.8) " << map2.insert(p1).second << std::endl;

        

    }

    std::cout << "\n------------------------- STD : ---------------------------\n"<<std::endl;
    {
        std::pair<int, float> p1(1, 5.8);
        std::pair<int, float> p2(2, 20.2);
        std::pair<int, float> p3(3, 30.3);
        std::pair<int, float> p4(4, 40.4);

        std::map<int, float> map2;
        map2.insert(p2);
        map2.insert(p3);
        map2.insert(p4);

        std::cout << "<<  -------------- Reverse -------------- >>" << std::endl;
        std::map<int, float>::reverse_iterator r_it = map2.rend();
        r_it--;
        std::cout << "Reverse Iterator = " <<(*r_it).first << std::endl;

        std::cout << "<< -------------- Element access -------- >>" << std::endl;
        map2[2] = 99.5;
        std::cout << "Map [2] = " << map2[7] << std::endl;
        std::cout << "size() = " << map2.size() << std::endl;

        std::cout << "<< -------------- Modifiers:  ------------ >>" << std::endl;
        std::cout << "insert (1,5.8) " << map2.insert(p1).second << std::endl;
        std::cout << "insert (1,5.8) " << map2.insert(p1).second << std::endl;



    

    }

    std::cout << "\n------------------------- END TESTs -----------------------\n"<<std::endl;
    return (0);                          
}