#include "../headers/spec.hpp"
#include <ncurses.h>

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
void window1() {
  WINDOW *w;
  init();
  std::vector<std::string> list = {"Create object", "Read object info", "Delete object", "Exit"};
  char item[30];
  int ch, i = 0;
  
  w = newwin(10, 20, 1, 1 ); // create a new window
  box(w, 0, 0); // sets default borders for the window
  // now print all the menu items and highlight the first one
  for(i = 0; i < 4; ++i) {
    if(i == 0) 
    wattron(w, A_STANDOUT); // highlights the first item.
    else
    wattroff(w, A_STANDOUT);
    sprintf(item, "%s",  list[i].c_str());
    mvwprintw( w, i+1, 2, "%s", item );
  }
  wrefresh(w); // update the terminal screen
  i = 0;
  noecho(); // disable echoing of characters on the screen
  keypad( w, TRUE ); // enable keyboard input for the window.
  curs_set( 0 ); // hide the default screen cursor.
  // get the input
  while(( ch = wgetch(w)) != 'q'){ 
    // right pad with spaces to make the items appear with even width.
    sprintf(item, "%s",  list[i].c_str()); 
    mvwprintw( w, i+1, 2, "%s", item ); 
    // use a variable to increment or decrement the value based on the input.
    switch( ch ) {
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
  endwin();
}



int main() {
  window1();
}