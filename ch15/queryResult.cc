
#include <set>
#include <string>
#include <memory>
#include <vector>


class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
	public:
		QueryResult(std::string s,
			        std::shared_ptr<std::set<line_no>> p,
					std::shared_ptr<std::vector<std::string>> f):
				sought(s), lines(p), file(f) { }

	private:
		std::string sought;  // 查询单词
		std::shared_ptr<std::set<line_no>> lines;  // 出现的行号
		std::shared_ptr<std::vector<std::string>> files; // 输入文将
};


std::ostream& print(std::ostream &os, const QueryResult &gr)
{
	// 如果找到了单词,打印出现次数和所有出现的位置
	os << qr.sought << " occurs " << qr.lines -> size() << " "
	   << make_plural(qr.lines -> size(), "time", "s") << std::endl;
	// 打印单词出现的每一行
	for(auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file -> begin() + num) << std::endl;
	return os;
}
