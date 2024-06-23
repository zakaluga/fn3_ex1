#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
void WriteString(std::ostream& os, const std::string& s){
    size_t length = s.length();
    os.write((char*)&length, sizeof(size_t));
    os.write(s.data(), (std::streamsize)length);
}

void ReadString(std::istream& is, std::string& s){
    size_t length;
    is.read ((char*)&length, sizeof(size_t));
    s.resize(length);
    is.read(s.data(), (std::streamsize)length);
}
class Furniture
{
public:
  std::string           name;
  std::string           material;
  std::string           move;
  std::string           sizes;

  Furniture()=default;

  ~Furniture()=default;
  static Furniture create()
  {
    Furniture furniture = Furniture();
    std::cout << "Add name of new furniture: ";
    std::cin>>furniture.name;
    std::cout << "\tAdd material of new furniture: ";
    std::cin>>furniture.material;
    std::cout << "\tAdd size of new furniture:";
    std::cin>>furniture.sizes;
    std::cout << "\tAdd position of new furniture:";
    std::cin>>furniture.move;
    return furniture;
  }
  void saveFurniture(std::ostream& os)
  {
    WriteString(os, name);
    WriteString(os, material); 
    WriteString(os, move); 
    WriteString(os, sizes); 
           
  }
  void loadFurniture(std::istream& is)
  {
    ReadString(is, name);
    ReadString(is, material);
    ReadString(is, move);
    ReadString(is, sizes);
  }
  
  void Print()
  {
    std::cout<<"\tName: "<<this->name<<"\n\t";
    std::cout<<"Material: "<<this->material<<"\n\t";
    std::cout<<"Position"<<this->sizes<<"\n\t";
    std::cout<<"Sizes"<<this->move;
  }
};

class Monitor
{
public:
  std::string         name;
  int                 resolution;
  bool                offon;
  Monitor()=default;
  ~Monitor()=default;
  static Monitor create()
  {
    Monitor monitor = Monitor();
    std::cout << "Add name of new monitor: ";
    std::cin>>monitor.name;
    std::cout << "\tAdd monitor resolution: ";
    std::cin  >> monitor.resolution;
    monitor.offon = false;
    return monitor;
  }

  void saveMonitor(std::ostream& os)
  {
    WriteString(os, name);
    os.write((char*)&resolution,sizeof(int)); 
    os.write((char*)&offon,sizeof(bool)); 
  }
  void loadMonitor(std::istream& is)
  {
    ReadString(is, name);
    is.read((char*)&resolution,sizeof(int)); 
    is.read((char*)&offon,sizeof(bool));
  }

  void Print() 
  {
    std::cout<<"\tName: "      <<this->name<<"\n\t"  
             <<"Resolution: "<<this->resolution<<"\n\t"; 
    if (this->offon)  {std::cout << "Monitor is ON\n";}
    else              {std::cout << "Monitor is OFF\n";}  
  }

};
class Processor {
public:
  std::string         name;
  int                 coresCount;
  int                 flowCount;
  int                 heatOut;
  bool                isWork;
  Processor() = default;
  ~Processor() = default;
  static Processor create() 
  {
    Processor processor = Processor();
    std::cout << "Add processor name: ";
    std::cin  >> processor.name;
    std::cout << "\tAdd processor cores count: ";
    std::cin  >> processor.coresCount;
    std::cout << "\tAdd processor flows count: ";
    std::cin  >> processor.flowCount;
    std::cout << "\tAdd processor heat out: ";
    std::cin  >> processor.heatOut;
    processor.isWork = true;
    return processor;
  }
  void saveProcessor(std::ostream& os)
  {
    WriteString(os, name);
    os.write((char*)&coresCount,sizeof(int)); 
    os.write((char*)&flowCount,sizeof(int)); 
    os.write((char*)&heatOut,sizeof(int)); 
    os.write((char*)&isWork,sizeof(bool)); 
  }
  void loadProcessor(std::istream& is)
  {
    ReadString(is, name);
    is.read((char*)&coresCount,sizeof(int)); 
    is.read((char*)&coresCount,sizeof(int)); 
    is.read((char*)&coresCount,sizeof(int)); 
    is.read((char*)&isWork,sizeof(bool));
  }
 

