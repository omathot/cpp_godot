#include "Spawner.h"
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>
# include <godot_cpp/classes/node2d.hpp>
# include <godot_cpp/classes/resource_loader.hpp>
# include <godot_cpp/classes/packed_scene.hpp>
# include <godot_cpp/classes/collision_shape2d.hpp>
# include <godot_cpp/classes/circle_shape2d.hpp>
# include <godot_cpp/classes/capsule_shape2d.hpp>
# include <godot_cpp/classes/rectangle_shape2d.hpp>
#include "Grandma.h"
// #include "timer.hpp"

using namespace godot;

void	Spawner::_bind_methods() {}

Spawner::Spawner(void) {
	preload_scenes();
	this->_time = 0;
	this->_wave = 0;
}

Spawner::~Spawner() {}




//---------------------------
//----------PROCESS----------
//---------------------------
void	Spawner::_process(double delta) {
	if (!(Engine::get_singleton()->is_editor_hint())) {
		this->_time += delta;
		if (this->_time < 20 && this->_wave == 0) {
			for (int i = 0; i < 14; i++) {
				Node	*ma = getGrandma();
				Node	*box = getBoxer();
				this->get_parent()->add_child(ma);
				this->get_parent()->add_child(box);
			}
			this->_wave++;
		}
		if (this->_time < 50 && this->_time > 20 && this->_wave == 1) {
			Ref<RandomNumberGenerator> rng = memnew(RandomNumberGenerator);
			rng->randomize();
			for (int i = 0; i < 24; i++) {
				Node	*ma = getGrandma();
				Node	*box = getBoxer();
				this->get_parent()->add_child(ma);
				this->get_parent()->add_child(box);
			}
			this->_wave++;
		}
	}
}



//------------------------------------
//----------SCENE MANAGEMENT----------
//------------------------------------
void	Spawner::preload_scenes() {
	// List all the scenes to preload
	preload_scene("res://scenes/grandma.tscn");
	preload_scene("res://scenes/boxer.tscn");
	// preload_scene("res://scenes/Enemy2.tscn");
	// Add more scenes as needed
}

void	Spawner::preload_scene(const String &path) {
	Ref<PackedScene> scene = ResourceLoader::get_singleton()->load(path);
	if (scene.is_valid()) {
		preloadedScenes[path] = scene;
	}
}

godot::Node*	Spawner::instantiate_scene(const String& path) {
	if (preloadedScenes.has(path)) {
		Ref<PackedScene> scene = preloadedScenes[path];
		Node* instance = scene->instantiate();
		if (instance)
			return (instance);
	}
	return (nullptr);
}




//--------------------------------
//----------SPAWN EDITOR----------
//--------------------------------

//----------------------------------------
//----------SPAWNER CHANGE SHAPE----------
//----------------------------------------
void	Spawner::changeAreaShapeToRect(Grandma *shape, float width, float height) {
	CollisionShape2D	*toChange = Object::cast_to<CollisionShape2D>(shape->find_child("gArea2D")->find_child("CollisionShape2D"));
	if (toChange) {
		Ref<RectangleShape2D> rectShape = Ref<RectangleShape2D>(memnew(RectangleShape2D));
		rectShape->set_size(Vector2(width, height));
		toChange->set_shape(rectShape);
	}
}

void	Spawner::changeAreaShapeToCapsule(Grandma *shape, float radius, float height) {
	CollisionShape2D	*toChange = Object::cast_to<CollisionShape2D>(shape->find_child("gArea2D")->find_child("CollisionShape2D"));
	if (toChange) {
		Ref<CapsuleShape2D> capsuleShape = Ref<CapsuleShape2D>(memnew(CapsuleShape2D));
		capsuleShape->set_radius(radius);
		capsuleShape->set_height(height);
		toChange->set_shape(capsuleShape);
	}
}

void	Spawner::changeAreaShapeToCircle(Grandma *shape, float radius) {
	CollisionShape2D	*toChange = Object::cast_to<CollisionShape2D>(shape->find_child("gArea2D")->find_child("CollisionShape2D"));
	if (toChange) {
		Ref<CircleShape2D> circleShape = Ref<CircleShape2D>(memnew(CircleShape2D));
		circleShape->set_radius(radius);
		toChange->set_shape(circleShape);
	}
}


//---------------------------------------
//----------SPAWNER GET ENEMIES----------
//---------------------------------------
Grandma*	Spawner::getGrandma() {
	Ref<RandomNumberGenerator> rng = memnew(RandomNumberGenerator);
	rng->randomize();
	Node	*tmp = instantiate_scene("res://scenes/grandma.tscn");
	if (Grandma	*ma = Object::cast_to<Grandma>(tmp)) {
		this->changeAreaShapeToCircle(ma, 400);
		float	x = rng->randf_range(600, 1000);
		float	y = rng->randf_range(0, 500);
		ma->set_position(Vector2(x, y));
		return (ma);
	}
	else {
		return (nullptr);
	}
}

Grandma*	Spawner::getBoxer() {
	Ref<RandomNumberGenerator> rng = memnew(RandomNumberGenerator);
	rng->randomize();
	Node	*tmp = instantiate_scene("res://scenes/boxer.tscn");
	if (Grandma	*box = Object::cast_to<Grandma>(tmp)) {
		this->setMelee(box);
		float	x = rng->randf_range(600, 1000);
		float	y = rng->randf_range(0, 500);
		box->set_position(Vector2(x, y));
		return (box);
	}
	else {
		return (nullptr);
	}
}


//-----------------------------------------
//----------SPAWNER SET BEHAVIOUR----------
//----------------------------------------- 
void	Spawner::setMelee(Grandma *src) {
	EnemyBehaviour	*pass = new MeleeBehaviour();
	src->setBehaviour(pass);
}

void	Spawner::setRanged(Grandma *src) {
	EnemyBehaviour	*pass = new RangedBehaviour();
	src->setBehaviour(pass);
}

void	Spawner::setPassive(Grandma *src) {
	EnemyBehaviour *pass = new PassiveBehaviour();
	src->setBehaviour(pass);
}