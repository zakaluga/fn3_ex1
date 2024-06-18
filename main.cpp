#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
class Item {
private:
    string name;
    string location;
    string serialNumber;
    string linkedItem;
 
public:
    Item(const string& name, const string& location, const string& serialNumber, const string& linkedItem) 
     : name(name), location(location), serialNumber(serialNumber), linkedItem(linkedItem){

    }
 
    virtual ~Item() {}
 
    virtual void displayInfo() const {
        cout << "\t1. Name: " << name << endl;
        cout << "\t2. Location: " << location << endl;
        cout << "\t3. Serial Number: " << serialNumber << endl;
        cout << "\t4. Linked Item: " << linkedItem << endl;
    }
 
    //getters
   string get_name()
    {
        return name;
    }
 
    string get_location()
    {
        return location;
    }
 
    string get_serNum()
    {
        return serialNumber;
    }
 
    string get_link()
    {
        return linkedItem;
    }
 
    //setters
    void set_name(string new_name)
    {
        name = new_name;
    }
 
    void set_location(string new_loc)
    {
        location = new_loc;
    }
 
    void set_serNum(string new_serNum)
    {
        serialNumber = new_serNum;
    }
 
    void set_link(string new_link)
    {
        linkedItem = new_link;
    }
 
};
 
class Desk : public Item {
private:
    string numDrawers;
 
public:
    Desk(const string& name, const string& location, const string& serialNumber, const string& linkedItem, string numDrawers)
        : Item(name, location, serialNumber, linkedItem), numDrawers(numDrawers) {}
 
    void displayInfo() const override {
        Item::displayInfo();
        cout << "\t5. Number of Drawers: " << numDrawers << endl;
    }
 
    string get_numDrawers()
    {
        return numDrawers;
    }
 
    void set_numDrawers(string new_numdr)
    {
        numDrawers = new_numdr;
    }
};
 
class Chair : public Item {
private:
    string material;
 
public:
    Chair(const string& name, const string& location, const string& serialNumber, const string& linkedItem, const string& material)
        : Item(name, location, serialNumber, linkedItem), material(material) {}
 
    void displayInfo() const override {
        Item::displayInfo();
        cout << "\t5. Material: " << material << endl;
    }
 
    string get_material()
    {
        return material;
    }
 
    void set_material(string new_material)
    {
        material = new_material;
    }
};
 
class Computer : public Item {
private:
    string processor;
 
public:
    Computer(const string& name, const string& location, const string& serialNumber, const string& linkedItem, const string& processor)
        : Item(name, location, serialNumber, linkedItem), processor(processor) {}
 
    void displayInfo() const override {
        Item::displayInfo();
        cout << "\t5. Processor: " << processor << endl;
    }
 
    string get_proc()
    {
        return processor;
    }
 
    void set_proc(string new_proc)
    {
        processor = new_proc;
    }
};
 
class Monitor : public Item {
private:
    string screenSize;
 
public:
    Monitor(const string& name, const string& location, const string& serialNumber, const string& linkedItem, string screenSize)
        : Item(name, location, serialNumber, linkedItem), screenSize(screenSize) {}
 
    void displayInfo() const override {
        Item::displayInfo();
        cout << "\t5. Screen Size: " << screenSize << " inches" << endl;
    }
 
    string get_screenSize()
    {
        return screenSize;
    }
 
    void set_screenSize(string new_size)
    {
        screenSize = new_size;
    }
};
 
class MiscItem : public Item {
private:
    string description;
 
public:
    MiscItem(const string& name, const string& location, const string& serialNumber, const string& linkedItem, const string& description)
        : Item(name, location, serialNumber, linkedItem), description(description) {}
 
    void displayInfo() const override {
        Item::displayInfo();
        cout << "\t5. Description: " << description << endl;
    }
 
    string get_desc()
    {
        return description;
    }
 
    void set_desc(string new_desc)
    {
        description = new_desc;
    }
};
 
class Inventory {
 private :
    vector<Desk> desks;
    vector<Chair> chairs;
    vector<Computer> computers;
    vector<Monitor> monitors;
    vector<MiscItem> miscItems;
 
public:
    // Добавление учебных предметов
    void addDesk(const Desk& desk) {
        desks.push_back(desk);
    }
 
