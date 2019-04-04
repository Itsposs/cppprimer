

class StrVec
{
	public:
		void push_back(const std::string&);  // 拷贝元素
		void push_back(std::string&&);   // 移动元素
	private:

};


void StrVec::push_back(const std::string &s)
{
	chk_n_alloc(); // 确保有空间容纳新元素

	// 在first_free指向的元素中构造s的一个副本
	alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string &&s)
{
	chk_n_alloc(); // 如果有需要的话为StrVec重新分配内存
	alloc.construct(first_free++, std::move(s));
}


StrVec vec;
std::string s = "some string or another";
vec.push_back(s); // &
vec.push_back("done");  // &&
