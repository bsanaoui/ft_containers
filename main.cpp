#include <vector>
#include <map>
#include <stack>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"

template <class T>
void    display(T first, T last, int i)
{
    std::cout << "<< ------ Display Map : " << i << " -------->>"<< std::endl;
    while (first != last)
    {
        std::cout << first->first << " => " << first->second << '\n';
        first++;
    }
}

int main()
{
	std::cout << "\n<============================================================================>\n";
	std::cout << "<============================== Vector Tests ================================>\n";
	std::cout << "<============================================================================>\n" << std::endl;
	{
		{
			std::cout <<"------------------------- FT swap, capacity, operator dereference  : --------------------------"<<std::endl;
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
		std::cout << "------------------------- STD swap, capacity, operator dereference  : --------------------------"<<std::endl;
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
		std::cout <<"------------------------- FT assign, begin, end, size : --------------------------"<<std::endl;
		{
			ft::vector<int> first;
			ft::vector<int> second;
			ft::vector<int> third;

			first.assign (7,100);             // 7 ints with a value of 100

			ft::vector<int>::iterator it;
			it=first.begin()+1;

			second.assign (it,first.end()-1); // the 5 central values of first

			int myints[] = {1776,7,4};
			third.assign (myints,myints+3);   // assigning from array.

			std::cout << "Size of first: " << int (first.size()) << '\n';
			std::cout << "Size of second: " << int (second.size()) << '\n';
			std::cout << "Size of third: " << int (third.size()) << '\n';
		}
		std::cout <<"------------------------- STD assign, begin, end, size : --------------------------"<<std::endl;
		{
			std::vector<int> first;
			std::vector<int> second;
			std::vector<int> third;

			first.assign (7,100);             // 7 ints with a value of 100

			std::vector<int>::iterator it;
			it=first.begin()+1;

			second.assign (it,first.end()-1); // the 5 central values of first

			int myints[] = {1776,7,4};
			third.assign (myints,myints+3);   // assigning from array.

			std::cout << "Size of first: " << int (first.size()) << '\n';
			std::cout << "Size of second: " << int (second.size()) << '\n';
			std::cout << "Size of third: " << int (third.size()) << '\n';
		}
		std::cout <<"------------------------- FT erase, ,push_back, constructor, iterator : : --------------------------"<<std::endl;
		{
			ft::vector<int> myvector;
			// set some values (from 1 to 10)
			for (int i=1; i<=10; i++) myvector.push_back(i);

			// erase the 6th element
			myvector.erase (myvector.begin()+5);

			// erase the first 3 elements:
			myvector.erase (myvector.begin(),myvector.begin()+3);

			std::cout << "myvector contains:";
			for (unsigned i=0; i<myvector.size(); ++i)
				std::cout << ' ' << myvector[i];
			std::cout << '\n';
		}
		std::cout <<"------------------------- STD erase, ,push_back, constructor, iterator : --------------------------"<<std::endl;
		{
			std::vector<int> myvector;
			// set some values (from 1 to 10)
			for (int i=1; i<=10; i++) myvector.push_back(i);

			// erase the 6th element
			myvector.erase (myvector.begin()+5);

			// erase the first 3 elements:
			myvector.erase (myvector.begin(),myvector.begin()+3);

			std::cout << "myvector contains:";
			for (unsigned i=0; i<myvector.size(); ++i)
				std::cout << ' ' << myvector[i];
			std::cout << '\n';
		}
	}

	std::cout << "\n<============================================================================>\n";
	std::cout << "<=============================== Stack Tests ================================>\n";
	std::cout << "<============================================================================>\n" << std::endl;
	{
		std::cout <<"------------------------- FT push, empty : --------------------------"<<std::endl;
		{
			ft::stack<int> mystack;

			for (int i=0; i<5; ++i) mystack.push(i);

			std::cout << "Popping out elements...";
			while (!mystack.empty())
			{
				std::cout << ' ' << mystack.top();
				mystack.pop();
			}
			std::cout << '\n';
		}
		std::cout <<"------------------------- STD push, empty : --------------------------"<< std::endl;
		{
			std::stack<int> mystack;

			for (int i=0; i<5; ++i) mystack.push(i);

			std::cout << "Popping out elements...";
			while (!mystack.empty())
			{
				std::cout << ' ' << mystack.top();
				mystack.pop();
			}
			std::cout << '\n';
		}
		std::cout <<"------------------------- FT top , size : --------------------------"<<std::endl;
		{
			ft::stack<int> mystack;

			mystack.push(10);
			mystack.push(20);

			mystack.top() -= 5;

			std::cout << "mystack.top() is now " << mystack.top() << '\n';
		}
		std::cout <<"------------------------- STD top, size : --------------------------"<< std::endl;
		{
			std::stack<int> mystack;

			mystack.push(10);
			mystack.push(20);

			mystack.top() -= 5;

			std::cout << "mystack.top() is now " << mystack.top() << '\n';
		}
	}

	std::cout << "\n<=============================================================================>\n";
	std::cout << "<================================ Map Tests ==================================>\n";
	std::cout << "<=============================================================================>\n" << std::endl;
	{
		std::cout << "\n|-----------------------------------------------------------|"<<std::endl;
		std::cout << "|------------------------- FT : ----------------------------|"<<std::endl;
		std::cout << "|-----------------------------------------------------------|\n"<<std::endl;
		{
			ft::pair<int, float> p1(1, 5.8);
			ft::pair<int, float> p2(2, 20.2);
			ft::pair<int, float> p3(3, 30.3);
			ft::pair<int, float> p4(4, 40.4);

			ft::map<int, float> map2;
			map2.insert(p2);
			map2.insert(p3);
			map2.insert(p4);

			std::cout << "  <<  ------------ Reverse : -------------- >>\n" << std::endl;
			ft::map<int, float>::reverse_iterator r_it = map2.rend();
			r_it--;
			std::cout << "Reverse Iterator = " <<(*r_it).first << std::endl;

			std::cout << "  << ------------ Element access : -------- >>\n" << std::endl;
			map2[2] = 99.5;
			std::cout << "Map [2] " << map2[7] << std::endl;
			std::cout << "size() = " << map2.size() << std::endl;


			std::cout << "  << -------------- Insert : -------------- >>\n" << std::endl;
			std::cout << "insert (1,5.8) " << map2.insert(p1).second << std::endl;
			std::cout << "insert (1,5.8) " << map2.insert(p1).second << std::endl;

			ft::map<int, float> map3;
			map3.insert(map2.begin(), map2.end());
			map3.insert(map2.begin()++, map2.end());
			display(map3.begin(), map3.end(), 3);

			std::cout << "  << ----------------- Erase : ------------ >>" << std::endl;
			ft::map<char,int> mymap;

			// insert some values:
			mymap['a']=10;
			mymap['b']=20;
			mymap['c']=30;
			mymap['d']=40;
			mymap['e']=50;
			mymap['f']=60;

			ft::map<char, int>::iterator it = mymap.end();
			mymap.erase ( ++mymap.begin(), --it);    // erasing by range
		
			//show content:
			display(mymap.begin(), mymap.end(), 1);

			std::cout << "  << ----------------- Other : ------------ >>" << std::endl;
			std::map<char,int> foo,bar;
			foo['a']=100;
			foo['b']=200;
			bar['a']=10;
			bar['z']=1000;

			// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
			if (foo==bar) std::cout << "foo and bar are equal\n";
			if (foo!=bar) std::cout << "foo and bar are not equal\n";
			if (foo< bar) std::cout << "foo is less than bar\n";
			if (foo> bar) std::cout << "foo is greater than bar\n";
			if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
			if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
		


		}
		std::cout << "\n|-----------------------------------------------------------|"<<std::endl;
		std::cout << "|------------------------- STD : ---------------------------|"<<std::endl;
		std::cout << "|-----------------------------------------------------------|\n"<<std::endl;

		{
			std::pair<int, float> p1(1, 5.8);
			std::pair<int, float> p2(2, 20.2);
			std::pair<int, float> p3(3, 30.3);
			std::pair<int, float> p4(4, 40.4);

			std::map<int, float> map2;
			map2.insert(p2);
			map2.insert(p3);
			map2.insert(p4);

			std::cout << "  <<  ------------ Reverse : -------------- >>\n" << std::endl;
			std::map<int, float>::reverse_iterator r_it = map2.rend();
			r_it--;
			std::cout << "Reverse Iterator = " <<(*r_it).first << std::endl;

			std::cout << "  << ------------ Element access : -------- >>\n" << std::endl;
			map2[2] = 99.5;
			std::cout << "Map [2] = " << map2[7] << std::endl;
			std::cout << "size() = " << map2.size() << std::endl;

			std::cout << "  << -------------- Insert : -------------- >>\n" << std::endl;
			std::cout << "insert (1,5.8) " << map2.insert(p1).second << std::endl;
			std::cout << "insert (1,5.8) " << map2.insert(p1).second << std::endl;

			std::map<int, float> map3;
			map3.insert(map2.begin(), map2.end());
			map3.insert(map2.begin()++, map2.end());
			display(map3.begin(), map3.end(), 3);

			std::cout << "  << ----------------- Erase : ------------ >>" << std::endl;

			std::map<char,int> mymap;

			// insert some values:
			mymap['a']=10;
			mymap['b']=20;
			mymap['c']=30;
			mymap['d']=40;
			mymap['e']=50;
			mymap['f']=60;

			std::map<char, int>::iterator it = mymap.end();
			mymap.erase ( ++mymap.begin(), --it);    // erasing by range
	
			//show content:
			display(mymap.begin(), mymap.end(), 1);
			std::cout << "  << ----------------- Other : ------------ >>" << std::endl;

			std::map<char,int> foo,bar;
			foo['a']=100;
			foo['b']=200;
			bar['a']=10;
			bar['z']=1000;

			// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
			if (foo==bar) std::cout << "foo and bar are equal\n";
			if (foo!=bar) std::cout << "foo and bar are not equal\n";
			if (foo< bar) std::cout << "foo is less than bar\n";
			if (foo> bar) std::cout << "foo is greater than bar\n";
			if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
			if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

		}
	}
	std::cout << "\n<=============================================================================>\n";
	std::cout << "<================================ END TESTs ==================================>\n";
	std::cout << "<=============================================================================>\n" << std::endl;


	// system ("leaks Containers");
	return (0);
}