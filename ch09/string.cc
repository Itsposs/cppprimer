


class defstring
{
	public:
		defstring() :
			data(new  char[1]) { *data = '\0'; }
		~defstring() noexcept { delete[] data; }
		defstring(const defstring &rhs) :
			data(new char[rhs.size() + 1]) { ::strcpy(data, rhs.c_str()); }
		defstring(const char *rhs) :
			data(new char[::strlen(rhs) + 1]) { :: strcpy(data, rhs); }
		defstring& operator=(defstring rhs) // c++11
		{
			swap(rhs);
			return this;
		}
		defstring(defstring &&rhs) noexcept // c++11 move ctor
			: data(rhs.data) { rhs.data = nullptr; }
		
	private:
		char *data;
};
