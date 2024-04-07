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
  void menu_item_delete(MENU* selected_menu, ITEM** selected_items, int arrlength, WINDOW* selected_window) {
    unpost_menu(selected_menu);
    free_menu(selected_menu);
    for(int i=0; i <= arrlength; ++i) {
      free_item(selected_items[i]);
    }
    delwin(selected_window);
    wrefresh(selected_window);
  }
  int menu_window(const char* arr[], int arrlength, MENU* selected_menu, ITEM** selected_items) { 
    WINDOW *selected_window;
    int ch;
    int sizeX = 25;
    int sizeY = 15;
    selected_items = (ITEM**) malloc(arrlength+1);
    for(int i=0; i<arrlength; i++ ) {
      selected_items[i] = new_item(arr[i], "");
    }
    selected_items[arrlength] = (ITEM*)NULL;
    /* Create Menu */
    selected_menu = new_menu(selected_items);
    /* Create Window for the menu */
    selected_window = newwin(sizeY, sizeX, (maxY-sizeY)/3, (maxX-sizeX)/3);
    box( selected_window, 0, 0 );
    keypad(selected_window, TRUE);
    /* set menu window */
    set_menu_win(selected_menu, selected_window);
    /*set menu sub window */
    set_menu_sub(selected_menu, derwin(selected_window, sizeY-(sizeY/5), sizeX-(sizeX/5), sizeY/5, sizeX/5));
    set_menu_mark(selected_menu, " "); /* string used as menu marker */
    /* set menu format - no of items to be displayed */
    set_menu_format(selected_menu, 5, 1);
    /*post the menu */
    post_menu(selected_menu);
    wrefresh(selected_window);
    int i = 0;
    while((ch = wgetch(selected_window))!= 23)
    {
      switch(ch) {
        case KEY_DOWN:
          menu_driver(selected_menu, REQ_DOWN_ITEM);          
          break;
        case KEY_UP:
          menu_driver(selected_menu, REQ_UP_ITEM);
          break;
        case KEY_NPAGE:
          menu_driver(selected_menu, REQ_SCR_DPAGE);
          break;
        case KEY_PPAGE:
          menu_driver(selected_menu, REQ_SCR_UPAGE);
          break;
        case '\n':
            if (current_item(selected_menu) == selected_items[0]) {
              
              break;
            }
            else if (current_item(selected_menu) == selected_items[1]) {
              break;
            }
            else if (current_item(selected_menu) == selected_items[2]) {
              break;
            }
            else if (current_item(selected_menu) == selected_items[3]) {
              break;
            }
      }
      wrefresh(selected_window);
    }
    return 0;
  }



  int menu_window() {      
        const char *main_menu_choices[] = {"Append item", "Get info", "Delete item", "Exit"}, 
          *append_menu_choices[] = {"Add Book", "Add Furniture", "Add Computer", "Add Monitor", "Add Other"}, 
          *ginfo_menu_choices[] = {"Get all info", "Get books info", "Get furniture info", "Get computers info", "Get monitors info", "Get other info"}, 
          *del_menu_choices[] = {"Delete all", "Delete book", "Delete furniture", "Delete computer", "Delete monitor", "Delete other"};
        MENU 
          *main_menu, *append_menu, *ginfo_menu, *del_menu;
        ITEM 
          **main_menu_items, **append_menu_items, **ginfo_menu_items, **del_menu_items;
        WINDOW *main_window;
    
    /* Create Items */
    int arrlength = 4;
    int ch;
    int sizeX = 25;
    int sizeY = 10;
    main_menu_items = (ITEM**) malloc(arrlength+1);
    for(int i=0; i<arrlength; i++ ) {
      main_menu_items[i] = new_item(main_menu_choices[i], "");
    }
    main_menu_items[arrlength] = (ITEM*)NULL;
    /* Create Menu */
    main_menu = new_menu(main_menu_items);
    /* Create Window for the menu */
    main_window = newwin(sizeY, sizeX, (maxY-sizeY)/3, (maxX-sizeX)/3);
    box( main_window, 0, 0 );
    keypad(main_window, TRUE);
    /* set menu window */
    set_menu_win(main_menu, main_window);
    /*set menu sub window */
    set_menu_sub(main_menu, derwin(main_window, sizeY-(sizeY/5), sizeX-(sizeX/5), sizeY/5, sizeX/5));
    set_menu_mark(main_menu, " "); /* string used as menu marker */
    /* set menu format - no of items to be displayed */
    set_menu_format(main_menu, 5, 1);
    /*post the menu */
    post_menu(main_menu);
    wrefresh(main_window);
    int i = 0;
    while((ch = wgetch(main_window))!= 23)
    {
      switch(ch) {
        case KEY_DOWN:
          menu_driver(main_menu, REQ_DOWN_ITEM);          
          break;
        case KEY_UP:
          menu_driver(main_menu, REQ_UP_ITEM);
          break;
        case KEY_NPAGE:
          menu_driver(main_menu, REQ_SCR_DPAGE);
          break;
        case KEY_PPAGE:
          menu_driver(main_menu, REQ_SCR_UPAGE);
          break;
        case '\n':
            if (current_item(main_menu) == main_menu_items[0]) {
              menu_item_delete(main_menu, main_menu_items, 4, main_window);            
              menu_window(append_menu_choices, 5, append_menu, append_menu_items);
              break;
            }
            else if (current_item(main_menu) == main_menu_items[1]) {
              menu_item_delete(main_menu, main_menu_items, 4, main_window);
              
              menu_window(ginfo_menu_choices, 6, ginfo_menu, ginfo_menu_items);
              break;
            }
            else if (current_item(main_menu) == main_menu_items[2]) {
              menu_item_delete(main_menu, main_menu_items, 4, main_window);
              
              menu_window(del_menu_choices, 6, del_menu, del_menu_items);
              break;
            }
            else if (current_item(main_menu) == main_menu_items[3]) {
              menu_item_delete(main_menu, main_menu_items, 4, main_window);
              return 0;
            }
      }
      wrefresh(main_window);
    }
    return 0;
  }
//general block ncurses windows end
  
  int main() {
    init();
    curs_set(0);
    int key_input;
    mvprintw(LINES - 2, 0, "Program by Davydov Vladimir");
    menu_window();
    endwin();
    exit;
}
