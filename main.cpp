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
        // ft::pair<int, float> p1(1, 5.8);
        // ft::pair<int, float> p2(2, 20.2);
        // ft::pair<int, float> p3(3, 30.3);
        // ft::pair<int, float> p4(4, 40.4);

        // ft::map<int, float> map2;
        // map2.insert(p2);
        // map2.insert(p3);
        // map2.insert(p4);

        // std::cout << "  <<  ------------ Reverse : -------------- >>\n" << std::endl;
        // ft::map<int, float>::reverse_iterator r_it = map2.rend();
        // r_it--;
        // std::cout << "Reverse Iterator = " <<(*r_it).first << std::endl;

        // std::cout << "  << ------------ Element access : -------- >>\n" << std::endl;
        // map2[2] = 99.5;
        // std::cout << "Map [2] " << map2[7] << std::endl;
        // std::cout << "size() = " << map2.size() << std::endl;


        // std::cout << "  << -------------- Insert : -------------- >>\n" << std::endl;
        // std::cout << "insert (1,5.8) " << map2.insert(p1).second << std::endl;
        // std::cout << "insert (1,5.8) " << map2.insert(p1).second << std::endl;

        // ft::map<int, float> map3;
        // map3.insert(map2.begin(), map2.end());
        // map3.insert(map2.begin()++, map2.end());
        // display(map3.begin(), map3.end(), 3);

        std::cout << "  << ----------------- Erase : ------------ >>" << std::endl;
        // ft::map<char,int> mymap;

        // // insert some values:
        // mymap['a']=10;
        // mymap['b']=20;
        // mymap['c']=30;
        // mymap['d']=40;
        // mymap['e']=50;
        // mymap['f']=60;

        // ft::map<char, int>::iterator it = mymap.end();
        // mymap.erase ( ++mymap.begin(), --it);    // erasing by range
       
        // //show content:
        // display(mymap.begin(), mymap.end(), 1);

        std::cout << "  << ----------------- Other : ------------ >>" << std::endl;

        


    }
    std::cout << "\n|-----------------------------------------------------------|"<<std::endl;
    std::cout << "|------------------------- STD : ---------------------------|"<<std::endl;
    std::cout << "|-----------------------------------------------------------|\n"<<std::endl;

    {
        // std::pair<int, float> p1(1, 5.8);
        // std::pair<int, float> p2(2, 20.2);
        // std::pair<int, float> p3(3, 30.3);
        // std::pair<int, float> p4(4, 40.4);

        // std::map<int, float> map2;
        // map2.insert(p2);
        // map2.insert(p3);
        // map2.insert(p4);

        // std::cout << "  <<  ------------ Reverse : -------------- >>\n" << std::endl;
        // std::map<int, float>::reverse_iterator r_it = map2.rend();
        // r_it--;
        // std::cout << "Reverse Iterator = " <<(*r_it).first << std::endl;

        // std::cout << "  << ------------ Element access : -------- >>\n" << std::endl;
        // map2[2] = 99.5;
        // std::cout << "Map [2] = " << map2[7] << std::endl;
        // std::cout << "size() = " << map2.size() << std::endl;

        // std::cout << "  << -------------- Insert : -------------- >>\n" << std::endl;
        // std::cout << "insert (1,5.8) " << map2.insert(p1).second << std::endl;
        // std::cout << "insert (1,5.8) " << map2.insert(p1).second << std::endl;

        // std::map<int, float> map3;
        // map3.insert(map2.begin(), map2.end());
        // map3.insert(map2.begin()++, map2.end());
        // display(map3.begin(), map3.end(), 3);

        // std::cout << "  << ----------------- Erase : ------------ >>" << std::endl;

        // std::map<char,int> mymap;

        // // insert some values:
        // mymap['a']=10;
        // mymap['b']=20;
        // mymap['c']=30;
        // mymap['d']=40;
        // mymap['e']=50;
        // mymap['f']=60;

        // std::map<char, int>::iterator it = mymap.end();
        // mymap.erase ( ++mymap.begin(), --it);    // erasing by range
   
        // //show content:
        // display(mymap.begin(), mymap.end(), 1);
        std::cout << "  << ----------------- Other : ------------ >>" << std::endl;



    }
    std::cout << "\n------------------------- END TESTs -----------------------\n"<<std::endl;
    return (0);                          
}