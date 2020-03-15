
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <stdexcept>

//template <typename T>
//class Singleton {
//	public:
//		static T* Instance() {
//			if (m_pInstance == nullptr)
//				m_pInstance = new T();
//			return m_pInstance;
//		}
//
//		template <typename T0>
//		static T* Instance(T0 arg0) {
//			if (m_pInstance == nullptr)
//				m_pInstance = new T(arg0);
//			return m_pInstance;
//		}
//
//		template <typename T0, typename T1>
//		static T* Instance(T0 arg0, T1 arg1) {
//			if (m_pInstance == nullptr)
//				m_pInstance = new T(arg0, arg1);
//			return m_pInstance;
//		}
//
//		static T* GetInstance() {
//			if (m_pInstance == nullptr)
//				throw std::logic_error("the instance isn't init.");
//			return m_pInstance;
//		}
//
//		static void DestroyInstance() {
//			delete m_pInstance;
//			m_pInstance = nullptr;
//		}
//
//	private:
//		static T *m_pInstance;
//
//		Singleton();
//		virtual ~Singleton();
//		Singleton(const Singleton &rhs);
//		Singleton& operator=(const Singleton &rhs);
//};
//
//template <typename T>
//T* Singleton<T>::m_pInstance = nullptr;

template <typename T>
class Singleton {
	public:
		template <typename... Args>
		static T* Instance(Args&&... args) {
			if (m_pInstance == nullptr)
				m_pInstance = new T(std::forward<Args>(args)...);
			return m_pInstance;
		}

		static T* GetInstance() {
			if (m_pInstance == nullptr)
				throw std::logic_error("the instance is not init.");
			return m_pInstance;
		}

		static void DestroyInstance() {
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	private:
		static T *m_pInstance;

		Singleton();
		virtual ~Singleton();
		Singleton(const Singleton &rhs);
		Singleton& operator=(const Singleton &rhs);
};

template <typename T>
T* Singleton<T>::m_pInstance = nullptr;
#endif // singleton.h
