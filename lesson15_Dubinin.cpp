#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <list>
using namespace std;

void Empty_Print()
{
    std::cout << std::endl;
};

void Main_Menu_Print()
{
    using namespace std;
    // Empty_Print();
    cout << "MENU" << endl;
    cout << "1. Show computer's list" << endl;
    cout << "2. Show monitor's list" << endl;
    cout << "3. Show chair's list" << endl;
    cout << "4. Show table's list" << endl;
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
void Is_Digit_Checking(string check_str)
{
    while (!IsDigit(check_str))
    {
        cout << "That's not a number" << endl
             << "Repeat input" << endl;
        cin >> check_str;
    }
}

map<string, string> id_map; // объявление глобально

void ID_Save(string id, string type) // сохраняет айди в мапу
{
    id_map.emplace(id, type);
}

void Delete_Element_ID(string search_id)
{
    auto it = id_map.find(search_id);
    if (it != id_map.end())
    {
        id_map.erase(search_id);
    }
}

namespace Computer
{
    class Computers
    {
        std::string ID;
        std::string serial_number;
        std::string graph_card;
        std::string cpu;

    public:
        friend std::ostream &operator<<(std::ostream &out, const Computers &computer);
        Computers(std::string _serial_number, std::string _graph_card, std::string _cpu, std::string _ID)
        {
            ID = _ID;
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

        void Set_ID(std::string set_ID)
        {
            ID = set_ID;
        };
        std::string Get_ID() const
        {
            return ID;
        };

        static void Computer_Menu_Print()
        {
            using namespace std;
            cout << "1.1 Emplace new element" << endl;
            cout << "1.2 Delete element" << endl;
            cout << "1.3 Change some element's characteristic" << endl;
            cout << "1.4 Get back to main menu" << endl;
            Empty_Print();
        }

        static void Computer_List_Print(std::list<Computers> &List_computer)
        {
            Empty_Print();
            if (List_computer.empty())
            {
                cout << "There's nothing in this list" << endl;
            }
            else
            {
                for (auto i = List_computer.begin(); i != List_computer.end(); i++)
                {
                    int n = distance(List_computer.begin(), i);
                    cout << "computer №" << (n + 1) << endl;
                    cout << *i << endl;
                    cout << endl;
                }
            }
        }

        static void Map_Computer_Deleting(std::list<Computers> &List_computer) // ищет айди в мапе, выполняет удаление по айди
        {
            std::string requested_ID;
            cout << "Enter ID of object you want to delete: ";
            cin >> requested_ID;
            auto it = id_map.find(requested_ID);
            string a;
            if (it != id_map.end())
            {
                a = it->second; // а - тип эл-та
            }
            if (a == "Computer")
            {
                for (auto i = List_computer.begin(); i != List_computer.end(); i++)
                {
                    Computers temporary_variable = *i;
                    if (requested_ID == temporary_variable.ID)
                    {
                        
                        List_computer.erase(i);
                        Delete_Element_ID(requested_ID);
                        cout << "Object with ID: '" << requested_ID << "' has been removed" << endl;
                    }
                }
            }
        }

        static void Map_Computer_Changing(std::list<Computers> &List_computer)
        {
            std::string requested_ID;
            cout << "Enter ID of object you want to change: ";
            cin >> requested_ID;
            auto it = id_map.find(requested_ID);
            string a;
            if (it != id_map.end())
            {
                a = it->second; // а - тип эл-та
            }
            if (a == "Computer")
            {
                for (auto q = List_computer.begin(); q != List_computer.end(); q++)
                {
                    Computers temporary_variable = *q;
                    if (requested_ID == temporary_variable.ID)
                    {
                        cout << "You could change: " << endl;
                        cout << "1. Registration number" << endl;
                        cout << "2. Graphic card" << endl;
                        cout << "3. CPU" << endl;
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
                            Empty_Print();
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
                            Empty_Print();
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
                            Empty_Print();
                            cout << peremennaya;
                        }
                        break;

                        default:
                            break;
                        };
                    };
                }
            }
        }

        // void
        static void Computer_switch(std::list<Computers> &List_computer)
        {
            string choisestr1;
            Computer_List_Print(List_computer);
            Computer_Menu_Print();

            string second_choise_str;
            cin >> second_choise_str;
            Is_Digit_Checking(second_choise_str);
            int second_choise = stoi(second_choise_str);
            while (second_choise != 4)
            {

                switch (second_choise)
                {
                case 1:
                {
                    string comp_id;
                    string comp_number;
                    string comp_card;
                    string comp_cpu;

                    Empty_Print();
                    cout << "Enter object's ID: ";
                    cin >> comp_id;
                    cout << "Enter computer's registration number: ";
                    cin >> comp_number;
                    cout << "Enter computer's graphic card: ";
                    cin >> comp_card;
                    cout << "Enter computer's CPU: ";
                    cin >> comp_cpu;
                    Computers new_object{comp_number, comp_card, comp_cpu, comp_id};

                    List_computer.push_back(new_object);
                    ID_Save(comp_id, "Computer");
                    Empty_Print();
                    cout << "Updated computer's list: ";
                    Empty_Print();
                    Computer_List_Print(List_computer);
                    Empty_Print();
                    Computer_Menu_Print();
                    string case1_str;
                    cin >> case1_str;
                    Is_Digit_Checking(case1_str);
                    second_choise = stoi(case1_str);
                }
                break;

                case 2:
                {

                    Map_Computer_Deleting(List_computer);
                    Computer_Menu_Print();
                    string case2_str;
                    cin >> case2_str;
                    Is_Digit_Checking(case2_str);
                    second_choise = stoi(case2_str);
                }
                break;
                case 3:
                {

                    Map_Computer_Changing(List_computer);
                    Computer_Menu_Print();
                    string case3_str;
                    cin >> case3_str;
                    Is_Digit_Checking(case3_str);
                    second_choise = stoi(case3_str);
                }
                break;

                } // скобка на свитч с компами
            }
        } // скобка на метод работы с компами
    };
    std::ostream &operator<<(std::ostream &out, const Computer::Computers &computer)
    {
        return out << "object's ID: " << computer.Get_ID() << std::endl
                   << "computer's registration number: " << computer.Get_number() << std::endl
                   << "computer's graphic card: " << computer.Get_card() << std::endl
                   << "computer's CPU: " << computer.Get_cpu() << std::endl;
    }

} // скобка на неймспейс компов

