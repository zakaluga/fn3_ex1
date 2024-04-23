#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>

struct Position {
    int pos_x;
    int pos_y;
    Position(int x, int y): pos_x(x), pos_y(y) {}
    Position(): pos_x(0), pos_y(0) {}
    ~Position() {}
};

int CheckInputNum(int num) {
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        std::cout << "Incorrect input!" << std::endl << "Enter the inventory number again: ";
        std::cin >> num;
    }
    return num;
}

Position CheckInputPos(Position pos) {
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        std::cout << "Incorrect input!" << std::endl << "Enter the position (x, y) again: ";
        std::cin >> pos.pos_x >> pos.pos_y;
    }
    return pos;
}

int CheckInputDiag(int d){
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        std::cout << "Incorrect input!" << std::endl << "Enter the diagonal again: ";
        std::cin >> d;
    }
    return d;
}

int CheckInputMenu(int n) {
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        std::cout << "Incorrect input!" << std::endl << "Enter the menu item again: ";
        std::cin >> n;
    }
    return n;
}

class Specifications {
protected:
    int inv_num;
    Position p;
public:
    Specifications(int n, Position p): inv_num(n), p(p) {}
    Specifications(): inv_num(-1), p() {}
    ~Specifications() {}
    void setInvNum() {
        int num;
        std::cout << "Enter the new inventory number: ";
        std::cin >> num;
        inv_num = CheckInputNum(num);
    }
    void setPos() {
        Position pos;
        std::cout << "Enter the new position (x, y): ";
        std::cin >> pos.pos_x >> pos.pos_y;
        p = CheckInputPos(pos);
    }
    virtual void Print() const = 0;
    virtual void PrintToFile(std::ofstream &fout) = 0;
    virtual void ChangeInf() = 0;
};

class Chair: public Specifications {
private:
    static inline std::string name = "Chair";
    std::string material;
public:
    Chair(int n, Position p, std::string m): Specifications(n, p), material(m){}
    Chair(): Specifications(), material("-") {}
    ~Chair() {}
    void Print() const override {
        std::cout << name << ":\tInventory number: " << inv_num << "\tPosition: (" << p.pos_x << ", " << p.pos_y << ")\tMaterial: " << material <<std::endl;
    }
    void PrintToFile(std::ofstream &fout) override {
        fout << name << ":\tInventory number: " << inv_num << "\tPosition: (" << p.pos_x << ", " << p.pos_y << ")\tMaterial: " << material <<std::endl;
    }
    void EnterInf() {
        std::cout << "Enter the inventory number: ";
        std::cin >> inv_num;
        inv_num = CheckInputNum(inv_num);
        std::cout << "Enter the chair position (x, y): ";
        std::cin >> p.pos_x >> p.pos_y;
        p = CheckInputPos(p);
        std::cout << "Enter the material of the chair: ";
        std::cin.get();
        getline(std::cin, material);
    }
    void ChangeInf() override {
        int n;
        do{
            system("clear");
            std::cout << "What do you want to change: " << std::endl;
            std::cout << "   1.Inventory number" << std::endl;
            std::cout << "   2.Position" << std::endl;
            std::cout << "   3.Material" << std::endl;
            std::cout << "   4.Exit" << std::endl << std::endl;
            std::cout << "Enter the selected item: ";
            std::cin >> n;
            n = CheckInputMenu(n);
            switch (n)
            {
            case 1: 
                system("clear"); 
                setInvNum();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            case 2: 
                system("clear");
                setPos();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            case 3:
            {
                system("clear");
                std::string s;
                std::cout << "Enter the new material: ";
                std::cin.get();
                getline(std::cin, s);
                material = s;
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                break;
            }
            case 4: break;
            default:
                system("clear"); 
                std::cout << "The entered item does not exist!" << std::endl << std::endl; 
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            }
        }while(n != 4);
    }
};

