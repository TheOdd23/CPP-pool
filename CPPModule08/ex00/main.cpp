#include "easyfind.hpp"

//Vectors: Arrays qui peuvent changer dynamiquement de taille.
//Alloue de la memoire supplémentaire pour éviter de realloc à chaque ajout.
//Prend plus de place dans la mémoire, mais offre une plus grande vitesse et efficacité de "storage" et d'agrandissement

//Lists: Permet de plus facilement jouer avec ses éléments, car ils peuvent être ajoutés ou détruit n'importe où dans la séquence.
//Peut avoir des iterateurs qui vont dans les deux sens.
//Downside, ne peut accéder à un élément à la position X sans partir du début ou de la fin de la liste.

//Deque (double end queues): Très similaire au vector, mais plus complexes.
//Plus efficace pour l'ajout de la destruction d'éléments que le Vector.
//Des éléments peuvent être ajoutés au debut et la fin de la queue.
//Leur mémoire peut être divisée en différents "chunks", contrairement au Vector dont la mémoire doit être linéaire.

int main(void){
	std::vector<int> vect;
	std::vector<int>::iterator vect2;
	std::deque<int> deq1;;
	std::deque<int>::iterator deq2;
	std::list<int> list1;
	std::list<int>::iterator list2;
	for (int i = 1; i < 30; i++)
		vect.push_back(i);
	for (int i = 75; i < 80; i++)
		deq1.push_back(i);
	for (int i = -2; i < 4; i++)
		list1.push_back(i);
	try{
		vect2 = easyfind(vect, 0);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		vect2 = easyfind(vect, 23);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Value was found: " << *vect2 << std::endl;
	try{
		vect2 = easyfind(vect, 35);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		deq2 = easyfind(deq1, 0);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		deq2 = easyfind(deq1, 79);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Value was found: " << *deq2 << std::endl;
	try{
		deq2 = easyfind(deq1, 35);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		list2 = easyfind(list1, 79);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		list2 = easyfind(list1, 3);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Value was found: " << *list2 << std::endl;
	return 0;
}