#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include "hybrid.h"

TEST_CASE("Human class functionality", "[Human]") {
    SECTION("Default constructor") {
        Human h;
        REQUIRE(h.getName() == "Unknown");
        REQUIRE(h.getAge() == 0);
        REQUIRE(h.isAlive() == true);
    }

    SECTION("Parameterized constructor") {
        Human h("Elena", 17);
        REQUIRE(h.getName() == "Elena");
        REQUIRE(h.getAge() == 17);
        REQUIRE(h.isAlive() == true);
    }

    SECTION("die() method") {
        Human h("Kai", 22);
        h.die();
        REQUIRE(h.isAlive() == false);
    }

    SECTION("becomeSupernatural() output") {
        Human h("Enzo", 27);
        std::ostringstream oss;
        std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

        h.becomeSupernatural();
        std::cout.rdbuf(oldCout);

        REQUIRE(oss.str() == "Enzo превращается в сверхъестественное существо!\n");
    }
}

TEST_CASE("Hybrid class functionality", "[Hybrid]") {
    SECTION("Inheritance from Human") {
        Hybrid h("Klaus", 1000);
        REQUIRE(h.getName() == "Klaus");
        REQUIRE(h.getAge() == 1000);
        REQUIRE(h.isAlive() == true);
    }

    SECTION("Default power states") {
        Hybrid h;
        REQUIRE(h.hasVampirePower() == false);
        REQUIRE(h.hasWerewolfPower() == false);
        REQUIRE(h.getRageLevel() == 0);
    }

    SECTION("activateVampirePower() output") {
        Hybrid h("Elijah", 900);
        std::ostringstream oss;
        std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

        h.activateVampirePower();
        std::cout.rdbuf(oldCout);

        REQUIRE(oss.str() == "Elijah активировал силу вампира!\n");
        REQUIRE(h.hasVampirePower() == true);
    }

    SECTION("activateWerewolfPower() output") {
        Hybrid h("Hayley", 200);
        std::ostringstream oss;
        std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

        h.activateWerewolfPower();
        std::cout.rdbuf(oldCout);

        REQUIRE(oss.str() == "Hayley активировал силу оборотня!\n");
        REQUIRE(h.hasWerewolfPower() == true);
    }

    SECTION("Rage level management") {
        Hybrid h("Tyler", 150);

        for (int i = 0; i < 5; ++i) {
            h.increaseRage();
        }
        REQUIRE(h.getRageLevel() == 50);

        std::ostringstream oss;
        std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
        h.checkRage();
        std::cout.rdbuf(oldCout);
        REQUIRE(oss.str().empty());

        for (int i = 0; i < 2; ++i) {
            h.increaseRage();
        }
        REQUIRE(h.getRageLevel() == 70);

        oss.str("");
        oldCout = std::cout.rdbuf(oss.rdbuf());
        h.checkRage();
        std::cout.rdbuf(oldCout);
        REQUIRE(oss.str() == "Tyler впадает в ярость! Уровень: 70\n");
    }

    SECTION("Method chaining") {
        Hybrid h("Rebekah", 800);
        h.activateVampirePower().activateWerewolfPower().increaseRage().increaseRage();

        REQUIRE(h.hasVampirePower() == true);
        REQUIRE(h.hasWerewolfPower() == true);
        REQUIRE(h.getRageLevel() == 20);
    }
}
