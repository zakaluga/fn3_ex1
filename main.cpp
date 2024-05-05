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
  class Book: public ID, public Name {
  private:
      char _isbn[256];  
      char _author[256];
  public:  
    void SetIsbn() { 
      getstr(this->_isbn);
    }
    char* GetIsbn() { 
      return (this->_isbn); 
    }
    void SetAuthor() { 
      getstr(this->_author);
    }
    char* GetAuthor () { 
      return (this->_author); 
    }
    ~Book() = default;
  };
  
  class Furniture: public ID, public Material, public Name {
  public:
    ~Furniture() = default;
  };
  class Computer: public ID, public Name {
  private:
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
    
    
    ~Computer() = default;
  };
  class Unregistered: public ID, public Material, public Name {
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
  const std::vector<std::string> del_choices = {"Delete book", "Delete furniture", "Delete computer", 
    "Delete other", "Back"};
  // Window and Menu Management
  WINDOW* win;
  MENU* menus[4];
  int maxY, maxX;
  //declaration of functions block
  //append
  void addBook(std::string item_name);
  void addFurniture(std::string item_name);
  void addComputer(std::string item_name);
  void addOther(std::string item_name);
  //get info
  void getInfoAll(std::string item_name);
  void getInfo(std::string item_name);
  //delete
  void deleteAll(std::string item_name);
  void deleteInfo(std::string item_name);

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
            addBook("Book"); 
            post_menu(current_menu);
            break;
          }
          case 1: {
            unpost_menu(current_menu);
            wrefresh(win);
            addFurniture("Furniture"); 
            post_menu(current_menu);
            break;
          }
          case 2: {
            unpost_menu(current_menu);
            wrefresh(win);
            addComputer("Computer"); 
            post_menu(current_menu);
            break;
          }
          case 3: {
            unpost_menu(current_menu);
            wrefresh(win);
            addOther("Other"); 
            post_menu(current_menu);
            break;
          }
          case 4: {
            current_menu = menus[0]; 
            break;
          }
        }
      }
      else if(current_menu == menus[2]) { //Get info menu actions
        switch(idx) {
         case 0: {
           unpost_menu(current_menu);
           wrefresh(win);
           getInfo("Book");
           getInfo("Furniture");
           getInfo("Computer");
           getInfo("Other");
           post_menu(current_menu);
           break;
         }
          case 1: {
            unpost_menu(current_menu);
            wrefresh(win);
            getInfo("Book"); 
            post_menu(current_menu);
            break;
          }
          case 2: {
            unpost_menu(current_menu);
            wrefresh(win);
            getInfo("Furniture"); 
            post_menu(current_menu);
            break;
            }
          case 3: {
            unpost_menu(current_menu);
            wrefresh(win);
            getInfo("Computer"); 
            post_menu(current_menu);
            break;
            }
          case 4: {
            unpost_menu(current_menu);
            wrefresh(win);
            getInfo("Other"); 
            post_menu(current_menu);
            break;
            }
          case 5: {
            current_menu = menus[0]; 
            break;
            }
        }
      }
      else if(current_menu == menus[3]) {
        switch(idx) {
          case 0: {
            unpost_menu(current_menu);
            wrefresh(win);
            deleteInfo("Book"); 
            post_menu(current_menu);
            break;
          }
          case 1: {
            unpost_menu(current_menu);
            wrefresh(win);
            deleteInfo("Furniture"); 
            post_menu(current_menu);
            break;
          }
          case 2: {
            unpost_menu(current_menu);
            wrefresh(win);
            deleteInfo("Computer"); 
            post_menu(current_menu);
            break;
          }
          case 3: {
            unpost_menu(current_menu);
            wrefresh(win);
            deleteInfo("Other"); 
            break;
          }
          case 4: {
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
void addBook(std::string item_name) {
  Book book;
  echo();
  std::string file_name = (item_name+".txt");
  std::ofstream file(file_name, std::ios_base::app);
  if (!file.is_open()) {
      mvprintw(maxY/2, maxX/2 - 20, "Error: Unable to open file for writing.");
      return;
  }
  mvprintw(maxY / 2 - 9, 1, "Enter book details:");
  mvprintw(maxY / 2 - 8, 1, "Title: ");
  book.SetName();
  mvprintw(maxY / 2 - 7, 1, "Author: ");
  book.SetAuthor();
  mvprintw(maxY / 2 - 6, 1, "ISBN: ");
  book.SetIsbn();
  
  mvprintw(maxY / 2 - 5, 1, "Quantity: ");
  book.SetQuantity();
  mvprintw(maxY / 2 - 4, 1, "ID: ");
  book.SetId();
  for (int i = 0; i < book.GetQuantityINT(); ++i) {
    file << book.GetAuthor() << " - \"" << book.GetName() << "\" ISBN: " << book.GetIsbn() << " ID: " << book.GetId() << "-" << i << "\n";
  }
  mvprintw(maxY / 2 - 3, 1, "Book added successfully.");
  getch();
  file.close();
  clear();
  werase(win);
  wrefresh(win);
  noecho();
}
void addFurniture(std::string item_name) {
  Furniture furn;
  echo();
  std::string file_name = (item_name+".txt");
  std::ofstream file(file_name, std::ios_base::app);
  if (!file.is_open()) {
      mvprintw(maxY/2, maxX/2 - 20, "Error: Unable to open file for writing.");
      return;
  }
  mvprintw(maxY / 2 - 9, 1, "Enter furniture element details:");
  mvprintw(maxY / 2 - 8, 1, "Title: ");
  furn.SetName();
  mvprintw(maxY / 2 - 7, 1, "Material: ");
  furn.SetMaterial();
  mvprintw(maxY / 2 - 6, 1, "Quantity: ");
  furn.SetQuantity();
  mvprintw(maxY / 2 - 5, 1, "ID: ");
  furn.SetId();
  for (int i = 0; i < furn.GetQuantityINT(); ++i) {
    file << "Element name: " << furn.GetName() << " Material: " << furn.GetMaterial() << " - ID: " << furn.GetId() << "-" << i << "\n";
  }
  mvprintw(maxY / 2 - 4, 1, "Furniture element added successfully.");
  getch();
  file.close();
  clear();
  werase(win);
  wrefresh(win);
  noecho();
}
void addComputer(std::string item_name) {
  Computer comp;
  echo();
  std::string file_name = (item_name+".txt");
  std::ofstream file(file_name, std::ios_base::app);
  if (!file.is_open()) {
      mvprintw(maxY/2, maxX/2 - 20, "Error: Unable to open file for writing.");
      return;
  }
  mvprintw(maxY / 2 - 9, 1, "Enter computer details:");
  mvprintw(maxY / 2 - 8, 1, "Enter model name:");
  comp.SetName();
  mvprintw(maxY / 2 - 7, 1, "If something is missing - leave derived field empty.");
  mvprintw(maxY / 2 - 6, 1, "Supply CPU info: ");
  comp.SetCPU();
  mvprintw(maxY / 2 - 5, 1, "Supply GPU info: ");
  comp.SetGPU();
  mvprintw(maxY / 2 - 4, 1, "Supply RAM info: ");
  comp.SetRAM();
  mvprintw(maxY / 2 - 3, 1, "Supply Motherboard info: ");
  comp.SetMB();
  mvprintw(maxY / 2 - 2, 1, "ID: ");
  comp.SetId();
  mvprintw(maxY / 2 - 1, 1, "Quantity: ");
  comp.SetQuantity();
  for (int i = 0; i < comp.GetQuantityINT(); ++i) {
    file << "Model: " << comp.GetName() << " CPU: " << comp.GetCPU() << " GPU: " << comp.GetGPU() << " RAM: " << comp.GetRAM() << " Motheboard: " << comp.GetMB() << " ID: " << comp.GetId() << "-" << i << "\n";
  }
  mvprintw(maxY / 2, 1, "Computer added successfully.");
  getch();
  file.close();
  clear();
  werase(win);
  wrefresh(win);
  noecho();
}
void addOther(std::string item_name) {
  echo();
  Unregistered other;
  std::string file_name = (item_name+".txt");
  std::ofstream file(file_name, std::ios_base::app);
  if (!file.is_open()) {
      mvprintw(maxY/2, maxX/2 - 20, "Error: Unable to open file for writing.");
      return;
  }
  mvprintw(maxY / 2 - 9, maxX / 2 - 10, "Enter unregistered item details: ");
  mvprintw(maxY / 2 - 8, 1, "Title: ");
  other.SetName();
  mvprintw(maxY / 2 - 7, 1, "Material: ");
  other.SetMaterial();
  mvprintw(maxY / 2 - 6, 1, "Quantity: ");
  other.SetQuantity();
  for (int i = 0; i < other.GetQuantityINT(); ++i) {
    file << "Element name: " << other.GetName() << " Material: " << other.GetMaterial() << " - No" << i << "\n";
  }
  mvprintw(maxY / 2 - 4, maxX / 2 - 14, "Unregistered element added successfully.");
  getch();
  file.close();
  clear();
  werase(win);
  wrefresh(win);
  noecho();
}
void getInfo(std::string item_name) {
  //viewPort imitation
  auto printContent = [&](int start, int end, const std::vector<std::string> content) 
    {
      werase(win);
      for (int i = start; i < start+end && i < content.size(); ++i) {
        mvprintw(i - start, 0, "%s", content[i].c_str());
      }
      wrefresh(win);
  };
  noecho();
  std::string file_name = (item_name+".txt");
  std::ifstream file(file_name);
  std::vector<std::string> content;
  if (!file.is_open()) {
      mvprintw(maxY/2, maxX/2 - 19, "Error: Unable to open file for reading.");
      getch();
      return;
  }
  if (is_empty(file)) {
    mvprintw(maxY/2, (maxX/2 - 11), "There are no entries yet");
    return;
  }
  clear();
  std::string line;
  int startLine = 0;
  int endLine = LINES - 2;
  while (std::getline(file, line)) {
    content.push_back(line);
  }
  content.push_back("Press enter to close this window");
  //content.push_back("You may navigate with arrows");
  file.close();
  printContent(startLine, endLine, content);
  int sw;
  while((sw = getch()) != '\n') {
    switch (sw) {
      case KEY_UP: {
        if (startLine > 0) {
          --startLine;
          printContent(startLine, endLine, content);
        }
        break;
      }
      case KEY_DOWN: {
        if (startLine + endLine < content.size()) {
          ++startLine;
          printContent(startLine, endLine, content);
        }
        break;
      } 
    }
  }
  clear();
  werase(win);
  wrefresh(win);
  noecho(); 
}
void deleteInfo(std::string item_name) {
  clear();
  echo();
  std::string file_name = (item_name+".txt");
  std::ifstream inFile(file_name);
  if (!inFile.is_open()) {
      mvprintw(0, maxX / 2 - 19, "Error: Unable to open file for reading.");
      return;
  }
  std::ofstream outFile("temp.txt");
  if (!outFile.is_open()) {
      mvprintw(0, maxX / 2 - 19, "Error: Unable to open temporary file.");
      inFile.close();
      return;
  }
  mvprintw(2, 2, "Enter ID or title of the item(s) to delete: ");
  char id[100];
  getstr(id);
  std::string line;
  bool deleted = false;
  while (std::getline(inFile, line)) {
      if (line.find(id) == std::string::npos) {
          outFile << line << std::endl;
      } else {
          deleted = true;
      }
  }
  inFile.close();
  outFile.close();
  remove(file_name.c_str());
  rename("temp.txt", file_name.c_str());
  if (deleted) {
      mvprintw(4, 2, ("Item deleted successfully."));
  } else {
      mvprintw(4, 2, ("Item not found."));
  }
  getch();
  clear();
  werase(win);
  wrefresh(win);
  noecho();
}
int main() {
  navigate();
  return 0;
}