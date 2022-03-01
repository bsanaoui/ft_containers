#include <vector>
#include "vector.hpp"


int main()
{
    ft::vector<int>    my_v(3,4);
	ft::vector<int>::const_iterator my_it,my_it1, tmp;
	my_it = my_v.begin();
	my_it1 = my_v.begin() + 1;
    
    return (0);                          
}