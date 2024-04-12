#pragma once
#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include <godot_cpp/classes/character_body2d.hpp>
# include "AItems.h"
# include "IWeapon.h"
// class	Iweapon;


namespace godot {

	class Character : public CharacterBody2D {
		GDCLASS(Character, CharacterBody2D)

	private:
		std::string	_name;
		AItems		*_inventory[10];
		IWeapon		*_weapon;

	protected:
		int		_health;
		int		_speed;
		float	_angle;
		float	_velocity;
		Vector2	_coordinates;
		float	_damage;

	public:
		Character(const std::string &name);
		Character(const Character &src);
		Character(void);
		~Character();
		
		static void		_bind_methods();
		
		void			setWeapon(IWeapon *src);
		void			performAction();
		void			outputInventory();
		void			whateverIWant();
		void			takeDamage(int damage);

	};
}

#endif