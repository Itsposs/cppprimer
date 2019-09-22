

#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <vector>
#include <string>


class Screen {
	friend class Window_mgr;
	//friend void Window_mgr::clear(ScreenIndex);
 public:
	// using pos = std::string::size_type; 
	typedef std::string::size_type pos;
	Screen() = default;

	// cursor被其类内初始值初始化为0
	Screen(pos ht, pos wd, char c)
		: height(ht),
		  width(wd),
		  contents(ht * wd, c) { }
	Screen& set(char);
	Screen& set(pos, pos, char);
	Screen& display(std::ostream& os) { do_display(os); return *this; }
	const Screen& display(std::ostream& os) const { do_display(os); return *this; }

	char get() const { return contents[cursor]; }
	void some_member() const { ++access_ctr; }
	inline char get(pos ht, pos wd) const;
	Screen& move(pos r, pos c); 
 private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	mutable size_t access_ctr;
	void do_display(std::ostream &os) const { os << contents; }
};

inline Screen& Screen::set(char c) { 
	contents[cursor] = c; 
	return *this; 
}
inline Screen& Screen::set(pos r, pos col, char ch) { 
	contents[r * width + col] = ch; 
	return *this;
}
inline Screen& Screen::move(pos r, pos c) {
	
	pos row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos r, pos c) const {

	pos row = r * width;
	return contents[row + c];
}



#endif
