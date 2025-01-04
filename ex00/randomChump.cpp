#include "Zombie.hpp"

void randomChump(std::string name) 
{
    Zombie zombie(name); // Appelle le constructeur
    zombie.announce();
}
