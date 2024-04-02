#include <ncurses.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

//all classes block start
    struct ID {
  private:
      uint16_t _id;   //identification number
  public:
      void SetId(uint16_t valId) {
          this->_id = valId;
      }
      uint16_t GetId() {
          return this->_id;
      }
      ID(): _id(0){};
  };
  class Move {    //movable object
  private:
      double _x;  //x coordinate. point located in the center of an object
      double _y;  //y coordinate. point located in the center of an object
      double _z;  //z coordinate. point located in the center of an object
  public:
      void SetX(double valX) {    //setter X
          this->_x = valX;
      }
      void SetY(double valY) {    //setter Y
          this->_y = valY;
      }
      void SetZ(double valZ) {    //setter Z
          this->_z = valZ;
      }
      double GetX() {             //getter X
          return this->_x;
      }
      double GetY() {             //getter Y
          return this->_y;
      }
      double GetZ() {             //getter Z
          return this->_z;
      }
      
      Move(): _x(0), _y(0), _z(0) {}
      ~Move() = default;
  };
  class Sizes {   //defines in constructor
  private:
      double _sizeX;  //length
      double _sizeY;  //width
      double _sizeZ;  //height
  public:
      double GetSizeX() {
          return this->_sizeX;
      }
      double GetSizeY() {
          return this->_sizeY;
      }
      double GetSizeZ() {
          return this->_sizeZ;
      }
      Sizes(double sizeX, double sizeY, double sizeZ): 
          _sizeX(sizeX), _sizeY(sizeY), _sizeZ(sizeZ) {}
      ~Sizes() = default;
  };
  class Book: public Move, Sizes, ID {
  private:
      std::string _isbn;  //defines in constructor
      std::string _name;  //defines in constructor
  public:  
      Book(double sizeX, double sizeY, double sizeZ, std::string isbn, std::string name): 
          Sizes(sizeX, sizeY, sizeZ), _isbn(isbn), _name(name) {}
      ~Book() = default;
  };
  class Furniture: public Move, Sizes, ID {
  private:
      std::string _materials;
      std::string _name;
  public:
      Furniture(double sizeX, double sizeY, double sizeZ, std::string materials, std::string name): 
          Sizes(sizeX, sizeY, sizeZ), _materials(materials), _name(name) {}
      ~Furniture() = default;
  };

    struct working {
  private:
      bool power;
      bool packed;
  public:
      bool GetPower() { return this->power; }
      bool GetPacked() { return this->packed; }
      void SetPower(bool valPow) { power = valPow; }
      void SetPacked(bool valpacked) { packed = valpacked; }
      bool isWorking() { if (power && packed) return true; }
  };
  class Computer: public Move, Sizes, ID, working {
  public:
      Computer(double sizeX, double sizeY, double sizeZ): Sizes(sizeX, sizeY, sizeZ){}
      ~Computer() = default;
  };
  class Monitor: public Move, Sizes, ID {
  public:
      Monitor(double sizeX, double sizeY, double sizeZ): Sizes(sizeX, sizeY, sizeZ){}
      ~Monitor() = default;

  };
  class Unregistered: public Move, Sizes, ID {
  private:
      std::string _materials;
      std::string _name;
  public:
      Unregistered(double sizeX, double sizeY, double sizeZ, std::string materials, std::string name): 
          Sizes(sizeX, sizeY, sizeZ), _materials(materials), _name(name) {}
      ~Unregistered() = default;
  };
//all classes block end

//general block ncurses windows start
  int maxY = 0;
  int maxX = 0;

  void init() {
    initscr(); // создание окна
    keypad(stdscr, TRUE);
    cbreak();
    getmaxyx(stdscr, maxY, maxX);
    clear(); // очищает экран
  }
  void drawScreen() {
    clear();
    refresh();
  }
//general block ncurses windows end


  void window2() {
    WINDOW *w;
    init();
    std::vector<std::string> list = {"Add new furniture", "Add new book", "Add new computer", "Add new monitor", "Add unregistered object"};
    char item[30];
    int ch;
    int i = 0;
    
    w = newwin(10, 20, 1, 1 ); // create a new window
    box(w, 0, 0); // sets default borders for the window
    // now print all the menu items and highlight the first one
    for(i = 0; i < 4; ++i) {
      wattroff(w, A_STANDOUT);
      sprintf(item, "%s",  list[i].c_str());
      mvwprintw( w, i+1, 2, "%s", item );
    }
    wrefresh(w); // update the terminal screen
    i = 0;
    noecho(); // disable echoing of characters on the screen
    keypad(w, TRUE ); // enable keyboard input for the window.
    curs_set( 0 ); // hide the default screen cursor.
    // get the input
    while((ch = wgetch(w)) != 'q') { 
      // right pad with spaces to make the items appear with even width.
      sprintf(item, "%s",  list[i].c_str()); 
      mvwprintw( w, i+1, 2, "%s", item ); 
      // use a variable to increment or decrement the value based on the input.
      switch(ch) {
        case (int)'\n':
          delwin(w);
          clear();
          endwin();
        case KEY_UP:
          --i;
          i = (i < 0) ? 4 : i;
          break;
        case KEY_DOWN:
          ++i;
          i = (i > 4) ? 0 : i;
          break;
      }
      // now highlight the next item in the list.
      wattron(w, A_STANDOUT);
      sprintf(item, "%s",  list[i].c_str());
      mvwprintw( w, i+1, 2, "%s", item);
      wattroff(w, A_STANDOUT);
    }
    delwin(w);
    clear();
    endwin();
  }
//first window block start
  void window1() {
    WINDOW *w;
    init();
    std::vector<std::string> list = {"Create object", "Read object info", "Delete object", "Exit"};
    char item[30];
    int ch;
    int i = 0;
    
    w = newwin(10, 20, 1, 1 ); // create a new window
    box(w, 0, 0); // sets default borders for the window
    // now print all the menu items and highlight the first one
    for(i = 0; i < 3; ++i) {
      wattroff(w, A_STANDOUT);
      sprintf(item, "%s",  list[i].c_str());
      mvwprintw( w, i+1, 2, "%s", item );
    }
    wrefresh(w); // update the terminal screen
    i = 0;
    noecho(); // disable echoing of characters on the screen
    keypad(w, TRUE ); // enable keyboard input for the window.
    curs_set( 0 ); // hide the default screen cursor.
    // get the input
    while((ch = wgetch(w)) != 'q') { 
      // right pad with spaces to make the items appear with even width.
      sprintf(item, "%s",  list[i].c_str()); 
      mvwprintw( w, i+1, 2, "%s", item ); 
      // use a variable to increment or decrement the value based on the input.
      switch(ch) {
        case (int)'\n':
          delwin(w);
          clear();
          switch(i) {
            case 0:
                window2();
            case 1: 
                
          }
        case KEY_UP:
          --i;
          i = (i < 0) ? 3 : i;
          break;
        case KEY_DOWN:
          ++i;
          i = (i > 3) ? 0 : i;
          break;
      }
      // now highlight the next item in the list.
      wattron(w, A_STANDOUT);
      sprintf(item, "%s",  list[i].c_str());
      mvwprintw( w, i+1, 2, "%s", item);
      wattroff(w, A_STANDOUT);
    }
    delwin(w);
    clear();
    endwin();
  }
//first window block end
int main() {
  window1();
}