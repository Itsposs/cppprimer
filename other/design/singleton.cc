
template <typename T>
class Singleton {
	public:
		template <typename... Args>
	private:
			Singleton();
			virtual ~Singleton();
			Singleton(const Singleton &rhs);
			Singleton& operator = (const Singleton &rhs);

			static T *instance;
};

template <typename T>
T *Singleton<T>::instance = nullptr;
