#include "CArray.h"

template <typename T>
void CArray<T>::Reallocation()
{
	const int cPie = 8;
	_capacity += cPie;

	T* pointer = new T[_capacity];
	memcpy(pointer, _rawPointer, sizeof(T) * (_capacity - cPie));

	delete[] _rawPointer;
	_rawPointer = pointer;
}

template <typename T>
void CArray<T>::Add(T item)
{
	if (_count == _capacity)
		Reallocation();

	_count++;
	_rawPointer[_count - 1] = item;
}