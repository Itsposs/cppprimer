
#include <iostream>

// sse_t 类型的每个对象将对齐到16字节边界
struct alignas(16) sse_t
{
	float sse_data[4];
};

// 数组 "cacheline" 将对齐到128字节边界
alignas(128) char cacheline[128];

int main(int argc, char *argv[])
{
	int len = sizeof(sse_t);
	std::cout << "len:" << len << std::endl;

	return 0;
}