class Table: public Specifications {
private:
    static inline std::string name = "Table";
    std::string material;
public:
    Table(int n, Position p, std::string m): Specifications(n, p), material(m) {}
    Table(): Specifications(), material("-") {}
    ~Table() {}
    void Print() const override {
        std::cout << name << ":\tNumber: " << inv_num << "\tPosition: (" << p.pos_x << ", " << p.pos_y << ")\tMaterial: " << material <<std::endl;
    }
    void PrintToFile(std::ofstream &fout) override {
        fout << name << ":\tNumber: " << inv_num << "\tPosition: (" << p.pos_x << ", " << p.pos_y << ")\tMaterial: " << material <<std::endl;
    }
    void EnterInf() {
        std::cout << "Enter the inventory number: ";
        std::cin >> inv_num;
        inv_num = CheckInputNum(inv_num);
        std::cout << "Enter the table position (x, y): ";
        std::cin >> p.pos_x >> p.pos_y;
        p = CheckInputPos(p);
        std::cout << "Enter the material of the table:";
        std::cin.get();
        getline(std::cin, material);
    }
    void ChangeInf() override {
        int n;
        do{
            system("clear");
            std::cout << "What do you want to change: " << std::endl;
            std::cout << "   1.Inventory number" << std::endl;
            std::cout << "   2.Position" << std::endl;
            std::cout << "   3.Material" << std::endl;
            std::cout << "   4.Exit" << std::endl << std::endl;
            std::cout << "Enter the selected item: ";
            std::cin >> n;
            n = CheckInputMenu(n);
            switch (n)
            {
            case 1: 
                system("clear"); 
                setInvNum();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            case 2: 
                system("clear");
                setPos();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            case 3:
            {
                system("clear");
                std::string s;
                std::cout << "Enter the new material: ";
                std::cin.get();
                getline(std::cin, s);
                material = s;
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                break;
            }
            case 4: break;
            default:
                system("clear"); 
                std::cout << "The entered item does not exist!" << std::endl << std::endl; 
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            }
        }while(n != 4);
    }
};

class CompSpecification {
protected:
    int inv_num;
    std::string type;
    std::string color;
public:
    CompSpecification(int n, std::string t, std::string c): inv_num(n), type(t), color(c) {}
    CompSpecification(): inv_num(-1), type("-"), color("-") {}
    ~CompSpecification() {}
    void setInvNum() {
        int num;
        std::cout << "Enter the new inventory number: ";
        std::cin >> num;
        inv_num = CheckInputNum(num);
    }
    void setType() {
        std::string s;
        std::cout << "Enter the new type: ";
        std::cin.get();
        getline(std::cin, s);
        type = s;
    }
    void setColor() {
        std::string s;
        std::cout << "Enter the new color: ";
        std::cin.get();
        getline(std::cin, s);
        color = s;
    }
    virtual void Print() const = 0;
    virtual void PrintToFile(std::ofstream &fout) = 0;
    virtual void EnterInf() {
        std::cout << "\tInventory number: ";
        std::cin >> inv_num;
        inv_num = CheckInputNum(inv_num);
        std::cout << "\tType: ";
        std::cin.get();
        getline(std::cin, type);
        std::cout << "\tColor: ";
        std::cin.get();
        getline(std::cin, color);
    }
};

