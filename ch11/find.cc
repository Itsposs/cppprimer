

void test() {
	std::string search_item("Alain de Botton");
	auto entries = authors.count(search_item);
	auto iter = authors.find(search_item);

	while (entries) {
		std::cout << iter -> second << std::endl;
		++iter;
		--entries;
	}
}



