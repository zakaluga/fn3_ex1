/*
int append_menu_func(WINDOW*& win, MENU*& menu, ITEM**& items, const std::vector<std::string> choices, const int sizeX, const int sizeY) {
}
int find_menu_func(WINDOW*& win, MENU*& menu, ITEM**& items, const std::vector<std::string> choices, const int sizeX, const int sizeY) {
}
int delete_menu_func(WINDOW*& win, MENU*& menu, ITEM**& items, const std::vector<std::string> choices, const int sizeX, const int sizeY) {
  
}
*/
#include <ncurses.h>
#include <menu.h>
#include <iostream>
#include <string>
#include <vector>

//allocate memory for window, initialize it for use
WINDOW* init_win (const int& sizeX, const int& sizeY, int& maxX, int& maxY) {
  WINDOW* win;
  initscr();
  clear();
  cbreak();
  noecho();
  getmaxyx(stdscr, maxY, maxX);
  curs_set(0);
  win = newwin(sizeY, sizeX, (maxY - sizeY) / 3, (maxX - sizeX) / 3);
  box(win, 0, 0);
  keypad(win, TRUE);
  clear;
  return win; 
}
//allocate memory and fill item**
ITEM** init_items(std::vector<std::string> choices) {
  ITEM** items = (ITEM**) malloc(choices.size()+1);
  for (int i = 0; i <= choices.size(); ++i) {
    items[i] = new_item(choices[i].c_str(), " ");
  }
  items[choices.size()] = (ITEM*)NULL;
  return items;
}
//allocate memory and fill menu* with item**
MENU* init_menu(ITEM** items) {
  return new_menu(items);
}
//free memory from menu*
void destroy_menu(MENU*& menu) {
  unpost_menu(menu);
  free_menu(menu);
}
//free memory from item**
void destroy_items(ITEM**& menu_items) {
  for(int i=0; i <= (sizeof(menu_items)/sizeof(menu_items[0])); ++i) {
    free_item(menu_items[i]);
  }
}
//post menu, refresh window
void display_menu(WINDOW*& win, MENU* menu, const int sizeX, const int sizeY) {
  set_menu_win(menu, win);
  set_menu_sub(menu, derwin(win, sizeY-(sizeY/5), sizeX-(sizeX/5), sizeY/5, sizeX/5));
  set_menu_mark(menu, " ");
  set_menu_format(menu, 5, 1);
  post_menu(menu);
  wrefresh(win);
}
//selector
int cycle(WINDOW*& win, MENU*& menu, ITEM**& items) { //at the end of the cycle, 
  int a;
  while (a = wgetch(win)) {
    switch(a) {
      case KEY_DOWN: {
        menu_driver(menu, REQ_DOWN_ITEM);
        break;
      }
      case KEY_UP: {
        menu_driver(menu, REQ_UP_ITEM);
        break;
      }
      case KEY_NPAGE: {
        menu_driver(menu, REQ_SCR_DPAGE);
        break;
      }
      case KEY_PPAGE: {
        menu_driver(menu, REQ_SCR_UPAGE);
        break;
      }
      case '\n': {
        int b = item_index(current_item(menu));
        destroy_menu(menu);
        destroy_items(items);
        delwin(win);
        wrefresh(win);
        return b;
      }
    }
  }
  return -1;
}



int main() {
  const std::vector<std::string> main_choices = {"Append item", "Get info", 
  "Delete item", "Exit"}; 
  const std::vector<std::string> append_choices = 
  {"Add Book", "Add Furniture", "Add Computer", "Add Monitor", "Add Other", "Back"};
  const std::vector<std::string> ginfo_choices = 
  {"Get all info", "Get books info", "Get furniture info", "Get computers info", 
  "Get monitors info", "Get other info", "Back"}; 
  const std::vector<std::string> del_choices = 
  {"Delete all", "Delete book", "Delete furniture", "Delete computer", 
  "Delete monitor", "Delete other", "Back"};
  WINDOW* win;
  ITEM** menu_items;
  MENU* menu;
  int maxY;
  int maxX;
  const int sizeX = 25;
  const int sizeY = 20;

  int ch;
  int b;
  init_win(sizeX, sizeY, maxX, maxY);
  while(ch=wgetch(win)) {
    menu_items = init_items(main_choices);
    menu = init_menu(menu_items);
    b = cycle(win, menu, menu_items);
  }
  delwin(win);
  wrefresh(win);
}