#include "../headers/spec.hpp"
#include <ncurses.h>
int main(int argc, char* argv[])
{
    /*// инициализация (должна быть выполнена 
    // перед использованием ncurses)
    initscr();
    // Измеряем размер экрана в рядах и колонках
    int x, y;
    getmaxyx(stdscr, y, x);
    // перемещение курсора в стандартном экране
    move(y / 2, x / 2);
    printw("Hello world"); // вывод строки
    refresh(); // обновить экран
    getch(); // ждём нажатия символа
    */
//  endwin(); // завершение работы с ncurses
    std::vector<Book> arrayBooks;
    double x, y, z;
    std::string isbn, name;
    std::cout << "Supply coordinates\n";
    std::cout << "X = ";
    std::cin >> x;
    std::cout << "\nY = ";
    std::cin >> y;
    std::cout << "\nZ = ";
    std::cin >> z;
    std::cout << "\nSupply isbn: ";
    std::cin >> isbn;
    std::cout << "\nSupply book name: ";
    std::cin >> name;
    arrayBooks.push_back(Book(x, y, z, isbn, name));
    

  return 0;
}
