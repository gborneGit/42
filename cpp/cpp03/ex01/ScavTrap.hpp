#ifndef _ScavTrap_hpp_
#define _ScavTrap_hpp_

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);
		ScavTrap &	operator=(ScavTrap const & src);

		void	attack(const std::string & target);
		void	guardGate(void);
};

#endif