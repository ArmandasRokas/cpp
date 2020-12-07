#ifndef MYVECTORWITHTEMPLATES_H_
#define MYVECTORWITHTEMPLATES_H_

// This implementation of a vector class is based on the one of previous weeks.
// The difference is that the one in this file is generic:
// it provides support for vectors of any type, not just integers.

// The class vector is now "templated"
// The template has one parameter: the base type/class T
template <class T>
class MyVectorWithTemplates {
	// Below we have replaced every occurrence of "double"
	// related to vector elements by "T"
	// Moreover, we have replaced all occurrences of "MyVectorWithTemplates"
	// by MyVectorWithTemplates<T>
private:
	T *content;							// note the use of T
	int size;
	int capacity;
	void resize();

public:
	MyVectorWithTemplates();
	MyVectorWithTemplates(int initialCapacity);

	~MyVectorWithTemplates();


	int getCapacity();
	int getSize();
	void push_back(T v); // note the use of T

	T at(unsigned int where);           // note the use of T
	T & operator[](unsigned int where); // note the use of T

	MyVectorWithTemplates<T> & operator=(MyVectorWithTemplates<T> &);
};

// We have now defined the templated interface of MyVectorWithTemplates.
// We need to define their templated implementation.
//
// Note that the templated implementation of MyVectorWithTemplates
// is not quite a "full" implementation: in fact, it is more like a skeleton;
// templated code becomes "real" code when the template parameter T
// is instantiated.
//
// Therefore, the templated "implementation" of MyVectorWithTemplates should be
// part of a .h file, to be included and instantiated by its users.
// The templated code should NOT not be in a .cpp file.
//
// However, requiring to include multiple .h files to use MyVectorWithTemplates
// can be inconvenient and confusing. Also, we should NOT write the templated
// "implementations" here, because they would make this .h file very long,
// full of implementation details, and difficult to read --- and this would be
// bad practice.
//
// A recommended practice is to put the templated "implementations" into a
// separate "template implementation file", and include such a file from the
// .h file: this is what we do below.
//
// Template implementation files usually have extensions like:
// .tpp, .tcc, .txx, .ipp.
#include "MyVectorWithTemplates.tpp"

#endif /* MYVECTORWITHTEMPLATES_H_ */
