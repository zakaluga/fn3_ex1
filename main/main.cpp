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

    std::vector<Computer> PC;
    std::cout << "Supply Computers\n";
    while(std::cin) {
        
    }





  return 0;
}
