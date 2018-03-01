#ifndef BATTLE_H
#define BATTLE_H

#include"..\creature\Creature.h"
#include "..\creature\Creature.h"
#include "..\creature\Human.h"
#include "..\creature\Elf.h"
#include "..\creature\Demon.h"
#include "..\creature\Cyberdemon.h"
#include "..\creature\Balrog.h"
#include "..\creature\Player.h"
#include "..\creature\Dwarf.h"


void attack(Creature* A, Creature *B);
void SOLO(Creature* A, Creature* B);

#endif