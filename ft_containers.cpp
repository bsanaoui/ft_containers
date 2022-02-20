#include <vector>
#include "vector.hpp"


int main()
{
    std::cout << "\n<----------< My ft::Vector >----------->\n" << std::endl;
    {
        std::vector<int> v1;
        std::vector<int>::iterator it = v1.begin();


        ft::vector<int> v(it, it);
    }

    std::cout << "\n<----------< Original STD::Vector >----------->\n" << std::endl;
    {

    }

    std::cout << "\n<----------< My ft::Tests >----------->\n" << std::endl;
    {
        int *ptr = new int[3];
        ptr[0] = 1;
        ptr[1] = 2;
        ptr[2] = 3;
        
        ft::VectorIterator<int> it(ptr);
  
        // it = ptr2;
        std::cout << *it << std::endl;

        std::cout << "\n// ************** < Reverse Iteraror > ************ //\n" << std::endl;
        ft::reverse_iterator< ft::VectorIterator<int> > rev_it(it);
        // rev_it -= 1;
        std::cout << rev_it[2] << std::endl;
        // if (rev_it == rev_it)
        //     std::cout << rev_it[-1] << std::endl;
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