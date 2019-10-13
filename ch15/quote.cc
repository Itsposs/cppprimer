
#include <string>
#include <iostream>

// 定义基类
class Quote
{
	public:
		Quote() = default;
		Quote(const std::string &book, double sales_price):
			bookNo(book), price(sales_price) { }
		std::string isbn() const { return bookNo; }
		virtual double net_price(std::size_t n) const
		{
			return n * price;
		}
		virtual ~Quote() = default;
	private:
		std::string bookNo;
	protected:
		double price = 0.0;
};


class Bulk_quote : public Quote
{
	public:
		Bulk_quote() = default;
		Bulk_quote(const std::string& book, double p, std::size_t qty, double disc):
			Quote(book, p), min_qty(qty), discount(disc) { }
		// 显式覆盖继承而来的函数net_price
		double net_price(std::size_t) const override;
		
	private:
		std::size_t min_qty = 0;
		double discount = 0.0;
};


double Bulk_quote::net_price(size_t cnt) const
{
	if(cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}


double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
	   << ret << std::endl;
	return ret;
}

void test() {
	Quote basic = {"621-15476", 3.6};
	Bulk_quote bulk = {"622-13678", 2.4, 10, 0.6};
	print_total(std::cout, basic, 20);
	print_total(std::cout, bulk, 20);
}


int main(int argc, char *argv[])
{
	test();
	return 0;
}
