#include "Handguns.h"
#include "Character.h"

using namespace godot;

Handguns::Handguns(void) {
	std::cout << "Handguns void constructor called" << std::endl;
}

// Handguns::Handguns(std::string &type) : IWeapon("Handguns") {

// }

Handguns::~Handguns() {
	std::cout << "Handguns deconstructor called" << std::endl;
}

void	Handguns::attack() {
	if (this->_ammo > 0) {
		this->_ammo--;
	}
	// else
	// 	this->reload();
}

// void	Handguns::reload() {
// 	int	*delay = (int *)10;
// 	if (this->_ammo != MAX_AMMO) {
// 		int	diff = MAX_AMMO - this->_ammo;
// 		for (int i = 0; i < diff; i++) {
// 			this->_ammo++;
// 			wait(delay);
// 		}
// 	}
// }

void	Handguns::executeAction1(Character &src) {
	this->attack();
	src.whateverIWant();
}