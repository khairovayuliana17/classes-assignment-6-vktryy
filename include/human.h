
// Human class here

#include <string>

class Human {
  protected:
    std::string name;
    int age;
    bool alive_status;

  public:
    Human();
    Human(const std::string& name, int age);

    void die();
    void becomeSupernatural();

    std::string getName() const;
    int getAge() const;
    bool isAlive() const;
};
