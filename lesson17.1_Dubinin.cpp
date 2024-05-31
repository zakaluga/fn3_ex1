#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <cstdio>
using namespace std;

void Empty_Print()
{
    std::cout << std::endl;
};

void Main_Menu_Print()
{
    // Empty_Print();
    cout << "MENU" << endl;
    cout << "1. Show computer's list" << endl;
    cout << "2. Show monitor's list" << endl;
    cout << "3. Show list of custom object's" << endl;
    cout << "4. Exit" << endl;
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

            if (List_computer.empty())
            {
                Empty_Print();
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
                            Empty_Print();
                            cout << "Enter new computer's registration number: ";
                            cin >> chan_number;
                            peremennaya.Set_number(chan_number);
                            cout << "Updated element: " << endl;
                            cout << peremennaya;
                            Empty_Print();
                        }
                        break;

                        case 2: // изменить вид. карту
                        {
                            string chan_card;
                            Empty_Print();
                            cout << "Enter new computer's graphic card: ";
                            cin >> chan_card;
                            peremennaya.Set_card(chan_card);
                            cout << "Updated element: " << endl;
                            cout << peremennaya;
                            Empty_Print();
                        }
                        break;

                        case 3: // изменить процессор
                        {
                            string chan_cpu;
                            Empty_Print();
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

namespace Custom
{
    class Customs
    {
        string ID;
        string name;
        map<string, string> object;

    public:
        friend std::ostream &operator<<(std::ostream &out, const Customs &custom);
        Customs(string _ID, string _name, map<string, string> _object)
        {
            ID = _ID;
            name = _name;
            object = _object;
        }
        void Set_ID(std::string set_ID)
        {
            ID = set_ID;
        };
        std::string Get_ID() const
        {
            return ID;
        };
        void Set_name(std::string set_name)
        {
            name = set_name;
        };
        std::string Get_name() const
        {
            return name;
        };

        static void Custom_Menu_Print()
        {
            Empty_Print();
            cout << "3.1 Emplace new element" << endl;
            cout << "3.2 Delete element" << endl;
            cout << "3.3 Change some element's characteristic" << endl;
            cout << "3.4 Get back to main menu" << endl;
            cout << endl;
        }

        static void Custom_List_Print(std::list<Customs> &List_custom)
        {
            if (List_custom.empty())
            {
                Empty_Print();
                cout << "There's nothing in this list" << endl;
            }
            else
            {
                for (auto i = List_custom.begin(); i != List_custom.end(); i++)
                {
                    cout << *i << endl;
                    cout << endl;
                }
            }
        }

        static void Map_Custom_Changing(std::list<Customs> &List_custom)
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
            if (a == "Custom")
            {
                for (auto q = List_custom.begin(); q != List_custom.end(); q++)
                {
                    Customs temporary_variable = *q;
                    if (requested_ID == temporary_variable.ID)
                    {
                        cout << "You could change: " << endl;
                        cout << "1. name" << endl;
                        
                        Empty_Print();
                        int ch_choise;
                        cin >> ch_choise;
                        Empty_Print();
                        Customs peremennaya = *q;
                        switch (ch_choise)
                        {      
                            case 1: // изменить номер
                        {
                            string chan_name;
                            Empty_Print();
                            cout << "Enter new object's name: ";
                            cin >> chan_name;
                            peremennaya.Set_name(chan_name);
                            cout << "Updated element: " << endl;
                            cout << peremennaya;
                            Empty_Print();
                        }
                        break;
                        }
                    }
                }
            }
        }

        static void Custom_Switch(std::list<Customs> &List_custom)
        {
            string choisestr1;
            Custom_List_Print(List_custom);
            Custom_Menu_Print();

            int second_choise;
            cin >> second_choise;
            while (second_choise != 4)
            {
                switch (second_choise)
                {
                case 1:
                {
                    string temp_ID;
                    string temp_name;
                    string temp_key;
                    string temp_value;
                    map<string, string> mapin;
                    int amount;
                    Empty_Print();
                    cout << "Enter object's ID: ";
                    cin >> temp_ID;
                    cout << "Enter object's name: ";
                    cin >> temp_name;
                    cout << "How many different characteristics are you going to introduce? ";
                    cin >> amount;
                    cout << "You can start entering. Remember to follow the format:" << endl
                         << "'characteristic'" << endl
                         << "'value'" << endl;
                    for (int i = 0; i < amount; i++)
                    {
                        cin >> temp_key;
                        cin >> temp_value;
                        mapin[temp_key] = temp_value;
                        cout << endl;
                    }
                    Customs new_object{temp_ID, temp_name, mapin};
                    List_custom.push_back(new_object);
                    ID_Save(temp_ID, "Custom");
                    cout << "Updated custom list: " << endl;
                    Custom_List_Print(List_custom);
                    for (const auto &[key, value] : mapin)
                    {
                        std::cout << key << ":  " << value << std::endl;
                    }
                    Empty_Print();
                    Custom_Menu_Print();
                    cin >> second_choise;
                }
                break;

                case 3:
                {
                    Map_Custom_Changing(List_custom);
                }
                break;
                default:
                    break;
                }
            }
        }
    };
    std::ostream &operator<<(std::ostream &out, const Custom::Customs &custom)
    {
        return out << "object's ID: " << custom.Get_ID() << std::endl
                   << "object's name: " << custom.Get_name() << std::endl;
                  
    }
};

int main()
{
    std::string main_choise;
    int main_choise_2;
    list<Computer::Computers> List_computer;
    list<Custom::Customs> List_custom;
    while (main_choise_2 != 4)
    {
        Empty_Print();
        Main_Menu_Print();
        Empty_Print();
        cin >> main_choise;
        auto IsDigit = [&](const std::string &s)
        {
            std::string::const_iterator it = s.begin();
            while (it != s.end() && std::isdigit(*it))
                ++it;
            return !s.empty() && it == s.end();
        };
        while (!IsDigit(main_choise))
        {
            std::cout << "That's not a number! Enter value again: " << std::endl;
            cin >> main_choise;
        }
        main_choise_2 = stoi(main_choise);

        switch (main_choise_2)
        {
        case 1:
        {
            Computer::Computers::Computer_switch(List_computer);
        }

        break;

        case 3:
        {
            Custom::Customs::Custom_Switch(List_custom);
        }
        break;
        }
    }
}; // скобка мэйна