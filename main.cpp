#include <ncurses.h>
#include <menu.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>


//general block ncurses windows start
  int maxY = 0;
  int maxX = 0;
  
  const char *main_menu_choices[] = {"Append item", "Get info", "Delete item", "Exit"}, 
      *append_menu_choices[] = {}, 
      *ginfo_menu_choices[] = {}, 
      *del_menu_choices[] = {};
  MENU 
    *main_menu, *append_menu, *ginfo_menu, *del_menu;
  ITEM 
    **main_menu_items, **append_menu_items, **ginfo_menu_items, **del_menu_items;
  WINDOW *main_window;

  void init() {
    initscr();
    clear();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, maxY, maxX);
    clear();
  }

  void menu_window(const char* arr[], int arrlength, WINDOW* w, MENU* selected_menu, ITEM** selected_items, bool recursion) {
    /* Create Items */
    int ch;
    selected_items = (ITEM **)calloc(4, sizeof(ITEM *));
    for(int i=0; i<4; i++ ) {
      selected_items[i] = new_item(arr[i], "" );
    }
    /* Create Menu */
    selected_menu = new_menu(selected_items);
    /* Create Window for the menu */
    w = newwin( 7, 15, 5, 5);
    box( w, 0, 0 );
    keypad(w, TRUE);
    /* set menu window */
    set_menu_win(selected_menu, w );
    /*set menu sub window */
    set_menu_sub(selected_menu, derwin(w, 6, 14, 1, 1));
    set_menu_mark(selected_menu, " "); /* string used as menu marker */
    /* set menu format - no of items to be displayed */
    set_menu_format(selected_menu, 5, 1);
    /*post the menu */
    post_menu(selected_menu);
    wrefresh(w);
    while((ch = wgetch(w))!= 23)
    {
      int i = 0;
      switch(ch) {
        case KEY_DOWN:
          
          menu_driver(selected_menu, REQ_DOWN_ITEM);
          if (i < arrlength)  { 
            ++i;
            set_current_item(selected_menu, selected_items[i]);
          }
          break;
        case KEY_UP:
          if (i != 0) { 
            --i;
            set_current_item(selected_menu, selected_items[i]);
          }
          menu_driver(selected_menu, REQ_UP_ITEM);
          break;
      //  case KEY_NPAGE:
      //    i=0;
      //    menu_driver(selected_menu, REQ_SCR_DPAGE);
      //    //set_current_item(selected_menu, selected_items[i]);
      //    break;
      //  case KEY_PPAGE:
      //    i=arrlength-1;
      //    menu_driver(selected_menu, REQ_SCR_UPAGE);
      //    //set_current_item(selected_menu, selected_items[i]);
      //    break;
        case KEY_ENTER:
            if (current_item(selected_menu) == main_menu_items[0]) { }
            else if (current_item(selected_menu) == main_menu_items[1]) { }
            else if (current_item(selected_menu) == main_menu_items[2]) { }
            else if (current_item(selected_menu) == main_menu_items[3]) {ch = 23;}
      }
      wrefresh(w);
    }

    unpost_menu(selected_menu);
    free_menu(selected_menu);
    for(int i=0; i < 4; i++) {
      free_item(selected_items[i]);
    }
  }
//general block ncurses windows end
  
  int main() {
    init();
    curs_set(0);
    int key_input;
    mvprintw(LINES - 2, 0, "Program by Davydov Vladimir");
    menu_window(main_menu_choices, 4, main_window, main_menu, main_menu_items, true);
    endwin();
}
