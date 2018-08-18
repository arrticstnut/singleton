///
/// @file    test.cc
/// @author  
/// @date    2018-08-17 23:08:49
///

#include "singleton.h"
#include "stdio.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using namespace cc;
int main(){
	cout << "......begin......" << endl;
	int *pint1 = Singleton<int>::getInstance();
	int *pint2 = Singleton<int>::getInstance();
	int *pint3 = Singleton<int>::getInstance();
	float *pfloat1 = Singleton<float>::getInstance();
	float *pfloat2 = Singleton<float>::getInstance();
	float *pfloat3  = Singleton<float>::getInstance();
	string *pstr1  = Singleton<string>::getInstance();
	string *pstr2  = Singleton<string>::getInstance();
	string *pstr3  = Singleton<string>::getInstance();
	printf("pint1 = %p\n",pint1);
	printf("pint2 = %p\n",pint2);
	printf("pint3 = %p\n",pint3);
	printf("pfloat1 = %p\n",pfloat1);
	printf("pfloat2 = %p\n",pfloat2);
	printf("pfloat3 = %p\n",pfloat3);
	printf("pstr1 = %p\n",pstr1);
	printf("pstr2 = %p\n",pstr2);
	printf("pstr3 = %p\n",pstr3);
	Singleton<int>::destroyInstance();
	Singleton<int>::destroyInstance();
	Singleton<int>::destroyInstance();
	Singleton<float>::destroyInstance();
	Singleton<float>::destroyInstance();
	Singleton<float>::destroyInstance();
	Singleton<double>::destroyInstance();
	Singleton<double>::destroyInstance();
	Singleton<double>::destroyInstance();
	Singleton<string>::destroyInstance();
	Singleton<string>::destroyInstance();
	Singleton<string>::destroyInstance();
	cout << "......end......" << endl;
}
