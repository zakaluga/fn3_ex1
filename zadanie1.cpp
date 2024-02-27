#include <iostream>
#include <string>
using namespace std;

class Table;

class Setup{
  protected:
  int heigth;
  int width;

  Setup(){}
  Setup(int heigth, int width){
    this ->heigth = heigth;
    this -> width = width;
  }
};

class Table:public Setup{
  public:
  Table():Setup(heigth,width){};
  string material;
  string color;
  void setParametr(int h, int w){
    heigth=h;
    width=w;
  };
  void print(){
    cout<<"height = "<<heigth<<" width = "<<width<<" material: "<<material<<" color: "<<color<<endl;
  };
};

main()
{
 Table stol;
 stol.setParametr(100,80);
 stol.material="wood";
 stol.color="yellow"; 
 stol.print();
}