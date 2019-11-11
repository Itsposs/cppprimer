
#include <memory>

template <typename T, typename... Args>
inline typename enable_if<!is_array<T>::value, 
std::unique_ptr<T>>::type make_unique(Args&&... args) {
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template <typename T> 
inline typename enable_if<is_array<T>::value && extent<T>::value == 0,
std::unique_ptr<T>>::type make_unique(size_t size) {
	typedef typename remove_extent<T>::type U;
	return std::unique_ptr<T>(new U[size]());
}

template <typename T, typename... Args>
typename enable_if<extent<T>::value != 0, void>::type 
make_unique(Args&&...) = delete;




