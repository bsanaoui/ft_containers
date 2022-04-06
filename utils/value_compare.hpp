#ifndef  __VALUE_COMPARE__
#define  __VALUE_COMPARE__

#include "../map.hpp"

namespace ft
{
    template <class value_type, class Compare>
    class value_compare : public std::binary_function<value_type, value_type, bool>
    {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
        friend class ft::map;
        protected:
            Compare comp;
            value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object

        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator() (const value_type& x, const value_type& y) const
            {
                return comp(x.first, y.first);
            }

    }; //class template value_compare
} // namespace ft

#endif