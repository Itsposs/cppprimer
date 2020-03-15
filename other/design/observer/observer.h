
#ifndef _OBSERVER_H_
#define _OBSERVER_H_ 

#include <list>
#include <string>
#include <iostream>

<<<<<<< HEAD
//class StockObserver;
//
//class Secretary {
//	public:
//		Secretary() {}
//		void setStatus(std::string &s) { status = s; }
//		std::string getStatus() const { return status; }
//		void Attach(StockObserver *rhs) { observers.push_back(rhs); }
//		void Notify() const;
//	private:
//		std::string status;
//		std::list<StockObserver *> observers;
//};
//
//
//class StockObserver {
//	public:
//		StockObserver(std::string s, Secretary *scy) 
//			: who(s), s(scy) {}
//		void Update() const {
//			std::cout << s -> getStatus() << " " << who << "!" << std::endl;
//		}
//	private:
//		std::string who;
//		Secretary *s;
//};
//
//void Secretary::Notify() const {
//	for (auto ob :  observers)
//		ob -> Update();
//}

class Subject {
	public:
	private:
};

=======
class StockObserver;

class Secretary {
	public:
		Secretary() {}
		void setStatus(std::string &s) { status = s; }
		std::string getStatus() const { return status; }
		void Attach(StockObserver *rhs) { observers.push_back(rhs); }
		void Notify() const;
	private:
		std::string status;
		std::list<StockObserver *> observers;
};


class StockObserver {
	public:
		StockObserver(std::string s, Secretary *scy) 
			: who(s), s(scy) {}
		void Update() const {
			std::cout << s -> getStatus() << " " << who << "!" << std::endl;
		}
	private:
		std::string who;
		Secretary *s;
};

void Secretary::Notify() const {
	for (auto ob :  observers)
		ob -> Update();
}


>>>>>>> e2763e0a43fdee023e83410a284fa63d0cbb0459
#endif // observer.h
