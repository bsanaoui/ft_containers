#include <vector>
#include "vector.hpp"


int main()
{
    std::cout << "\n<----------< My ft::Vector >----------->\n" << std::endl;
    {
        ft::vector<int> v1(10, 10);
        ft::vector<int> v2(v1);
        // v2 = v1;
        ft::vector<int>::iterator it = v2.begin();
        std::cout << *(it+1) << std::endl;
        std::cout << v1.max_size() << std::endl;
    }

    std::cout << "\n<--------< Original STD Tests >------->\n" << std::endl;
    {
        std::vector<int> v1(10,10);
        std::vector<int> v2(v1);
  
        // v1 = v2;
        std::cout << v2[0] << std::endl;
        std::cout << v2.max_size() << std::endl;
    }
    std::cout << "\n<------------< End Tests >------------>" << std::endl;

    return (0);                          
}