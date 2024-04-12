#ifndef HANDGUNS_H
# define HANDGUNS_H

# include "IWeapon.h"

const int	MAX_AMMO = 10;

namespace godot {

	class Handguns : public IWeapon {

	private:
		int		_ammo = MAX_AMMO;
		float	_damage;

	public:
		// Handguns(std::string &type);
		Handguns(void);
		~Handguns();

		void	attack();
		void	executeAction1(Character &owner);
		// void	reload();

	};

}

#endif