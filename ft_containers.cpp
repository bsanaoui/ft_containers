#include <vector>
#include "utils/VectorIterator.hpp"
#include "vector.hpp"
#include "utils/reverse_iterator.hpp"

int main()
{
    std::cout << "\n<----------< My ft::Tests >----------->\n" << std::endl;
    {
        int *ptr = new int[5];
        int *ptr2 = new int[3];

        ptr[0] = 1;
        ptr[1] = 2;
        ptr[2] = 3;

        ptr2[0] = -1;
        ptr2[1] = -2;
        ptr2[2] = -3;
        
        ft::VectorIterator<int> it(ptr);
        ft::VectorIterator<int> it2(ptr2);
        
        // it = ptr2;

        std::cout << it2 - it << std::endl;
        std::cout << *it << std::endl;
    }
    std::cout << "\n<--------< Original STD Tests >------->\n" << std::endl;
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        std::vector<int>::iterator it = v.begin();


        std::vector<int> v2;
        v2.push_back(1);
        v2.push_back(2);
        v2.push_back(3);
        std::vector<int>::iterator it2 = v2.begin();


        std::cout << it2 - it << std::endl;
        std::cout << *it << std::endl;
    }
    std::cout << "\n<------------< End Tests >------------>" << std::endl;

    return (0);                          
}