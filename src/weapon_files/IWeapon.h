#ifndef IWEAPON_H
# define IWEAPON_H

# include <iostream>
// # include "Character.h"

namespace godot {
class Character;

	class IWeapon {

	private:
		// std::string	_type;

	public:
		// IWeapon(const std::string const &type);
		// IWeapon();
		~IWeapon() {};

		// const std::string	&getType() const;

		virtual	void	attack() = 0;
		virtual void	executeAction1(Character &src) = 0;
		// virtual void	executeAction2(Character &src) = 0;
		// virtual void	executeAction3(Character &src) = 0;
		// virtual void	executeAction4(Character &src) = 0;
		// virtual void	executeAction5(Character &src) = 0;
		// virtual void	executeAction6(Character &src) = 0;
		// virtual void	executeAction7(Character &src) = 0;
		// virtual void	executeAction8(Character &src) = 0;
		// virtual void	executeUltimate(Character &src) = 0;

	};

}

#endif