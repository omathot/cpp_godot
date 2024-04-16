#ifndef BULLET_H
# define BULLET_H

# include <iostream>
# include <godot_cpp/classes/area2d.hpp>

namespace godot {
	class Character;

	class Bullet : public Area2D {
		GDCLASS(Bullet, Area2D)
	
	private:
		Vector2		_target;
		float		_speed = 800;
		float		_time;
		Vector2		_direction;
		float		_distance;
		// Character	*_owner;

	public:
		Bullet(/* args */);
		~Bullet();

		static void	_bind_methods();
		void		_physics_process(double delta) override;
		void		_ready() override;

		void		tryDamage(Node *src);

		void		setTarget(Vector2 target);
		float		getSpeed();
		void		setSpeed(float n);
		// void		setOwner(Character *src);
	
	};
}

#endif