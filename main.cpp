#include <iostream>
#include <clocale>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<int> inventory_numbers;

bool check_inventory_number(int number) {
    for (int i = 0; i < inventory_numbers.size(); i++)
        if (inventory_numbers[i] == number)
            return true;

    return false;
}

// Функция требует ввести число от мин до макс
int input_int(int min, int max) {

    int answer;

    cout << ">> ";
    cin >> answer;

    // Если пользователь введет не число, поток cin заблокируется
    // и с него нельзя будет дальше получать данные
    // В этом случае cin.fail() будет давать true
    while (cin.fail() || answer < min || answer > max) {
        // Разблокируем поток
        cin.clear();
        // Проигнорируем символы, введенные пользователем
        cin.ignore(256, '\n');
        cout << "Ошибка ввода данных.\n>> ";
        // Потребуем ввести число заново
        cin >> answer;
    }

    return answer;
}

// Размеры предмета
struct Parameter {
    double height, width, length;

    Parameter() : height(0), width(0), length(0) {}
    
    Parameter(double h, double w, double l) : height(h), width(w), length(l) {};

    // Метод, аналогичный функции input_int, но для вещественных чисел
    double input_double() {

        double answer;

        cout << ">> ";
        cin >> answer;

        // Если пользователь введет не число, поток cin заблокируется
        // и с него нельзя будет дальше получать данные
        // В этом случае cin.fail() будет давать true
        while (cin.fail() || answer <= 0) {
            // Разблокируем поток
            cin.clear();
            // Проигнорируем символы, введенные пользователем
            cin.ignore(256, '\n');
            cout << "Ошибка ввода данных.\n>> ";
            // Потребуем ввести число заново
            cin >> answer;
        }

        return answer;
    }

    void input() {
        cout << endl << "Введите параметры предмета." << endl;
        
        cout << "Высота: ";
        height = input_double();

        cout << "Ширина: ";
        width = input_double();

        cout << "Длина: ";
        length = input_double();
        
        cout << endl;
    }

    void display() const {
        cout << "Ширина: " << width << endl;
        cout << "Высота: " << height << endl;
        cout << "Длина: " << length << endl;
    }
};


// Класс Стул 
class Chair {
private: 
    int number; 
    Parameter parameter;
public:
    
    Chair(double w = 0, double h = 0, double l = 0) : parameter(w, h, l) {}

    
    Chair(const Parameter& parameter) : parameter(parameter) {}
    
    void display() const {
        cout << "Стул #" << number << endl;
        parameter.display();
        cout << endl;
    }

    void change() {
        cout << "Новый инвентарный номер: ";
        number = input_int(1, 10000);

        while (check_inventory_number(number)) {
            cout << "Данный инвентарный номер уже существует!" << endl;
            number = input_int(1, 10000);
        }

        inventory_numbers.push_back(number);

        parameter.input();
    }

    int get_number() const {
        return number;
    }

    Parameter get_parameter() const {
        return parameter;
    }

    void set_number(int n) {
        number = n;
    }
};

// Класс Парта
class Table {
public:
    int number;
    Parameter parameter;

    Table(double w = 0, double h = 0, double l = 0) : parameter(w, h, l) {}

    Table(const Parameter& parameter) : parameter(parameter) {}

    void display() const {
        cout << "Парта #" << number << endl;
        parameter.display();
        cout << endl;
    }

    void change() {
        cout << "Новый инвентарный номер: ";
        number = input_int(1, 10000);

        while (check_inventory_number(number)) {
            cout << "Данный инвентарный номер уже существует!" << endl;
            number = input_int(1, 10000);
        }

        inventory_numbers.push_back(number);

        parameter.input();
    }

    int get_number() const {
        return number;
    }

    Parameter get_parameter() const {
        return parameter;
    }

    void set_number(int n) {
        number = n;
    }
};

// Класс Монитор
class Monitor {
public:
    int number;
    Parameter parameter;

    bool is_turned_on;   
    int resX;      
    int resY;
    int diagonal;

    Monitor() {}

