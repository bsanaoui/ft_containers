#include <vector>
#include "vector.hpp"


int main()
{
    int index = 0;
    std::cout << "\n<----------< My ft::Vector >----------->\n" << std::endl;
    {
        ft::vector<int> v1;

        v1.push_back(5);
        v1.push_back(5);
        v1.push_back(5);
        v1.push_back(5);
        v1.push_back(5);
        // ft::vector<int> v2(v1);
        // // v2 = v1;
        // ft::vector<int>::iterator it_begin_1 = v1.begin();
        // ft::vector<int>::iterator it_end_1 = v1.end();

        // std::cout << "iterator [" << index << "] = "<< *(it_begin_1 + index) << std::endl;

        // ft::vector<int>::iterator it1 = v1.begin();
        // v1.resize(15, -5);
        // // v1.reserve(12);
        // v1.assign(it_begin_1, it_end_1);
        // v1.assign(50, 99);
        // v1.push_back(15);
        // v1.pop_back();
        // std::cout << "insert in [" << index << "] = "<< *(v1.insert(it1 + 500, 1000)) << std::endl;        std::cout << "size: "<< v1.size() << " | Capacity: " << v1.capacity() 
            // << " | element [" << index << "]= " << v1.at(index) <<std::endl;
        // std::cout << "iterator [" << index << "] = "<< *(it_begin_1 + index) << std::endl;
    }

    std::cout << "\n<--------< Original STD Tests >------->\n" << std::endl;
    {
        std::vector<int> v1;

        v1.push_back(5);
        v1.push_back(5);
        v1.push_back(5);
        v1.push_back(5);
        v1.push_back(5);
        
        // std::vector<int> v2(v1);
        // // v2 = v1;
        // std::vector<int>::iterator it_begin_1 = v1.begin();
        // std::vector<int>::iterator it_end_1 = v1.end();

        // std::cout << "iterator [" << index << "] = "<< *(it_begin_1 + index) << std::endl;

        // std::vector<int>::iterator it1 = v1.begin();
        // v1.resize(15, -5);
        // // v1.reserve(12);
        // v1.assign(it_begin_1, it_end_1);
        // v1.assign(50, 99);
        // v1.push_back(15);
        // v1.pop_back();
        // std::cout << "insert in [" << index << "] = "<< *(v1.insert(it1+500, 1000)) << std::endl;
        // std::cout << "size: "<< v1.size() << " | Capacity: " << v1.capacity() 
            // << " | element [" << index << "]= " << v1.at(index) <<std::endl;
        // std::cout << "iterator [" << index << "] = "<< *(it_begin_1 + index) << std::endl;

    }
    std::cout << "\n<------------< End Tests >------------>" << std::endl;
    // system("leaks Containers");
    return (0);                          
}