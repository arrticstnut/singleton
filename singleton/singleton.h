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
			static Singleton * getInstance();
			static void destroyInstance();
		private:
			Singleton(){cout << "Singleton()" << endl;}
			~Singleton(){cout << "~Singleton()" << endl;}
			//禁止复制
			Singleton(const Singleton &) = delete;
			Singleton & operator=(const Singleton &) = delete;
		private:
			static std::mutex m_mutex;
			static Singleton * m_pInstance;
	};

	Singleton* Singleton::m_pInstance = nullptr;
	std::mutex Singleton::m_mutex;

	Singleton* Singleton::getInstance(){
		if(nullptr == m_pInstance){
			std::lock_guard<std::mutex> guard(m_mutex);
			if(nullptr == m_pInstance){
				m_pInstance = new Singleton();
			}
		}
		return m_pInstance;
	}

	void Singleton::destroyInstance(){
		if(m_pInstance != nullptr){
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
}//end of namespace
#endif

