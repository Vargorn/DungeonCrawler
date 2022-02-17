#include "Trap.h"

Trap::Trap(Player& player)
{
	this->type = rand() % TRAPS::SIZE;
	switch (this->type)
	{
	case TRAPS::MUSHROOMS: {
		player.setMana(0);
		break;
	}
	case TRAPS::ROCKFALL: {

		break;
	}
	case TRAPS::PRESSURE_PLATE: {

		break;
	}
	case TRAPS::TRIPWIRE: {

		break;
	}
	case TRAPS::SPIKE_PIT: {

		break;
	}case TRAPS::CEILING_SPIKES: {

		break;
	}
	case TRAPS::CRUMBLING_BRIDGE: {

		break;
	}
	case TRAPS::DARTS: {

		break;
	}
	case TRAPS::FALLING_LOGS: {

		break;
	}
	case TRAPS::GAS_TRAP: {

		break;
	}
	case TRAPS::ROTTEN_PLANK: {

		break;
	}
	case TRAPS::SWINGING_LOG: {

		break;
	}
	case TRAPS::MAZE: {

		break;
	}
	}
}