    Monitor(bool v, int x, int y, int d) : is_turned_on(v), resX(x), resY(y), diagonal(d), parameter(0, 0, 0) {}

    void display() const {
        cout << "Монитор #" << number << endl << 
                "Разрешение экрана: " << resX << " на " << resY << " пикселей" << endl << 
                "Диагональ: " << diagonal << " дюймов" << endl << 
                (is_turned_on ? "Включен" : "Выключен") << endl << endl;
    }

    void set_turned(bool is_turned_on) {
        is_turned_on = is_turned_on;
    }

    // Метод для получения инвентарного номера
    int get_number() const {
        return number;
    }

    Parameter get_parameter() const {
        return parameter;
    }

    void set_number(int n) {
        number = n;
    }

    void change() {
        cout << "Новый инвентарный номер: ";
        number = input_int(1, 10000);

        while (check_inventory_number(number)) {
            cout << "Данный инвентарный номер уже существует!" << endl;
            number = input_int(1, 10000);
        }

        inventory_numbers.push_back(number);

        cout << "Включен ли монитор (да (1) / нет (2)): ";
        is_turned_on = input_int(1, 2) == 1;

        cout << "Разрешение по X: ";
        resX = input_int(1, 6000);

        cout << "Разрешение по Y: ";
        resY = input_int(1, 6000);

        cout << "Диагональ: ";
        diagonal = input_int(1, 6000);
    }
};

// Класс ПК
class PC {
public:
    int number;
    Parameter parameter;

    string processor; 
    string video_card;

    int mem;
    int ram;

    bool is_turned_on;

    PC() {}

    PC(bool v, int m, int r, string pr, string card) : is_turned_on(v), 
        mem(m), ram(r), processor(pr), video_card(card), parameter(0, 0, 0) {}

    void display() const {
        cout << "Компьютер #" << number << endl <<
                "Процессор: " << processor << endl <<
                "Видеокарта: " << video_card << endl <<
                "Постоянная память: " << mem << " Гб" << endl <<
                "Оперативная память: " << ram << " Гб" << endl <<
                (is_turned_on ? "Включен" : "Выключен") << endl << endl;
    }

    void set_turned(bool is_turned_on) {
        is_turned_on = is_turned_on;
    }

    int get_number() const {
        return number;
    }

    Parameter get_parameter() const {
        return parameter;
    }

    void set_number(int n) {
        number = n;
    }

    void change() {
        cout << "Новый инвентарный номер: ";
        number = input_int(1, 10000);

        while (check_inventory_number(number)) {
            cout << "Данный инвентарный номер уже существует!" << endl;
            number = input_int(1, 10000);
        }

        inventory_numbers.push_back(number);

        cout << "Включен ли ПК (да (1) / нет (2)): ";
        is_turned_on = input_int(1, 2) == 1;

        cout << "Постоянная память: ";
        mem = input_int(1, 10000);

        cout << "Оперативная память: ";
        ram = input_int(1, 10000);

        cout << "Процессор: ";
        getline(cin, processor);
        getline(cin, processor);

        cout << "Видеокарта: ";
        getline(cin, video_card);
        getline(cin, video_card);
    }
};

// Класс Предмета незарегистрированного типа
class UnregisteredItem {
public:
    int number;
    
    string name;
    string description;

    vector<pair<string, string>> attributes;

    UnregisteredItem() {}
    UnregisteredItem(const string& name, const string& description="Отстутствует") : 
        name(name), description(description) {}

    void display() const {
        cout << "Незарегистрированный предмет #" << number << endl <<
            "Название: " << name << endl <<
            "Описание: " << description << endl;
        
        for (int i = 0; i < attributes.size(); i++) {
            cout << "Свойство. " << attributes[i].first << " -> " << attributes[i].second << endl;
        }
        
        cout << endl;
    }

