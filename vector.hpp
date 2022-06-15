#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>

namespace ft
{
	template < typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T											value_type;
		typedef Allocator 									allocator_type;
		typedef typename allocator_type::pointer 			pointer;
		typedef typename allocator_type::const_pointer 		const_pointer;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		// typedef ft::iterator<iterator>						iterator;
		// typedef ft::iterator<const_iterator>				const_iterator;
		// typedef ft::reverse_iterator<iterator>				reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		// Default constructor. Constructs an empty container with a default-constructed allocator.
		vector()
			: _data(NULL), _size(0), _capacity(0)
		{
		}

		// Constructs an empty container with the given allocator alloc.
		explicit vector( const Allocator &alloc )
			: _alloc(alloc), _data(NULL), _size(0), _capacity(0)
		{
		}

		// Constructs the container with count copies of elements with value value.
		explicit vector( size_type count, const T &value = T(), const Allocator &alloc = Allocator() )
			: _alloc(alloc), _data(NULL), _size(count), _capacity(count)
		{
			_data = _alloc.allocate(count);
			for (size_type i = 0; i < count; i++)
				_alloc.construct(&_data[i], value);
		}

		// Constructs the container with the contents of the range [first, last].
		template < typename InputIt >
		vector( InputIt first, InputIt last, const Allocator &alloc = Allocator() )
			: _alloc(alloc), _data(NULL)
		{
			_size = std::distance(first, last);
			_capacity = _size;
			_data = _alloc.allocate(_capacity);
			for (int i = 0; i < _size; i++)
			{
				_alloc.construct(&_data[i], *first);
				first++;
			}
		}

		// Destructor
		~vector()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			_alloc.deallocate(_data, _size);
		}
		// ***
		// Element access
		// ***

		reference at( size_type pos )
		{
			if (!(pos < _size))
				throw std::exception();
			return _data[pos];
		}

		const_reference at( size_type pos ) const
		{
			if (!(pos < _size))
				throw std::exception();
			return _data[pos];
		}

		reference operator[]( size_type pos )
		{
			return _data[pos];
		}

		const_reference operator[]( size_type pos ) const
		{
			return _data[pos];
		}

		reference front()
		{
			return *_data;
		}

		const_reference front() const
		{
			return *_data;
		}

		reference back()
		{
			return _data[_size - 1];
		}

		const_reference back() const
		{
			return *_data[_size - 1];
		}

		T* data()
		{
			return _data;
		}

		const T* data() const
		{
			return _data;
		}

		// ***
		// Capacity
		// ***

		bool empty() const
		{
			return _size == 0;
		}

		size_type size() const
		{
			return _size;
		}

		size_type max_size() const
		{
			return _alloc.max_size();
		}

		void reserve( size_type new_cap )
		{
			pointer tmp;

			if (new_cap > _alloc.max_size())
				throw std::length_error("vector::reserve");
			if (new_cap > _capacity)
			{
				tmp = _alloc.allocate(new_cap);
				for (size_type i = 0; i < _size; i++)
				{
					try
					{
						_alloc.construct(&tmp[i], _data[i]);
					}
					catch (const std::exception &e)
					{
						for (size_type j = 0; j < i; j++)
						{
							_alloc.destroy(&tmp[j]);
						}
						_alloc.deallocate(tmp, new_cap);
						return;
					}
				}
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_data[i]);
				_alloc.deallocate(_data, _size);
				_data = tmp;
				_capacity = new_cap;
			}
		}

		size_type capacity() const
		{
			return _capacity;
		}

		// ***
		// Modifiers
		// ***
		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			_size = 0;
		}

		void push_back( const T& value )
		{
			if (_size == _capacity)
			{
				int new_capacity = (_size == 0) ? 1 : _size * 2;
				this->reserve(new_capacity);
			}
			_alloc.construct(_data + _size, value);
			_size++;
		}

		void pop_back()
		{
			_alloc.destroy(&_data[_size - 1]);
			_size--;
		}

		/*
		void resize( size_type count, value_type value = value_type() )
		{
			if (count < _size)
			{
				for (size_type i = count; i < _size; i++)
					_alloc.destroy(&_data[i]);
				_size = count;
			}
			else if (count > _size)
			{
				// Waiting for iterator implementation to use insert( iterator pos, size_type count, const T& value );
			}
		}
		*/

	private:
		allocator_type _alloc;
		pointer _data;
		size_type _size;
		size_type _capacity;
	};
}

#endif
