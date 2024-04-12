#include "Coins.h"


Coins::Coins(void) : AItems("coin") {
	this->_stacks = true;
	std::cout << "Coin constructor called" << std::endl;
}

Coins::~Coins() {
	std::cout << "Coin destructor called" << std::endl;
}

void Coins::use() {
	std::cout << "$$ Used coin $$" << std::endl;
}

AItems*	Coins::clone() const {
	AItems *to_return = new Coins();
	return (to_return);
}

int	Coins::getAmount() const {
	return (this->_amount);
}