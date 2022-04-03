#ifndef  __SWAP_HPP__
#define  __SWAP_HPP__

namespace ft
{
   template <class T>
   void swap ( T& a, T& b )
    {
        T c(a); a=b; b=c;
    }
} // namespace ft

#endif