// iterator.cpp
// ENSF 614 - Fall 2022 - Lab 6, Ex A

#include <iostream>
#include <assert.h>
#include "mystring2.h"
#include <string.h>

using namespace std;

template <class T>
class Vector {
public: 
  class VectIter{
    friend class Vector;
  private:
    Vector *v; // points to a vector object of type T
    int index;    // represents the subscript number of the vector's
                  // array.
  public:
    VectIter(Vector& x);
 
    T operator++();
    //PROMISES: increments the iterator's indes and return the 
    //          value of the element at the index position. If
    //          index exceeds the size of the array it will 
    //          be set to zero. Which means it will be circulated
    //          back to the first element of the vector.

    T  operator++(int);
    // PRIMISES: returns the value of the element at the index
    //           position, then increments the index. If
    //           index exceeds the size of the array it will 
    //           be set to zero. Which means it will be circulated
    //           back to the first element of the vector.

    T  operator--();
    // PROMISES: decrements the iterator index, and return the
    //           the value of the element at the index. If
    //           index is less than zero it will be set to the 
    //           last element in the aray. Which means it will be
    //           circulated to the last element of the vector.

    T  operator--(int);
    // PRIMISES: returns the value of the element at the index
    //           position, then decrements the index. If
    //           index is less than zero it will be set to the 
    //           last element in the aray. Which means it will be
    //           circulated to the last element of the vector.

    T operator *();
    // PRIMISES: returns the value of the element at the current 
    //           index position.
  };

  Vector(int sz); 
  ~Vector();

  T& operator[](int i);
  // PRIMISES: returns existing value in the ith element of 
  //           array or sets a new value to  the ith element in
  //           array. 
  
  void ascending_sort();
  // PRIMISES: sorts the vector values in ascending order. 
	
private:
  T *array;               // points to the first element of an array of T
  int size;               // size of array
  void swap(T&, T &); // swaps the values of two elements in array
};

template <class T >
void Vector<T>::ascending_sort()
{
	for(int i=0; i< size-1; i++)
		for(int j=i+1; j < size; j++)
			if(array[i] > array[j])
				swap(array[i], array[j]);
}

template<>
void Vector<Mystring>::ascending_sort()
{
	for(int i=0; i< size-1; i++)
		for(int j=i+1; j < size; j++)
      if(strcmp(array[i].c_str(), array[j].c_str()) > 0)
				swap(array[i], array[j]);
}

template<>
void Vector<const char*>::ascending_sort()
{
	for(int i=0; i< size-1; i++)
		for(int j=i+1; j < size; j++)
      if(strcmp(array[i], array[j]) > 0)
				swap(array[i], array[j]);
}

template <class T >
void Vector<T>::swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <class T >
T Vector<T>::VectIter::operator *()
{
  return v -> array[index];
}

template <class T >
Vector<T>::VectIter::VectIter(Vector& x)
{
  v = &x;
  index = 0;
}

template <class T >
Vector<T>::Vector(int sz)
{
  size=sz;
  array = new T [sz];
  assert (array != NULL);
}

template <class T >
Vector<T>::~Vector()
{
  delete [] array;
  array = NULL;
}


template <class T >
T& Vector<T>::operator[] (int i)
{
  return array[i];
}
template <class T >
T Vector<T>::VectIter::operator++(){
  if (index < v -> size - 1){
    index++;
  }
  else {
    index = 0;
  }
  return (*v)[index];
}

template <class T >
T Vector<T>::VectIter::operator++(int){
  int temp = 0;
  if (index < v -> size){
    temp = index;
    index ++;
  }
  else {
    index = 0;
  }
  return (*v)[temp];
}

template <class T >
T Vector<T>::VectIter::operator--(){
  if (index > 0){
    index--;
  }
  else {
    index = v -> size - 1;
  }
  return (*v)[index];
}

template <class T >
T Vector<T>::VectIter::operator--(int){
  int temp = index;
  if (index > 0){
    index--;
  }
  else {
    index = v -> size - 1;
  }
  return (*v)[temp];
}


int main()
{
#if 1
 Vector<int> x(3);
 x[0] = 999;
 x[1] = -77;
 x[2] = 88;

 Vector<int>::VectIter iter(x);

 cout << "\n\nThe first element of vector x contains: " << *iter; 

 // the code between the  #if 0 and #endif is ignored by
 // compiler. If you change it to #if 1, it will be compiled
 

	cout << "\nTesting an <int> Vector: " << endl;
	
	cout << "\n\nTesting sort";
	x.ascending_sort();
  cout << "\n\nTesting Postfix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << iter++;
	cout << "\n\nTesting Prefix --:";
	for (int i=0; i<3 ; i++)
		cout << endl << --iter;

	cout << "\n\nTesting Prefix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << ++iter;	
	
	cout << "\n\nTesting Postfix --";
	for (int i=0; i<3 ; i++)
		cout << endl << iter--;
	
	cout << endl;
#endif
#if 1
	cout << "Testing a <Mystring> Vector: " << endl;
	Vector<Mystring> y(3);
	y[0] = "Bar";
	y[1] = "Foo";
	y[2] = "All";;
	
	Vector<Mystring>::VectIter iters(y);
	
	cout << "\n\nTesting sort";
	y.ascending_sort();
#endif
#if 1	
	for (int i=0; i<3 ; i++)
		cout << endl << iters++.c_str();
#endif
#if 1	
	cout << "\n\nTesting Prefix --:";
	for (int i=0; i<3 ; i++)
		cout << endl << (--iters).c_str();
	
	cout << "\n\nTesting Prefix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << (++iters).c_str();
	
	cout << "\n\nTesting Postfix --";
	for (int i=0; i<3 ; i++)
		cout << endl << (iters--).c_str();
	
	cout << endl; cout << "Testing a <char *> Vector: " << endl;
	Vector<const char*> z(3);
	z[0] = "Orange";
	z[1] = "Pear";
	z[2] = "Apple";;
	
	Vector<const char*>::VectIter iterchar(z);
	
	cout << "\n\nTesting sort";
	z.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iterchar++;
	
#endif
	cout << "\nProgram Terminated Successfully." << endl;
	
	return 0;
}












