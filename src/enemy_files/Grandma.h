#ifndef GRANDMA_H
# define GRANDMA_H

# include <iostream>
# include <godot_cpp/classes/character_body2d.hpp>
# include <godot_cpp/classes/scene_tree.hpp>
# include <godot_cpp/classes/viewport.hpp>
# include <godot_cpp/classes/engine.hpp>
# include <godot_cpp/godot.hpp>
# include "Stat.h"
// # include "EnemyBehavior.h"

class	EnemyBehaviour;

namespace godot {
	// class	Stat;
	class	Node;
	class	Character;
	class	Area2D;

	class Grandma : public CharacterBody2D {
		GDCLASS(Grandma, CharacterBody2D)

	private:
		EnemyBehaviour	*_behavior;

		Stat		_health;
		Stat		_speed;
		Stat		_damage;
		Vector2		_target;
		Character	*charNode;
		Area2D		*myArea;

	public:
		Grandma(void);
		~Grandma();
		
		static void		_bind_methods();
		void			_process(double _delta) override;
		void			_physics_process(double _delta) override;
		void			_ready() override;
		
		void			whatever();
		void			handleAttack(Node *src);
		void			mtakeDamage(float n);

		float			getHealth();
		void			setHealth(float n);
		float			getDamage();
		void			setDamage(float n);
		float			getSpeed();
		void			setSpeed(float n);
		Vector2			getTarget();
		void			setTarget(Vector2 n);
		Character*		getChar();
		void			setBehaviour(EnemyBehaviour *behaviour);
	};
}

#endif