class Screen: public CompSpecification {
private:
    static inline std::string name = "Screen";
    int diagonal;
public:
    Screen(int n, std::string t, std::string c, int d): CompSpecification(n, t, c), diagonal(d){}
    Screen(): CompSpecification(), diagonal(0) {}
    ~Screen() {}
    void Print() const override {
        std::cout << "\t" << name << ":\t\tInventory number: " << inv_num << "\tType: " << type << "\tColor: " << color << "\tDiagonal: " << diagonal << std::endl;
    }
    void PrintToFile(std::ofstream &fout) override {
        fout << "\t" << name << ":\t\tInventory number: " << inv_num << "\tType: " << type << "\tColor: " << color << "\tDiagonal: " << diagonal << std::endl;
    }
    void EnterInf() override {
        CompSpecification::EnterInf();
        std::cout << "\tDiagonal: ";
        std::cin >> diagonal;
        diagonal = CheckInputDiag(diagonal);
    }
    void ChangeInf() {
        int n;
        do{
            system("clear");
            std::cout << "What do you want to change: " << std::endl;
            std::cout << "   1.Inventory number" << std::endl;
            std::cout << "   2.Type" << std::endl;
            std::cout << "   3.Color" << std::endl;
            std::cout << "   4.Diagonal" << std::endl;
            std::cout << "   5.Exit" << std::endl << std::endl;
            std::cout << "Enter the selected item: ";
            std::cin >> n;
            n = CheckInputMenu(n);
            switch (n)
            {
            case 1: 
                system("clear"); 
                setInvNum();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            case 2: 
                system("clear"); 
                setType();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                break;
            case 3: 
                system("clear"); 
                setColor();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                break;
            case 4:
            {
                system("clear");
                int d;
                std::cout << "Enter the new Diagonal: ";
                std::cin >> d;
                diagonal = CheckInputDiag(d);
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            }
            case 5: break;
            default:
                system("clear");
                std::cout << "The entered item does not exist!" << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            }
        }while(n != 5);
    }
};
class Comp_mouse: public CompSpecification {
private:
    static inline std::string name = "Computer mouse";
public:
    Comp_mouse(int n, std::string t, std::string c): CompSpecification(n, t, c) {}
    Comp_mouse(): CompSpecification() {}
    ~Comp_mouse() {}
    void Print() const override {
        std::cout << "\t" << name << ":\tInventory number: " << inv_num << "\tType: " << type << "\tColor: " << color << std::endl;
    }
    void PrintToFile(std::ofstream &fout) override {
        fout << "\t" << name << ":\tInventory number: " << inv_num << "\tType: " << type << "\tColor: " << color << std::endl;
    }
    void EnterInf() override { 
        CompSpecification::EnterInf();
    }
    void ChageInf() {
        int n;
        do{
            system("clear");
            std::cout << "What do you want to change: " << std::endl;
            std::cout << "   1.Inventory number" << std::endl;
            std::cout << "   2.Type" << std::endl;
            std::cout << "   3.Color" << std::endl;
            std::cout << "   4.Exit" << std::endl << std::endl;
            std::cout << "Enter the selected item: ";
            std::cin >> n;
            n = CheckInputMenu(n);
            switch (n)
            {
            case 1: 
                system("clear"); 
                setInvNum();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            case 2: 
                system("clear");
                setType(); 
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                break;
            case 3: 
                system("clear");
                setColor();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                break;
            case 4: break;
            default:
                system("clear");
                std::cout << "The entered item does not exist!" << std::endl << std::endl;
                std::cout << "Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            }
        }while(n != 4);
    }
};
class Keyboard: public CompSpecification {
private:
    static inline std::string name = "Keyboard";
public:
    Keyboard(int n, std::string t, std::string c): CompSpecification(n, t, c) {}
    Keyboard(): CompSpecification() {}
    ~Keyboard() {}
    void Print() const override {
        std::cout << "\t" << name << ":\tInventory number: " << inv_num << "\tType: " << type << "\tColor: " << color << std::endl;     
    }
    void PrintToFile(std::ofstream &fout) override {
        fout << "\t" << name << ":\tInventory number: " << inv_num << "\tType: " << type << "\tColor: " << color << std::endl;     
    }
    void EnterInf() override {
        CompSpecification::EnterInf();
    }
    void ChageInf() {
        int n;
        do{
            system("clear");
            std::cout << "What do you want to change: " << std::endl;
            std::cout << "   1.Inventory number" << std::endl;
            std::cout << "   2.Type" << std::endl;
            std::cout << "   3.Color" << std::endl;
            std::cout << "   4.Exit" << std::endl << std::endl;
            std::cout << "Enter the selected item: ";
            std::cin >> n;
            n = CheckInputMenu(n);
            switch (n)
            {
            case 1: 
                system("clear"); 
                setInvNum();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            case 2: 
                system("clear");
                setType(); 
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                break;
            case 3: 
                system("clear");
                setColor();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                break;
            case 4: break;
            default:
                system("clear");
                std::cout << "The entered item does not exist!" << std::endl << std::endl;
                std::cout << "Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            }
        }while(n != 4);
    }
};

class Computer: public Specifications {
private:
    static inline std::string name = "Computer";
    std::string model;
    Screen scr;
    Comp_mouse mouse;
    Keyboard keyb;
public:
    Computer(int n, Position p, std::string m, Screen s, Comp_mouse c_m, Keyboard k): Specifications(n, p), model(m), scr(s), mouse(c_m), keyb(k) {}
    Computer(): Specifications(), model("-"), scr(), mouse(), keyb() {}
    ~Computer() {}
    void Print() const override {
        std::cout << name << ":\tNumber: " << inv_num << "\tPosition: (" << p.pos_x << ", " << p.pos_y << ")\tModel: " << model << std::endl;
        scr.Print();
        mouse.Print();
        keyb.Print();
    }
    void PrintToFile(std::ofstream &fout) override {
        fout << name << ":\tNumber: " << inv_num << "\tPosition: (" << p.pos_x << ", " << p.pos_y << ")\tModel: " << model << std::endl;
        scr.PrintToFile(fout);
        mouse.PrintToFile(fout);
        keyb.PrintToFile(fout);
    }
    void EnterInf() {
        std::cout << "Enter the inventory number: ";
        std::cin >> inv_num;
        inv_num = CheckInputNum(inv_num);
        std::cout << "Enter the computer position (x, y): ";
        std::cin >> p.pos_x >> p.pos_y;
        p = CheckInputPos(p);
        std::cout << "Enter the model of the computer: ";
        std::cin.get();
        getline(std::cin, model);
        std::cout << "Enter information about the screen: " << std::endl;
        scr.EnterInf();
        std::cout << "Enter information about the computer mouse: " << std::endl;
        mouse.EnterInf();
        std::cout << "Enter information about the keyboard: " << std::endl;
        keyb.EnterInf();
    }  
    void ChangeInf() override {
        int n;
        do{
            system("clear");
            std::cout << "What do you want to chage: " << std::endl;
            std::cout << "   1.Inventory number" << std::endl;
            std::cout << "   2.Position" << std::endl;
            std::cout << "   3.Model" << std::endl;
            std::cout << "   4.Screen" << std::endl;
            std::cout << "   5.Computer mouse" << std::endl;
            std::cout << "   6.Keyboard" << std::endl;
            std::cout << "   7.Exit" << std::endl << std::endl;
            std::cout << "Enter the selected item: ";
            std::cin >> n;
            n = CheckInputMenu(n);
            switch (n)
            {
            case 1: 
                system("clear");
                setInvNum();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            case 2: 
                system("clear");
                setPos();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout << "Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            case 3:
            {
                system("clear");
                std::string s;
                std::cout << "Enter the new model: ";
                std::cin.get();
                getline(std::cin, s);
                model = s;
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout << "Press any key to continue";
                std::cin.get();
                break;
            }
            case 4: scr.ChangeInf(); break;
            case 5: mouse.ChageInf(); break;
            case 6: keyb.ChageInf(); break;
            case 7: break;
            default:
                system("clear");
                std::cout << "The entered item does not exist!" << std::endl << std::endl;
                std::cout << "Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
        }
        }while(n != 7);
    }
};

class NonEdItem: public Specifications {
private:
   std::string name;
public:
   NonEdItem(std::string n, int num, Position p): name(n), Specifications(num, p) {}
   NonEdItem(): name("Non-education subject"), Specifications() {}
   ~NonEdItem() {}
   void Print() const override {
    std::cout << name << ":\tNumber: " << inv_num << "\tPosition: (" << p.pos_x << ", " << p.pos_y << ")" << std::endl;
   }
   void PrintToFile(std::ofstream &fout) override {
    fout << name << ":\tNumber: " << inv_num << "\tPosition: (" << p.pos_x << ", " << p.pos_y << ")" << std::endl;
   }
   void EnterInf() {
        std::cout << "Enter the name of the item: ";
        std::cin.get();
        getline(std::cin, name);
        std::cout << "Enter the inventory number of the item: ";
        std::cin >> inv_num;
        inv_num = CheckInputNum(inv_num);
        std::cout << "Enter the item position (x, y): ";
        std::cin >> p.pos_x >> p.pos_y;
        p = CheckInputPos(p);
    }
    void ChangeInf() override {
        int n;
        do{
            system("clear");
            std::cout << "What do you want to chage: " << std::endl;
            std::cout << "   1.Inventory number" << std::endl;
            std::cout << "   2.Position" << std::endl;
            std::cout << "   3.Exit" << std::endl << std::endl;
            std::cout << "Enter the selected item: ";
            std::cin >> n;
            n = CheckInputMenu(n);
            switch (n)
            {
            case 1: 
                system("clear"); 
                setInvNum();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            case 2: 
                system("clear");
                setPos();
                system("clear");
                std::cout << "Information has been changed." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
            case 3: break;
            default:
                system("clear"); 
                std::cout << "The entered item does not exist!" << std::endl << std::endl; 
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
                break;
        }
        }while(n != 3);
    }
};

int CheckInputItem(int n, std::vector<Specifications*> items) {
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        std::cout << "Incorrect input." << std::endl << "Enter the number of the item again: ";
        std::cin >> n;
    }
    while((n == 0) or (n > items.size())) {
        std::cout << "Incorrect number of the item." << std::endl << "Enter the number of the item again: ";
        std::cin >> n;
    }
    return n;
}

int main() {
    int n, k, l;
    std::vector<Specifications*> items;

    do {
        system("clear");
        std::cout << "Menu: " << std::endl;
        std::cout << "   1.View items and information about them" << std::endl;
        std::cout << "   2.Add new items" << std::endl;
        std::cout << "   3.Change information about items" << std::endl;
        std::cout << "   4.Delete information" << std::endl;
        std::cout << "   5.Save data to a file" << std::endl; 
        std::cout << "   6.Exit" << std::endl << std::endl;
        std::cout << "Enter the selected menu item: ";
        std::cin >> n;
        n = CheckInputMenu(n);
        switch (n)
        {
        case 1:             //просмотр информации о зарег. предметах
        {
            system("clear");
            if(items.empty())
                std::cout << "There is no information about the items." << std::endl << std::endl;
            else{
                std::cout << "Information about the items: " << std::endl << std::endl;
                for(int i = 0; i < items.size(); i++) {
                    std::cout << i + 1 << ") ";
                    items[i]->Print();
                }
                std::cout << std::endl;
            }
            std::cout << "Press any key to continue";
            std::cin.get();
            std::cin.get();
            break;
        }
        case 2:            //добавление новых предметов
        {
            do{
                system("clear");
                std::cout<< "Which item do you want to add: " << std::endl;
                std::cout << "   1.Chair" << std::endl;
                std::cout << "   2.Table" << std::endl;
                std::cout << "   3.Computer" << std::endl;
                std::cout << "   4.Non-educational item" << std::endl;
                std::cout << "   5.Exit" << std::endl << std::endl;
                std::cout << "Enter the selected menu item: ";
                std::cin >> k;
                k = CheckInputMenu(k);
                system("clear");
                switch (k)
                {
                case 1:
                {
                    Chair* new_chair = new Chair;
                    new_chair->EnterInf();
                    items.push_back(new_chair);
                    system("clear");
                    std::cout << "A new item has been added." << std::endl << std::endl;
                    std::cout << "Press any key to continue";
                    std::cin.get();
                    break;
                }
                case 2:
                {
                    Table* new_table = new Table;
                    new_table->EnterInf();
                    items.push_back(new_table);
                    system("clear");
                    std::cout << "A new item has been added." << std::endl << std::endl;
                    std::cout << "Press any key to continue";
                    std::cin.get();
                    break;
                }
                case 3:
                {
                    Computer* new_computer = new Computer;
                    new_computer->EnterInf();
                    items.push_back(new_computer);
                    system("clear");
                    std::cout << "A new item has been added." << std::endl << std::endl;
                    std::cout << "Press any key to continue";
                    std::cin.get();
                    break;
                }
                case 4:
                {
                    NonEdItem* new_item = new NonEdItem;
                    new_item->EnterInf();
                    items.push_back(new_item);
                    system("clear");
                    std::cout << "A new item has been added." << std::endl << std::endl;
                    std::cout << "Press any key to continue";
                    std::cin.get();
                    std::cin.get();
                    break;
                }
                case 5: break;
                default:
                    system("clear");
                    std::cout << "The entered item does not exist!" << std::endl << std::endl;
                    std::cout << "Press any key to continue";
                    std::cin.get();
                    std::cin.get();
                    break;
            }
            }while(k != 5);
            break;
        }
        case 3:            //изменение информации о зарег. предметах
        {
            system("clear");
            if(items.empty()){
                std::cout << "There is no information about the items." << std::endl << std::endl;
                std::cout << "Press any key to continue";
                std::cin.get();
                std::cin.get();
            }
            else{
                int n;
                std::cout << "List of items: " << std::endl << std::endl;
                for(int i = 0; i < items.size(); i++) {
                    std::cout << i + 1 << ") ";
                    items[i]->Print();
                }
                std::cout << "Enter the number of the item you want to change: ";
                std::cin >> n;
                n = CheckInputItem(n, items);
                system("clear");
                items[n - 1]->ChangeInf();
            }
            break;
        }
        case 4:             //удаление информации о зарег. предметах
        {
            system("clear");
            if(items.empty()){
                std::cout << "There is no information about the items." << std::endl << std::endl;
                std::cout << "Press any key to continue";
                std::cin.get();
                std::cin.get();
            }
            else{
                int n;
                std::cout << "List of items: " << std::endl;
                for(int i = 0; i < items.size(); i++) {
                    std::cout << i + 1 << ") ";
                    items[i]->Print();
                }
                std::cout << "Enter the number of the item you want to delete: ";
                std::cin >> n;
                n = CheckInputItem(n, items);
                system("clear");
                items.erase(items.begin() + n - 1);
                std::cout << "Information has been deleted." << std::endl << std::endl;
                std::cout << "Press any key to continue";
                std::cin.get();
                std::cin.get();
            }
            break;
        }
        case 5:             //сохранение информации в файл
        {
            system("clear");
            if(items.empty()){
                std::cout << "There is no information about the items to save." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
            }
            else{
                std::ofstream fout("InventorySystem.txt");
                for(int i = 0; i < items.size(); i++) {
                    items[i]->PrintToFile(fout);
                }
                fout.close();
                std::cout << "Information has been saved." << std::endl << std::endl;
                std::cout <<"Press any key to continue";
                std::cin.get();
                std::cin.get();
            }
            break;
        }
        case 6: break;
        default:
            system("clear");
            std::cout << "The entered item does not exist!" << std::endl << std::endl;
            std::cout <<"Press any key to continue";
            std::cin.get();
            std::cin.get();
            break;
        }
    }while(n != 6);
}