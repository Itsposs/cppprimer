#include "folder.h"


void Folder::add_to_Messages(const Folder &f)
{
	for (auto msg : f.msgs)
		msg -> addFldr(this); // 将这个Folder添加到所有Message中
}


void Folder::remove_from_Msgs()
{
	while (!msgs.empty()) // 将这个Folder从它所有Message中删除
		(*msgs.begin()) -> remove(*this);
}


Folder::Folder(const Folder &f) : msgs(f.msgs)
{
	add_to_Messages(f); // 将Folder添加到它所有Message的folder中
}


Folder::~Folder()
{
	remove_from_Msgs();
}


Folder& Folder::operator=(const Folder &f)
{
	remove_from_Msgs();
	msgs = f.msgs;
	add_to_Messages();
	return *this;
}


void Folder::save(Message &m)
{
	folder.insert(&m);
	m.addFldr(*this);
}


void Folder::remove(Message &m)
{
	folder.erase(&m);
	m.remMsg(*this);
}



void Folder::debug_print()
{
	std::cerr << "Folder contains " << msgs.size() 
		      << " messages" << std::endl;
	int ctr = 1;

	for (set<Message*>::iterator m = msgs.begin(); 
		m != msgs.end(); ++m) 
	{
		std::cerr << "Message " << ctr++ << ":\n\t" 
			      << (*m) -> contents << std::endl;
	}
}
