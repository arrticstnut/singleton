///
/// @file    singleton.h
/// @author  
/// @date    2018-08-17 22:49:32
///

#ifndef __CC_SINGLETON_H__
#define __CC_SINGLETON_H__
#include <iostream>
#include <mutex>
using std::cout;
using std::endl;

namespace cc
{
	class Singleton
	{
		public:
			static Singleton & getInstance();
		private:
			static Singleton & createInstance();
		private:
			Singleton(){cout << "Singleton()" << endl;}
			~Singleton(){cout << "~Singleton()" << endl;}
			Singleton(const Singleton &) = delete;
			Singleton & operator=(const Singleton &) = delete;
		private:
			//由于局部静态变量是非线程安全的，所以要加锁，并加一个标志位
			static bool m_isExisted;//标记实例是否存在
			static std::mutex m_mutex;
	};

	bool Singleton::m_isExisted = false;
	std::mutex Singleton::m_mutex;

	Singleton & Singleton::getInstance(){
		if(false == m_isExisted){
			std::lock_guard<std::mutex> guard(m_mutex);
			if(false == m_isExisted){
				return createInstance();
			}
		}
		return createInstance();
	}

	Singleton & Singleton::createInstance(){
		static Singleton instance;
		return instance;
	}

}//end of namespace
#endif

