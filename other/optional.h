
#ifndef _OPTIONAL_H_
#define _OPTIONAL_H_

#include <utility>
#include <stdexcept>
#include <type_traits>

template <typename T>
class Optional {
	using data_t = typename std::aligned_storage<sizeof(T), 
				std::alignment_of<T>::value>::type;
	public:
		Optional() {}
		Optional(const T& v) { Create(v); }
		Optional(T &&v) { Create(std::move(v)); }
		Optional(const Optional &other) {
			if (other.IsInit())
				Assign(other);
		}
		Optional(Optional &&other) {
			if (other.IsInit()) {
				Assign(std::move(other));
				other.Destroy();
			}
		}

		Optional& operator=(Optional &&other) {
			Assign(std::move(other));
			return *this;
		}
		
		Optional& operator=(const Optional &other) {
			Assign(other);
			return *this;
		}

		~Optional() { Destroy(); }

		template <typename... Args>
		void Emplace(Args&&... args) {
			Destroy();
			Create(std::forward<Args>(args)...);
		}

		bool IsInit() const { return m_hasInit; }
		explicit operator bool() const { return IsInit(); }
		
		T& operator*() { return *((T*)(&m_data)); }

		T const& operator*() const {
			if (IsInit()) { return *((T*)(&m_data)); }
			throw std::logic_error("is not init.");
		}
		
		bool operator == (const Optional<T> &rhs) const {
			return (!bool(*this)) != (!rhs) ? false : (!bool(*this) ? true : 
					(*(*this)) == (*rhs));
		}

		bool operator < (const Optional<T> &rhs) const {
			return !rhs ? false : (!bool(*this) ? true : (*(*this) < (*rhs)));
		}

		bool operator != (const Optional<T> &rhs) { 
			return !(*this == (rhs));
		}

	private:
		bool m_hasInit = false;
		data_t m_data;

		template <typename... Args>
		void Create(Args&&... args) {
			new (&m_data) T(std::forward<Args>(args)...);
			m_hasInit = true;
		}

		void Destroy() {
			if (m_hasInit) {
				m_hasInit = false;
				((T*)(&m_data)) -> ~T();
			}
		}

		void Assign(const Optional &other) {
			if (other.IsInit()) {
				Copy(other.m_data);
				m_hasInit = true;
			} else {
				Destroy();
			}
		}

		void Copy(const data_t &val) {
			Destroy();
			new (&m_data) T(*((T*)(&val)));
		}
};

#endif