    void addChair(const Chair& chair) {
        chairs.push_back(chair);
    }
 
    void addComputer(const Computer& computer) {
        computers.push_back(computer);
    }
 
    void addMonitor(const Monitor& monitor) {
        monitors.push_back(monitor);
    }
 
    // Добавление не учебных предметов
    void addMiscItem(const MiscItem& miscItem) {
        miscItems.push_back(miscItem);
    }
 
    //getters
    Desk& get_desk_by_index(int index)
    {
        if (index <= desks.size()) {
            return this->desks[index];
        }
    }
 
    Chair& get_chair_by_index(int index)
    {
        if (index <= chairs.size()) {
            return this->chairs[index];
        }
    }
 
    Computer& get_comp_by_index(int index)
    {
        if (index <= computers.size()) {
            return this->computers[index];
        }
    }
 
    Monitor& get_mon_by_index(int index)
    {
        if (index <= monitors.size()) {
            return this->monitors[index];
        }
    }
 
    MiscItem& get_mItem_by_index(int index)
    {
        if (index <= miscItems.size()) {
            return this->miscItems[index];
        }
    }
 
    void upd_desk_by_index(int index, int index_of_field, string tmp)
    {
        switch (index_of_field)
        {
        case 1:
        {
            get_desk_by_index(index).set_name(tmp);
            break;
        }
        case 2:
        {
            get_desk_by_index(index).set_location(tmp);
            break;
        }
        case 3:
        {
            get_desk_by_index(index).set_serNum(tmp);
            break;
        }
        case 4:
        {
            get_desk_by_index(index).set_link(tmp);
            break;
        }
        case 5:
        {
            get_desk_by_index(index).set_numDrawers(tmp);
            break;
        }
        default:
            break;
        }
    }
    void upd_chair_by_index(int index, int index_of_field, string tmp)
    {
        switch (index_of_field)
        {
        case 1:
        {
            get_chair_by_index(index).set_name(tmp);
            break;
        }
        case 2:
        {
            get_chair_by_index(index).set_location(tmp);
            break;
        }
        case 3:
        {
            get_chair_by_index(index).set_serNum(tmp);
            break;
        }
        case 4:
        {
            get_chair_by_index(index).set_link(tmp);
            break;
        }
        case 5:
        {
            get_chair_by_index(index).set_material(tmp);
            break;
        }
        default:
            break;
        }
    }
    void upd_comp_by_index(int index, int index_of_field, string tmp)
    {
        switch (index_of_field)
        {
        case 1:
        {
            get_comp_by_index(index).set_name(tmp);
        }
        case 2:
        {
            get_comp_by_index(index).set_location(tmp);
        }
        case 3:
        {
            get_comp_by_index(index).set_serNum(tmp);
        }
        case 4:
        {
            get_comp_by_index(index).set_link(tmp);
        }
        case 5:
        {
            get_comp_by_index(index).set_proc(tmp);
        }
        default:
            break;
        }
    }
    void upd_mon_by_index(int index, int index_of_field, string tmp)
    {
        switch (index_of_field)
        {
        case 1:
        {
            get_mon_by_index(index).set_name(tmp);
            break;
        }
        case 2:
        {
            get_mon_by_index(index).set_location(tmp);
            break;
        }
        case 3:
        {
            get_mon_by_index(index).set_serNum(tmp);
            break;
        }
        case 4:
        {
            get_mon_by_index(index).set_link(tmp);
            break;
        }
        case 5:
        {
            get_mon_by_index(index).set_screenSize(tmp);
            break;
        }
        default:
            break;
        }
    }
    void upd_mItem_by_index(int index, int index_of_field, string tmp)
    {
        switch (index_of_field)
        {
        case 1:
        {
            get_mItem_by_index(index).set_name(tmp);
            break;
        }
        case 2:
        {
            get_mItem_by_index(index).set_location(tmp);
            break;
        }
        case 3:
        {
            get_mItem_by_index(index).set_serNum(tmp);
            break;
        }
        case 4:
        {
            get_mItem_by_index(index).set_link(tmp);
            break;
        }
        case 5:
        {
            get_mItem_by_index(index).set_desc(tmp);
            break;
        }
 
        default:
            break;
        }
    }
 
 
    int get_size_desks()
    {
        return desks.size();
    }
 
