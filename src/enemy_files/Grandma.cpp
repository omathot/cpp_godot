#include "Grandma.h"
#include "Character.h"
#include "EnemyBehaviour.h"
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/classes/area2d.hpp>
// #include "Stat.h"

using namespace godot;
//------------------------------
//----------GODOT BIND----------
//------------------------------
void	Grandma::_bind_methods() {
	// ----------SIGNALS----------
	ADD_SIGNAL(MethodInfo("handleAttack", PropertyInfo(Variant::FLOAT, "damage")));
	ClassDB::bind_method(D_METHOD("handleAttack", "damage"), &Grandma::handleAttack);
	ClassDB::bind_method(D_METHOD("mtakeDamage", "damage"), &Grandma::mtakeDamage);

	// ----------SETTERS N GETTERS----------
	ClassDB::bind_method(D_METHOD("getHealth"), &Grandma::getHealth);
	ClassDB::bind_method(D_METHOD("setHealth", "_health"), &Grandma::setHealth);
	ClassDB::bind_method(D_METHOD("getDamage"), &Grandma::getDamage);
	ClassDB::bind_method(D_METHOD("setDamage", "_damage"), &Grandma::setDamage);
	ClassDB::bind_method(D_METHOD("getSpeed"), &Grandma::getSpeed);
	ClassDB::bind_method(D_METHOD("setSpeed", "_speed"), &Grandma::setSpeed);

	//----------EXPORT----------
	ClassDB::add_property("Grandma", PropertyInfo(Variant::FLOAT, "_health"), "setHealth", "getHealth");
	ClassDB::add_property("Grandma", PropertyInfo(Variant::FLOAT, "_damage"), "setDamage", "getDamage");
	ClassDB::add_property("Grandma", PropertyInfo(Variant::FLOAT, "_speed"), "setSpeed", "getSpeed");
}


//--------------------------------
//----------CONSTRUCTORS----------
//--------------------------------
Grandma::Grandma(void) {
	this->_behavior = new RangedBehaviour();
	this->_health.setValue(50);
	this->_speed.setValue(200);
	this->_damage.setValue(5);
	this->myArea = nullptr;
	this->add_to_group("enemies", true);
}

Grandma::~Grandma() {
	delete this->_behavior;
}


//----------------------------
//----------ON READY----------
//----------------------------
void	Grandma::_ready() {
	Node	*area = find_child("gArea2D");
	this->myArea = Object::cast_to<Area2D>(area);
	if (myArea) {
		myArea->add_user_signal("handleAttack", Array::make(Variant::OBJECT));
		// Callable callable = Callable(this, "handleAttack");
		myArea->connect("body_entered", Callable(this, "handleAttack"));
	}
	// Node *tmp = find_child("Bullet", true, false);
	// if (tmp) {
	// 	tmp->connect("tryDamage", Callable(this, "mtakeDamage"));
	// }


	if (!(Engine::get_singleton()->is_editor_hint())) {
		//Second part of signal, wait until in tree to get_tree()
		Node		*tmp = get_tree()->get_current_scene()->find_child("Character");
		Character	*character = Object::cast_to<Character>(tmp);
		Callable pcallable = Callable(character, "ptakeDamage");
		myArea->connect("handleAttack", pcallable);


		Node	*node = get_tree()->get_current_scene()->find_child("Character", true, true);
		this->charNode = Object::cast_to<Character>(node);
		if (charNode)
			this->_target = this->get_global_position().direction_to(this->charNode->get_global_position());

	}
}


//-----------------------------
//----------PROCESSES----------
//-----------------------------
void	Grandma::_physics_process(double delta) {
	if (this->_behavior)
		this->_behavior->ownPhysics(this);
}

void	Grandma::_process(double delta) {

}


//--------------------------
//----------CUSTOM----------
//--------------------------
//!! this is only happening once, even when staying near Character at the moment !! 
void	Grandma::handleAttack(Node *src) {
	if (Character *tmp = Object::cast_to<Character>(src)) {

		if (tmp->has_method("ptakeDamage")){
			tmp->ptakeDamage(this->getDamage());
			emit_signal("handleAttack", src);
			// src->get_parent()->ptakeDamage(get_parent()->getDamage());
		}
	}
	// else {
	// 	ERR_PRINT("NOPE");
	// }
}

void	Grandma::mtakeDamage(float n) {
	ERR_PRINT("MA TAKING DMG");
	if (this->_health.getValue() - n > 0) {
		this->_health.setValue(this->_health.getValue() - n);
	}
	else {
		queue_free();
	}
}

void	Grandma::whatever() {
	if (_behavior)
		this->_behavior->whatever();
	else
		std::cout << " !! No behaviour defined !!" << std::endl;
}




//-------------------------------------
//----------SETTERS N GETTERS----------
//-------------------------------------
float	Grandma::getHealth() {
	return (this->_health.getValue());
}

void	Grandma::setHealth(float n) {
	this->_health.setValue(n);
}

float	Grandma::getDamage() {
	return (this->_damage.getValue());
}

void	Grandma::setDamage(float n) {
	this->_damage.setValue(n);
}

float	Grandma::getSpeed() {
	return (this->_speed.getValue());
}

void	Grandma::setSpeed(float n) {
	this->_speed.setValue(n);
}

Vector2	Grandma::getTarget() {
	return (this->_target);
}

void	Grandma::setTarget(Vector2 n) {
	this->_target = n;
}

godot::Character* Grandma::getChar() {
	return (this->charNode);
}

void	Grandma::setBehaviour(EnemyBehaviour *behaviour) {
	if (this->_behavior)
		delete (this->_behavior);
	this->_behavior = behaviour;
}