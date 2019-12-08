

class ErrCode
{
	public:
		std::string msg() const { return std::string("error"); }
	private:
};


void error_msg(ErrCode e, const std::initializer_list<std::string> &il)
{
	std::cout << e.msg() << ": ";
	for (auto beg = il.begin(); beg != il.end(); ++beg)
	{
		std::cout << *beg << " ";
	}
	std::cout << std::endl;
}


int main(int argc, char *argv[])
{
	std::string expected{"hello"};
	std::string actual{"world"};

	if (expected != actual)
		error_msg(ErrCode(42), {"functionX", expected, actual});
	else
		error_msg(ErrCode(0), {"functionX", "okay"});
	return 0;
}
