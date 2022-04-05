# ifndef __PAIR_HPP__
# define __PAIR_HPP__

// #include <iostream>
// -------------------------- Namespace "ft" -------------------------- //
namespace ft
{    
    // ****************************************** //
    // ********** Vector Class template ********* //
    // ****************************************** //
    template < class T1, class T2>   
    class pair
    {
        // ================================== //
        // ========= Member Types =========== //
        // ================================== //
        public:

        typedef T1  first_type;
        typedef T2  second_type;

        // ============================================== //
        // ============ Member  Attributs =============== //
        // ============================================== //

        first_type  first;
        second_type second;

        // ========================================================== //
        // ============= Constructors & Destructor ================== //
        // ========================================================== //
        public:

        pair() : first(), second() {}

		template<class U, class V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second){
		}

		pair (const first_type& a, const second_type& b){
			first = a;
			second = b;
		}

        // ============================================== //
        // ===============   Operators    =============== //
        // ============================================== //
		pair& operator= (const pair& pr){
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}

    }; // Class Template pair;

    // ================================================================== //
    // ===============   Non-member function overloads    =============== //
    // ================================================================== //
	template <class T1, class T2>
  	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		  return lhs.first==rhs.first && lhs.second==rhs.second;
	}

	template <class T1, class T2>
  	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		  return !(lhs==rhs);
	}

	template <class T1, class T2>
  	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
	  	return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	}

	template <class T1, class T2>
  	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
	  	return !(rhs<lhs);
	}

	template <class T1, class T2>
  	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
	  	return rhs<lhs;
	}

	template <class T1, class T2>
  	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
	  	return !(lhs<rhs);
	}

} // Namespace ft;

#endif