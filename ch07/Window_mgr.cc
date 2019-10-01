
#include "Window_mgr.h"


Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s) {
	screens.push_back(s);
	return screens.size() - 1;
}

void Window_mgr::clear(ScreenIndex i) {
	// s是一个Screen的引用,指向我们想清空的那个屏幕
	Screen &s = screens[i];
	// 将那个选定的Screen重置为空白
	s.contents = std::string(s.height * s.width, ' ');
}



