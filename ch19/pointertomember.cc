

class Screen{
	public:
		typedef std::string::size_type pos;
		Screen() = default;
		char get_cursor() const { return contents[cursor]; }
		char get() const;
		char get(pos ht, pos wd) const;
		static const std::string Screen::*data() { return &Screen::contents; }
	private:
		std::string contents;
		pos cursor;
		pos height, width;
};


void test() {
	const std::string Screen::*pdata;
	pdata = &Screen::contents;
	
	Screen myScreen, *pScreen = &myScreen;
	auto s = myScreen.*pdata;
	s = pScreen -> *pdata;

	const std::string Screen::*pdata = Screen::data();
	auto s = myScreen.*pdata;

}