    void change() {
        cout << "Новый инвентарный номер: ";
        number = input_int(1, 10000);

        while (check_inventory_number(number)) {
            cout << "Данный инвентарный номер уже существует!" << endl;
            number = input_int(1, 10000);
        }

        inventory_numbers.push_back(number);

        cout << "Название предмета: ";
        cin >> name;

        cout << "Описание предмета в одну строку: ";
        getline(cin, description);
        getline(cin, description);

        string attribute, value;

        attributes.clear();
        
        cout << "Количество свойств: ";
        int n_attributes = input_int(0, 10);

        for (int i = 0; i < n_attributes; i++) {
            cout << "Название свойства " << i + 1 << ": ";
            cin >> attribute;

            cout << "Значение свойства " << i + 1 << ": ";
            cin >> value;

            attributes.push_back(make_pair(attribute, value));
        }
    }

    void set_number(int n) {
        number = n;
    }
    
    int get_number() const {
        return number;
    }
};

// Класс Меню
class Menu {
private:
    static vector<string> cmds;
    int answer;
public:
    int get_answer() const {
        return answer;
    }

    void run() {

        for (int i = 0; i < cmds.size(); i++) {
            cout << i + 1 << ". " << cmds[i] << endl;
        }

        answer = input_int(1, 10);
    }
};

// Вектор названий команд меню
vector<string> Menu::cmds = {
    "Вывести информацию о предметах",
    "Добавить новый учебный предмет",
    "Добавить новый неучебный предмет",
    "Изменить информацию о предмете",
    "Удалить информацию о предмете",
    "Считать данные из указанного файла",
    "Считать данные из файла по умолчанию",
    "Сохранить данные в указанный файл",
    "Сохранить данные в файл по умолчанию",
    "Завершить работу"
};

// Класс, реализующий систему инвентаризации
class InventorySystem {
private:
    Menu menu;

    vector<UnregisteredItem> unregistered_items;
    vector<Chair> chairs;
    vector<Table> tables;
    vector<Monitor> monitors;
    vector<PC> pcs;
public:
    void clear() {
        inventory_numbers.clear();
        unregistered_items.clear();
        chairs.clear();
        tables.clear();
        monitors.clear();
        pcs.clear();
    }

    void run() {

        int answer;
        while (1) {
            menu.run();
            answer = menu.get_answer();

            if (answer == 1) {
                show_info();
            }
            else if (answer == 2) {
                add_registered_item();
            }
            else if (answer == 3) {
                add_unregistered_item();
            }
            else if (answer == 4) {
                change_info();
            }
            else if (answer == 5) {
                remove_item();
            }
            else if (answer == 6) {
                string filename;
                cout << "Имя файла: ";
                cin >> filename;

                read_from_file(filename);
            }
            else if (answer == 7) {
                read_from_file("data.txt");
            }
            else if (answer == 8) {
                string filename;
                cout << "Имя файла: ";
                cin >> filename;

                save_to_file(filename);
            }
            else if (answer == 9) {
                save_to_file("data.txt");
            }
            else if (answer == 10) {
                break;
            }
        }
    }

    void show_info() const {

        cout << endl << "Информация о предметах:" << endl << endl;

        cout << "Учебные предметы" << endl;
        if (chairs.size() > 0) {
            for (int i = 0; i < chairs.size(); i++)
                chairs[i].display();
        }
        else {
            cout << "Стульев нет." << endl << endl;
        }

        if (tables.size() > 0) {
            for (int i = 0; i < tables.size(); i++)
                tables[i].display();
        }
        else {
            cout << "Парт нет." << endl << endl;
        }

        if (monitors.size() > 0) {
            for (int i = 0; i < monitors.size(); i++)
                monitors[i].display();
        }
        else {
            cout << "Мониторов нет." << endl << endl;
        }

        if (pcs.size() > 0) {
            for (int i = 0; i < pcs.size(); i++)
                pcs[i].display();
        }
        else {
            cout << "ПК нет." << endl << endl;
        }

        cout << "Неучебные предметы" << endl;
        if (unregistered_items.size() > 0) {
            for (int i = 0; i < unregistered_items.size(); i++)
                unregistered_items[i].display();
        }
        else {
            cout << "Прочих предметов нет." << endl << endl;
        }
    }

    void add_unregistered_item() {
        cout << endl << "Добавление незарегистрированного предмета." << endl;

        UnregisteredItem item;
        item.change();
        unregistered_items.push_back(item);

        cout << "Информация о предмете успешно добавлена в систему!" << endl << endl;
    }

