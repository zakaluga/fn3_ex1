#include <ncurses.h>
#include <menu.h>
#include <iostream>
#include <string>
#include <vector>

// Definitions for menu options
const std::vector<std::string> main_choices = {"Append item", "Get info", 
  "Delete item", "Exit"};
const std::vector<std::string> append_choices = 
  {"Add Book", "Add Furniture", "Add Computer",  "Add Other", "Back"};
const std::vector<std::string> ginfo_choices = {"Get all info", "Get books info", "Get furniture info", 
  "Get computers info", "Get other info", "Back"};
const std::vector<std::string> del_choices = {"Delete all", "Delete book", "Delete furniture", "Delete computer", 
  "Delete other", "Back"};

// Window and Menu Management
WINDOW* win;
MENU* menus[4];
int maxY, maxX;
const int sizeX = 20, sizeY = 15;

void init_ncurses() { //general initialization
  initscr();
  cbreak();
  noecho();
  getmaxyx(stdscr, maxY, maxX);
  win = newwin(sizeY, sizeX, (maxY-sizeY)/2, (maxX-sizeX)/2);
  keypad(win, TRUE);
  box(win, 0, 0);
  refresh();
}
ITEM** create_items(const std::vector<std::string>& choices) {  //creating items (temporarily, for each menu)
  ITEM** items = new ITEM*[choices.size() + 1];
  for (size_t i = 0; i < choices.size(); i++) {
    items[i] = new_item(choices[i].c_str(), "");
  }
  items[choices.size()] = nullptr;
  return items;
}
void free_items(ITEM** items) { //freeing items, haven't been used, but I've written it anyways
  for (int i = 0; items[i] != nullptr; i++) {
    free_item(items[i]);
  }
  delete[] items;
}
void setup_menus() {  //allocating menus and setting them up
  menus[0] = new_menu(create_items(main_choices));
  menus[1] = new_menu(create_items(append_choices));
  menus[2] = new_menu(create_items(ginfo_choices));
  menus[3] = new_menu(create_items(del_choices));
  for (auto& menu : menus) {
    set_menu_win(menu, win);
    set_menu_sub(menu, derwin(win, sizeY - 4, sizeX - 4, 2, 2));
    set_menu_mark(menu, "> ");
  }
}
void free_menus() {
  for (auto& menu : menus) {
    unpost_menu(menu);  // Unpost menus before freeing them
    free_menu(menu);    // Free the menu
    ITEM** items = menu_items(menu);
    if (items) {
        int count = item_count(menu);
        for (int i = 0; i < count; i++) {
            free_item(items[i]);  // Free each item
        }
    }
  }
}
void show_menu(MENU* menu) {
  post_menu(menu);
  wrefresh(win);
}
int navigate_menu(MENU* menu) {
  int ch, selection = -1;
  while ((ch = wgetch(win)) != KEY_F(1)) {
    switch (ch) {
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
        selection = item_index(current_item(menu));
        unpost_menu(menu);
        return selection;
    }
    wrefresh(win);
  }
  return -1; // Exit on F1
}
void navigate() {
  init_ncurses();
  setup_menus();
  bool running = true;
  MENU* current_menu = menus[0];
  int idx;
  while (running) {
    show_menu(current_menu);
    idx = navigate_menu(current_menu);
    // Main menu actions
    if (current_menu == menus[0]) {
      switch (idx) {
        case 0: current_menu = menus[1]; break; // Append item
        case 1: current_menu = menus[2]; break; // Get info
        case 2: current_menu = menus[3]; break; // Delete item
        case 3: running = false; break; // Exit
        default: break;
      }
    } 
   else if (current_menu == menus[1]) {  //Append menu actions
      switch(idx) {
        //case 0: addBook(); break;
        //case 1: addFurniture(); break;
        //case 2: addComputer(); break;
        //case 3: addOther(); break;
        case 4: current_menu = menus[0]; break;
      }
    }
    else if(current_menu == menus[2]) {
      switch(idx) {
        //case 0: getInfoAll(); break;
        //case 1: getInfoBooks(); break;
        //case 2: getInfoFurniture(); break;
        //case 3: getComputersInfo(); break;
        //case 4: getOtherInfo(); break;
        case 5: current_menu = menus[0]; break;
      }
    }
    else if(current_menu == menus[3]) {
      switch(idx) {
        case 5: current_menu = menus[0]; break;
      }
    }
  }
  // Before exiting, ensure all menus are unposted and freed
  delwin(win);
  win = nullptr;
  endwin();
}

int main() {
  navigate();
  return 0;
}