namespace Monitor
{

    struct Resolution
    {
        friend std::ostream &operator<<(std::ostream &out, const Resolution &reso);
        // friend std::istream &operator>>(srd::istream &in, const Resolution &reso);
        int aflat_pix; // горизонтально
        int apeak_pix; // вертикально
    };
    std::ostream &operator<<(std::ostream &outm, const Monitor::Resolution &reso)
    {
        return outm << reso.aflat_pix << "x" << reso.apeak_pix;
    }
    void Read_Resolution(Resolution read)
    {
        cout << "Enter the number of pixels horizontally: " << endl;
        cin >> read.aflat_pix;
        cout << "Enter the number of pixels vertically: " << endl;
        cin >> read.apeak_pix;
    }

    class Monitors
    {
        std::string ID;
        std::string serial_number;
        Resolution resolution;
        int diagonal;

    public:
        friend std::ostream &operator<<(std::ostream &outm, const Monitors &monitor);

        void Set_number(std::string set_number)
        {
            serial_number = set_number;
        };
        std::string Get_number() const
        {
            return serial_number;
        };
        void Set_resolution(Resolution set_resolution)
        {
            resolution = set_resolution;
        };
        Resolution Get_resolution() const
        {
            return resolution;
        };
        void Set_diagonal(int set_diagonal)
        {
            diagonal = set_diagonal;
        };
        int Get_diagonal() const
        {
            return diagonal;
        };
        void Set_ID(std::string set_ID)
        {
            ID = set_ID;
        };
        std::string Get_ID() const
        {
            return ID;
        };

        static void Monitors_Menu_Print()
        {
            cout << "1.1 Emplace new element" << endl;
            cout << "1.2 Delete element" << endl;
            cout << "1.3 Change some element's characteristic" << endl;
            cout << "1.4 Get back to main menu" << endl;
            Empty_Print();
        };

        static void Monitors_List_Print(std::list<Monitors> &List_monitor)
        {

            int len = List_monitor.size();
            if (len == 0)
            {
                cout << "There's nothing in this list" << endl;
                Empty_Print();
            }
            for (auto i = List_monitor.begin(); i != List_monitor.end(); i++)
            {
                int n = distance(List_monitor.begin(), i);

                cout << "monitor №" << (n + 1) << endl;
                cout << *i << endl;
                cout << endl;
            }
        };

        static void Monitor_switch()
        {
            string choisestr1;
            list<Monitors> List_monitor;
            Monitors_List_Print(List_monitor);
            Monitors_Menu_Print();
            string second_choise_str;
            cin >> second_choise_str;
            Is_Digit_Checking(second_choise_str);
            int second_choise = stoi(second_choise_str);
            while (second_choise != 4)
            {

                switch (second_choise)
                {
                case 1:
                {
                    std::string mon_ID;
                    std::string mon_number;
                    Resolution mon_resolution;
                    int mon_diagonal;
                    cout << "Enter monitor's registration number: ";
                    cin >> mon_number;
                    Read_Resolution(mon_resolution);
                    cout << "Enter monitor's diagonal: ";
                    cin >> mon_diagonal;
                    // Monitors new_object{mon_ID, mon_number, mon_resolution, mon_diagonal};
                    // List_monitor.push_back(new_object);
                    Empty_Print();
                    cout << "Updated monitor's list: ";
                    Empty_Print();
                    Monitors_List_Print(List_monitor);
                    Empty_Print();
                    Monitors_Menu_Print();
                    string case1_str;
                    cin >> case1_str;
                    Is_Digit_Checking(case1_str);
                    second_choise = stoi(case1_str);
                }
                }
            }

        }; // скоба на класс мониторов
    };
    std::ostream &operator<<(std::ostream &outm, const Monitor::Monitors &monitor)
    {
        return outm << "object's ID: " << monitor.Get_ID() << std::endl
                    << "monitor's serial number: " << monitor.Get_number() << std::endl
                    << "monitor's resolution: " << monitor.Get_resolution() << std::endl
                    << "length of diagonal: " << monitor.Get_diagonal() << std::endl;
    }

    // скобка на неймспейс на мониторы
}
class Tables
{
    int length;
    int width;
    string material;
};

int main()
{
    int main_choise;
    list<Computer::Computers> List_computer;
    while (main_choise != 6)
    {
        Empty_Print();
        Main_Menu_Print();
        Empty_Print();
        string main_choise_str;
        cin >> main_choise_str;
        Is_Digit_Checking(main_choise_str);
        int main_choise = stoi(main_choise_str);

        switch (main_choise)
        {
        case 1:
        {
            Computer::Computers::Computer_switch(List_computer);
        }
        break;
            /*case 2:
            {
            }
            break;*/
        }
    }
}; // скобка мэйна