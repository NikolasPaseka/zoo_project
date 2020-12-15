//
// Created by nikol on 04.12.2020.
//

#include "Chest.h"

Chest::Chest(Weapon* weapon, Armor* armor, Potion* potion){
    m_weapon = weapon;
    m_armor = armor;
    m_potion = potion;
}

Chest::Chest(Weapon* weapon): Chest(weapon, nullptr, nullptr){
}

Chest::Chest(Armor* armor): Chest(nullptr, armor, nullptr){
}

Chest::Chest(Potion* potion): Chest(nullptr, nullptr, potion){
}

Weapon* Chest::getWeapon(){
    return m_weapon;
}

Armor* Chest::getArmor(){
    return m_armor;
}

Potion* Chest::getPotion(){
    return m_potion;
}

void Chest::removeContent(){
    if (m_armor != nullptr){
        m_armor = nullptr;
    } else if (m_weapon != nullptr){
        m_weapon = nullptr;
    } else if (m_potion != nullptr){
        m_potion = nullptr;
    }
}

Chest::~Chest(){
    if (m_weapon != nullptr){
        delete m_weapon;
    }
    if (m_armor != nullptr){
        delete m_armor;
    }
    if (m_potion != nullptr){
        delete m_potion;
    }
}