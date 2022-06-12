#ifndef ENABLE_IF_H
#define ENABLE_IF_H

namespace ft
{
	template< bool B, typename T = void >
	struct enable_if {};

	template< true, typename T >
	struct enable_if
	{
		typedef T	type;
	};
}

#endif
