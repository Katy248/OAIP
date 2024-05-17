#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

enum AnimalType {Cat, Dog, Parrot, Horse, Pig, Sheep, Other};

inline const string toString(AnimalType animal)
{
    switch (animal)
    {
    case Cat: return "Кот";
    case Dog: return "Собака";
    case Parrot: return "Попугай";
    case Horse: return "Лошадь";
    case Pig: return "Свинья";
    case Sheep: return "Овца";
    case Other: return "Другое";
    default:
        break;
    }
}

inline const string toString(bool gender)
{
    if(gender)
        return "Мужской";
    else 
        return "Женский";
}

std::istream& operator>>(std::istream& is, AnimalType& animal)
{
    std::string name;
    is >> name;

    if (name == "Cat")
        animal = Cat;
    else if (name == "Dog")
        animal = Dog;
    else if (name == "Parrot")
        animal = Parrot;
    else if (name == "Horse")
        animal = Horse;
    else if (name == "Pig")
        animal = Pig;
    else if (name == "Sheep")
        animal = Sheep;
    else
        animal = Other;
    return is;
}

struct Animal
{
    AnimalType animal;
    string name;
    bool gender;
    int price;
};

class ZooShop
{

public:
    ZooShop()
    {
        cout << "Создан новый зоомагазин" << endl;
    }

    ZooShop(vector<Animal> animals)
    {
        pets = animals;
    }

    ZooShop(ZooShop &t)
    {
        pets = t.pets;
    }

    ~ZooShop()
    {
        cout << "Зоомагазин закрыт" << endl;
    }

    void addPet(Animal pet);

    bool ifAnimalForSale(AnimalType animal);

    bool removePetByName(string removeName);

    void addPetFromKeyboard();

    void printAllPets();

    ZooShop& operator+=(Animal pet)
    {
        pets.push_back(pet);
        return *this;
    }

private:
    vector<Animal> pets;
};

void ZooShop::addPet(Animal pet)
{
    pets.push_back(pet);
}

bool ZooShop::ifAnimalForSale(AnimalType animal)
{
    Animal temp;
    auto it = std::find_if(pets.begin(), pets.end(), [&an = animal] (const Animal& m) -> bool{return an == m.animal;});
    if(it != std::end(pets))
        return true;
    else
        return false;
}

bool ZooShop::removePetByName(string removeName)
{
    Animal temp;
    auto it = std::find_if(pets.begin(), pets.end(), [&rN = removeName] (const Animazl& m) -> bool{return rN == m.name;});
    if(it != std::end(pets))
    {
        int index = std::distance(pets.begin(), it);
        pets.erase(pets.begin() + index); 
        return true;
    }
    else
        return false;

}

void ZooShop::addPetFromKeyboard()
{
    Animal nA;
    cin >> nA.animal >> nA.name >> nA.gender >> nA.price;
    pets.push_back(nA);
}

void ZooShop::printAllPets()
{
    for (size_t i = 0; i < pets.size(); i++)
    {
        cout << "\nЖивотное - " << toString(pets[i].animal)
            << "\nИмя - " << pets[i].name
            << "\nПол - " << toString(pets[i].gender)
            << "\nЦена  - " << pets[i].price << endl;
    }
}

int main()
{
    ZooShop zoo;

    zoo.addPetFromKeyboard();
    zoo.printAllPets();

// Pig Валя 0 40

    cout << "\nДобавили Вадима"<< endl;
    Animal Cat = {AnimalType::Cat, "Вадим", true, 100};
    zoo.addPet(Cat);
    zoo.printAllPets();

    cout << "\nДобавили Вову" << endl;
    Animal Dogs = {AnimalType::Dog, "Вова", true, 1000};
    zoo += Dogs;
    zoo.printAllPets();

    zoo.removePetByName("Вова");
    cout << "\nУдалили Вову" << endl;
    zoo.printAllPets();
    cout << endl;

    cout << zoo.ifAnimalForSale(AnimalType::Cat) << endl;
    cout << zoo.ifAnimalForSale(AnimalType::Sheep) << endl;
    return 0;
}