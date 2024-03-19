#include <iostream>
#include "task1.h"

int main()
{
    std::cout << "You can choose\n1. Laptop\n2. Pen\n3. Table\n4. Notebook" << std::endl;
    int n;
    std::cin >> n;
    switch (n)
    {
    case 1:
    {
        std::cout << "Enter efficiency: ";
        int ef;
        std::cin >> ef;
        std::cout << "Enter processor clock frequency: ";
        int freq;
        std::cin >> freq;
        std::cout << "Enter processor capacity: ";
        int cap;
        std::cin >> cap;
        Laptop laptop(ef, freq, cap);
        bool finish = true;
        while (finish)
        {
            std::cout << "Availible operations\n1 Get/Set efficiency, write 1.1 and print get or set and value\n";
            std::cout << "1.2 Get/Set processor clock frequency, write 1.2 and print get or set and value\n";
            std::cout << "1.3 Get/Set processor capacity, write 1.3 and print get or set and value\n";
            // Как будто никто смотреть это не будет
        }
        break;
    }
    case 2:
    {
        std::cout << "Enter cahrge of your pen: ";
        int charge;
        std::cin >> charge;
        std::cout << "Press 1 if your pen with you else press 0: ";
        bool withMe;
        std::cin >> withMe;
        Pen pen(charge, withMe);
        break;
    }
    case 3:
    {
        std::cout << "Enter height of the table: ";
        int height;
        std::cin >> height;
        std::cout << "Enter lenght of the table: ";
        int len;
        std::cin >> len;
        std::cout << "Enter width of the table: ";
        int width;
        std::cin >> width;
        std::cout << "Enter weight of the table: ";
        int weight;
        std::cin >> weight;
        std::cout << "Enter material of the table: ";
        std::string mat;
        std::cin >> mat;
        Table table(height, len, width, weight, mat);
        break;
    }
    case 4:
    {
        std::cout << "Enter kol pages of notebook: ";
        int kol;
        std::cin >> kol;
        std::cout << "Enter current page of notebook: ";
        int curPage;
        std::cin >> curPage;
        Notebook notebook(kol, curPage);
        if (curPage != 0)
        {
            notebook.MakeUsed();
        }
        break;
    }
    default:
        break;
    }
    return 0;
}
