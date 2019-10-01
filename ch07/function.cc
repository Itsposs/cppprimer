
#include <string>
#include <iostream>


class Window_mgr {
	public:
		void clear();
	private:
};


class Screen {
	friend void Window_mgr::clear();
	public:
		Screen() = default;
		Screen(unsigned ht, unsigned wd, char c)
			: height(ht), width(wd), contents(ht * wd, c) { }
	private:
		unsigned height = 0, width = 0;
		unsigned cursor = 0;
		std::string contents;
};

void Window_mgr::clear() {
	Screen myscreen(10, 2, 'X');
	std::cout << "before contents: ";
	std::cout << myscreen.contents << std::endl;
	myscreen.contents = "";
	std::cout << "after contents: ";
	std::cout << myscreen.contents << std::endl;
}

int main(int argc, char *argv[]) {
	
	Window_mgr mgr;
	mgr.clear();

	return 0;
}
