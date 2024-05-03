#include <ncurses.h>
#include <menu.h>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <inttypes.h>

//C-thing atoi imitation
int a2i(const char *s)
{
  int sign=1;
  if(*s == '-'){
    sign = -1;
    s++;
  }
  int num=0;
  while(*s){
    num=((*s)-'0')+num*10;
    s++;   
  }
  return num*sign;
}



//all classes block start
  struct ID {
  private:
    char _id[256];   //identification number
    char _quantity[256];
  public:
      
      void SetQuantity() {
        getstr(this->_quantity);
      }
      char* GetQuantityCHAR() {
        return (this->_quantity);
      }
      int GetQuantityINT() {
        return (a2i(this->_quantity));
      }
      void SetId() {
        getstr(this->_id);
      }
      char* GetId() {
        return (this->_id);
      }
      ~ID() = default;
  };
  class Book: public ID {
  private:
      char _isbn[256];  
      char _name[256];  
      char _author[256];
  public:  
    void SetIsbn() { 
      getstr(this->_isbn);
    }
    char* GetIsbn() { 
      return (this->_isbn); 
    }
    void SetName() { 
      getstr(_name);
    }
    char* GetName () { 
      return (this->_name); 
    }
    void SetAuthor() { 
      getstr(this->_author);
    }
    char* GetAuthor () { 
      return (this->_author); 
    }
    ~Book() = default;
  };
  struct Material {
  private:
    char _materials[256];
  public:
    void SetMaterial() {
      getstr(this->_materials);
    }
    char* GetMaterial() { 
      return (this->_materials); 
    }
  };
  struct Name {
  private:
    char _name[256];
  public:
    void SetName() {
      getstr(this->_name);
    }
    char* GetName() {
      return (this->_name);
    }
  };

  class Furniture: public ID, public Material, public Name {
  private:
    Material _mat;
    Name _nam;
  public:
    ~Furniture() = default;
  };
  class Computer: public ID, public Name {
  private:
    bool _power;
    char _compCPU[256], _compGPU[256], _compRAM[256],_compMB[256];
  public:
    void SetCPU() {
      getstr(this->_compCPU);
    }
    void SetGPU() {
      getstr(this->_compGPU);
    }
    void SetRAM() {
      getstr(this->_compRAM);
    }
    void SetMB() {
      getstr(this->_compMB);
    }
    void SetPower(bool valPow) { 
      _power = valPow; 
    }
    char* GetCPU() {
      return this->_compCPU;
    }
    char* GetGPU() {
      return this->_compGPU;
    }
    char* GetRAM() {
      return this->_compRAM;
    }
    char* GetMB() {
      return this->_compMB;
    }
    bool GetPower() { 
      return this -> _power; 
    }
    bool GetPacked() { 
      if (_compCPU && _compGPU && _compRAM && _compMB) {
        return true;
      } 
      else {
        return false;
      }
    }
    bool isWorking() { 
      if (_power && GetPacked()) {
        return true;
      } 
      else {
        return false;
      }  
    }
    ~Computer() = default;
  };
  class Unregistered: public ID, public Material, public Name {
  private:
    Material _mat;
    Name _nam;
  public:
    ~Unregistered() = default;
  };
