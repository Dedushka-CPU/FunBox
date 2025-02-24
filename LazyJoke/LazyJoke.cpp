#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>
#include <ctime>

#ifdef _WIN32
#include <windows.h> // Для Windows: настройка консоли
#endif

class RandomGenerator {
private:
    std::mt19937 rng; // Генератор случайных чисел Mersenne Twister
public:
    RandomGenerator() {
        rng.seed(static_cast<unsigned>(std::time(0)));
    }
    int getRandom(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }
};

class LazyGenix {
private:
    std::vector<std::string> nouns = {
        "робот", "тостер", "носки", "тапки", "кот", "чайник", "утюг", "пылесос", 
        "диван", "стул", "лампа", "зеркало", "ковёр", "холодильник", "микроволновка", 
        "шкаф", "подушка", "одеяло", "гитара", "барабан", "пианино", "мышка", 
        "клавиатура", "монитор", "телефон", "телевизор", "часы", "будильник", 
        "зонтик", "рюкзак", "ботинки", "шляпа", "очки", "ложка", "вилка", "тарелка"
    };
    std::vector<std::string> additions = {
        "с Wi-Fi", "для собак", "с подсветкой", "на батарейках", "для космоса", 
        "с камерой", "на солнечной энергии", "с музыкой", "для кошек", "с таймером", 
        "с автопилотом", "из золота", "с запахом пиццы", "на колёсах", "с пультом", 
        "для офиса", "с подогревом", "водонепроницаемый", "с Bluetooth", "для детей", 
        "с лазером", "с голосовым управлением", "в полосочку", "с блестками", 
        "для путешествий", "с кофеваркой", "на магнитах", "с экраном", "для фитнеса", 
        "с вентилятором", "с подсказками", "в стиле ретро", "с ароматом ванили"
    };
    std::map<std::string, std::string> jokes = {
        {"робот", "роботик-хулигантик"}, 
        {"кот", "котик-пузатик"}, 
        {"тостер", "тостер-монстр"}, 
        {"чайник", "чайник-визгун"}, 
        {"утюг", "утюг-гладильщик"}, 
        {"пылесос", "пылесос-жрун"}, 
        {"диван", "диван-лежебока"}, 
        {"лампа", "лампа-светлячок"}, 
        {"зеркало", "зеркало-кривозеркальце"}, 
        {"ковёр", "ковёр-летаун"}, 
        {"холодильник", "холодильник-морозко"}, 
        {"шкаф", "шкаф-прятальщик"}, 
        {"подушка", "подушка-обнималка"}, 
        {"гитара", "гитара-шумелка"}, 
        {"мышка", "мышка-бегушка"}, 
        {"клавиатура", "клавиатура-стучалка"}, 
        {"телефон", "телефон-звонилка"}, 
        {"часы", "часы-тикалки"}, 
        {"зонтик", "зонтик-спасалка"}, 
        {"очки", "очки-смотрелки"}, 
        {"ложка", "ложка-черпалка"}
    };
    RandomGenerator random;

public:
    std::string generateIdea() {
        int lazyChance = random.getRandom(0, 100);
        if (lazyChance < 30) { // 30% шанс лени
            return "Я устал, давай позже!";
        }

        std::string word1 = nouns[random.getRandom(0, nouns.size() - 1)];
        std::string word2 = additions[random.getRandom(0, additions.size() - 1)];

        if (jokes.find(word1) != jokes.end()) {
            word1 = jokes[word1];
        }

        return "Моя гениальная идея: " + word1 + " " + word2;
    }

    void run() {
        std::string answer;
        do {
            std::cout << "Хочешь новую идею? (да/нет): ";
            std::cin >> answer;
            if (answer == "да") {
                std::cout << generateIdea() << std::endl;
            }
        } while (answer == "да");

        std::cout << "Пока, лентяй!" << std::endl;
    }
};

int main() {
    LazyGenix game;
    game.run();
    return 0;
}