#include "hybrid.h"
#include <iostream>

Human::Human() : name("Unknown"), age(0), alive_status(true) {}

Human::Human(const std::string& name, int age) : name(name), age(age), alive_status(true) {}

void Human::die() {
    alive_status = false;
    std::cout << name << " умер." << std::endl;
}

void Human::becomeSupernatural() {
    std::cout << name << " превращается в сверхъестественное существо!" << std::endl;
}

std::string Human::getName() const { return name; }

int Human::getAge() const { return age; }

bool Human::isAlive() const { return alive_status; }
