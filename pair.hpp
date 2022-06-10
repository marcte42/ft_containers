#ifndef PAIR_HPP
#define PAIR_HPP

#include <iostream>

namespace ft
{
	template < class T1, class T2 >
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		pair()
		{
		}

		pair( const T1& x, const T2& y )
		{
		}

		template< class U1, class U2 >
		pair( const pair<U1, U2>& p )
		{
		}
	};

	template< class T1, class T2 >
	std::pair<T1,T2> make_pair( T1 t, T2 u );

	template< class T1, class T2 >
	bool operator==( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
	
	}

	template< class T1, class T2 >
	bool operator!=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
	
	}

	template< class T1, class T2 >
	bool operator<( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{

	}

	template< class T1, class T2 >
	bool operator<=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{

	}

	template< class T1, class T2 >
	bool operator>( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{

	}

	template< class T1, class T2 >
	bool operator>=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{

	}
}

#endif
