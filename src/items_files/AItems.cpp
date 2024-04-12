#include "AItems.h"

AItems::AItems(std::string const &type) : _type(type) {
	std::cout << this->_type << " AItems constructor called" << std::endl;
}

AItems::~AItems() {
	std::cout << this->_type << " AItems deconstructor called" << std::endl;
}

void	AItems::use() {
	std::cout << "Basic AItem use function, not called from an Item" << std::endl;
}