#include "utils/avl_tree.hpp"
#include "utils/pair.hpp"
#include "utils/MapIterator.hpp"
#include <map>


int main()
{
    std::cout <<"------------------------- FT : ----------------------------"<<std::endl;
    {
        ft::pair<int, float> p1(1, 5.8);
        ft::pair<int, float> p2(2, 10);
        ft::pair<int, float> p3(3, 20);

        ft::AvlTree<int, float> *tree = new ft::AvlTree<int, float>();

        tree->setRoot(tree->insertNode(tree->getRoot(), p1)); // create node
        tree->setRoot(tree->insertNode(tree->getRoot(), p2));
        tree->setRoot(tree->insertNode(tree->getRoot(), p3));

        // tree->setRoot(tree->deleteNode(tree->getRoot(), p1)); //delete node
        // tree->printTree(tree->getRoot(), "", true);
        
        ft::MapIterator<int, float> it(tree, tree);
        std::cout << "Iterator = " <<(*it++).first << std::endl;

        // std::cout << tree->getData()->first << std::endl;
        // while(1);
    }

    std::cout << "------------------------- STD : ---------------------------"<<std::endl;
    {
        std::pair<int, float> p1(1, 5.8);
        std::pair<int, float> p2(2, 10);
        std::pair<int, float> p3(3, 20);

        std::map<int, float> map;
        map.insert(p1);
        map.insert(p2);
        map.insert(p3);

        std::map<int, float>::iterator it = map.begin();
        std::cout << "Iterator = " <<(*it).first << std::endl;
    }

    std::cout << "------------------------- END TESTs -----------------------"<<std::endl;
    return (0);                          
}