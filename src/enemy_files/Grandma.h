#ifndef GRANDMA_H
# define GRANDMA_H

# include "IMob.h"

namespace godot {

	class Grandma : public IMob {
	// GDCLASS(Grandma, IMob)

	private:

	public:
		Grandma(void);
		~Grandma();

		// void	_bind_methods();

		void	_process(double delta) override;
		void	attack(Character &target) override;
	};

}

#endif