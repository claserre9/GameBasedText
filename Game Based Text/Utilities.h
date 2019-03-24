#pragma once
#include "Room.h"
#include "Player.h"

void displayStory();
void displayMap();
void MenuWithMap(Player& player, Room* room);
void MenuWithOutMap(Player& player, Room* room);
