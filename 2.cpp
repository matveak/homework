#include <iostream>
#include <fstream>
#include <string>

struct Product {
    std::string name;
    int day;
    int month;
    int year;
    int quantity;
    std::string category;

    Product() = default;

    Product(const std::string& n, int d, int m, int y, int q, const std::string& c)
        : name(n), day(d), month(m), year(y), quantity(q), category(c) {}

    bool isExpired(int currentDay, int currentMonth, int currentYear) const {
        if (year < currentYear) return true;
        if (year > currentYear) return false;
        if (month < currentMonth) return true;
        if (month > currentMonth) return false;
        return day < currentDay;
    }

    void print() const {
        std::cout << "Название: " << name << ", Срок годности: " << year << "-" << month << "-" << day
            << ", Количество: " << quantity << ", Категория: " << category << std::endl;
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    Product newProduct;
    std::string line;
    std::cout << "Введите название продукта: ";
    std::getline(std::cin, newProduct.name);
    std::cout << "Введите срок годности (ДД ММ ГГГГ): ";
    std::cin >> newProduct.day >> newProduct.month >> newProduct.year;
    std::cout << "Введите количество: ";
    std::cin >> newProduct.quantity;
    std::cin.ignore();
    std::cout << "Введите категорию: ";
    std::getline(std::cin, newProduct.category);

    std::ofstream outputFile("expired_food.txt", std::ios_base::app);
    if (outputFile.is_open()) {
        outputFile << newProduct.name << " " << newProduct.day << "-" << newProduct.month << "-" << newProduct.year
            << " " << newProduct.quantity << " " << newProduct.category << std::endl;
        outputFile.close();
    }
    std::ifstream inputFile("expired_food.txt");
    if (inputFile.is_open()) {
        std::cout << "\nПродукты с истекшим сроком годности:\n";
        int currentDay, currentMonth, currentYear;
        std::cout << "Введите текущую дату (ДД ММ ГГГГ): ";
        std::cin >> currentDay >> currentMonth >> currentYear;

        while (std::getline(inputFile, line)) {
            int pos = 0;
            size_t found = line.find(' ');
            std::string name = line.substr(pos, found - pos);
            pos = found + 1;
            found = line.find(' ', pos);
            std::string expiryDate = line.substr(pos, found - pos);
            pos = found + 1;
            found = line.find(' ', pos);
            int quantity = std::stoi(line.substr(pos, found - pos));
            pos = found + 1;
            std::string category = line.substr(pos);

            int day, month, year;
            int posDash1 = expiryDate.find('-');
            int posDash2 = expiryDate.find('-', posDash1 + 1);
            day = std::stoi(expiryDate.substr(0, posDash1));
            month = std::stoi(expiryDate.substr(posDash1 + 1, posDash2 - posDash1 - 1));
            year = std::stoi(expiryDate.substr(posDash2 + 1));

            Product product(name, day, month, year, quantity, category);
            if (product.isExpired(currentDay, currentMonth, currentYear)) {
                product.print();
            }
        }
        inputFile.close();
    }

    return 0;
}