    void add_registered_item() {
        cout << endl << "Добавление зарегистрированного предмета." << endl << endl;

        cout << "Название предмета (стул (1) / парта (2) / монитор (3) / ПК (4)): ";

        Parameter parameter;
        int answer = input_int(1, 4);

        if (answer == 1) {
            Chair chair;
            chair.change();

            chairs.push_back(chair);
        } else if (answer == 2) {
            Table table;
            table.change();
            
            tables.push_back(table);
        } else if (answer == 3) {
            Monitor monitor;
            monitor.change();

            monitors.push_back(monitor);
        } else if (answer == 4) {
            PC pc;
            pc.change();

            pcs.push_back(pc);
        }

        cout << "Информация о предмете успешно добавлена в систему!" << endl << endl;
    }

    void remove_item() {
        cout << endl << "Удаление информации о предмете." << endl << endl;

        show_info();

        cout << endl << "Введите инвентарный номер удаляемого предмета: ";

        int number;

        cin >> number;

        bool deleted = false;
        for (int i = 0; i < chairs.size(); i++) {
            if (chairs[i].get_number() == number) {
                chairs.erase(chairs.begin() + i);
                deleted = true;
                break;
            }
        }

        for (int i = 0; i < tables.size(); i++) {
            if (tables[i].get_number() == number) {
                tables.erase(tables.begin() + i);
                deleted = true;
                break;
            }
        }

        for (int i = 0; i < monitors.size(); i++) {
            if (monitors[i].get_number() == number) {
                monitors.erase(monitors.begin() + i);
                deleted = true;
                break;
            }
        }
        
        for (int i = 0; i < pcs.size(); i++) {
            if (pcs[i].get_number() == number) {
                pcs.erase(pcs.begin() + i);
                deleted = true;
                break;
            }
        }

        for (int i = 0; i < unregistered_items.size(); i++) {
            if (unregistered_items[i].get_number() == number) {
                unregistered_items.erase(unregistered_items.begin() + i);
                deleted = true;
                break;
            }
        }

        if (deleted) {

            for (int i = 0; i < inventory_numbers.size(); i++) {
                if (inventory_numbers[i] == number) {
                    inventory_numbers.erase(inventory_numbers.begin() + i);
                }
            }

            cout << "Информация о предмете успешно удалена!" << endl << endl;
        } 
        else
            cout << "Данных о предмете с указанным номером нет!" << endl << endl;
    }

    void change_info() {
        cout << endl << "Изменение информации о предмете." << endl << endl;

        show_info();

        cout << endl << "Введите инвентарный номер предмета: ";

        int number;

        cin >> number;

        for (int i = 0; i < inventory_numbers.size(); i++) {
            if (inventory_numbers[i] == number) {
                inventory_numbers.erase(inventory_numbers.begin() + i);
            }
        }

        bool changed = false;
        for (int i = 0; i < chairs.size(); i++) {
            if (chairs[i].get_number() == number) {
                chairs[i].change();
                changed = true;
                break;
            }
        }

        for (int i = 0; i < tables.size(); i++) {
            if (tables[i].get_number() == number) {
                tables[i].change();
                changed = true;
                break;
            }
        }

        for (int i = 0; i < monitors.size(); i++) {
            if (monitors[i].get_number() == number) {
                monitors[i].change();
                changed = true;
                break;
            }
        }

        for (int i = 0; i < pcs.size(); i++) {
            if (pcs[i].get_number() == number) {
                pcs[i].change();
                changed = true;
                break;
            }
        }

        for (int i = 0; i < unregistered_items.size(); i++) {
            if (unregistered_items[i].get_number() == number) {
                unregistered_items[i].change();
                changed = true;
                break;
            }
        }

        if (changed)
            cout << "Информация о предмете успешно изменена!" << endl << endl;
        else
            cout << "Данных о предмете с указанным номером нет!" << endl << endl;
    }

