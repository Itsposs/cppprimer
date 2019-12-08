


class Bulk_quote : public Disc_quote {
	public:
		// 继承Disc_quote的构造函数
		using Disc_quote::Disc_quote;
		Bulk_quote(const std::sstring& book, double price,
				std::size_t qty, double disc) :
			Disc_quote(book, price, qty, disc) { }
		double net_price(std::size_t) const;
};
