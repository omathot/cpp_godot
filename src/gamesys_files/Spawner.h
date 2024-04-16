#ifndef SPAWNER_H
# define SPAWNER_H

# include <iostream>
# include "EnemyBehaviour.h"
# include <godot_cpp/classes/node.hpp>
// # include <ref.hpp>
# include <godot_cpp/godot.hpp>
// # include "Grandma.h"

namespace godot {
	class CollisionShape2D;

	class Spawner : public Node {
		GDCLASS(Spawner, Node)

	private:
		Dictionary	preloadedScenes;
		float		_time;
		int			_wave;
		
		
	public:
		Spawner();
		~Spawner();

		static void	_bind_methods();
		void		_process(double _delta) override;

		void	preload_scenes();
		void	preload_scene(const String &path);
        Node*	instantiate_scene(const String& path);
		void	changeAreaShapeToCircle(Grandma *collision_shape, float radius);
		void	changeAreaShapeToCapsule(Grandma *collision_shape, float radius, float height);
		void	changeAreaShapeToRect(Grandma *collision_shape, float width, float height);
		
		Grandma	*getGrandma();
		Grandma	*getBoxer();

		void	setMelee(Grandma *src);
		void	setRanged(Grandma *src);
		void	setPassive(Grandma *src);

	};

}



#endif