  void Print() 
  {
    std::cout << "\tProcessor name: " << this->name     << "\n\t" 
              << "Cores count: "    << this->coresCount << "\n\t" 
              << "Flows count: "    << this->flowCount  << "\n\t"
              << "Heat out: "       << this->heatOut    << "\n\t";
    if (this->isWork)  {std::cout << "Processor is OK\n";} 
    else               {std::cout << "Processor is NOT OK\n";}
  }
};

class Other
{

public:
  std::map<std::string,std::string>property;
  Other()=default;
  ~Other()=default;

  void saveAnother(std::ostream& os){
        size_t length = property.size();
        os.write((char*)&length, sizeof(size_t));
        for (auto [key,value]: property) {
            WriteString(os, key);
            WriteString(os, value);
        }

    }
    void loadAnother(std::istream& is){
        property.clear();
        size_t length;
        is.read ((char*)&length, sizeof(size_t));
        for (size_t i=0; i<length; i++){
            std::string name;
            std::string value;
            ReadString(is, name);
            ReadString(is, value);
            property.insert({name, value});
        }
    }
  
  void Print()
  {
    for (auto[key,value]:property) 
    {
      std::cout<<key<<":"<<value<<"\n";
    }
  }

  void createProperty()
  {
    std::string name_property;
    std::string value_property;
    int a;
    std::cout << "\tWhat you want to do\n\t";
    std::cout << "1) Enter new property with value\n\t"
              << "2) Exit\n";
    std::cin>>a;
    switch (a)
    {
    case 1:
      std::cout << "Enter new property and value : ";
      std::cin  >> name_property>>value_property;
      this->property.insert({name_property,value_property});
      createProperty();     
      break;
    case 2:
      break;
    
    default:
      createProperty();
      break;
    }
  }

  static Other create() 
  {
    Other customObject = Other();
      customObject.createProperty();
      return customObject;
  };

};
enum e_type
{
  eFurniture=0,
  eMonitor,
  eProcessor,
  eOther
};
struct type_index
{
 e_type type;
 int index; 
};

std::vector<Furniture>  setFurniture;
std::vector<Monitor>    setMonitor;
std::vector<Processor>  setProcessor;
std::vector<Other>      setOther;

std::map<std::string,type_index> indexation;

void Viewinv()
{
  if  (setFurniture.size() == 0) 
  {
    std::cout << "no furniture" << "\n\t";
    std::cout << "\n";
  }
  else
  {
    std::cout << "FURNITURE\n\t";
    for (size_t i = 0; i < setFurniture.size(); i++) 
    {
      std::cout << "furniture " << i+1 << std::endl;
      setFurniture[i].Print();
      std::cout << "\n\t";
    }
  }
  if  (setMonitor.size() == 0) 
  {
    std::cout << "no monitor" << "\n\t";
    std::cout << "\n";
  }
  else
  {
    std::cout << "MONITOR\n\t";
    for (size_t i = 0; i < setMonitor.size(); i++) 
    {
      std::cout << "monitor " << i+1 << std::endl;
      setMonitor[i].Print();
      std::cout << "\n\t";
    }
  }
  if  (setProcessor.size() == 0) 
  {
    std::cout << "no processor" << "\n\t";
    std::cout << "\n";
  }
  else
  {
    std::cout << "PROCESSOR\n\t";
    for (size_t i = 0; i < setProcessor.size(); i++) 
    {
      std::cout << "processor " << i+1 << "\n";
      setProcessor[i].Print();
      std::cout << "\n\t";
    }
  }
  if  (setOther.size() == 0) 
  {
    std::cout << "no other items" << "\n\t";
    std::cout << "\n";
  }
  else
  {
    std::cout << "OTHER\n\t";
    for (size_t i = 0; i < setOther.size(); i++) 
    {
      std::cout << "other " << i+1 << std::endl;
      setOther[i].Print();
      std::cout << "\n\t";
    }
  }
}

