


template <typename T>
std::string ToString(T t) {
	if (typeid(T) == typeid(int) || typeid(T) == typeid(double) || 
			typeid(T) == typeid(float) || typeid(T) == typeid(float)) {
		std::stringstream ss;
		ss << value;
		return ss.str();
	} else if (typeid(T) == typeid(std::string)) {
		return t;
	}
}


template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, std::string>::type
	ToString(T &t) { return std::to_string(t); }

template <typename T>
typename std::enable_if<!std::is_same<T>::value, std::string>::type
	ToString(T &t) { return t; }


