#ifndef  __STACK__HPP__
#define  __STACK__HPP__

#include <iostream>
#include "vector.hpp"

// -------------------------- Namespace "ft" -------------------------- //
namespace ft
{    
    // ****************************************** //
    // ********** stack Class template ********** //
    // ****************************************** //
    template <class T, class Container = ft::vector<T> > 
    class stack
    {
        // ================================== //
        // ========= Member Types =========== //
        // ================================== //
		public:
	
        typedef T           value_type;
        typedef Container   container_type;
		typedef	size_t		size_type;

		// ============================================== //
        // ========= Member Private Attributs =========== //
        // ============================================== //
        private:
		container_type _container;

		// ========================================================== //
        // ============= Constructors & Destructor ================== //
        // ========================================================== //
		public:
	
		explicit stack (const container_type& ctnr = container_type()) : _container(ctnr){}

		// ============================================== //
        // ===========   Member Functions    ============ //
        // ============================================== //
		bool empty() const{
			return (_container.empty());
		}

		size_type size() const{
			return (_container.size());
		}

		value_type& top(){
			return (_container.back());
		}

		const value_type& top() const{
			return (_container.back());
		}

		void push (const value_type& val){
			_container.push_back(val);
		}

		void pop(){
			_container.pop_back();
		}

    }; // clas tamplate stack

	// ================================================================== //
    // ===============   Non-member function overloads    =============== //
    // ================================================================== /|

	// ----------------- > Relational operators (stack)
	
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs == rhs);
	}
		
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs != rhs);
	}
		
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs < rhs);
	}
		
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs <= rhs);
	}
		
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs > rhs);
	}
		
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs >= rhs);
	}

} // namespace ft

#endif