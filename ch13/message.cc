#include "message.h"


Message& Message::operator=(const Message &rhs)
{
	// 通过先删除指针再插入它们来处理自赋值情况
	remove_from_Folders();  // 更新已有Folder
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);   // 将本Message添加到那些Folder中
	return *this;
}

void Message::remove_from_Folders()
{
	for (auto f : folders)  // 对folders中每个指针
		f -> remMsg(this);  // 从该Folder中删除本Message
}

Message::~Message()
{
	remove_from_Folders();
}


void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

// 将本Message添加到指向m的Folder中
void Message::add_to_Folders(const Message &m)
{
	for(auto f : m.folders)
		f -> addMsg(this);
}


Message::Message(const Message &m):
	contents(m.contents)
{
	add_to_Folders(m);  // 将本消息添加到指向m的Folder中
}


void Message::debug_print()
{
	std::cerr << "Message:\n\t" << contents << std::endl;
	std::cerr << "Appears in " << folders.size() << " Folders" << std::endl;
}

