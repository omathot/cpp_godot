#ifndef STAT_H
# define STAT_H

# include "iostream"
# include <godot_cpp/classes/object.hpp>
namespace godot {

	class Stat : public Object {
		GDCLASS(Stat, Object)
	
	protected:
		float	_value;

	public:
		Stat(void);
		~Stat();

		static void	_bind_methods();
		float	getValue() const;
		void	setValue(float n);
	};

}



#endif