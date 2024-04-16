#ifndef HANDGUNS_H
# define HANDGUNS_H

# include "IWeapon.h"
#include <godot_cpp/variant/dictionary.hpp>

const int	MAX_AMMO = 10;

namespace godot {
	class Vector2;
	class String;
	class Node;
	class Character;

	class Handguns : public IWeapon {

	private:
		Dictionary	preloadedScenes;
		Character	*_owner;
		int		_ammo = MAX_AMMO;
		float	_damage;
		bool	_reloading = false;

	public:;
		Handguns(void);
		~Handguns();

		void	aattack(Vector2 target);
		void	executeAction1(Character &owner, Vector2 target);

		void	specialAction();
		
		Node*	instantiate_scene(const String &path);
		void	preload_scenes();
		void	preload_scene(const String &path);
		void	setOwner(Character *src);
		void	reload();

	};

}

#endif