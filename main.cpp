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
    initscr();
    clear();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, maxY, maxX);
    clear();
  }


//general block ncurses windows end
  
  int main() {
    init();
    curs_set(0);
    const char *main_menu_choices[] = {"Append item", "Get info", "Delete item", "Exit"}, 
      *append_menu_choices[] = {}, 
      *ginfo_menu_choices[] = {}, 
      *del_menu_choices[] = {};
    MENU 
      *main_menu, *append_menu, *ginfo_menu, *del_menu;
    ITEM 
      **main_menu_items, **append_menu_items, **ginfo_menu_items, **del_menu_items;

    WINDOW *w;
    int key_input;
    /*
    ITEM **items;
    MENU *my_menu;
    ITEM *cur_item;
    init();
    mvprintw(LINES - 2, 0, "Program by Davydov Vladimir");
    post_menu(my_menu);
    refresh();

    free_item(*items);
    free_menu(my_menu);
    clear();
    refresh();
    endwin(); */
}