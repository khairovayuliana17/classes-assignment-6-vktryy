#include "hybrid.h"
#include <iostream>

Hybrid::Hybrid(const std::string& name, int age) :
    Human(name, age), vampire_power(false), werewolf_power(false), rage_level(0) {}

Hybrid& Hybrid::activateVampirePower() {
    vampire_power = true;
    std::cout << name << " активировал силу вампира!" << std::endl;
    return *this;
}

Hybrid& Hybrid::activateWerewolfPower() {
    werewolf_power = true;
    std::cout << name << " активировал силу оборотня!" << std::endl;
    return *this;
}

Hybrid& Hybrid::increaseRage() {
    if (rage_level < 100) {
        rage_level += 10;
        if (rage_level > 100) {
            rage_level = 100;
        }
    }
    checkRage();
    return *this;
}

void Hybrid::checkRage() {
    if (rage_level >= 70) {
        std::cout << name << " впадает в ярость! Уровень: " << rage_level << std::endl;
    }
}

bool Hybrid::hasVampirePower() const { return vampire_power; }

bool Hybrid::hasWerewolfPower() const { return werewolf_power; }

int Hybrid::getRageLevel() const { return rage_level; }
