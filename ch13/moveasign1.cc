
class StrVec
{
	public:
		StrVec(StrVec&&) noexcept;
	private:
		
};


StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
	// 直接检测自赋值
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free; // 从rhs接管资源
		cap = rhs.cap;

		// 将rhs置于可析构状态
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}


