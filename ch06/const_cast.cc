

const std::string& shorterString(const std::string &s1,
	const std::string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}


std::string & shorterString(std::string &s1, std::string &s2)
{
	auto &r = shorterString(const_cast<const std::string&>(s1),
		const_cast<const std::string&>(s2));
	return const_cast<std::string&>(r);
}



