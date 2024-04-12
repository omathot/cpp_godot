#include "Grandma.h"
#include "Character.h"

using namespace godot;

Grandma::Grandma(void) : IMob("Grandma") {
	this->_health = 50;
	this->_speed = 10;
	this->_damage = 5;
}

Grandma::~Grandma() {

}

void	Grandma::attack(Character &target) {
	if (&target) {
		target.takeDamage(this->_damage);
	}
}

void	Grandma::_process(double delta) {
	// Character *bro = get_node(NodePath("root/Main/Character"));
	Character	*bro = get_node<Character>(NodePath("root/Main/Character"));
	Vector2 charPos = bro->get_position();
	Vector2 selfPos = this->get_position();
	selfPos.move_toward(charPos, delta);
	
	// tests
	// double angle = get_angle_to(charPos);
	// Viewport *screenXY = get_viewport();
	// Node	*test = new Node();
	// add_child(test);
}