    void save_to_file(const string& filename) {
        ofstream fout(filename);

        fout << chairs.size() << endl;

        for (int i = 0; i < chairs.size(); i++) {
            fout << chairs[i].get_number() << " " << chairs[i].get_parameter().height
                << " " << chairs[i].get_parameter().width
                << " " << chairs[i].get_parameter().length << endl;
        }

        fout << tables.size() << endl;

        for (int i = 0; i < tables.size(); i++) {
            fout << tables[i].get_number() << " " << tables[i].get_parameter().height
                << " " << tables[i].get_parameter().width
                << " " << tables[i].get_parameter().length << endl;
        }

        fout << monitors.size() << endl;

        for (int i = 0; i < monitors.size(); i++) {
            fout << monitors[i].get_number() << " " << monitors[i].is_turned_on <<
                " " << monitors[i].resX << " " << monitors[i].resY << " " << monitors[i].diagonal << endl;
        }

        fout << pcs.size() << endl;

        for (int i = 0; i < pcs.size(); i++) {
            fout << pcs[i].get_number() << " " << pcs[i].is_turned_on << " " <<
                pcs[i].mem << " " << pcs[i].ram << endl;
            fout << pcs[i].processor << endl;
            fout << pcs[i].video_card << endl;
        }

        fout << unregistered_items.size() << endl;

        for (int i = 0; i < unregistered_items.size(); i++) {
            fout << unregistered_items[i].number << endl;
            fout << unregistered_items[i].name << endl;
            fout << unregistered_items[i].description << endl;

            fout << unregistered_items[i].attributes.size() << endl;

            for (int j = 0; j < unregistered_items[i].attributes.size(); j++) {
                fout << unregistered_items[i].attributes[j].first << " "
                    << unregistered_items[i].attributes[j].second << endl;
            }
        }

        fout.close();

        cout << "Информация сохранена в файл." << endl;
    }

    void read_from_file(const string& filename) {

        clear();

        ifstream fin(filename);

        if (!fin.is_open()) {
            cout << "Файл не может быть открыт!" << endl << endl;
            return;
         }

        int size;
        fin >> size;

        int number, h, w, l;

        for (int i = 0; i < size; i++) {
            fin >> number >> h >> w >> l;
            chairs.push_back(Chair(h, w, l));
            chairs[chairs.size() - 1].set_number(number);
            inventory_numbers.push_back(number);
        }

        fin >> size;

        for (int i = 0; i < size; i++) {
            fin >> number >> h >> w >> l;
            tables.push_back(Table(h, w, l));
            tables[tables.size() - 1].set_number(number);
            inventory_numbers.push_back(number);
        }

        fin >> size;

        bool is_turned_on;
        int x, y, d;
        for (int i = 0; i < size; i++) {
            fin >> number >> is_turned_on >> x >> y >> d;
            monitors.push_back(Monitor(is_turned_on, x, y, d));
            monitors[monitors.size() - 1].set_number(number);
            inventory_numbers.push_back(number);
        }

        fin >> size;

        int m, r;
        string pr, card;
        for (int i = 0; i < size; i++) {
            fin >> number >> is_turned_on >> m >> r;
            
            getline(fin, pr);
            getline(fin, pr);
            getline(fin, card);
            
            pcs.push_back(PC(is_turned_on, m, r, pr, card));
            pcs[pcs.size() - 1].set_number(number);
            inventory_numbers.push_back(number);
        }
        
        fin >> size;

        string name, description;
        for (int i = 0; i < size; i++) {

            UnregisteredItem item;

            fin >> item.number >> item.name;
            getline(fin, item.description);
            getline(fin, item.description);

            int n_attributes;
            fin >> n_attributes;

            string attribute, value;
            for (int i = 0; i < n_attributes; i++) {
                fin >> attribute >> value;
                item.attributes.push_back(make_pair(attribute, value));
            }
            
            unregistered_items.push_back(item);
        }
        
        fin.close();

        cout << "Информация считана из файла." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    InventorySystem inventory_system;

    // Создаём объект типа Система инвентаризации
    inventory_system.read_from_file("data.txt");

    // Запускаем его работу через метод run
    inventory_system.run();

    inventory_system.save_to_file("data.txt");
}
