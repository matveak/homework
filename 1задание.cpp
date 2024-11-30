#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct Diver {
    std::string name;
    int age;
    int depth;
    int experience;
};


void writeDiverToFile(const Diver& diver, std::ofstream& outfile) {
    outfile << diver.name << " " << diver.age << " " << diver.depth << " " << diver.experience << std::endl;
}


Diver readDiverFromFile(std::ifstream& infile) {
    Diver diver;
    infile >> diver.name >> diver.age >> diver.depth >> diver.experience;
    return diver;
}



void printDiver(const Diver& diver) {
    std::cout << "Имя: " << diver.name << ", Возраст: " << diver.age << ", Глубина: " << diver.depth << " м, Опыт: " << diver.experience << " лет\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::ofstream outfile("divers.txt");

    for (int i = 0; i < 5; ++i) {
        Diver diver;
        std::cout << "Введите данные для водолаза " << i + 1 << ":\n";
        std::cout << "Имя: ";
        std::cin >> diver.name;
        std::cout << "Возраст: ";
        std::cin >> diver.age;
        std::cout << "Максимальная глубина (м): ";
        std::cin >> diver.depth;
        std::cout << "Опыт работы (лет): ";
        std::cin >> diver.experience;
        writeDiverToFile(diver, outfile);
    }
    outfile.close();

    std::ifstream infile("divers.txt");

    std::cout << "\nДанные о водолазах из файла:\n";
    while (infile.peek() != EOF) {
        Diver diver = readDiverFromFile(infile);
        printDiver(diver);
        if (diver.depth > 50) {
            std::cout << "Может работать на глубине более 50 метров" << std::endl;
        }
    }
    infile.close();

    return 0;
}