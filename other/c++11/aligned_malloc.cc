
#include <cassert>

inline void* 
aligned_malloc(size_t size, size_t alignment) {
	// xxxxxx0 & xxxxxx1
	assert(!(alignment & (alignment - 1)));
	size_t offset = sizeof(void*) + (--alignment);

	char *p = static_cast<char*>(malloc(offset + size));
	if (!p) return nullptr;

	void *r = reinterpret_cast<void*>(reinterpret_cast<size_t>
			(p + offset) & (~alignment));

	static_cast<void**>(r)[-1] = p;
	return r;
}

inline void aligned_free(void *p) {
	free(static_cast<void**>(p)[-1]);
}


