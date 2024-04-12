#ifndef COINS_H
# define COINS_H

# include "AItems.h"

class Coins : public AItems {

private:
	int	_amount;

public:
	Coins(/* args */);
	~Coins();

	void	use();
	AItems*	clone() const;
	int		getAmount() const;

};

#endif