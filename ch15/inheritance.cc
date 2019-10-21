

#include <string>
#include <iostream>

class Quote {
	public:
		std::string isbn() const;
		virtual double net_price(std::size_t n) const;
	private:
		std::string bookNo;
	protected:
		double price;
		
};

std::string Quote::isbn() const {
	return bookNo;
}

double Quote::net_price(std::size_t n) const {
	return n * price;
}

class Bulk_quote : public Quote {
	public:
		double net_price(std::size_t n) const override;
};


double print_total(std::ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: "
	   << n << " total due: " << ret << std::endl;
	return ret;
}

void test() {
	Quote basic;
	Bulk_quote bulk;
	print_total(std::cout, basic, 20);
	print_total(std::cout, bulk, 20);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
