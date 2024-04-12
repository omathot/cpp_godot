#ifndef IMOB_H
# define IMOB_H

# include <iostream>
# include <godot_cpp/classes/rigid_body2d.hpp>

namespace godot {
	class Character;

	class IMob : public RigidBody2D {
		// GDCLASS(IMob, RigidBody2D)


	private:
		std::string	_type;

	protected:
		int	_health;
		int	_damage;
		int	_speed;

	public:
		// IMob(void) {};
		IMob(const std::string &type);
		~IMob() {};

		// virtual void	_bind_methods() = 0;

		virtual void	attack(Character &target) = 0;

	};

}


#endif