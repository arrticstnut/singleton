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
		//嵌套类，自动释放内存
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
			class Auto;
			static Auto _auto;//自动释放类
			static std::mutex _mutex;
			static Singleton * _pInstance;
	};

	class Singleton::Auto{
		public:
			~Auto(){ destroyInstance(); }
	};

	Singleton::Auto Singleton::_auto;
	Singleton* Singleton::_pInstance = nullptr;
	std::mutex Singleton::_mutex;

	Singleton* Singleton::getInstance(){
		if(nullptr == _pInstance){
			std::lock_guard<std::mutex> guard(_mutex);
			if(nullptr == _pInstance){
				_pInstance = new Singleton();
			}
		}
		return _pInstance;
	}

	void Singleton::destroyInstance(){
		if(_pInstance != nullptr){
			delete _pInstance;
			_pInstance = nullptr;
		}
	}
}//end of namespace
#endif

