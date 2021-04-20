#pragma once

template <class T>
class CArray
{
protected:

	int _capacity;
	int _count;
	T* _rawPointer;

	void Reallocation();

public:

	CArray()
	{
		_capacity = 8;
		_count = 0;

		_rawPointer = new T[_capacity];
	}

	virtual ~CArray()
	{
		if (_rawPointer)
			delete[] _rawPointer;
	}

	int GetCount() const { return _count; }
	void Add(T item);
};