    int get_size_chairs()
    {
        return chairs.size();
    }
 
    int get_size_comps()
    {
        return computers.size();
    }
 
    int get_size_mons()
    {
        return monitors.size();
    }
 
    int get_size_mItems()
    {
        
        return miscItems.size();
    }
 
    // Удаление учебных предметов
    void removeDesk(size_t index) {
        if (index < desks.size()) {
            desks.erase(desks.begin() + index);
        }
    }
 
    void removeChair(size_t index) {
        if (index < chairs.size()) {
            chairs.erase(chairs.begin() + index);
        }
    }
 
    void removeComputer(size_t index) {
        if (index < computers.size()) {
            computers.erase(computers.begin() + index);
        }
    }
 
    void removeMonitor(size_t index) {
        if (index < monitors.size()) {
            monitors.erase(monitors.begin() + index);
        }
    }
 
    // Удаление не учебных предметов
    void removeMiscItem(size_t index) {
        if (index < miscItems.size()) {
            miscItems.erase(miscItems.begin() + index);
        }
    }
 
    // Вывод информации о учебных предметах
    void displayDesks() const {
        cout << "\n\nВсе столы: \n";
        for (size_t i = 0; i < desks.size(); ++i) {
            cout << "Desk " << i + 1 << ":" << endl;
            desks[i].displayInfo();
            cout << endl;
        }
    }
 
    void displayChairs() const {
        cout << "\n\nВсе стулья: \n";
        for (size_t i = 0; i < chairs.size(); ++i) {
            cout << "Chair " << i + 1 << ":" << endl;
            chairs[i].displayInfo();
            cout << endl;
        }
    }
 
    void displayComputers() const {
        cout << "\n\nВсе компьютеры: \n";
        for (size_t i = 0; i < computers.size(); ++i) {
            cout << "Computer " << i + 1 << ":" << endl;
            computers[i].displayInfo();
            cout << endl;
        }
    }
 
    void displayMonitors() const {
        cout << "\n\nВсе мониторы: \n";
        for (size_t i = 0; i < monitors.size(); ++i) {
            cout << "Monitor " << i + 1 << ":" << endl;
            monitors[i].displayInfo();
            cout << endl;
        }
    }
 
    // Вывод информации о не учебных предметах
    void displayMiscItems() const {
        cout << "\n\nВсе неучебные предметы: \n";
        for (size_t i = 0; i < miscItems.size(); ++i) {
            cout << "Misc Item " << i + 1 << ":" << endl;
            miscItems[i].displayInfo();
            cout << endl;
        }
    }
 
    void displayItems() const {
        cout << "\nСписок всех предметов: \n";
        displayDesks();
        displayChairs();
        displayComputers();
        displayMonitors();
        displayMiscItems();
    }
};
 
void addItem(int choice_of_item, Inventory& inv)
{
    string name;
    string location;
    string serialNumber;
    string linkedItem;
    cout << "Введите имя предмета: ";
    cin >> name;
    cout << "Введите местоположение предмета: ";
    cin >> location;
    cout << "Введите серийный номер предмета: ";
    cin >> serialNumber;
    cout << "Введите связь с другим предметом: ";
    cin >> linkedItem;
    switch (choice_of_item)
    {
    case 1: {
        string numdrawers;

        cout << "Введите количество ящиков в столе:";
        cin >> numdrawers;
        Desk new_obj = Desk(name, location, serialNumber, linkedItem, numdrawers);
        cout << "\nСозданный объект : \n";
        new_obj.displayInfo();
        inv.addDesk(new_obj);
        break;
    }
    case 2: {
        string material;
        cout << "Введите материал, из которого сделан стул:";
        cin >> material;
        Chair new_obj = Chair(name, location, serialNumber, linkedItem, material);
        cout << "\nСозданный объект : \n";
        new_obj.displayInfo();
        inv.addChair(new_obj);
        break;
    }
    case 3: {
        string processor;
        cout << "Введите процессор компьютера:";
        cin >> processor;
        Computer new_obj = Computer(name, location, serialNumber, linkedItem, processor);
        cout << "\nСозданный объект : \n";
        new_obj.displayInfo();
        inv.addComputer(new_obj);
        break;
    }
    case 4: {
        string screenSize;
        cout << "Введите диагональ монитора:";
        cin >> screenSize;
        Monitor new_obj = Monitor(name, location, serialNumber, linkedItem, screenSize);
        cout << "\nСозданный объект : \n";
        new_obj.displayInfo();
        inv.addMonitor(new_obj);
        break;
    }
    case 5: {
        string description;
        cout << "Введите описание:";
        cin >> description;
        MiscItem new_obj = MiscItem(name, location, serialNumber, linkedItem, description);
        cout << "\nСозданный объект : \n";
        new_obj.displayInfo();
        inv.addMiscItem(new_obj);
        break;
    }
    default:
        break;
    }
}
 
