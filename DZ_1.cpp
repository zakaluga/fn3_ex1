#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <memory>
#include <sstream>

using namespace std;

class Computer {
private:
    string serialNumber;
    string model;
    string processor;
    int ram; // оперативная память в ГБ
public:
    Computer(const string& serial, const string& mdl, const string& proc, int memory)
        : serialNumber(serial), model(mdl), processor(proc), ram(memory) {}

    string getSerialNumber() const {
        return serialNumber;
    }

    void saveToFile(ofstream& out) const {
        out << "C " << serialNumber << " " << model << " " << processor << " " << ram << endl;
    }

    void loadFromFile(ifstream& in) {
        in >> serialNumber >> model >> processor >> ram;
    }

    void print() const {
        cout << "Компьютер - Серийный номер: " << serialNumber << ", Модель: " << model
            << ", Процессор: " << processor << ", ОЗУ: " << ram << " ГБ" << endl;
    }
};

class Table {
private:
    string serialNumber;
    string type;
    string material; // материал стола
public:
    Table(const string& serial, const string& typ, const string& mat)
        : serialNumber(serial), type(typ), material(mat) {}

    string getSerialNumber() const {
        return serialNumber;
    }

    void saveToFile(ofstream& out) const {
        out << "T " << serialNumber << " " << type << " " << material << endl;
    }

    void loadFromFile(ifstream& in) {
        in >> serialNumber >> type >> material;
    }

    void print() const {
        cout << "Стол - Серийный номер: " << serialNumber << ", Тип: " << type
            << ", Материал: " << material << endl;
    }
};

class Painting {
private:
    string serialNumber;
    string title;
    string artist;
    int year;
public:
    Painting(const string& serial, const string& ttl, const string& art, int yr)
        : serialNumber(serial), title(ttl), artist(art), year(yr) {}

    string getSerialNumber() const {
        return serialNumber;
    }

    void saveToFile(ofstream& out) const {
        out << "P " << serialNumber << " " << title << " " << artist << " " << year << endl;
    }

    void loadFromFile(ifstream& in) {
        in >> serialNumber >> title >> artist >> year;
    }

    void print() const {
        cout << "Картина - Серийный номер: " << serialNumber << ", Название: " << title
            << ", Художник: " << artist << ", Год: " << year << endl;
    }
};

class Chair {
private:
    string serialNumber;
    string type;
    string material; // материал стула
public:
    Chair(const string& serial, const string& typ, const string& mat)
        : serialNumber(serial), type(typ), material(mat) {}

    string getSerialNumber() const {
        return serialNumber;
    }

    void saveToFile(ofstream& out) const {
        out << "H " << serialNumber << " " << type << " " << material << endl;
    }

    void loadFromFile(ifstream& in) {
        in >> serialNumber >> type >> material;
    }

    void print() const {
        cout << "Стул - Серийный номер: " << serialNumber << ", Тип: " << type
            << ", Материал: " << material << endl;
    }
};

class CustomItem {
private:
    string serialNumber;
    string name;
    unordered_map<string, string> properties;
public:
    CustomItem(const string& serial, const string& nm)
        : serialNumber(serial), name(nm) {}

    string getSerialNumber() const {
        return serialNumber;
    }

    void addProperty(const string& key, const string& value) {
        properties[key] = value;
    }

    void saveToFile(ofstream& out) const {
        out << "U " << serialNumber << " " << name << " " << properties.size();
        for (const auto& prop : properties) {
            out << " " << prop.first << " " << prop.second;
        }
        out << endl;
    }

    void loadFromFile(ifstream& in) {
        size_t propCount;
        in >> serialNumber >> name >> propCount;
        for (size_t i = 0; i < propCount; ++i) {
            string key, value;
            in >> key >> value;
            properties[key] = value;
        }
    }

    void print() const {
        cout << "Пользовательский предмет - Серийный номер: " << serialNumber << ", Название: " << name << endl;
        for (const auto& prop : properties) {
            cout << "  " << prop.first << ": " << prop.second << endl;
        }
    }
};

