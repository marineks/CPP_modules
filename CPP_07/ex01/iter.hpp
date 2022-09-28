
#ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <iostream>

template <typename T>
void pow(T &x) {

	x = x * x;
	std::cout << "x is now : " << x << std::endl;
}

template <typename T>
void print(T &y) {

	std::cout << y << std::endl;
}

template<typename T>
void	iter(T *array, int len, void f(T &array))
{
	for (int i = 0; i < len; i++)
		f(array[i]);
}


#endif
