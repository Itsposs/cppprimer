
class Employee
{
	public:
		Employee(std::string &s, int num) :
			name(s), mysn(num) { }
		Employee() { mysn++; }
		Employee(const Employee &rhs) 
		{
			name = rhs.namme;
			mysn = sn++;
		}
		~Employee() { }
	private:
		std::string  name;
		int mysn;
		static int sn;
};