void modifyItemMenu(Inventory& inv, int choice_of_item)
{
    int index = 0;
    int field_choice;
    string tmp;
    switch (choice_of_item) {
    case 1: {
        inv.displayDesks();
        cout << "\nВведите индекс предмета, который хотите изменить: ";
        cin >> index; 
        index -= 1;
        if (index <= inv.get_size_desks())
        {
            cout << "\nИзменяемый объект: \n";
            inv.get_desk_by_index(index).displayInfo();
            cout << "\t0. Назад\n";
            cout << "\nВведите номер поля, который хотите изменить: ";
            cin >> field_choice;
            if (field_choice != 0)
            {
                cout << "\nВведите новое значение : ";
                cin >> tmp;
                inv.upd_desk_by_index(index, field_choice, tmp);
            }
        }
        break;
    }
    case 2: {
        inv.displayChairs();
        cout << "\nВведите индекс предмета, который хотите изменить: ";
        cin >> index; index -= 1;
        if (index <= inv.get_size_chairs())
        {
            cout << "\nИзменяемый объект: \n";
            inv.get_chair_by_index(index).displayInfo();
            cout << "\t0. Назад\n";
            cout << "\nВведите номер поля, который хотите изменить: ";
            cin >> field_choice;
            if (field_choice != 0)
            {
                cout << "\nВведите новое значение : ";
                cin >> tmp;
                inv.upd_chair_by_index(index, field_choice, tmp);
            }
        }
        break;
    }
    case 3: {
        inv.displayComputers();
        cout << "\nВведите индекс предмета, который хотите изменить: ";
        cin >> index;  index -= 1;
        if (index <= inv.get_size_comps())
        {
            cout << "\nИзменяемый объект: \n";
            inv.get_comp_by_index(index).displayInfo();
            cout << "\t0. Назад\n";
            cout << "\nВведите номер поля, который хотите изменить: ";
            cin >> field_choice;
            if (field_choice != 0)
            {
                cout << "\nВведите новое значение : ";
                cin >> tmp;
                inv.upd_comp_by_index(index, field_choice, tmp);
            }
        }
        break;
    }
    case 4: {
        inv.displayMonitors();
        cout << "\nВведите индекс предмета, который хотите изменить: ";
        cin >> index;  index -= 1;
        if (index <= inv.get_size_mons())
        {
            cout << "\nИзменяемый объект: \n";
            inv.get_mon_by_index(index).displayInfo();
            cout << "\t0. Назад\n";
            cout << "\nВведите номер поля, который хотите изменить: ";
            cin >> field_choice;
            if (field_choice != 0)
            {
                cout << "\nВведите новое значение : ";
                cin >> tmp;
                inv.upd_mon_by_index(index, field_choice, tmp);
            }
        }
        break;
    }
    case 5: {
        inv.displayMiscItems();
        cout << "\nВведите индекс предмета, который хотите изменить: ";
        cin >> index;  index -= 1;
        if (index <= inv.get_size_mItems())
        {
            cout << "\nИзменяемый объект: \n";
            inv.get_mItem_by_index(index).displayInfo();
            cout << "\t0. Назад\n";
            cout << "\nВведите номер поля, который хотите изменить: ";
            cin >> field_choice;
            if (field_choice != 0)
            {
                cout << "\nВведите новое значение : ";
                cin >> tmp;
                inv.upd_mItem_by_index(index, field_choice, tmp);
            }
        }
        break;
    }
    default:
        break;
    }
}
 
 
void removeItem(Inventory& inv, int index)
{
    int i_index;
    switch (index)
    {
    case 1:
    {
        inv.displayDesks();
        cout << "\nВыберите индекс удаляемого предмета: ";
        cin >> i_index;
        inv.removeDesk(i_index - 1);
        break;
    }
    case 2:
    {
        inv.displayChairs();
        cout << "\nВыберите индекс удаляемого предмета: ";
        cin >> i_index;
        inv.removeChair(i_index - 1);
        break;
    }
    case 3:
    {
        inv.displayComputers();
        cout << "\nВыберите индекс удаляемого предмета: ";
        cin >> i_index;
        inv.removeComputer(i_index - 1);
        break;
    }
    case 4:
    {
        inv.displayMonitors();
        cout << "\nВыберите индекс удаляемого предмета: ";
        cin >> i_index;
        inv.removeMonitor(i_index - 1);
        break;
    }
    case 5:
    {
        inv.displayMiscItems();
        cout << "\nВыберите индекс удаляемого предмета: ";
        cin >> i_index;
        inv.removeMiscItem(i_index - 1);
        break;
    }
    default:
        break;
    }
}
 
