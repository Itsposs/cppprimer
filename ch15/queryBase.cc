

class TextQuery;
class QueryResult;

class Query_base
{
	friend class Query;
	protected:
		using line_no = TextQuery::line_no;  // 用于eval函数
		virtual ~Query_base() = default;
	private:
		//
		virtual QueryResult eval(const TextQuery&) const = 0;
		// rep是表示查询的一个string
		virtual std::string rep() const = 0;
};
