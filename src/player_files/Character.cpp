#include "Character.h"
#include "Stat.h"
#include "Handguns.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/camera2d.hpp>

using namespace godot;

//----------------------------------
//----------GODOT BINDINGS----------
//----------------------------------
void	Character::_bind_methods() {
	ClassDB::bind_method(D_METHOD("ptakeDamage"), &Character::ptakeDamage);

	ClassDB::bind_method(D_METHOD("getSpeed"), &Character::getSpeed);
	ClassDB::bind_method(D_METHOD("setSpeed", "_speed"), &Character::setSpeed);
	ClassDB::add_property("Character", PropertyInfo(Variant::FLOAT, "_speed"), "setSpeed", "getSpeed");
}


//--------------------------------
//----------CONSTRUCTORS----------
//--------------------------------
Character::Character() {
	this->_health = 100;
	this->_speed = 400;
	this->_time = 0;
	// this->_angle = 0;
	// this->_velocity = 0;
	this->_damage = 40;
	this->_target = this->get_global_position();
	this->add_to_group("Friendly", true);
	this->myArea = nullptr;
	this->_weapon = new Handguns();
	this->_weapon->setOwner(this);
	// for (int i = 0; i < 10; i++) {
	// 	this->_inventory[i] = NULL;
	// }
}

Character::~Character() {
	// for (int i = 0; i < 10; i++) {
	// 	delete this->_inventory[i];
	// 	this->_inventory[i] = NULL;
	// }
}


//----------------------------
//----------ON READY----------
//----------------------------
void	Character::_ready() {
	this->_target = this->get_global_position();
	Node *tmp = find_child("Area2D");
	this->myArea = Object::cast_to<Area2D>(tmp);
	tmp = find_child("gArea2D", true, false);
	if (tmp) {
		Callable callable = Callable(this, "ptakeDamage");
		tmp->connect("handleAttack", callable);
	}
}


//---------------------------------
//----------MANAGE INPUTS----------
//---------------------------------
void	Character::_input(const Ref<InputEvent> &event) {
	if (const InputEventMouseButton *mouse_event = Object::cast_to<const InputEventMouseButton>(*event)) {
		if (mouse_event->get_button_index() == MOUSE_BUTTON_RIGHT && mouse_event->is_pressed()) {
			this->moveHeld = true;
			Camera2D	*camera = Object::cast_to<Camera2D>(find_child("Camera2D"));
			this->_target = camera->get_global_mouse_position();
		}
	}
	if (const InputEventMouseButton *mouse_event = Object::cast_to<const InputEventMouseButton>(*event)) {
		if (mouse_event->get_button_index() == MOUSE_BUTTON_RIGHT && mouse_event->is_released())
			this->moveHeld = false;
	}
	if (const InputEventKey *keyEvent = Object::cast_to<const InputEventKey>(*event)) {
		if (keyEvent->get_keycode() == KEY_Q && keyEvent->is_pressed()) {
			Camera2D	*camera = Object::cast_to<Camera2D>(find_child("Camera2D"));
			Vector2 sTarget = camera->get_global_mouse_position();
			this->_weapon->executeAction1(*this, sTarget);
		}
	}
}


//-----------------------------
//----------PROCESSES----------
//-----------------------------
void	Character::_physics_process(double delta) {
	this->_time += delta;
	if (!(Engine::get_singleton()->is_editor_hint())) {
		this->set_velocity(this->get_global_position().direction_to(this->_target) * this->_speed);
		if (this->moveHeld) {
			Camera2D	*camera = Object::cast_to<Camera2D>(find_child("Camera2D"));
			this->_target = camera->get_global_mouse_position();
		}
		if (this->get_global_position().distance_to(this->_target) > 10)
			move_and_slide();
	}
}


//----------------------------------
//----------WEAPON ACTIONS----------
//----------------------------------
void	Character::performAction() {
	// if (this->_weapon) {
	// 	this->_weapon->executeAction1(*this);
	// }
}

void	Character::whateverIWant() {}


//---------------------------
//----------SIGNALS----------
//---------------------------
void	Character::ptakeDamage(float dmg) {
	// ERR_PRINT("taking damage");
	if ((this->_health - dmg) > 0) {
		this->_health -= dmg;
		std::cout << this->_health << std::endl;
	}
	else {
		this->_health = 0;
		// get_tree()->quit();
		// get_tree()->quit();
	}
}


//-------------------------------------
//----------SETTERS N GETTERS----------
//-------------------------------------
float	Character::getSpeed() {
	return (this->_speed);
}

void	Character::setSpeed(float n) {
	this->_speed = n;
}

void	Character::setWeapon(IWeapon *src) {
	_weapon = src;
}

float	Character::getDamage() {
	return (this->_damage);
}

void	Character::setDamage(float n) {
	this->_damage = n;
}

float	Character::getTime() {
	return (this->_time);
}