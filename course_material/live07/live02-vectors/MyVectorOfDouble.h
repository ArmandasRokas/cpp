#ifndef MYVECTOROFDOUBLE_H_
#define MYVECTOROFDOUBLE_H_

//See comments in MyVectorOfInt.h
class MyVectorOfDouble {
private:
	double *content;
	int size;
	int capacity;
	void resize();

public:
	MyVectorOfDouble();
	MyVectorOfDouble(int initialCapacity);

	~MyVectorOfDouble();


	int getCapacity();
	int getSize();
	void push_back(double v);

	double at(unsigned int where);
	double & operator[](unsigned int where);

	MyVectorOfDouble & operator=(MyVectorOfDouble &);
};

#endif /* MYVECTOROFDOUBLE_H_ */