void Addinv ()
{
  int a;
  std::cout << "\tAdd objects\n\t";
  std::cout << "1. Furniture\n\t"; 
  std::cout << "2. Monitor\n\t"; 
  std::cout << "3. Processor\n\t"; 
  std::cout << "4. Other\n\t";
  std::cin >> a;
  std::cout <<"\n\t";
  if(a==1) 
  {
    setFurniture.push_back(Furniture::create());
  }
  if(a==2) 
  {
    setMonitor.push_back(Monitor::create());
  }
  if(a==3) 
  {
    setProcessor.push_back(Processor::create());
  }
  if(a==4) 
  {
    setOther.push_back(Other::create());
  }
};
void Editinv()
{
  size_t a;
  std::cout << "\tEdit objects\n\t";
  std::cout << "1. Furniture\n\t"; 
  std::cout << "2. Monitor\n\t"; 
  std::cout << "3. Processor\n\t"; 
  std::cout << "4. Other\n\t";
  std::cin>>a;
  std::cout <<"\n\t";
    if (a == 1) 
    {
        int b;
        std::cout << "What's the number?\n\t";
        std::cin >> a;
        std::cout << "\n\t";
        std::cout << "1. name\n\t";
        std::cout << "2. material\n\t";
        std::cout << "3. position\n\t";
        std::cout << "4. size\n\t";
        std::cin >> b;
        std::cout << "\n\t";
        if (b == 1)
        {
          std::cin >> setFurniture[a-1].name;
        };
        if (b == 2)
        {
          std::cin >> setFurniture[a-1].material;
        };
        if (b == 3)
        {
          std::cin >> setFurniture[a-1].move;
        };
        if (b == 4)
        {
          std::cin >> setFurniture[a-1].sizes;
        };
    };  
    if (a == 2) 
    {
        int b;
        std::cout << "What's the number?\n\t";
        std::cin >> a;
        std::cout << "\n\t";
        std::cout << "1. name\n\t";
        std::cout << "2. resolution\n\t";
        std::cout << "3. Off/On\n\t";
        std::cin >> b;
        std::cout << "\n\t";
        if (b == 1)
        {
          std::cin >> setMonitor[a-1].name;
        };
        if (b == 2)
        {
          std::cin >> setMonitor[a-1].resolution;
        };
        if (b == 3)
        {
          std::cin >> setMonitor[a-1].offon;
        };
    }  
    if (a == 3) 
    {
        int b;
        std::cout << "What's the number?\n\t";
        std::cin >> a;
        std::cout << "\n\t";
        std::cout << "1. name\n\t";
        std::cout << "2. cores count\n\t";
        std::cout << "3. flow count \n\t";
        std::cout << "4. heat out\n\t";
        std::cout << "5. is work?\n\t";
        std::cin >> b;
        std::cout << "\n\t";
        if (b == 1)
        {
          std::cin >> setProcessor[a-1].name;
        };
        if (b == 2)
        {
          std::cin >> setProcessor[a-1].coresCount;
        };
        if (b == 3)
        {
          std::cin >> setProcessor[a-1].flowCount;
        };
        if (b == 4)
        {
          std::cin >> setProcessor[a-1].heatOut;
        };
        if (b == 5)
        {
          std::cin >> setProcessor[a-1].isWork;
        };
    };  
    if (a == 4) 
    {
        std::cout << "What's the number?\n\t";
        std::cin >> a;
        std::cout << "\n";
        int i =1;
        for (auto[key,value]:setOther[a-1].property)
        {
          std::cout<<i<<". "<<key<<"\n";
          i++;
        }
        int b;
        std::cout<<"What do you change?\n";
        std::cin>>b;
        std::cout<<"\n";
        int c =1;
        for (auto[key,value]:setOther[a-1].property)
        {
          if(b==c)
          {
            std::cin>>value;
          }
          c++;
        }
    };  
 

};

