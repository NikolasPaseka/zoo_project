//
// Created by dalib on 11.12.2020.
//

#include "Buy.h"

Buy::Buy(): Interaction("Buy"){
}

void Buy::makeInteraction(Hero* hero, FriendlyCharacter* friendlyCharacter){
    int choice;
    std::cout << "+-----------SHOP-----------+\n";
    friendlyCharacter->printInventory();
    std::cout << "What do you want to buy?" << std::endl;
    std::cout << "\t[1] Weapon" << std::endl;
    std::cout << "\t[2] Armor" << std::endl;
    std::cout << "\t[3] I changed my mind" << std::endl;
    std::cin >> choice;
    if (choice == 1) {
        buyWeapon(hero, friendlyCharacter);
    } else if (choice == 2){
        buyArmor(hero, friendlyCharacter);
    }
}

void Buy::buyWeapon(Hero* hero, FriendlyCharacter* friendlyCharacter){
    int choice;
    std::cout << "Which one?" <<std::endl;
    std::cin >> choice;

    Weapon* weapon = friendlyCharacter->getInventory()->getWeapon(choice);
    if (weapon != nullptr) {
        if (weapon->getPrice() <= hero->getCoins()) {
            std::cout << "You bought: " << weapon->getName();
            hero->getInventory()->addWeapon(weapon);
            hero->addCoins(-weapon->getPrice());
        } else {
            std::cout << "You dont have enough coins\n";
            friendlyCharacter->getInventory()->addWeapon(weapon);
        }
    }
}

void Buy::buyArmor(Hero* hero, FriendlyCharacter* friendlyCharacter){
    int choice;
    std::cout << "Which one?" <<std::endl;
    std::cin >> choice;

    Armor* armor = friendlyCharacter->getInventory()->getArmor(choice);
    if (armor != nullptr){
        if (armor->getPrice() <= hero->getCoins()) {
            std::cout << "You bought: " << armor->getName();
            hero->getInventory()->addArmor(armor);
            hero->addCoins(-armor->getPrice());
        } else {
            std::cout << "You dont have enough coins\n";
            friendlyCharacter->getInventory()->addArmor(armor);
        }
    }
}