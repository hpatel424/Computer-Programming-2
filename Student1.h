#pragma once

#include <iostream>
#include<string>
using namespace std;

template <class T>
class Student1
{
private:
	string firstName, lastName;
	int ID;
	float w1, w2, w3, w4;
	T t1, t2, t3, t4;
	int weight[4];

public:
	Student1(string arg1 = "N/A", string arg2 = "N/A", int arg3 = 0, float w1 = 0, float w2 = 0, float w3 = 0, float w4 = 0, T t1 = 0, T t2 = 0, T t3 = 0, T t4 = 0, int n1 = 10);

	string getFirstName(void);
	void setFirstName(string first);

	string getLastName(void);
	void setLastName(string last);

	int getID(void);
	void setID(int id);

	float getW1(void);
	void setW1(float W1);
	float getW2(void);
	void setW2(float W2);
	float getW3(void);
	void setW3(float W3);
	float getW4(void);
	void setW4(float W4);

	T getT1(void);
	void setT1(T test1);
	T getT2(void);
	void setT2(T test2);
	T getT3(void);
	void setT3(T test3);
	T getT4(void);
	void setT4(T test4);

	int getWeight(int n)
	{
		return weight[n];
	}
	void setWeight(int w, int n) {
		weight[n] = w;
	}

	T getWeightedAvg(void);
	char getGrade(void);

	void print(void);

};