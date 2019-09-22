
#ifndef _WINDOWMGR_H_
#define _WINDOWMGR_H_

#include "Screen.h"

class Window_mgr {
 public:
	// 窗口中每个屏幕的编号
	using ScreenIndex = std::vector<Screen>::size_type;
	// 向窗口添加一个Screen,返回它的编号
	ScreenIndex addScreen(const Screen&);
	// 按照编号将指定的Screen重置为空白
	void clear(ScreenIndex);
 private:
	std::vector<Screen> screens{Screen(24, 80, ' ')};
};

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




#endif // Window_mgr.h
