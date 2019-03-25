#pragma once
#include "Room.h"
#include "Player.h"
#include "Caporal.h"
#include "Captain.h"
#include "Colonel.h"
#include "Lieutenant.h"

void displayStory();
void displayMap();
void MenuWithMap(Player& player, Room* & room);
void Menu(Player& player, Room* & room);
void figthscene_1(Player& player, Caporal& caporal, Room* & room);
void figthscene_2(Player& player, Captain & captain, Room* & room);
string finalfight(Player& player, Colonel & colonel, Lieutenant & lieutenant, Room* & room);