void add_def_item(Inventory& inv)
{
    inv.addDesk(Desk("desk 1", "location 1", "101", "chair 1", "5"));
    inv.addChair(Chair("chair 1", "location 2", "202", "desk 1", "metal"));
    inv.addMiscItem(MiscItem("Something good", "location 3", "303", "Something not good", "It's finally works!"));
    inv.addMiscItem(MiscItem("Something not good", "location 4", "404", "Something good", "Actually!"));
}
 
int main()
{
 
    Inventory inv;
    cout << "Система инвентаризации пока не хранит никаких данных о предметах." << endl;
 
    // Регистрация предметов
    bool exitMenu = false;
    while (!exitMenu) {
        cout << "\nМеню:\n";
        cout << "1. Просмотреть список предметов\n";
        cout << "2. Добавить предмет\n";
        cout << "3. Изменить информацию об предмете\n";
        cout << "4. Удалить предмет\n";
        cout << "5. Добавить предметы для примера\n";
        cout << "0. Выйти\n";
        int choice;
        cin >> choice;
 
        switch (choice) {
        case 1: {
            inv.displayItems();
            break;
        }
        case 2: {
            int i_choice;
            cout << "\n1. Стол\n";
            cout << "2. Стул\n";
            cout << "3. Компьютер\n";
            cout << "4. Монитор\n";
            cout << "5. Неучебный предмет\n";
            cout << "0. Назад\n";
            cin >> i_choice;
            if (i_choice != 0)
            {
                addItem(i_choice, inv);
            }
            break;
        }
        case 3: {
            int i_choice;
            cout << "\n Что вы хотите изменить?";
            cout << "\n1. Стол\n";
            cout << "2. Стул\n";
            cout << "3. Компьютер\n";
            cout << "4. Монитор\n";
            cout << "5. Неучебный предмет\n";
            cout << "0. Назад\n";
            cin >> i_choice;
            if (i_choice != 0)
            {
                modifyItemMenu(inv, i_choice);
            }
            break;
        }
        case 4: {
            cout << "\nЧто вы хотите удалить?";
            int i_choice;
            cout << "\n1. Стол\n";
            cout << "2. Стул\n";
            cout << "3. Компьютер\n";
            cout << "4. Монитор\n";
            cout << "5. Неучебный предмет\n";
            cout << "0. Назад\n";
            cin >> i_choice;
            if (i_choice != 0)
            {
                removeItem(inv, i_choice);
            }
            break;
        }
        case 5:
        {
            add_def_item(inv);
            break;
        }
        case 0: {
            exitMenu = true;
            break;
        }
        default: {
            cout << "Неправильный выбор. Попробуйте снова.\n";
        }
        }
    }
 
    cout << "Программа завершена." << endl;
    return 0;
}