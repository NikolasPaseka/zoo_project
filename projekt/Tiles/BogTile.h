//
// Created by dalib on 06.12.2020.
//

#ifndef MAIN_CPP_BOGTILE_H
#define MAIN_CPP_BOGTILE_H

#include "Tile.h"

class BogTile: public Tile {
public:
    BogTile();
    BogTile(Enemy* enemy);
    BogTile(Chest* chest);
    BogTile(FriendlyCharacter* friendlyCharacter);
    void printTile(bool printHero);
};


#endif //MAIN_CPP_BOGTILE_H