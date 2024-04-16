#ifndef ENEMEYBEHAVIOUR_H
# define ENEMEYBEHAVIOUR_H

# include <iostream>
# include <godot_cpp/classes/engine.hpp>
# include "Grandma.h"
// class	Grandma;

//Interface
class EnemyBehaviour {
public:
	virtual ~EnemyBehaviour() {};
	virtual void	whatever() = 0;
	virtual void	ownPhysics(godot::Grandma *ma) = 0;
};

//Melee
class MeleeBehaviour : public EnemyBehaviour {
public:
	void	whatever() override;
	void	ownPhysics(godot::Grandma *ma) override;
};

//Ranged
class RangedBehaviour : public EnemyBehaviour {
public:
	void	whatever() override;
	void	ownPhysics(godot::Grandma *ma) override;
};

//Passive
class PassiveBehaviour : public EnemyBehaviour {
public:
	void	whatever() override;
	void	ownPhysics(godot::Grandma *ma) override;
};


#endif