#include <ncurses.h>
#include <menu.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
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
//declaration of functions block
//append
void addBook();
void addFurniture();
void addComputer();
void addOther();
//get info
void getInfoAll();
void getInfoBook();
void getInfoFurniture();
void getInfoComputers();
void getInfoOther();
//delete
void deleteAll();
void deleteBook();
void deleteFurniture();
void deleteComputer();
void deleteOther();

void init_ncurses() { //general initialization
  initscr();
  cbreak();
  noecho();
  getmaxyx(stdscr, maxY, maxX);
  win = newwin(maxY, maxX, 0, 0);
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
    set_menu_sub(menu, derwin(win, maxY - 4, maxX - 4, 2, 2));
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
  while ((ch = wgetch(win)) != KEY_F(2)) {
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
  return -1; // Exit on F2
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
        case 0: { 
          unpost_menu(current_menu);
          wrefresh(win);
          addBook(); 
          post_menu(current_menu);
          break;
        }
    //    case 1: {
    //      unpost_menu(current_menu);
    //      wrefresh(win);
    //      addFurniture(); 
    //      post_menu(current_menu);
    //      break;
    //    }
    //    case 2: {
    //      unpost_menu(current_menu);
    //      wrefresh(win);
    //      addComputer(); 
    //      post_menu(current_menu);
    //      break;
    //    }
    //    case 3: {
    //      unpost_menu(current_menu);
    //      wrefresh(win);
    //      addOther(); 
    //      post_menu(current_menu);
    //      break;
    //    }
        case 4: {
          current_menu = menus[0]; 
          break;
        }
      }
    }
    else if(current_menu == menus[2]) { //Get info menu actions
      switch(idx) {
     //   case 0: {
     //     unpost_menu(current_menu);
     //     wrefresh(win);
     //     getInfoAll(); 
     //     post_menu(current_menu);
     //     break;
     //   }
        case 1: {
          unpost_menu(current_menu);
          wrefresh(win);
          getInfoBook(); 
          post_menu(current_menu);
          break;
        }
    //    case 2: {
    //      unpost_menu(current_menu);
    //      wrefresh(win);
    //      getInfoFurniture(); 
    //      post_menu(current_menu);
    //      break;
    //      }
    //    case 3: {
    //      unpost_menu(current_menu);
    //      wrefresh(win);
    //      getInfoComputers(); 
    //      post_menu(current_menu);
    //      break;
    //      }
    //    case 4: {
    //      unpost_menu(current_menu);
    //      wrefresh(win);
    //      getInfoOther(); 
    //      post_menu(current_menu);
    //      break;
    //      }
        case 5: {
          current_menu = menus[0]; 
          break;
          }
      }
    }
    else if(current_menu == menus[3]) {
      switch(idx) {
       // case 0: {
       //   unpost_menu(current_menu);
       //   wrefresh(win);
       //   deleteAll(); 
       //   post_menu(current_menu);
       //   break;
       // }
        case 1: {
          unpost_menu(current_menu);
          wrefresh(win);
          deleteBook(); 
          post_menu(current_menu);
          break;
        }
      //  case 2: {
      //    unpost_menu(current_menu);
      //    wrefresh(win);
      //    deleteFurniture(); 
      //    post_menu(current_menu);
      //    break;
      //  }
      //  case 3: {
      //    unpost_menu(current_menu);
      //    wrefresh(win);
      //    deleteComputer(); 
      //    post_menu(current_menu);
      //    break;
      //  }
      //  case 4: {
      //    unpost_menu(current_menu);
      //    wrefresh(win);
      //    deleteOther(); 
      //    break;
      //  }
        case 5: {
          current_menu = menus[0]; 
          break;
        }
      }
    }
  }
  delwin(win);
  win = nullptr;
  endwin();
}
void addBook() {
  echo();
  std::ofstream file("books.txt", std::ios_base::app);
  if (!file.is_open()) {
      mvprintw(0, 0, "Error: Unable to open file for writing.");
      return;
  }
  mvprintw(2, 2, "Enter book details:");
  mvprintw(4, 2, "Title: ");
  char title[100];
  getstr(title);
  mvprintw(5, 2, "Author: ");
  char author[100];
  getstr(author);
  mvprintw(6, 2, "ISBN: ");
  char isbn[20];
  getstr(isbn);
  file << title << "," << author << "," << isbn << std::endl;
  mvprintw(8, 2, "Book added successfully.");
  file.close();
  clear();
  werase(win);
  wrefresh(win);
  noecho();
}

void getInfoBook() {
  echo();
  std::ifstream file("books.txt");
  if (!file.is_open()) {
      mvprintw(0, 0, "Error: Unable to open file for reading.");
      return;
  }
  clear();
  mvprintw(0, 0, "Books Information:");
  std::string line;
  int row = 2; 
  while (std::getline(file, line)) {
      mvprintw(row++, 0, line.c_str()); 
  }
  file.close();
  mvprintw(row + 1, 0, "Press any key to return to the main menu."); 
  getch(); 
  clear();
  werase(win);
  wrefresh(win);
  noecho(); 
}

void deleteBook() {
  clear();
  echo();
  std::ifstream inFile("books.txt");
  if (!inFile.is_open()) {
      mvprintw(0, 0, "Error: Unable to open file for reading.");
      return;
  }

  std::ofstream outFile("temp.txt");
  if (!outFile.is_open()) {
      mvprintw(0, 0, "Error: Unable to open temporary file.");
      inFile.close();
      return;
  }
  mvprintw(2, 2, "Enter the title of the book to delete: ");
  char title[100];
  getstr(title);

  std::string line;
  bool deleted = false;
  while (std::getline(inFile, line)) {
      if (line.find(title) == std::string::npos) {
          outFile << line << std::endl;
      } else {
          deleted = true;
      }
  }

  inFile.close();
  outFile.close();
  remove("books.txt");
  rename("temp.txt", "books.txt");

  if (deleted) {
      mvprintw(4, 2, "Book deleted successfully.");
  } else {
      mvprintw(4, 2, "Book not found.");
  }
  clear();
  werase(win);
  wrefresh(win);
  noecho();
}

int main() {
  navigate();
  return 0;
}
