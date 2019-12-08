

void test() {
	std::string search_item("Alain de Botton");
	
	// first
	auto entries = authors.count(search_item);
	auto iter = authors.find(search_item);

	while (entries) {
		std::cout << iter -> second << std::endl;
		++iter;
		--entries;
	}
	
	// second
	for (auto beg = authors.lower_bound(search_item),
						end = authors.upper_bound(search_item);
						beg != end; ++beg)
		std::cout << beg -> second << std::endl;

	// third
	for (auto pos = authors.equal_range(search_item);
				pos.first != pos.second; ++pos.first)
		std::cout << pos.first -> second << std::endl;
}



