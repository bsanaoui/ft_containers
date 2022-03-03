#include "vector.hpp"
#include <vector>

int main(){
    {
        ft::vector<int>v1;

        for (size_t i = 0; i < 1000000; i++)
            v1.push_back(i);
        
        ft::vector<int>::iterator it = v1.begin();
         v1.erase(it , it + 1000000);
        for (size_t i = 0; i < v1.size(); i++)
        {
            std::cout << v1[i] << std::endl;
        }
        std::cout << "capacity " <<v1.capacity() << std::endl;
    }
    std::cout << "------"<<std::endl;
    {
        std::vector<int>v1;
        for (size_t i = 0; i < 1000000; i++)
            v1.push_back(i);
        std::vector<int>::iterator it = v1.begin();
        v1.erase(it , it + 1000000);
        for (size_t i = 0; i < v1.size(); i++)
        {
            std::cout << v1[i] << std::endl;
        }
         std::cout << "capacity " <<v1.capacity() << std::endl;
    }
    return 0;
}
