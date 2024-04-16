#include "Bullet.h"
#include "Grandma.h"
#include "Character.h"

using namespace godot;

void	Bullet::_bind_methods() {
	ADD_SIGNAL(MethodInfo("tryDamage", PropertyInfo(Variant::FLOAT, "damage")));
	ClassDB::bind_method(D_METHOD("tryDamage", "damage"), &Bullet::tryDamage);

	ClassDB::bind_method(D_METHOD("getSpeed"), &Bullet::getSpeed);
	ClassDB::bind_method(D_METHOD("setSpeed", "_health"), &Bullet::setSpeed);

	ClassDB::add_property("Bullet", PropertyInfo(Variant::FLOAT, "_speed"), "setSpeed", "getSpeed");
}

Bullet::Bullet(/* args */) {}

Bullet::~Bullet() {}


//----------------------------
//----------ON READY----------
//----------------------------
void	Bullet::_ready() {
	//----------CONNECT MY SIGNALS----------
	// this->add_user_signal("tryDamage", Array::make(Variant::OBJECT));
	// this->connect("body_entered", Callable(this, "tryDamage"));

	//----------CONNECT TO OTHER NODES----------

	//----------SETUP----------
	this->_direction = (_target - get_position()).normalized();
	this->_distance = 0;
	this->_time = 0;
}


//-----------------------------
//----------PROCESSES----------
//-----------------------------
void	Bullet::_physics_process(double delta) {
	if (!(Engine::get_singleton()->is_editor_hint())) {
		_time += delta;
		set_position(get_position() + _direction * _speed * delta);
		if (_time > 5)
			queue_free();
	}
}

void	Bullet::tryDamage(Node *src) {
	if (src->is_class("godot::Grandma")) {
		ERR_PRINT("it is");
	}
	else {
		ERR_PRINT(src->get_class());
	}
	if (Grandma	*ma = Object::cast_to<Grandma>(src)) {
		ERR_PRINT("TRYING DAMAGE1");
		if (ma->has_method("mtakeDamage")) {
			ma->mtakeDamage(1000);
			emit_signal("tryDamage", src);
		}
	}
}


//-------------------------------------
//----------GETTERS N SETTERS----------
//-------------------------------------
void	Bullet::setTarget(Vector2 target) {
	this->_target = target;	
}

float	Bullet::getSpeed() {
	return (this->_speed);
}

void	Bullet::setSpeed(float n) {
	this->_speed = n;
}

// void	Bullet::setOwner(Character *src) {
// 	this->_owner = src;
// }