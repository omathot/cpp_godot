#pragma once
#ifndef AITEMS_H
# define AITEMS_H

#include <iostream>

class AItems {

private:
	std::string	_type;

protected :
	bool		_stacks;

public:
	AItems(std::string const &type);
	AItems(void);
	virtual ~AItems();

	std::string const &getType() const;
	virtual AItems* clone() const = 0;
	virtual void use(void);
	
};

#endif