
#include <list>
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

template <typename T>
class SyncQueue {
	public:
		SyncQueue(int maxSize)
			: m_maxSize(maxSize) {}
		
		void Put(const T &x) {
			std::lock_guard<std::mutex> locker(m_mutex);
			while (IsFull()) {
				std::cout << "buffer full, wait..." << std::endl;
				m_notFull.wait(m_mutex);
			}
			m_queue.push_back(x);
			m_notEmpty.notify_one();
		}

		void Take(T &x) {
			std::lock_guard<std::mutex> locker(m_mutex);
			while (IsEmpty()) {
				std::cout << "buffer empty, wait..." << std::endl;
				m_notEmpty.wait(m_mutex);
			}
			x = m_queue.front();
			m_queue.pop_front();
			m_notFull.notify_one();
		}
		
		bool Empty() {
			std::lock_guard<std::mutex> locker(m_mutex);
			return m_queue.empty();
		}

		bool Full() {
			std::lock_guard<std::mutex> locker(m_mutex);
			return m_queue.size() == m_maxSize;
		}

		size_t Size() {
			std::lock_guard<std::mutex> locker(m_mutex);
			return m_queue.size();
		}

		int Count() { return m_queue.size(); }
	private:
		std::list<T> m_queue;
		std::mutex m_mutex;
		std::condition_variable_any m_notEmpty;
		std::condition_variable_any m_notFull;
		int m_maxSize;

		bool IsFull() const { return m_queue.size() == m_maxSize; }
		bool IsEmpty() const { return m_queue.empty(); }
};
