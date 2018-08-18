///
/// @file    singleton.h
/// @author  
/// @date    2018-08-17 22:49:32
///

#ifndef __CC_SINGLETON_H__
#define __CC_SINGLETON_H__
#include <iostream>
using std::cout;
using std::endl;
namespace cc
{
	class Singleton
	{
		public:
			static Singleton & getInstance();
		private:
			Singleton(){cout << "Singleton()" << endl;}
			~Singleton(){cout << "~Singleton()" << endl;}
			//禁止复制
			Singleton(const Singleton &) = delete;
			Singleton & operator=(const Singleton &) = delete;
		private:
			static Singleton m_Instance;
	};

	Singleton Singleton::m_Instance;

	Singleton & Singleton::getInstance(){
		return m_Instance;
	}

}//end of namespace
#endif

