#include "Zombie.hpp"

int main() 
{
    // Zombie créé sur le tas
    Zombie* heapZombie = newZombie("New Zombie");
    heapZombie->announce();
    delete heapZombie;
    
    // Zombie créé sur la pile
    randomChump("Random Zombie");

    return 0;
}