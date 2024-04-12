#include "Character.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void	Character::_bind_methods() {
	// ClassDB::bind_method(D_METHOD("getName"), &Character::getName);
	// ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &GDExample::set_amplitude);
	// ClassDB::add_property("GDExample", PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");
}

Character::Character() : _name("") {
	this->_health = 100;
	this->_speed = 10;
	this->_angle = 0;
	this->_velocity = 0;
	this->_damage = 40;
	this->_coordinates = Vector2(0, 0);
	for (int i = 0; i < 10; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << this->_name << " Character void constructor called" << std::endl;
}

Character::Character(const Character &src) : _name(src._name) {
	_health = 100;
	_speed = 10;
	_angle = 0;
	_velocity = 0;
	_damage = 40;
	_coordinates = Vector2(0, 0);
	for (int i = 0; i < 10; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << this->_name << " Character copy constructor called" << std::endl;
}

Character::Character(const std::string &name) : _name(name) {
	std::cout << this->_name << " Character std::string constructor called" << std::endl;
}

Character::~Character() {
	std::cout << this->_name << " Character deconstructor called" << std::endl;
	for (int i = 0; i < 10; i++) {
		delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
}

void	Character::outputInventory() {
	for (int i = 0; i < 10; i++) {
		if (this->_inventory[i])
			std::cout << this->_inventory[i]->getType() << " in " << this->_name << "'s Inventory at index:" << i << std::endl;
	}
}

void	Character::setWeapon(IWeapon *src) {
	_weapon = src;
}

void	Character::performAction() {
	if (this->_weapon) {
		this->_weapon->executeAction1(*this);
	}
}

void	Character::whateverIWant() {
	
}

void	Character::takeDamage(int damage) {
	this->_health -= damage;
}
