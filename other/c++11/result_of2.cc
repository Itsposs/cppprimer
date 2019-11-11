


template <typename Fn>
auto GroupBy(const std::vector<Person> &vt, const Fn &keySelector) ->
	std::mutimap<decltype(keySelector((Person&)nullptr)), Person> {
	
	typedef decltype(keySelector(*(Person*)nullptr)) key_type;
	std::mutimap<key_type, Person> map;
	std::for_each(vt.begin(), vt.end(), [&](const Person &person){
			map.insert(std::make_pair(keySelector(person), person));
			});
	return map;
}


template <typename Fn>
std::mutimap<typename std::result_of<Fn(Person)>::type, Person>
	GroupBy(const std::vector<Person> &vt, Fn &&keySelector) {
	
	typedef std::result_of<Fn(Person)>::type key_type;
	std::mutimap<key_type, Person> map;
	std::for_each(vt.begin(), vt.end(), [&](const Person &person){
			map.insert(std::make_pair(keySelector(person), person));
			});
	return map;
}
