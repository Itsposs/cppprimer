
#ifndef _OBSERVER_H_
#ifndef _OBSERVER_H_ 

class Sbuject;

class Observer {
	public:
		virtual ~Observer();
		virtual void Update(Sbuject *theChangedSubject) = 0;
	protected:
		Observer();
};

class Sbuject {

};

#endif // observer.h
