#include "Zombie.hpp"

int main()
{
    int N = 5; 
    std::string name = "ZombieName";

    // Création d'une horde de zombies
    Zombie* horde = zombieHorde(N, name);

    // Vérification si la horde a été créée
    if (horde != NULL)
    {
        // Faire annoncer chaque zombie
        for (int i = 0; i < N; ++i)
        {
            horde[i].announce();
        }

        // Libérer la mémoire de la horde
        delete[] horde;
    }
    else
    {
        std::cerr << "Failed to create zombie horde." << std::endl;
    }

    return 0;
}
