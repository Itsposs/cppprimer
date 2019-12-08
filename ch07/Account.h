

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account {
 public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
 private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
};

void Account::rate(double newRate) {
	interestRate = newRate;
}

#endif // Account.h
