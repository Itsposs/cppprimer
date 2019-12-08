#ifndef _STRING_H_
#define _STRING_H_

#include <memory>
#include <string.h>


class String
{
	friend String operator+(const String&, const String&);
	friend String add(const String&, const String&);
	friend std::ostream &operator<<(std::ostream&, const String&);
	friend std::ostream &print(std::ostream&, const String&);

	public:
		String() : sz(0), p(nullptr) { }
		String(char *cp) :    // String str("hello world")
			sz(strlen(cp)), p(a.allocate(sz))
		{
			std::uninitialized_copy(cp, cp + sz, p);
		}

		String(const String &s) : sz(s.sz), p(a.allocate(s.sz))
		{
			std::uninitialized_copy(s.p, s.p + sz, p);
		}
		
		String(size_t n, char c) : sz(n), p(a.allocate(n)) // String str(n, 't')
		{
			std::uninitialized_fill_n(p, sz, c);
		}

		String &operator=(const String&);
		~String() { if(p) a.deallocate(p, sz); } 
		String &operator=(const char*);   // car = "Studebaker"
		String &operator=(char);          // model = 'T'

		const char *begin()       { return p; }
		const char *begin() const { return p; }
		const char *end()         { return p + sz; }
		const char *end() const   { return p + sz; }

		size_t size() const { return sz;}
		void swap(String &s) { char *tmp = p; p = s.p; s.p = tmp;
			std::size_t cnt = sz; sz = s.sz; s.sz = cnt; }
		
	private:
		std::size_t sz;
		char *p;
		static std::allocator<char> a;
};



#endif