void Deleteinv()
{
  size_t a;
  std::cout << "\tDelete objects\n\t";
  std::cout << "1. Furniture\n\t"; 
  std::cout << "2. Monitor\n\t"; 
  std::cout << "3. Processor\n\t"; 
  std::cout << "4. Other\n\t";
  std::cin>>a;
  std::cout <<"\n\t";
  if(a==1)
  {
        std::cout << "What's the number?" << std::endl;
        size_t n;
        std::cin >> n;
        std::cout << std::endl;
        setFurniture.erase(setFurniture.begin()+(n-1));  
  }
  if(a==2)
  {
        std::cout << "What's the number?" << std::endl;
        size_t n;
        std::cin >> n;
        std::cout << std::endl;
        setMonitor.erase(setMonitor.begin()+(n-1));  
  }
  if(a==3)
  {
        std::cout << "What's the number?" << std::endl;
        size_t n;
        std::cin >> n;
        std::cout << std::endl;
        setProcessor.erase(setProcessor.begin()+(n-1));  
  }
  if(a==4)
  {
        std::cout << "What's the number?" << std::endl;
        size_t n;
        std::cin >> n;
        std::cout << std::endl;
        setOther.erase(setOther.begin()+(n-1));  
  }
}

void savefile(){
    std::ofstream file("data.bin");
    // сохранять количество элементов данного типа
    size_t length = setFurniture.size();
    file.write((char*)&length, sizeof(size_t));
    for (size_t i = 0; i < setFurniture.size(); i++){
        setFurniture[i].saveFurniture(file);
    }

    length = setMonitor.size();
    file.write((char*)&length, sizeof(size_t));
    for (size_t i = 0; i < setMonitor.size(); i++){
        setMonitor[i].saveMonitor(file);
    }
    
    length = setProcessor.size();
    file.write((char*)&length, sizeof(size_t));
    for (size_t i = 0; i < setProcessor.size(); i++){
        setProcessor[i].saveProcessor(file);
    }
    length = setOther.size();
    file.write((char*)&length, sizeof(size_t));
    for (size_t i = 0; i < setOther.size(); i++){
        setOther[i].saveAnother(file);
    }

}

void loadfile(){
    std::ifstream file("data.bin");
    auto& is = file;
    size_t length;
    is.read ((char*)&length, sizeof(size_t));
    setFurniture.resize(length);
    for (size_t i = 0; i < setFurniture.size(); i++){
        
        setFurniture[i].loadFurniture(file);
    }

    length;
    is.read ((char*)&length, sizeof(size_t));
    setMonitor.resize(length);
    for (size_t i = 0; i < setMonitor.size(); i++){
        
       setMonitor[i].loadMonitor(file);
    }

    length;
    is.read ((char*)&length, sizeof(size_t));
    setProcessor.resize(length);
    for (size_t i = 0; i < setProcessor.size(); i++){
        setProcessor[i].loadProcessor(file);
    }

    length;
    is.read ((char*)&length, sizeof(size_t));
    setOther.resize(length);
    for (size_t i = 0; i < setOther.size(); i++){
        setOther[i].loadAnother(file);
    }

}
std::string flag;
void menu() 
{
  while (flag!="stop")
  {
    std::cout << "What you want to do?\n\t"
              << "1) View registred objects\n\t"
              << "2) Add new objects\n\t"
              << "3) Edit objects\n\t"
              << "4) Delete object\n\t"
              << "5) save file\n\t"
              << "6) load file\n\t"
              << "7) Exit\n";
    int a;
    std::cin>>a;
    std::cout<<"\n";
    if(a==1)
    {
      Viewinv();
    }
    if(a==2)
    {
      Addinv();
    }
    if(a==3)
    {
      Editinv();
    }
    if(a==4)
    {
      Deleteinv();
    }
    if(a==5)
    {
      savefile();
    }
    if(a==6)
    {
      loadfile();
    }
    if(a==7)
    {
      flag="stop";
    }
 }  
}

int main()
{
  menu();
}