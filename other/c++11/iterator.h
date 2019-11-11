
#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <cstddef>

namespace detail_range {
	template <typename T>
	class iterator {
		public:
			using value_type = T;
			using size_type = size_t;
			iterator(size_type cur_start, value_type begin_val, 
					value_type step_val) :
				cursor_(cur_start),
				step_   (step_val),
				value_ (begin_val) { value_ += (step_ * cursor_); }
		value_type operator*() const { return value_; }
		bool operator!=(const iterator &rhs) const { return (cursor_ != rhs.cursor_); }
		iterator& operator++() { // prefix++ operator only
			value_ += step_;
			++cursor_;
			return (*this); 
		}
		private:
			size_type      cursor_;
			const value_type step_;
			value_type      value_;

	};

} // detail_range 

#endif
