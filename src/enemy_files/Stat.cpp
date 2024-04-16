#include "Stat.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;


void	Stat::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("getValue"), &Stat::getValue);
	godot::ClassDB::bind_method(D_METHOD("setValue", "_value"), &Stat::setValue);
	godot::ClassDB::add_property("Stat", PropertyInfo(Variant::FLOAT, "value"), "setValue", "getValue");
}

Stat::Stat(void) {

}

Stat::~Stat() {

}

float	Stat::getValue() const {
	return (this->_value);
}

void	Stat::setValue(float n) {
	this->_value = n;
}