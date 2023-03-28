#include "Zombie.hpp"

int	main(){
	Zombie	*heap = newZombie("HeapBoy");
	heap->announce();
	randomChump("StackBoy");
	delete(heap);
	return (0);
}