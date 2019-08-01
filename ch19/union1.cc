

class Token
{
	public:
		// 因为union含有一个string成员,所以Token必须定义拷贝控制成员
		// 定义移动构造函数和移动赋值运算符的任务留待本节练习完成
		Token() : tok(INT), ival{0} { }
		Token(const Token &t) : tok(t.tok) { copyUnion(t); }
		Token &operator=(const Token&);
		// 如果union含有一个string成员,则我们必须销毁它
		~Token() { if(tok == STR) sval.~string(); }
		// 下面的赋值运算符负责设置union的不同成员
		Token &operator=(const std::string&);
		Token &operator=(char);
		Token &operator=(int);
		Token &operator=(double);
	private:
		enum {INT, CHAR, DBL, STR} tok; // 判别式
		union { // 匿名union
			char   cval;
			int    ival;
			double dval;
			std::string sval;
		}; // 每个Token对象含有一个该未命名union类型的未命名成员
		// 检查判别式,然后酌情拷贝union成员
		void copyUnion(const Token&)
};

Token &Token::operator=(int i)
{
	if(tok == STR)
		sval.~string(); // 如果当前存储的是string,释放它
	ival = i;
	tok = INT;          // 更新判别式
	return *this;
}

Token &Token::operator=(char c)
{
	if(tok == STR)
		sval.~string(); // 如果当前存储的是string,释放它
	cval = c;
	tok = CHAR;          // 更新判别式
	return *this;

}
Token &Token::operator=(double d)
{
	if(tok == STR)
		sval.~string(); // 如果当前存储的是string,释放它
	dval = d;
	tok = DBL;          // 更新判别式
	return *this;

}
Token &Token::operator=(const std::string &s)
{
	if(tok == STR)  // 如果当前存储的是string,可以直接赋值
		sval = s;
	else
		new(&sval) std::string(s); // 否则需要先构造一个string
	tok = STR;    // 更新判别式
	return *this;
}

void Token::copyUnion(const Token &t)
{
	switch(t.tok)
	{
		case Token::INT: ival = t.ival; break;
		case Token::CHAR:cval = t.cval; break;
		case Token::DBL: dval = t.dval; break;
		// 要想拷贝一个string可以使用定位new表达式构造它
		case Token::STR: new(&sval) std::string(t.sval); break;
	}
}


Token &Token::operator=(const Token &t)
{
	// 如果此对象的值是string而t的值不是,则我们必须释放原来的string
	if(tok == STR && t.tok != STR) sval.~string();
	if(tok == STR && t.tok == STR)
		sval = t.sval;  // 无须构造一个新string
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}


