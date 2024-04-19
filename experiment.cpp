#include <ncurses.h>
#include <menu.h>
#include <iostream>
#include <string>
#include <vector>


//MENU* m;
//ITEM** m_items;
//int amount;
//int ch;
//WINDOW* w;  //сделать отдельно основное окно. явно выделить память

    
void init(WINDOW*& w) {
  initscr();
  clear();
  cbreak();
  noecho();
  keypad(w, TRUE);
  clear();
}
WINDOW* create_window() {
  int maxY = 0;
  int maxX = 0;
  getmaxyx(stdscr, maxY, maxX);
  WINDOW* win = newwin(10, 25, (maxY-10)/3, (maxX-25)/3);
  return win;
}
inline void free_everything(ITEM**& menu_items, MENU*& menu, int n) {
  unpost_menu(menu);
  free_menu(menu);
  for (int i = 0; menu_items[i] != (ITEM*)NULL; ++i) {
    free_item(menu_items[i]);
  }
  free_item(*menu_items);
}
MENU* create_menu(WINDOW*& w, ITEM**& menu_items, std::vector<std::string>&choices) {
  int n = choices.size();
  menu_items = (ITEM**)calloc(n+1, sizeof(ITEM*));
  for (int i = 0; i < n; ++i) {
    menu_items[i] = new_item(choices[i].c_str(), "");
  }
  menu_items[n] = (ITEM*)NULL;
  return new_menu(menu_items);
//  return menu;
}
inline void show_menu(WINDOW*& w, ITEM**& menu_items, MENU*& menu, std::vector<std::string>&choices) {
  set_menu_win(menu, w);
  set_menu_sub(menu, derwin(w, 8, 20, 2, 5)); //8 + 2 = 10 - Y; 20 + 5 = 25 - X
  set_menu_mark(menu, " ");
  set_menu_format(menu, 5, 1);
  post_menu(menu);
  wrefresh(w);
}


void main_window_func(WINDOW*& w, ITEM**& menu_items, MENU*& menu, std::vector<std::string>&choices) {
  
  init(w);
  box(w, 0, 0);
  
  menu = create_menu(w, menu_items, choices);
  set_menu_win(menu, w);
  set_menu_sub(menu, derwin(w, 8, 20, 2, 5)); //8 + 2 = 10 - Y; 20 + 5 = 25 - X
  set_menu_mark(menu, " ");
  set_menu_format(menu, 5, 1);
  post_menu(menu);
  wrefresh(w);
  //show_menu(w, menu_items, menu, choices);
  wrefresh(w);
  int ch;
  while(ch = wgetch(w)) {
    switch(ch) {
      case KEY_DOWN:
        menu_driver(menu, REQ_DOWN_ITEM);
        break;
      case KEY_UP:
        menu_driver(menu, REQ_UP_ITEM);
        break;
      case KEY_NPAGE:
        menu_driver(menu, REQ_SCR_DPAGE);
        break;
      case KEY_PPAGE:
        menu_driver(menu, REQ_SCR_UPAGE);
        break;
      case '\n':
        if (current_item(menu) == menu_items[0]) {
          free_everything(menu_items, menu, 4);
          break;//return 0;
        }
        else if (current_item(menu) == menu_items[1]) {
          free_everything(menu_items, menu, 4);
          break;//return 1;
        }
        else if (current_item(menu) == menu_items[2]) {
          free_everything(menu_items, menu, 4);
          break;//return 2;
        }
        else if (current_item(menu) == menu_items[3]) {
          free_everything(menu_items, menu, 4);
          break;//return 3;
        }
    }
  }
  //return 0;
}

int main() {
  std::vector<std::string> main_choices = {"Append item", "Get info", "Delete item", "Exit"}; 
  std::vector<std::string> append_choices = {"Add Book", "Add Furniture", "Add Computer", "Add Monitor", "Add Other", "Back"};
  std::vector<std::string> ginfo_choices = {"Get all info", "Get books info", "Get furniture info", "Get computers info", "Get monitors info", "Get other info", "Back"}; 
  std::vector<std::string> del_choices = {"Delete all", "Delete book", "Delete furniture", "Delete computer", "Delete monitor", "Delete other", "Back"};
  WINDOW* win = create_window();
  ITEM** main_items;
  MENU* main_menu;
  main_window_func(win, main_items, main_menu, main_choices);

}