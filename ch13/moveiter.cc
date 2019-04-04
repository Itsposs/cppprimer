



void StrVec::reallocate()
{
	// 分配大小两倍于当前规模的内存空间
	auto newcapacity = size() ? 2 * size() : 1;
	auto first = alloc.allocate(newcapacity);

	// 移动元素
	auto last = std::uninitialized_copy(std::make_move_iterator(begiin()),
		std::make_move_iterator(end()), first);

	free(); // 释放旧内存
	elements = first;  // 更新指针
	first_free = last;
	cap = elements + newcapacity;
}
