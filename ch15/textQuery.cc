
#include <fstream>
#include <memory>
#include <vector>
#include <string>

class QueryResult;

class TextQuery
{
	public:
		using line_no = std::vector<std::string>::size_type;
		TextQuery(std::ifstream&);
		QueryResult query(const std::string&) const;
	private:
		std::shared_ptr<std::vector<std::string>> file; // 输入文件
		// 每个单词到它所在的行号的集合的映射
		std::map<std::string, std::shared_ptr<std::set<line_no>>> wm; 
};

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>)
{
	std::string text;
	while(getline(is, text))
	{
		file -> push_back(text);
		// 计算的vector的元素个数,也即文本第一行
		int n = file -> size() - 1;
		std::istringstream line(text);
		std::string word;
		while(line >> word)
		{
			auto &lines = wm[word];
			if(!lines)
				lines.reset(new set<line_no>);  // 分配一个新的set
			lines -> insert(n);
		}
	}
}


QueryResult TextQuery::query(const std::string &sought) const
{
	// 如果未找到sought,我们将返回一个指向此set的指针
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

	// 使用find而不是下标运算符来查找单词,避免将单词添加到wm中!
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file); // 未找到
	else
		return QueryResult(sought, loc -> second, file);
}
























