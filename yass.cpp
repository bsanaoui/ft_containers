#include "vector.hpp"
#include <vector>

int main(){
    {
        ft::vector<int>v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        ft::vector<int>::iterator it = v1.begin();
        v1.insert(it , it-100, it-5);
        for (size_t i = 0; i < v1.size(); i++)
        {
            std::cout << v1[i] << std::endl;
        }
        std::cout << "capacity " <<v1.capacity() << std::endl;
    }
    std::cout << "------"<<std::endl;
    // {
    //     std::vector<int>v1;
    //     v1.push_back(1);
    //     v1.push_back(2);
    //     v1.push_back(3);
    //     v1.push_back(4);
    //     v1.push_back(5);
    //     std::vector<int>::iterator it = v1.begin();
    //      v1.insert(it , it-100, it-5);
    //     for (size_t i = 0; i < v1.size(); i++)
    //     {
    //         std::cout << v1[i] << std::endl;
    //     }
    //      std::cout << "capacity " <<v1.capacity() << std::endl;
    // }
    return 0;
}
