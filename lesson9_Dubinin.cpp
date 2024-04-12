#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <list>

struct Base
{
    int width;
    int length;
    int hight;
    std::string color;
};

class Computers
{
    std::string serial_number;
    std::string graph_card;
    std::string cpu;

public:
    friend std::ostream &operator<<(std::ostream &out, const Computers &computer);
    Computers(std::string _serial_number, std::string _graph_card, std::string _cpu)
    {
        serial_number = _serial_number;
        graph_card = _graph_card;
        cpu = _cpu;
    }
    void Set_number(){

    };
    std::string Get_number() const
    {
        return serial_number;
    };
    void Set_card(){

    };
    std::string Get_card() const
    {
        return graph_card;
    };
    void Set_cpu(){

    };
    std::string Get_cpu() const
    {
        return cpu;
    };
};

std::ostream &operator<<(std::ostream &out, const Computers &computer)
{
    return out << "computer's registration number: " << computer.Get_number() << std::endl
               << "computer's graphic card: " << computer.Get_card() << std::endl
               << "computer's CPU: " << computer.Get_cpu() << std::endl;
}

class Monitors
{
    Base screen;
    int resolution;
};

class Portaits
{
    Base picture;
    std::string name;
};

class Tables
{
};

bool IsDigit(std::string str)
{
    size_t z = str.length();
    for (size_t i = 0; i < z; i++)
    {
        if (!std::isdigit(str[i]))
        {
            return false;
        }
    };
    return true;
};

void Empty_Print()
{
    for (int i = 0; i < 2; i++)
    {
        std::cout << std::endl;
    }
};

void Menu_Print()
{
    using namespace std;
    Empty_Print();
    cout << "MENU" << endl;
    cout << "1. Show  computer's list" << endl;
    cout << "2. Show table's list" << endl;
    cout << "3. Show chair's list" << endl;
    cout << "4. Show portaits's list" << endl;
    cout << "5. Show all lists" << endl;
    cout << "6. Exit" << endl;
}

/*void Computer_List_Print(){
    using namespace std;

    for (auto i = List_computer.begin(); i != List_computer.end(); i++)
                {
                    int n = distance(List_computer.begin(), i);
                    if (n == 0){
                        cout<<"There's nothing in this list yet"<<endl;
                    }
                    else{
                    cout << "computer №" << (n + 1) << endl;
                    cout << *i << endl;
                    cout << endl;
                    }
                }
}*/

int main()
{

    using namespace std;
    string choisestr1;

    list<Computers> List_computer;

    Menu_Print(); // печать менюшки

    Empty_Print();

    bool res = false;
    do
    {
        cin >> choisestr1;
        Empty_Print();
        res = !IsDigit(choisestr1);
        if (res)
        {
            cout << "Wrong number. Enter value again:\n";
        }
    } while (res);

    int first_choise = stoi(choisestr1);
    while (first_choise != 6)
    {
        switch (first_choise)
        {
        case 1:
        {
            for (auto i = List_computer.begin(); i != List_computer.end(); i++)
            {
                int n = distance(List_computer.begin(), i);

                cout << "computer №" << (n + 1) << endl;
                cout << *i << endl;
                cout << endl;
            }

            cout << "1.1 Emplace new element" << endl;
            cout << "1.2 Delete element" << endl;
            cout << "1.3 Change some element's characteristic" << endl;
            cout << "1.4 Get back to main menu" << endl;
            Empty_Print();
            string choisestr2;
            cin >> choisestr2;

            while (!IsDigit(choisestr2))
            {
                cout << "Wrong number. Enter value again:\n";
                cin >> choisestr2;
                Empty_Print();
            }
            int second_coise = stoi(choisestr2);
            Empty_Print();
            switch (second_coise)
            {
            case 1:
            {
                string comp_number;
                string comp_card;
                string comp_cpu;

                cout << "Enter computer's number: ";
                cin >> comp_number;
                cout << "Enter computer's graphic card: ";
                cin >> comp_card;
                cout << "Enter computer's CPU: ";
                cin >> comp_cpu;
                Computers new_object{comp_number, comp_card, comp_cpu};

                List_computer.push_back(new_object);
                Empty_Print();
                cout << "Updated computer's list: ";
                Empty_Print();
                for (auto i = List_computer.begin(); i != List_computer.end(); i++)
                {
                    int n = distance(List_computer.begin(), i);

                    cout << "computer №" << (n + 1) << endl;
                    cout << *i << endl;
                    cout << endl;
                }
            }
            break;

                break;
            case 2:
            {
                auto p = List_computer.begin();
                cout << "Which one element you want to remove?" << endl;
                Empty_Print();
                int k;
                cin >> k;
                advance(p, k - 1);
                List_computer.erase(p);
                Empty_Print();
                cout << "Updated computer's list: ";
                for (auto i = List_computer.begin(); i != List_computer.end(); i++)
                {
                    int n = distance(List_computer.begin(), i);
                    cout << "computer №" << (n + 1) << endl;
                    cout << *i << endl;
                    cout << endl;
                }
                break;
            }
            break;

            case 3:
            {
            }
            break;
            } // скобка на свитч с компами

        } // скобка на кейс работы с компами

        }; // скобка внешнего свитча
    };     // скобка закольцовки
};         // скобка мэйна