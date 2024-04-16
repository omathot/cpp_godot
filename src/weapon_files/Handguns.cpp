#include "Handguns.h"
#include "Character.h"
#include "weapon_files/projectiles/Bullet.h"
#include <godot_cpp/godot.hpp>
# include <godot_cpp/classes/resource_loader.hpp>
# include <godot_cpp/classes/packed_scene.hpp>
# include <godot_cpp/classes/scene_tree.hpp>

using namespace godot;


//--------------------------------
//----------CONSTRUCTORS----------
//--------------------------------
Handguns::Handguns(void) {
	std::cout << "Handguns void constructor called" << std::endl;
}

Handguns::~Handguns() {
	std::cout << "Handguns deconstructor called" << std::endl;
}


//--------------------------
//----------ATTACK----------
//--------------------------
void	Handguns::aattack(Vector2 target) {
	preload_scenes();
	if (this->_ammo > 0 && !_reloading) {
		Node	*tmp = instantiate_scene("res://scenes/bullet.tscn");
		if (Bullet	*bullet = Object::cast_to<Bullet>(tmp)) {
			bullet->set_global_position(_owner->get_global_position());
			Vector2 direction = target - bullet->get_global_position();
			float	angle = atan2(direction.y, direction.x) + M_PI;

			bullet->setTarget(target);
			bullet->set_rotation(angle);
			// bullet->setOwner(this->_owner);

			//----------BULLET SIGNALS----------
			Array enemies = this->_owner->get_tree()->get_nodes_in_group("enemies");
			bullet->connect("body_entered", Callable(bullet, "tryDamage"));
			for (int i = 0; i < enemies.size(); i++) {
				Node	*enemy = Object::cast_to<Node>(enemies[i]);
				bullet->connect("tryDamage", Callable(enemy, "mtakeDamage"));
			}
			_owner->get_parent()->add_child(bullet);
			this->_ammo--;
		}
	}
	else
		this->reload();
}


//-----------------------------------
//----------SPECIAL ACTIONS----------
//-----------------------------------
void	Handguns::reload() {
	float	time = 50000;
	this->_reloading = true;
	if (this->_ammo != MAX_AMMO) {
		int	diff = MAX_AMMO - this->_ammo;
		for (int i = 0; i < diff; i++) {
			float time2 = _owner->getTime();
			while (time > 3)
				time--;
			this->_ammo++;
		}
	}
	this->_reloading = false;
}


//----------------------------------
//----------WEAPON ACTIONS----------
//----------------------------------
void	Handguns::executeAction1(Character &src, Vector2 target) {
	this->aattack(target);
}

void	Handguns::specialAction() {
	this->reload();
}


//------------------------------------
//----------SCENE MANAGEMENT----------
//------------------------------------
Node*	Handguns::instantiate_scene(const String& path) {
	if (preloadedScenes.has(path)) {
		Ref<PackedScene> scene = preloadedScenes[path];
		Node* instance = scene->instantiate();
		if (instance)
			return (instance);
	}
	return (nullptr);
}

void	Handguns::preload_scenes() {
	preload_scene("res://scenes/bullet.tscn");
}

void	Handguns::preload_scene(const String &path) {
	Ref<PackedScene> scene = ResourceLoader::get_singleton()->load(path);
	if (scene.is_valid()) {
		preloadedScenes[path] = scene;
	}
}


//-------------------------------------
//----------SETTERS N GETTERS----------
//-------------------------------------
void	Handguns::setOwner(Character *src) {
	this->_owner = src;
}