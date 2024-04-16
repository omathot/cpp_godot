#include "EnemyBehaviour.h"
// #include "Grandma.h"
#include "Character.h"

using namespace godot;


// -------------MELEE BEHAVIOUR------------
void	MeleeBehaviour::whatever() {
	std::cout << "Melee whatever" << std::endl;
}

void	MeleeBehaviour::ownPhysics(Grandma *ma) {
	if (!(Engine::get_singleton()->is_editor_hint())) {
		//  = this->get_global_position().direction_to(this->charNode->get_global_position());
		ma->setTarget(ma->get_global_position().direction_to(ma->getChar()->get_global_position()));
		ma->set_velocity(ma->getTarget() * ma->getSpeed());
		ma->move_and_slide();
	}
}

// ----------RANGED BEHAVIOUR-----------

void	RangedBehaviour::whatever() {
	std::cout << "Ranged whatever" << std::endl;
}

void	RangedBehaviour::ownPhysics(Grandma *ma) {
	if (!(Engine::get_singleton()->is_editor_hint())) {
		//  = this->get_global_position().direction_to(this->charNode->get_global_position());
		ma->setTarget(ma->get_global_position().direction_to(ma->getChar()->get_global_position() / 2));
		ma->set_velocity(ma->getTarget() * ma->getSpeed());
		ma->move_and_slide();
	}
}

//----------PASSIVE BEHAVIOUR-------------

void	PassiveBehaviour::whatever() {
	std::cout << "Passive whatever" << std::endl;
}

void	PassiveBehaviour::ownPhysics(Grandma *ma) {
	
}