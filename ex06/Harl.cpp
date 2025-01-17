#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}
void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int	lvl = -1;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			lvl = i;
			break;;
		}
	}
switch (lvl)
{
    case 0:
        this->debug();
		std::cout << std::endl;
    case 1:
        this->info();
		std::cout << std::endl;
    case 2:
        this->warning();
		std::cout << std::endl;
    case 3:
        this->error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
}
