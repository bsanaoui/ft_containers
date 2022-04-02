#include "utils/avl_tree.hpp"
#include "utils/pair.hpp"
#include "utils/MapIterator.hpp"
#include <map>
#include <vector>
#include "map.hpp"
#include "utils/pair.hpp"


int main()
{
    std::cout <<"------------------------- FT : ----------------------------"<<std::endl;
    {
        ft::pair<int, float> p1(1, 5.8);
        ft::pair<int, float> p2(2, 10);
        ft::pair<int, float> p3(3, 20);
        ft::pair<int, float> p4(4, 30);

        ft::AvlTree<int, float, std::less<int>, std::allocator<ft::pair<const int, float> > > tree;

        tree._root = tree.insertNode(tree._root, p1); // create node
        tree._root = tree.insertNode(tree._root, p2); // create node
        tree._root = tree.insertNode(tree._root, p3); // create node
        tree._root = tree.insertNode(tree._root, p4); // create node

        ft::MapIterator<int, float>  it(tree._root, tree._root);
        ft::MapIterator<int, float>  it2(tree._root, tree._root);
        std::cout << "Iterator 1 : " << (*it).first << std::endl;
        it2++;
        it2++;
        it2++;
        // it2++;

        ft::map<int, float> map1(it, it2);
        map1.display(1);
        std::cout << "Size = " <<  map1.size() << std::endl;

        ft::map<int, float> map2(map1);
        map2.display(2);
        std::cout << "Size = " <<  map2.size() << std::endl;


        ft::MapIterator<int, float>  it3 = map2.end();
        it3--;
        std::cout << "Iterator = " << (*it3).first << std::endl;

        std::cout << "//----------------- Reverse --------------------- //" << std::endl;
        ft::map<int, float>::reverse_iterator r_it = map2.rend();
        r_it--;
        std::cout << "Reverse Iterator = " <<(*r_it).first << std::endl;


    }

    std::cout << "------------------------- STD : ---------------------------"<<std::endl;
    {
        // std::pair<int, float> p1(1, 5.8);
        std::pair<int, float> p2(2, 10);
        std::pair<int, float> p3(3, 20);
        std::pair<int, float> p4(4, 40);

        std::map<int, float> map;
        // map.insert(p1);
        map.insert(p2);
        map.insert(p3);
        map.insert(p4);

        std::map<int, float>::reverse_iterator r_it = map.rend();
        r_it--;
        std::cout << "Reverse Iterator = " <<(*r_it).first << std::endl;
    }

    std::cout << "------------------------- END TESTs -----------------------"<<std::endl;
    return (0);                          
}