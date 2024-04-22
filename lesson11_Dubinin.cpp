#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <list>
using namespace std;

struct Base
{
    int width;
    int length;
    int hight;
    std::string color;
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
    // Empty_Print();
    cout << "MENU" << endl;
    cout << "1. Show  computer's list" << endl;
    cout << "2. Show table's list" << endl;
    cout << "3. Show chair's list" << endl;
    cout << "4. Show portaits's list" << endl;
    cout << "5. Show all lists" << endl;
    cout << "6. Exit" << endl;
}

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
}

namespace Computer
{
    class Computers
    {
        std::string serial_number;
        std::string graph_card;
        std::string cpu;

    public:
        friend std::ostream &operator<<(std::ostream &out, const Computers &computer);
        // friend bool operator == (const Computers & other);
        Computers(std::string _serial_number, std::string _graph_card, std::string _cpu)
        {
            serial_number = _serial_number;
            graph_card = _graph_card;
            cpu = _cpu;
        }
        void Set_number(std::string set_number)
        {
            serial_number = set_number;
        };
        std::string Get_number() const
        {
            return serial_number;
        };
        void Set_card(std::string set_card)
        {
            graph_card = set_card;
        };
        std::string Get_card() const
        {
            return graph_card;
        };
        void Set_cpu(std::string set_cpu)
        {
            cpu = set_cpu;
        };
        std::string Get_cpu() const
        {
            return cpu;
        };
        void Set_all(std::string set_number, std::string set_card, std::string set_cpu)
        {
            serial_number = set_number;
            graph_card = set_card;
            cpu = set_cpu;
        };

        void Computer_Menu_Print()
        {
            using namespace std;
            cout << "1.1 Emplace new element" << endl;
            cout << "1.2 Delete element" << endl;
            cout << "1.3 Change some element's characteristic" << endl;
            cout << "1.4 Get back to main menu" << endl;
            Empty_Print();
        }

        void Computer_List_Print(std::list<Computers> &List_computer)
        {

            int len = List_computer.size();
            if (len == 0)
            {
                cout << "There's nothing in this list" << endl;
                Empty_Print();
            }
            for (auto i = List_computer.begin(); i != List_computer.end(); i++)
            {
                int n = distance(List_computer.begin(), i);

                cout << "computer №" << (n + 1) << endl;
                cout << *i << endl;
                cout << endl;
            }
        }

        void Computer_switch()
        {
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
                    Computer_List_Print(List_computer);

                    Computer_Menu_Print();
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
                    // Empty_Print();
                    while (second_coise != 4)
                    {
                        switch (second_coise)
                        {
                        case 1:
                        {
                            string comp_number;
                            string comp_card;
                            string comp_cpu;

                            cout << "Enter computer's registration number: ";
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
                            Computer_List_Print(List_computer);
                            Empty_Print();
                            Computer_Menu_Print();
                        }
                        break;

                            break;
                        case 2:
                        {
                            auto p = List_computer.begin();
                            cout << "Which one element you want to remove?" << endl;
                            Empty_Print();
                            int remove_index;
                            cin >> remove_index;
                            advance(p, remove_index - 1);
                            List_computer.erase(p);
                            Empty_Print();
                            cout << "Clearing is done" << endl;
                            cout << "Updated computer's list: " << endl;
                            Empty_Print();
                            Computer_List_Print(List_computer);
                            Empty_Print();
                            Computer_Menu_Print();
                        }
                        break;

                        case 3:
                        {
                            auto q = List_computer.begin();
                            cout << "Which computer do you want to change the characteristics of?" << endl;
                            Empty_Print();
                            int change_index;
                            cin >> change_index;
                            advance(q, change_index - 1);
                            cout << *q << endl;
                            cout << "You could change: " << endl;
                            cout << "1. Registration number" << endl;
                            cout << "2. Graphic card" << endl;
                            cout << "3. CPU" << endl;
                            cout << "4. All of them" << endl;
                            Empty_Print();
                            int ch_choise;
                            cin >> ch_choise;
                            Empty_Print();
                            Computers peremennaya = *q;
                            switch (ch_choise)
                            {
                            case 1: // изменить номер
                            {
                                string chan_number;
                                cout << "Enter new computer's registration number: ";
                                cin >> chan_number;
                                peremennaya.Set_number(chan_number);
                                cout << "Updated element: " << endl;
                                cout << peremennaya;
                            }
                            break;

                            case 2: // изменить вид. карту
                            {
                                string chan_card;
                                cout << "Enter new computer's graphic card: ";
                                cin >> chan_card;
                                peremennaya.Set_card(chan_card);
                                cout << "Updated element: " << endl;
                                cout << peremennaya;
                            }
                            break;

                            case 3: // изменить процессор
                            {
                                string chan_cpu;
                                cout << "Enter new computer's cpu: ";
                                cin >> chan_cpu;
                                peremennaya.Set_cpu(chan_cpu);
                                cout << "Updated element: " << endl;
                                cout << peremennaya;
                            }
                            break;

                            case 4: // изменить все поля
                            {
                                string local_num;
                                string local_card;
                                string local_cpu;
                                cout << "Enter new computer's registration number: ";
                                cin >> local_num;
                                cout << "Enter new computer's graphic card: ";
                                cin >> local_card;
                                cout << "Enter new computer's cpu:";
                                cin >> local_cpu;
                                peremennaya.Set_all(local_num, local_card, local_cpu);
                                cout << "Updated element: " << endl;
                                cout << peremennaya;
                            }
                            break;

                            default:
                                break;
                            }; // скобка свитча с выбором изменения характеристик
                        }
                        break;
                            // ДЕКОМПОЗИРОВАТЬ ВСЕ
                        case 4:
                        {
                        }
                        break;
                        } // скобка на свитч с компами
                    }
                } // скобка на кейс работы с компами

                }; // скобка внешнего свитча
            };
        }
    };

    std::ostream &operator<<(std::ostream &out, const Computers &computer)
    {
        return out << "computer's registration number: " << computer.Get_number() << std::endl
                   << "computer's graphic card: " << computer.Get_card() << std::endl
                   << "computer's CPU: " << computer.Get_cpu() << std::endl;
    }

} // скобка на неймспейс компов

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

int main()
{

    Menu_Print();
    Empty_Print();
    int main_choise;
    cin >> main_choise;
    switch (main_choise)
    {
    case 1:
    {    
        Computer::Computers first_case;
        first_case.Computer::Computers::Computer_Menu_Print();
        
    } 
    break;

    default:
        break;
    }

}; // скобка мэйна