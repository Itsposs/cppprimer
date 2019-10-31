

#ifndef IMPL_H_
#define IMPL_H_

#include "iterator.h"
#include <stdexcept>

namespace detail_range {
	template <typename T>
	class impl {
		public:
			using value_type = T;
			using reference       = const value_type&;
			using const_reference = const value_type&&;
			using iterator        = const detail_range::iterator<value_type>;
			using const_iterator  = const detail_range::iterator<value_type>;
			using size_type       = typename iterator::size_type;

			impl(value_type begin_val, value_type end_val, value_type step_val)
				: begin_(begin_val),
				  end_    (end_val),
				  step_  (step_val),
					max_count_(get_adjusted_count()) 
					{}

			size_type size() const { return max_count_; }
			const_iterator begin() const { return { 0, begin_, step_ }; }
			const_iterator end() const { return { max_count_, begin_, step_ }; }
		private:
			const value_type begin_;
			const value_type end_;
			const value_type step_;
			const size_type  max_count_;

			size_type get_adjusted_count() const {
				if (step_ > 0 && begin_ >= end_)
					throw std::logic_error("End value must be greater than begin value.");
				else if (step_ < 0 && begin_ <= end_)
					throw std::logic_error("End value must be less than begin value.");
	
				size_type x = static_cast<size_type>((end_ - begin_) / step_);
				if (begin_ + (step_ * x) != end_)
					++x;
				return x;
			}
	};

}

#endif
