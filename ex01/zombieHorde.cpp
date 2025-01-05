#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL; // Utilisation de NULL au lieu de nullptr

    // Allocation dynamique d'un tableau de zombies
    Zombie* zombies = new Zombie[N];

    // Initialisation de chaque zombie avec un nom unique
    for (int i = 0; i < N; i++)
    {
        zombies[i].setName(name + std::to_string(i + 1)); // "name1", "name2", ...
    }

    return zombies;
}