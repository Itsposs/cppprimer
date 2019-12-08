
#include <vector>
#include <string>
#include <memory>
#include <iostream>

class Item
{
	public:
		Item(std::vector<int> vec, std::shared_ptr<std::string> p)
			: data(vec), ptr(p) { }
		std::vector<int> retdata() const {  return data; }
	private:
		std::vector<int> data;
		std::shared_ptr<std::string> ptr;
};

int main(int argc, char *argv[])
{
	{
		std::vector<int> vec1{1, 3, 5, 7};
		std::shared_ptr<std::string> ptr1 = std::make_shared<std::string>("hello world!");
		Item item1(vec1, ptr1);
		Item *p = &item1;
		int len1 = sizeof item1;
		int len2 = sizeof item1.retdata();
		int len3 = sizeof p;
		int len4 = sizeof *p;
		Item *&d = p;
		int len5 = sizeof d;
		std::cout << "len1:" << len1 << " len2:" << len2 << " len3:" << len3 
				  << " len4:" << len4 << " len5:" << len5 << std::endl;
	}

	return 0;
}
