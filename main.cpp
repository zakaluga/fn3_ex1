#include <ncurses.h>
#include <menu.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>


//general block ncurses windows start
  int maxY = 0;
  int maxX = 0;
  
  void init() {
    initscr(); // создание окна
    clear();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
    getmaxyx(stdscr, maxY, maxX);
    clear(); // очищает экран
  }

  void interface(std::string ch[], ITEM **items, ITEM* c_item, int c, int n) {

  }

//general block ncurses windows end
  
  int main() {	
    std::string choices[] = {
    "Choice 1",
    "Choice 2",
    "Choice 3",
    "Choice 4",
    "Exit",
  };
    ITEM **items;
    int c;				
    MENU *my_menu;
    int n_choices;
    ITEM *cur_item;
    init();
    n_choices = sizeof(choices)/sizeof(choices[0]);
    items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

    for(int i = 0; i < n_choices; ++i) {
      items[i] = new_item(" ", choices[i].c_str());
    }
    items[n_choices] = (ITEM *)NULL;
    my_menu = new_menu((ITEM **)items);
    mvprintw(LINES - 2, 0, "Program by Davydov Vladimir");
    post_menu(my_menu);
    refresh();

    while((c = getch()) != '\n')
    {   switch(c){	
          case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
          case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
      }
    }	

    free_item(*items);
    free_menu(my_menu);
    clear();
    refresh();
    endwin();
}