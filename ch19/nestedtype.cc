


class TextQuery {
	public:
		class QueryResult;
	private:
};


class TextQuery::QueryResult {
	friend std::ostream& 
				 print(std::ostream&, const QueryResult&);
	public:
		// 无需定义QueryResult::line_no
		QueryResult(std::string,
								std::shared_ptr<std::set<line_no>>,
								std::shared_ptr<std::vector<std::string>>);
	private:
		static int static_mem;
};

TextQuery::QueryResult::QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>> p,
		std::shared_ptr<std::vector<std::string>> f) :
	sought(s), lines(p), file(f) { }

int TextQuery::QueryResult::static_mem = 1024;


