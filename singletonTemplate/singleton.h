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
	template<typename T>
	class Singleton
	{
		public:
			static T * getInstance();
			static void destroyInstance();
		private:
			Singleton(){cout << "Singleton()" << endl;}
			~Singleton(){cout << "~Singleton()" << endl;}
			//禁止复制
			Singleton(const Singleton &) = delete;
			Singleton & operator=(const Singleton &) = delete;
		private:
			static std::mutex m_mutex;
			static T * m_pInstance;
	};

	template<typename T>
	T* Singleton<T>::m_pInstance = nullptr;

	template<typename T>
	std::mutex Singleton<T>::m_mutex;

	template<typename T>
	T* Singleton<T>::getInstance(){
		if(nullptr == m_pInstance){
			std::lock_guard<std::mutex> guard(m_mutex);
			if(nullptr == m_pInstance){
				m_pInstance = new T;
			}
		}
		return m_pInstance;
	}

	template<typename T>
	void Singleton<T>::destroyInstance(){
		if(m_pInstance != nullptr){
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
}//end of namespace
#endif

