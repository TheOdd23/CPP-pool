#include "DiamondTrap.hpp"

int	main(){
	DiamondTrap	JeanGuy("Frodon");
	DiamondTrap	Paul(JeanGuy);

	JeanGuy.attack("Gandalf");
	JeanGuy.WhoAmI();
	Paul.WhoAmI();
	JeanGuy.highFivesGuys();
	Paul.guardGate();
	JeanGuy.takeDamage(23);
	JeanGuy.beRepaired(2);
	return (0);
}