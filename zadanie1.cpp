#include <iostream>
#include <string>
using namespace std;

class Setup{
  protected:
  string name;
  int length;
  int heigth;
  int width;
  int weigth;
  int count;
  string material;
  string color;
  public:
  Setup(){}
  Setup(string _name,int _length,int _heigth, int _width,int _weigth,int _count,string _material,string _color){
    name = _name;
    length =_length;
    heigth =_heigth;
    width = _width;
    weigth =_weigth;
    count = _count;
    material = _material;
    color = _color;
    
  }
  void print(){
    cout<<"Name: "<<name<<"\tmaterial: "<<material<<"\tcolor: "<<color<<"\tcount: "<<count<<"\n";
    cout <<"Parameters: length = "<<length<<"\theigth = " <<heigth<<"\twidth = "<<width<<"\tweigth = "<<weigth<<"\n";
    cout<<"\n";
  };
};

class Table:public Setup{
  public:
  Table():Setup("Table",150,100,80,10,12,"Wood","yellow"){};
  Table(string n,int l,int h, int w,int we,int k,string m,string c):Setup(name,length,heigth,width,weigth,count,material,color){};
};

class Chair:public Setup{
  public:
  Chair():Setup("Chair",70,120,80,2,30,"Wood","yellow"){};
  Chair(string n,int l,int h, int w,int we,int k,string m,string c):Setup(name,length,heigth,width,weigth,count,material,color){};
};

class Shelf:public Setup{
public:
  Shelf():Setup("Shelf",110,300,100,80,5,"Wood+glass","yellow"){};
  Shelf(string n,int l,int h, int w,int we,int k,string m,string c):Setup(name,length,heigth,width,weigth,count,material,color){};  
};

int main()
{
  
}