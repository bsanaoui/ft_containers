# ifndef __MAKE_PAIR_HPP__
# define __MAKE_PAIR_HPP__

#include  "pair.hpp"
// -------------------------- Namespace "ft" -------------------------- //
namespace ft
{
    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
    return ( pair<T1,T2>(x,y) );
    }

} // Namespace ft;

#endif