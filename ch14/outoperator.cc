#include <iostream>
#include <string>


class Sales_data
{
	friend std::ostream &operator << (std::ostream &os, const Sales_data &item);
	public:
		Sales_data() = default;
		Sales_data(const std::string &s, unsigned n, double p) :
			bookNo(s), units_sold(n), revenue(p * n) { }
		std::string isbn() const { return bookNo; }

	private:
		double avg_price() const
		{ return units_sold ? revenue / units_sold : 0; }
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
};




std::ostream &operator << (std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

int main(int argc, char *argv[])
{
	Sales_data data = {"ISBN-20019-06-07", 8, 16.30};
	std::cout << data << std::endl;
	return 0;
}


