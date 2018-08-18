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
	Singleton & m1 = Singleton::getInstance();
	Singleton & m2 = Singleton::getInstance();
	Singleton & m3 = Singleton::getInstance();
	printf("m1 = %p\n",&m1);
	printf("m2 = %p\n",&m2);
	printf("m3 = %p\n",&m3);
	cout << "......end......" << endl;
}