void showMenu(const vector<pair<string, vector<string>>>& customItemTypes) {
    cout << "1. Добавить предмет" << endl;
    cout << "2. Удалить предмет по серийному номеру" << endl;
    cout << "3. Найти предмет по серийному номеру" << endl;
    cout << "4. Показать всю инвентаризацию" << endl;
    cout << "5. Сохранить инвентаризацию в файл" << endl;
    cout << "6. Загрузить инвентаризацию из файла" << endl;
    cout << "7. Создать новый пользовательский тип" << endl;
    cout << "8. Показать количество предметов каждого типа" << endl;
    cout << "9. Выход" << endl;
}

void saveInventory(const unordered_map<string, unique_ptr<Computer>>& computers,
    const unordered_map<string, unique_ptr<Table>>& tables,
    const unordered_map<string, unique_ptr<Painting>>& paintings,
    const unordered_map<string, unique_ptr<Chair>>& chairs,
    const unordered_map<string, unique_ptr<CustomItem>>& customItems,
    const vector<pair<string, vector<string>>>& customItemTypes) {
    ofstream outFile("inventory.txt");
    if (outFile.is_open()) {
        outFile << computers.size() + tables.size() + paintings.size() + chairs.size() + customItems.size() << endl;
        for (const auto& pair : computers) {
            pair.second->saveToFile(outFile);
        }
        for (const auto& pair : tables) {
            pair.second->saveToFile(outFile);
        }
        for (const auto& pair : paintings) {
            pair.second->saveToFile(outFile);
        }
        for (const auto& pair : chairs) {
            pair.second->saveToFile(outFile);
        }
        for (const auto& pair : customItems) {
            pair.second->saveToFile(outFile);
        }
        outFile.close();
    }
    else {
        cout << "Ошибка при открытии файла для записи!" << endl;
        return;
    }


    cout << "Инвентаризация сохранена!" << endl;
}

void loadInventory(unordered_map<string, unique_ptr<Computer>>& computers,
    unordered_map<string, unique_ptr<Table>>& tables,
    unordered_map<string, unique_ptr<Painting>>& paintings,
    unordered_map<string, unique_ptr<Chair>>& chairs,
    unordered_map<string, unique_ptr<CustomItem>>& customItems,
    vector<pair<string, vector<string>>>& customItemTypes) {
    ifstream inFile("inventory.txt");
    if (inFile.is_open()) {
        size_t size;
        char typeChar;
        computers.clear();
        tables.clear();
        paintings.clear();
        chairs.clear();
        customItems.clear();
        inFile >> size;
        for (size_t i = 0; i < size; ++i) {
            inFile >> typeChar;
            if (typeChar == 'C') {
                auto computer = make_unique<Computer>("", "", "", 0);
                computer->loadFromFile(inFile);
                computers[computer->getSerialNumber()] = move(computer);
            }
            else if (typeChar == 'T') {
                auto table = make_unique<Table>("", "", "");
                table->loadFromFile(inFile);
                tables[table->getSerialNumber()] = move(table);
            }
            else if (typeChar == 'P') {
                auto painting = make_unique<Painting>("", "", "", 0);
                painting->loadFromFile(inFile);
                paintings[painting->getSerialNumber()] = move(painting);
            }
            else if (typeChar == 'H') {
                auto chair = make_unique<Chair>("", "", "");
                chair->loadFromFile(inFile);
                chairs[chair->getSerialNumber()] = move(chair);
            }
            else if (typeChar == 'U') {
                auto customItem = make_unique<CustomItem>("", "");
                customItem->loadFromFile(inFile);
                customItems[customItem->getSerialNumber()] = move(customItem);
            }
        }
        inFile.close();
    }
    else {
        cout << "Ошибка при открытии файла для чтения!" << endl;
        return;
    }


    cout << "Инвентаризация загружена!" << endl;
}

void addCustomType(vector<pair<string, vector<string>>>& customItemTypes) {
    string typeName;
    cout << "Введите название нового типа предмета: ";
    cin >> typeName;

    vector<string> properties;
    string property;
    cout << "Введите свойства для типа " << typeName << " (для завершения введите 'end'):" << endl;
    while (true) {
        cout << "Свойство: ";
        cin >> property;
        if (property == "end") break;
        properties.push_back(property);
    }

    customItemTypes.push_back({ typeName, properties });
    cout << "Новый пользовательский тип добавлен!" << endl;
}

