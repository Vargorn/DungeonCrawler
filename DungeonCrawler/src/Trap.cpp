#include "Trap.h"

Trap::Trap(Player& player)
{
	std::cout << "It's a trap!!! " << std::endl;
	this->type = rand() % TRAPS::SIZE;
	switch (this->type)
	{
	case TRAPS::MUSHROOMS: {
		player.setMana(0);
		break;
	}
	case TRAPS::ROCKFALL: {
		player.setStamina(player.getStamina() - rand() % 30);
		break;
	}
	case TRAPS::PRESSURE_PLATE: {
		player.setHp(player.getHp() - rand() % 15);
		break;
	}
	case TRAPS::TRIPWIRE: {
		player.setHp(player.getHp() - rand() % 10);
		player.setStamina(player.getStamina() - rand() % 10);
		break;
	}
	case TRAPS::SPIKE_PIT: {
		player.setHp(player.getHp() - rand() % 15);
		player.setStamina(player.getStamina() - rand() % 15);
		break;
	}case TRAPS::CEILING_SPIKES: {
		player.setMana(player.getMana() - rand() % 30);
		break;
	}
	case TRAPS::CRUMBLING_BRIDGE: {
		player.setStamina(player.getStamina() - rand() % 20);
		break;
	}
	case TRAPS::DARTS: {
		player.setHp(player.getHp() - rand() % 10);
		break;
	}
	case TRAPS::FALLING_LOGS: {
		player.setHp(player.getHp() - rand() % 34);
		break;
	}
	case TRAPS::GAS_TRAP: {
		player.setStamina(0);
		break;
	}
	case TRAPS::ROTTEN_PLANK: {
		player.setStamina(10);
		break;
	}
	case TRAPS::SWINGING_LOG: {
		player.setHp(player.getHp() - rand() % 15);
		player.setStamina(player.getStamina() - rand() % 15);
		break;
	}
	case TRAPS::MAZE: {
		player.setMana(player.getMana() - rand() % 20);
		player.setStamina(player.getStamina() - rand() % 15);
		break;
	}
	}
}

Trap::Trap()
{
}
