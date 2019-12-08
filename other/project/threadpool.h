
#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#include <list>
#include <memory>
#include <atomic>
#include <thread>
#include <functional>
#include "syncqueue.h"

const int MaxTaskCount = 100;

class ThreadPool {
	public:
		using Task = std::function<void()>;
		ThreadPool(int numThreads = std::thread::hardware_concurrency())
			: m_queue(MaxTaskCount) { Start(numThreads); }
		~ThreadPool() { Stop(); }
		void Start(int numThreads) {
			m_running = true;
			for (int i = 0; i < numThreads; ++i) 
				m_threadgroup.push_back(std::make_shared<std::thread>
						(&ThreadPool::RunInThread, this));
		}

		void Stop() { std::call_once(m_flag, [this]{ StopThreadGroup(); }); }
		void AddTask(const Task &task) { m_queue.Put(task); }
		void AddTask(Task &&task) { m_queue.Put(std::forward<Task>(task)); }
	private:
		std::list<std::shared_ptr<std::thread>> m_threadgroup;
		SyncQueue<Task> m_queue;
		std::atomic_bool m_running;
		std::once_flag m_flag;
		
		void RunInThread() {
			while (m_running) {
				std::list<Task> list;
				m_queue.Take(list);

				for (auto &task : list) {
					if (!m_running) return;
					task();
				}
			}
		}

		void StopThreadGroup() {
			m_queue.Stop();
			m_running = false;

			for (auto thread : m_threadgroup) {
				if (thread)
					thread -> join();
			}
			m_threadgroup.clear();
		}
};


#endif // threadpool.h
