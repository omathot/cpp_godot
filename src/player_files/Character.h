#pragma once
#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include <godot_cpp/classes/character_body2d.hpp>
# include <godot_cpp/classes/input_event_key.hpp>
# include <godot_cpp/classes/input_event_mouse_button.hpp>

// class	Iweapon;

namespace godot {
	class	Stat;
	class	Area2D;
	class	IWeapon;

	class Character : public CharacterBody2D {
		GDCLASS(Character, CharacterBody2D)

	private:
		String	_name;
		IWeapon	*_weapon;
		Vector2	_target;
		Area2D	*myArea;
		bool	moveHeld;
		float	_damage;
		float	_time;

	protected:
		int		_health;
		int		_speed;
		// float	_angle;
		// float	_velocity;

	public:
		// Character(const Character &src);
		Character(void);
		~Character();
		
		static void		_bind_methods();
		void			_physics_process(double _delta) override;
		void			_input(const Ref<InputEvent> &event) override;
		void			_ready() override;
		
		void			setWeapon(IWeapon *src);
		void			performAction();
		// void			outputInventory();
		void			whateverIWant();
		void			ptakeDamage(float dmg);

		float			getSpeed();
		void			setSpeed(float n);
		float			getDamage();
		void			setDamage(float n);
		float			getTime();

	};
}

#endif