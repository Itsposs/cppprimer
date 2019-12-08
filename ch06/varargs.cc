
#include <cstdio>

#define LOG(...) { \
	fprintf(stderr, "%s: Line %d:\t", __FILE__, __LINE__); \
	fprintf(stderr, __VA_ARGS__); \
	fprintf(stderr, "\n"); \
}


int main(int argc, char *argv[])
{
	int val{5};
	LOG("value = %d", val);

	return 0;
}
