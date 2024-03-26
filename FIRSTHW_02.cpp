#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

class MAININFO {
public:
    string I_NAME, I_INDEX;
    int I_Amount, I_Date;

    void update_info() {
        cout << "Name of ITEM:";
        cin >> I_NAME;
        cout << "Index of ITEM:";
        cin >> I_INDEX;
        cout << "Date of obtainment:";
        cin >> I_Date;
        cout << "Amount of ITEMs:";
        cin >> I_Amount;
        cout << "--------------------------" << endl;
    }
};

class Inventory {
public:
    MAININFO item;

    void display_info() {
        cout << "Name of ITEM:" << item.I_NAME << endl;
        cout << "Index of ITEM:" << item.I_INDEX << endl;
        cout << "Date of obtainment:" << item.I_Date << endl;
        cout << "Amount of ITEMs:" << item.I_Amount << endl;
        cout << "--------------------------" << endl << endl;
    }
};

int main() 
{
    setlocale(LC_ALL, "ru");


    int F;
    int N;
    cout << "[----------------------UNI ITEMS DATABASE----------------------]" << endl;
   


     /*Чтение данных из файла при запуске программы*/
    ifstream file("E:/Education/ВВИТ/SEM 1-2/GITHUB/TaskN1_02/inventory_data.txt");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    Inventory inventory[6];

    
     for (int i = 0; i < 6; i++) {
         file >> inventory[i].item.I_NAME >> inventory[i].item.I_INDEX >> inventory[i].item.I_Date >> inventory[i].item.I_Amount;
     }

     file.close();
    
    
    for (int i = 0; i < 6; i++) {
        cout << "INFORMATION FOR ITEM " << i + 1 << ":" << endl << endl;
        inventory[i].display_info();
    }

    cout << "IF INFO CHANGE IS NEEDED ENTER 1" << endl;
    cout << "TO END ENTER 2" << endl;
    cout << "V07" << endl;

    cin >> F;

    if (F < 2) {
        cout << "CHOOSE ITEM:" << endl;
        int i = 0;

        cin >> i;
        cout << "ENTER UPDATED INFO " << i << ":" << std::endl;
        inventory[i - 1].item.update_info();

        do {
            cout << "TO PROCEED WITH CHANGE ENTER 1" << endl;
            cout << "TO DISPLAY WHOLE LIST ENTER 2" << endl;
            cout << "TO SAVE CHANGES ENTER 3" << endl;
            cout << "TO EXIT PROGRAM ENTER 4" << endl << endl;

            cin >> N;
            switch (N) {
            case 1:
            {cout << "CHOOSE ITEM:" << endl;
            int i = 0;
            cin >> i;
            cout << "ENTER UPDATED INFO " << i << ":" << std::endl;
            inventory[i - 1].item.update_info();
            };
            break;

            case 2:
                for (int i = 0; i < 6; i++) {
                    cout << "INFORMATION FOR ITEM " << i + 1 << ":" << endl << endl;

                    inventory[i].display_info();
                }
                break;

            case 3: {
                //// Запись данных в файл при завершении программы
                ofstream outfile("E:/Education/ВВИТ/SEM 1-2/GITHUB/TaskN1_02/inventory_data.txt");
                if (!outfile.is_open()) {
                    cerr << "Error opening file." << endl;
                    return 1;
                }

                outfile << "[----------------------UNI ITEMS DATABASE----------------------]" << endl << endl;

                for (int i = 0; i < 6; i++) {
                    outfile
                        << " " << i + 1 << "." << endl
                        << "    " << "NAME: " << inventory[i].item.I_NAME << endl
                        << "    " << "INDEX: " << inventory[i].item.I_INDEX << endl
                        << "    " << "Date: " << inventory[i].item.I_Date << endl
                        << "    " << "Amount: " << inventory[i].item.I_Amount << endl << endl;
                }

                outfile.close();
            }
                  break;

            default:
                cout << "END" << endl;
                break;
            }
        } while (N < 4);
    }
    else {
        return 0;
    };

    
}
   