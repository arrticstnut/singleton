///
/// @file    test.cc
/// @author  
/// @date    2018-08-17 23:08:49
///

#include "singleton.h"
#include "stdio.h"
#include <iostream>
using std::cout;
using std::endl;
using namespace cc;
int main(){
	cout << "......begin......" << endl;
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	Singleton *p3 = Singleton::getInstance();
	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	printf("p3 = %p\n",p3);
	Singleton::destroyInstance();
	Singleton::destroyInstance();
	Singleton::destroyInstance();
	cout << "......end......" << endl;
}
