#include <vector>
#include "vector.hpp"


int main()
{
   {
      std::cout <<"-------------------------my--------------------------"<<std::endl;
        ft::vector<int> foo(5, 100);   // three ints with a value of 100
        ft::vector<int> bar(3, 200);   // five ints with a value of 200
        ft::vector<int>::iterator it_b(foo.begin());
        ft::vector<int>::iterator it_b1(bar.begin());

        std::cout << *it_b << std::endl;
        std::cout << *it_b1 << std::endl;
        foo.swap(bar);
        std::cout << *it_b << std::endl;
        std::cout << *it_b1 << std::endl;
        std::cout << "foo contains:";
        for (unsigned i=0; i<foo.size(); i++)
          std::cout << ' ' << foo[i];
        std::cout << '\n';

        std::cout << "bar contains:";
        for (unsigned i=0; i<bar.size(); i++)
          std::cout << ' ' << bar[i];
        std::cout << '\n';
        std::cout << "foo | size = " << foo.size() << ", capacity" << foo.capacity() << std::endl;
        std::cout << "bar | size = " << bar.size() << ", capacity" << bar.capacity() << std::endl;

    }
    std::cout << "-------------------------std--------------------------"<<std::endl;
    {
        std::vector<int> foo(5, 100);   // three ints with a value of 100
        std::vector<int> bar(3, 200);   // five ints with a value of 200
        std::vector<int>::iterator it_b(foo.begin());
        std::vector<int>::iterator it_b1(bar.begin());

        std::cout << *it_b << std::endl;
        std::cout << *it_b1 << std::endl;
        foo.swap(bar);
        std::cout << *it_b << std::endl;
        std::cout << *it_b1 << std::endl;
        std::cout << "foo contains:";
        for (unsigned i=0; i<foo.size(); i++)
          std::cout << ' ' << foo[i];
        std::cout << '\n';

        std::cout << "bar contains:";
        for (unsigned i=0; i<bar.size(); i++)
          std::cout << ' ' << bar[i];
        std::cout << '\n';
         std::cout << "foo | size = " << foo.size() << ", capacity" << foo.capacity() << std::endl;
        std::cout << "bar | size = " << bar.size() << ", capacity" << bar.capacity() << std::endl;
    }
    return (0);                          
}