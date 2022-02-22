#ifndef  __ENABLE_IF_HPP__
#define  __ENABLE_IF_HPP__

namespace ft
{
    template<bool B, typename T>
    struct enable_if {};

    template<typename T>
    struct enable_if<true, T> { typedef T type; };
} // namespace ft

#endif