//all classes block end
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
          case 1: {
            unpost_menu(current_menu);
            wrefresh(win);
            addFurniture(); 
            post_menu(current_menu);
            break;
          }
          case 2: {
            unpost_menu(current_menu);
            wrefresh(win);
            addComputer(); 
            post_menu(current_menu);
            break;
          }
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
//checking if file is empty
bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}
void addBook() {
  Book book;
  echo();
  std::ofstream file("books.txt", std::ios_base::app);
  if (!file.is_open()) {
      mvprintw(maxY/2, maxX/2 - 20, "Error: Unable to open file for writing.");
      return;
  }
  mvprintw(maxY / 2 - 9, maxX / 2 - 5, "Enter book details:");
  mvprintw(maxY / 2 - 8, maxX / 2 - 6, "Title: ");
  book.SetName();
  mvprintw(maxY / 2 - 7, maxX / 2 - 6, "Author: ");
  book.SetAuthor();
  mvprintw(maxY / 2 - 6, maxX / 2 - 6, "ISBN: ");
  book.SetIsbn();
  mvprintw(maxY / 2 - 5, maxX / 2 - 6, "ID: ");
  book.SetId();
  mvprintw(maxY / 2 - 4, maxX / 2 - 6, "Quantity: ");
  book.SetQuantity();
  for (int i = 0; i < book.GetQuantityINT(); ++i) {
    file << book.GetAuthor() << " - \"" << book.GetName() << "\" ISBN: " << book.GetIsbn() << " ID: " << book.GetId() << "-" << i << "\n";
  }
  mvprintw(maxY / 2 - 3, maxX / 2 - 6, "Book added successfully.");
  getch();
  file.close();
  clear();
  werase(win);
  wrefresh(win);
  noecho();
}
void addFurniture() {
  Furniture furn;
  echo();
  std::ofstream file("furniture.txt", std::ios_base::app);
  if (!file.is_open()) {
      mvprintw(maxY/2, maxX/2 - 20, "Error: Unable to open file for writing.");
      return;
  }
  mvprintw(maxY / 2 - 9, maxX / 2 - 10, "Enter furniture element details:");
  mvprintw(maxY / 2 - 8, maxX / 2 - 6, "Title: ");
  furn.SetName();
  mvprintw(maxY / 2 - 7, maxX / 2 - 6, "Material: ");
  furn.SetMaterial();
  mvprintw(maxY / 2 - 6, maxX / 2 - 6, "Quantity: ");
  furn.SetQuantity();
  mvprintw(maxY / 2 - 5, maxX / 2 - 6, "ID: ");
  furn.SetId();
  for (int i = 0; i < furn.GetQuantityINT(); ++i) {
    file << "Element name: " << furn.GetName() << " Material: " << furn.GetMaterial() << " - ID: " << furn.GetId() << "-" << i << "\n";
  }
  mvprintw(maxY / 2 - 4, maxX / 2 - 14, "Furniture element added successfully.");
  getch();
  file.close();
  clear();
  werase(win);
  wrefresh(win);
  noecho();
}
void addComputer() {
  Computer comp;
  echo();
  std::ofstream file("computers.txt", std::ios_base::app);
  if (!file.is_open()) {
      mvprintw(maxY/2, maxX/2 - 20, "Error: Unable to open file for writing.");
      return;
  }
  mvprintw(maxY / 2 - 9, maxX / 2 - 10, "Enter computer details:");
  mvprintw(maxY / 2 - 8, maxX / 2 - 12, "Enter model name. If you know what you do, you can make something up here");
  comp.SetName();
  mvprintw(maxY / 2 - 7, maxX / 2 - 12, "Supply info about it's compartments. If there is none - leave derived field empty.");
  mvprintw(maxY / 2 - 6, maxX / 2 - 12, "Supply CPU info: ");
  comp.SetCPU();
  mvprintw(maxY / 2 - 5, maxX / 2 - 12, "Supply GPU info: ");
  comp.SetGPU();
  mvprintw(maxY / 2 - 4, maxX / 2 - 12, "Supply RAM info: ");
  comp.SetRAM();
  mvprintw(maxY / 2 - 3, maxX / 2 - 12, "Supply Motherboard info: ");
  comp.SetMB();
  mvprintw(maxY / 2 - 1, maxX / 2 - 12, "Quantity: ");
  comp.SetQuantity();
  mvprintw(maxY / 2 - 2, maxX / 2 - 12, "ID: ");
  comp.SetId();
  for (int i = 0; i < comp.GetQuantityINT(); ++i) {
    file << "Model: " << comp.GetName() << " CPU: " << comp.GetCPU() << " GPU: " << comp.GetGPU() << " RAM: " << comp.GetRAM() << " Motheboard: " << comp.GetMB() << " ID: " << comp.GetId() << "-" << i << "\n";
  }
  mvprintw(maxY / 2 - 4, maxX / 2 - 14, "Computer added successfully.");
  getch();
  file.close();
  clear();
  werase(win);
  wrefresh(win);
  noecho();
}
void addOther() {

}
void getInfoBook() {
  echo();
  std::ifstream file("books.txt");
  if (!file.is_open()) {
      mvprintw(maxY/2, maxX/2 - 19, "Error: Unable to open file for reading.");
      getch();
      return;
  }
  if (is_empty(file)) {
    mvprintw(maxY/2, (maxX/2 - 11), "There are no books yet");
    return;
  }
  clear();
  mvprintw(maxY / 2 - 5, maxX / 2 - 9, "Books Information:");
  std::string line;
  int row = maxY/2 - 3; 
  while (std::getline(file, line)) {
    ++row;
    mvprintw(row, maxX / 2 - 12, line.c_str()); 
  }
  file.close();
  mvprintw(row + 2, maxX/2 - 41, "Press any key to return to the main menu."); 
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
