
#include <set>
#include <string>
#include <memory>
#include <iostream>


// 定义基类
class Quote {
	public:
		Quote() = default;
		Quote(const Quote&) = default;
		Quote(Quote&&) = default;
		Quote& operator=(const Quote&) = default;
		Quote& operator=(Quote&&) = default;
		Quote(const std::string &book, double sales_price):
			bookNo(book), price(sales_price) { }
		std::string isbn() const { return bookNo; }
		virtual double net_price(std::size_t n) const {
			return n * price;
		}
		virtual ~Quote() = default;
	private:
		std::string bookNo;
	protected:
		double price = 0.0;
};

void testQuote() {
	Quote q1;
	Quote q2{"0-201-70353-X", 3.2};   // c++11
	auto val = q2.isbn();
	std::cout << "val" << val << std::endl;
	int n = 6;
	auto total = q2.net_price(6);
	std::cout << "total:" << total << std::endl;
}

class Bulk_quote : public Quote {
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

//
double Bulk_quote::net_price(size_t cnt) const {
	if(cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

double print_total(std::ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
	   << ret << std::endl;
	return ret;
}

void testBulk_quote() {
	Bulk_quote b1;
	Bulk_quote b2{"0-201-70353-X", 3.2, 6, 0.6};
	auto val = b2.isbn();
	std::cout << "val:" << val << std::endl;
	int n = 8;
	auto total = b2.net_price(8);
	std::cout << "total:" << total << std::endl;
	print_total(std::cout, b2, 9);
}

class Basket {
	public:
		// Basket使用合成的默认构造函数和拷贝控制成员
		void add_item(const std::shared_ptr<Quote> &sale) {
			items.insert(sale);
		}
		// 打印每本书的总价和购物蓝中所有书的总价
		double total_receipt(std::ostream&) const;
	private:
		static bool compare(const std::shared_ptr<Quote> &lhs,
			const std::shared_ptr<Quote> &rhs) {
			return lhs -> isbn() < rhs -> isbn();
		}
		std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items {compare};

};

double Basket::total_receipt(std::ostream &os) const {
	double sum = 0.0;
	for(auto iter = items.cbegin(); iter != items.cend(); 
		iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
}

void testBasket() {
	Basket b1;
	Basket b2;
	b2.add_item(std::make_shared<Quote>("123", 45));
	b2.add_item(std::make_shared<Bulk_quote>("345", 45, 3, .15));
	b2.total_receipt(std::cout);
}

void test() {
	testQuote();
	testBulk_quote();
	testBasket();
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