void countItems(const unordered_map<string, unique_ptr<Computer>>& computers,
    const unordered_map<string, unique_ptr<Table>>& tables,
    const unordered_map<string, unique_ptr<Painting>>& paintings,
    const unordered_map<string, unique_ptr<Chair>>& chairs,
    const unordered_map<string, unique_ptr<CustomItem>>& customItems) {
    unordered_map<string, int> itemCounts;
    for (const auto& pair : computers) {
        itemCounts["Computer"]++;
    }
    for (const auto& pair : tables) {
        itemCounts["Table"]++;
    }
    for (const auto& pair : paintings) {
        itemCounts["Painting"]++;
    }
    for (const auto& pair : chairs) {
        itemCounts["Chair"]++;
    }
    for (const auto& pair : customItems) {
        itemCounts["CustomItem"]++;
    }

    cout << "Количество предметов по типам:" << endl;
    for (const auto& pair : itemCounts) {
        cout << pair.first << ": " << pair.second << endl;
    }
}
bool getIntInput(int& input) {
    cin >> input;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool getStringInput(string& input) {
    cin >> input;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "rus");
    unordered_map<string, unique_ptr<Computer>> computers;
    unordered_map<string, unique_ptr<Table>> tables;
    unordered_map<string, unique_ptr<Painting>> paintings;
    unordered_map<string, unique_ptr<Chair>> chairs;
    unordered_map<string, unique_ptr<CustomItem>> customItems;
    vector<pair<string, vector<string>>> customItemTypes;

    int choice;
    string serialNumber, model, type, name, properties, key, value, processor, material, title, artist;
    int ram, year;

    do {
        showMenu(customItemTypes);
        cout << "Выберите опцию: ";
        while (!getIntInput(choice)) {
            cout << "Неверный ввод. Пожалуйста, введите число: ";
        }
        switch (choice) {
        case 1: { // Добавить предмет
            int addChoice;
            cout << "1. Добавить компьютер" << endl;
            cout << "2. Добавить стол" << endl;
            cout << "3. Добавить картину" << endl;
            cout << "4. Добавить стул" << endl;
            cout << "5. Добавить пользовательский предмет" << endl;
            cout << "Выберите опцию: ";
            cin >> addChoice;

            if (addChoice == 1) { // Добавить компьютер
                cout << "Введите серийный номер: ";
                while (!getStringInput(serialNumber)) {
                    cout << "Неверный ввод. Пожалуйста, введите текст: ";
                }
                cout << "Введите модель: ";
                while (!getStringInput(model)) {
                    cout << "Неверный ввод. Пожалуйста, введите текст: ";
                }
                cout << "Введите процессор: ";
                while (!getStringInput(processor)) {
                    cout << "Неверный ввод. Пожалуйста, введите текст: ";
                }
                int ram;
                cout << "Введите ОЗУ (ГБ): ";
                while (!getIntInput(ram)) {
                    cout << "Неверный ввод. Пожалуйста, введите число: ";
                }
                computers[serialNumber] = make_unique<Computer>(serialNumber, model, processor, ram);
                cout << "Компьютер добавлен!" << endl;
            }
            else if (addChoice == 2) { // Добавить стол
                cout << "Введите серийный номер: ";
                while (!getStringInput(serialNumber)) {
                    cout << "Неверный ввод. Пожалуйста, введите текст: ";
                }
                cout << "Введите тип: ";
                while (!getStringInput(type)) {
                    cout << "Неверный ввод. Пожалуйста, введите текст: ";
                }
                cout << "Введите материал: ";
                while (!getStringInput(material)) {
                    cout << "Неверный ввод. Пожалуйста, введите текст: ";
                }
                tables[serialNumber] = make_unique<Table>(serialNumber, type, material);
                cout << "Стол добавлен!" << endl;
            }
            else if (addChoice == 3) { // Добавить картину
                cout << "Введите серийный номер: ";
                while (!getStringInput(serialNumber)) {
                    cout << "Неверный ввод. Пожалуйста, введите текст: ";
                }
                cout << "Введите название: ";
                while (!getStringInput(title)) {
                    cout << "Неверный ввод. Пожалуйста, введите текст: ";
                }
                cout << "Введите художника: ";
                while (!getStringInput(artist)) {
                    cout << "Неверный ввод. Пожалуйста, введите текст: ";
                }
                cout << "Введите год: ";
                while (!getIntInput(year)) {
                    cout << "Неверный ввод. Пожалуйста, введите число: ";
                }
                paintings[serialNumber] = make_unique<Painting>(serialNumber, title, artist, year);
                cout << "Картина добавлена!" << endl;
            }
            else if (addChoice == 4) { // Добавить стул
                cout << "Введите серийный номер: ";
                while (!getStringInput(serialNumber)) {
                    cout << "Неверный ввод. Пожалуйста, введите текст: ";
                }
                cout << "Введите тип: ";
                while (!getStringInput(type)) {
                    cout << "Неверный ввод. Пожалуйста, введите текст: ";
                }
                cout << "Введите материал: ";
                while (!getStringInput(material)) {
                    cout << "Неверный ввод. Пожалуйста, введите текст: ";
                }
                chairs[serialNumber] = make_unique<Chair>(serialNumber, type, material);
                cout << "Стул добавлен!" << endl;
            }
            else if (addChoice == 5) { // Добавить пользовательский предмет
                cout << "Введите серийный номер: ";
                cin >> serialNumber;
                cout << "Введите название: ";
                cin >> name;
                auto customItem = make_unique<CustomItem>(serialNumber, name);
                cout << "Введите свойства (для завершения введите 'end'):" << endl;
                while (true) {
                    cout << "Свойство: ";
                    cin >> key;
                    if (key == "end") break;
                    cout << "Значение: ";
                    cin >> value;
                    customItem->addProperty(key, value);
                }
                customItems[serialNumber] = move(customItem);
                cout << "Пользовательский предмет добавлен!" << endl;
            }
            else {
                cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
            }
            break;
        }

        case 2: { // Удалить предмет по серийному номеру
            cout << "Введите серийный номер: ";
            while (!getStringInput(serialNumber)) {
                cout << "Неверный ввод. Пожалуйста, введите текст: ";
            }
            if (computers.erase(serialNumber) || tables.erase(serialNumber) || paintings.erase(serialNumber) || chairs.erase(serialNumber) || customItems.erase(serialNumber)) {
                cout << "Предмет удален!" << endl;
            }
            else {
                cout << "Предмет с таким серийным номером не найден." << endl;
            }
            break;
        }

        case 3: { // Найти предмет по серийному номеру
            cout << "Введите серийный номер: ";
            while (!getStringInput(serialNumber)) {
                cout << "Неверный ввод. Пожалуйста, введите текст: ";
            }
            if (computers.find(serialNumber) != computers.end()) {
                computers[serialNumber]->print();
            }
            else if (tables.find(serialNumber) != tables.end()) {
                tables[serialNumber]->print();
            }
            else if (paintings.find(serialNumber) != paintings.end()) {
                paintings[serialNumber]->print();
            }
            else if (chairs.find(serialNumber) != chairs.end()) {
                chairs[serialNumber]->print();
            }
            else if (customItems.find(serialNumber) != customItems.end()) {
                customItems[serialNumber]->print();
            }
            else {
                cout << "Предмет с таким серийным номером не найден." << endl;
            }
            break;
        }

        case 4: { // Показать всю инвентаризацию
            cout << "Инвентаризация:" << endl;
            for (const auto& pair : computers) {
                pair.second->print();
            }
            for (const auto& pair : tables) {
                pair.second->print();
            }
            for (const auto& pair : paintings) {
                pair.second->print();
            }
            for (const auto& pair : chairs) {
                pair.second->print();
            }
            for (const auto& pair : customItems) {
                pair.second->print();
            }
            break;
        }

        case 5: { // Сохранить инвентаризацию в файл
            saveInventory(computers, tables, paintings, chairs, customItems, customItemTypes);
            break;
        }

        case 6: { // Загрузить инвентаризацию из файла
            loadInventory(computers, tables, paintings, chairs, customItems, customItemTypes);
            break;
        }

        case 7: { // Создать новый пользовательский тип
            addCustomType(customItemTypes);
            break;
        }

        case 8: { // Показать количество предметов каждого типа
            countItems(computers, tables, paintings, chairs, customItems);
            break;
        }

        case 9: { // Выход
            cout << "Выход..." << endl;
            break;

        default:
            cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
            break;
        }
        }
    } while (choice != 9);

    return 0;
}

