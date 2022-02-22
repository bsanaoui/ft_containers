#ifndef  __IS_INTEGRAL_HPP__
#define  __IS_INTEGRAL_HPP__

#include <utility>

namespace ft
{ 
    template <class T> struct is_integral;

    template <class T> struct is_integral : std::false_type { };
    template<> struct is_integral<bool> : std::true_type { };
    template<> struct is_integral<char> : std::true_type { };
    template<> struct is_integral<unsigned char> : std::true_type { };
    template<> struct is_integral<signed char> : std::true_type { };
  
    template<> struct is_integral<wchar_t> : std::true_type { };

    template<> struct is_integral<short> : std::true_type { };
    template<> struct is_integral<unsigned short> : std::true_type { };
    template<> struct is_integral<int> : std::true_type { };
    template<> struct is_integral<unsigned int> : std::true_type { };
    template<> struct is_integral<long> : std::true_type { };
    template<> struct is_integral<unsigned long> : std::true_type { };
    template<> struct is_integral<long long> : std::true_type { };
    template<> struct is_integral<unsigned long long> : std::true_type { };

} // namespace ft



#endif