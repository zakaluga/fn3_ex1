#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Setup //Шаблон, по которому описывается инвентарь учебного класса
{
  private:
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
  Setup(string _name,int _length,int _heigth, int _width,int _weigth,int _count,string _material,string _color)
  {
    name = _name;
    length =_length;
    heigth =_heigth;
    width = _width;
    weigth =_weigth;
    count = _count;
    material = _material;
    color = _color;
    
  }
  void print()
  {
    cout<<"Name: "<<name<<"\tmaterial: "<<material<<"\tcolor: "<<color<<"\tcount: "<<count<<"\n";
    cout <<"Parameters: length = "<<length<<"\theigth = " <<heigth<<"\twidth = "<<width<<"\tweigth = "<<weigth<<"\n";
    cout<<"\n";
  };

  void SetSetup ()
  {
    cout<<"Enter item name: ";
    cin>>name;
    cout<<endl;

    cout<<"Enter amount of items: ";
    cin>>count;
    cout<<endl;

    if (count>0)
    {
      cout<<"length = ";
      cin>>length;
      cout<<endl;

      cout<<"heigth = ";
      cin>>heigth;
      cout<<endl;

      cout<<"width = ";
      cin>>width;
      cout<<endl;

      cout <<"material: ";
      cin>>material;
      cout<<endl;

      cout<<"color: ";
      cin>>color;
      cout<<endl;
    }

  };

  // Здесь будет работа с файлом

};
class inventorisationClassroom
{
  private:
  vector<Setup>registered;
  vector<Setup>non_registered;
  public:

  void Add_registered(const Setup& item)
  {
    registered.push_back(item);
  };

  void Add_non_registered(const Setup& item)
  {
    non_registered.push_back(item);
  };

  void Delete ()
  {
    registered.clear();
    non_registered.clear();
  };

  // Здесь будет работа с файлом
  
};



int main()
{
  
}