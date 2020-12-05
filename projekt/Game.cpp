//
// Created by nikol on 19.11.2020.
//

#include "Game.h"

Game::Game(Map* map, Hero* hero, StoryTeller* story){
    m_map = map;
    m_hero = hero;
    m_story = story;
    printProlog();
    printMenu();
}

void Game::printProlog() {
    m_story->printChapter(1);
    m_hero->createHero();
    //m_hero->printInfo();
}

char Game::getPlayerInput(){
    char playerInput;
    std::cin >> playerInput;
    return playerInput;
}

void Game::printMenu(){
    while (m_map->getCurrentLocationIndex() < m_map->getLocations().size()-1) {
        m_map->printLocationInfo();
        locationPrintMenu();
        std::cout << "What do you want to do?\n     1. Go to next location\n";
        whatToDo();
    }
    std::cout << "You are now in final location.... Final boss is coming....." << std::endl;
    std::cout << "Oh wait a moment, we dont have fighting system, You died" << std::endl;
}

void Game::whatToDo(){
    if (getPlayerInput() == '1'){
        m_map->printSideLocations();
    }
}

void Game::locationPrintMenu(){
    tileCoordinates coor = m_map->getTileCoordinates();
    while (coor.x < locationSize-1 or coor.y < locationSize-1) {
        m_map->printLocation();
        std::cout << "What do you want to do? \n";
        std::cout << "\t 1. Move on tile \n";
        std::cout << "\t 2. View inventory \n";
        if (m_map->getEnemy() != nullptr){
            std::cout << "\t 5. Attack Enemy \n";
        }
        if (m_map->getChest() != nullptr){
            std::cout << "\t 4. Open chest \n";
        }
        std::cout << "\t 3. exit \n";
        whatToDo2();
        coor = m_map->getTileCoordinates();
    }
}

void Game::whatToDo2(){
    char playerInput = getPlayerInput();
    if (playerInput == '1'){
        m_map->printTileSides();
    } else if (playerInput == '2'){
        m_hero->printInventory();
    } else if (playerInput == '3') {
        m_map->setTileCoordinatesToExit();
    } else if (playerInput == '4'){
        inspectChest();
    } else if (playerInput == '5'){
        std::cout << "utocim \n";
    }
}

void Game::inspectChest(){
    Item* item;
    std::cout << "You have found: \n";
    if (m_map->getChest()->getWeapon() != nullptr){
        item = m_map->getChest()->getWeapon();
    } else if (m_map->getChest()->getArmor() != nullptr){
        item = m_map->getChest()->getArmor();
    } else if (m_map->getChest()->getPotion() != nullptr){
        item = m_map->getChest()->getPotion();
    }
    item->printInfo();
    std::cout << "Would you like to take it?\n\t1. Yes\n\t2. No\n";
    if (getPlayerInput() == '1'){
        std::cout << m_hero->getHeroName() << " is taking " << item->getName() << " from chest...\n";
        if (item->getItemType() == "weapon"){
            m_hero->takeWeapon(m_map->getChest()->getWeapon());
        } else if (item->getItemType() == "armor"){
            m_hero->takeArmor(m_map->getChest()->getArmor());
        } else if (item->getItemType() == "potion"){
            m_hero->takePotion(m_map->getChest()->getPotion());
        }
        m_map->removeChest();
    }
}

Game::~Game(){
    delete m_map;
    delete m_hero;
}