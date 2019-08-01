
#include <string>

class Query_base;
class TextQuery;
class QueryResult;

class WordQuery : public Query_base
{
	friend class Query;
	WordQuery(const std::string &s) : query_word(s) { }
	// 具体的类:WordQuery将定义所有继承而来的纯虚函数
	QueryResult eval(const TextQuery &t) const { return t.query(query_word); }


	std::string rep() const { return query_word; }
	std::string query_word;  // 要查找的单词
};



