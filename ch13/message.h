#ifndef _MESSAGE_H
#define _MESSAGE_H


#include <iostream>
#include <set>


class Folder
{
	public:
		Folder();
		Folder(const Folder&);
		~Folder();
		Folder& operator=(const Folder&);
	private:
		std::set<Message*> msgs;		
		void addMsg(Message &m);
		void remMsg(Message &m);
};




class Message
{
		friend class Folder;
	public:
		// folders被隐式初始化为空集合
		explicit Message(const std::string &str = ""):
			contents(str) { }
		// 拷贝控制成员,用来管理指向本Message的指针
		Message(const Message&);
		Message& operator=(const Message&);
		~Message();
		// 从给定Folder集合中添加/删除本Message
		void save(Folder&);
		void remove(Folder&);
	private:
		std::string contents; // 实际消息文本
		std::set<Folder*> folders;  // 包含本Message的Folder

		void add_to_Folders(const Message&);
		void remove_from_Folders();
};

#endif // message.h
