#include <iostream>
#include <chrono>
#include <string>


void replace1(std::string &s,const std::string &oldVal,
	const std::string &newVal)
{
	auto len = oldVal.size();  
	if(!len)
		return;
	auto iter = s.begin();
	while(iter < s.end()) // 替换的字符串为空,返回.
	{
		auto iter1 = iter;
		auto iter2 = oldVal.begin();
		// s中iter1开始的子串每个字符都与oldVal相同
		while(iter2 != oldVal.end() && *iter1 == *iter2)
		{
			iter1++;
			iter2++;
		}
		if(iter2 == oldVal.end())
		{
			iter = s.erase(iter,iter1);
			if(newVal.size())
			{
				iter2 = newVal.end();
				do
				{
					// 有后向前逐个插入newVal中的字符
					iter2--;
					iter = s.insert(iter,*iter2);
				}while(iter2 > newVal.begin());
			}
			// 迭代器移动到新插入内容之后
			iter += newVal.size(); 
		}
		else
		{
			iter++;
		}
	}
}

void replace2(std::string &s,const std::string &oldVal,
	const std::string &newVal)
{
	int p = 0;
	while((p = s.find(oldVal,p)) != std::string::npos)
	{
		s.replace(p,oldVal.size(),newVal);
		p += newVal.size();
	}
}


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
