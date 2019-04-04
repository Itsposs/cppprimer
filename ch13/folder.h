#ifndef _FOLDER_H_
#define _FOLDER_H_

#include <set>

class Folder
{
		friend Message;
		friend void swap(Message&, Message&);
		//friend class Message;
	public:
		Folder() { }
		Folder(const Folder&);
		~Folder();
		Folder& operator=(const Folder&);
		void save(Message&);
		void remove(Message&);
		void debug_print();
	private:
		std::set<Message*> msgs;
		// 工具函数
		void add_to_Messages(const Folder &f);
		void remove_from_Msgs();
		void addMsg(Message &m) { msgs.insert(m); }
		void remMsg(Message &m) { msgs.erase(m); }
};





#endif // folder.h
