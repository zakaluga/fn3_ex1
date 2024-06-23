#include <iostream> 
#include <vector>
#include <fstream>
#include <forward_list>
#include <ctime>
#include <variant>
#include <typeinfo>

// bool __fastcall LogicProgram(int&, std::string, Operator &);

class Item  {
public: 
    Item(std::string name_, std::size_t id_) : name(name_), id(id_) {}
    virtual std::string getName() const {return name;}
    virtual std::size_t getId() const {return id;}
    virtual ~Item() = default;
protected: 
    std::string name;
    std::size_t id;
};

class Processor : public Item {
public:
    Processor(std::string name_, std::size_t id_, double freq_, std::size_t count_cors_) : Item(name_, id_) {
        freq = freq_; count_cors = count_cors_;
    }
    double getFreq() const {return freq;}
    std::size_t getCors() const {return count_cors;}
private:
    double freq;
    std::size_t count_cors;
};

class Table : public Item { 
public:
    
};

class Computer : public Item {
public:
    Computer(std::string name_, std::size_t id_) : Item(name_, id_) {}
    //Computer(std::initializer_list<std::size_t>&& vec, std::string name_, std::size_t id_) : Item(name_, id_) {}
    friend std::ostream& operator<<(std::ostream& os, const Computer& cp)
    {
        os << "name : " << cp.getName() << " id : " << cp.getId();
        return os;
    }
private: 
    double price;
};

class AnyObject : public Item {
public: 
    AnyObject(std::string name_, std::size_t id_) : Item(name_, id_) {} 
    void setProperty(std::variant<std::string, double, int> p) {
        property = p;
    }
    std::variant<std::string, double, int> getProperty() {
        return property;
    }
private:
    std::variant<std::string, double, int> property;
};

class Operator {
public:
    Operator(Operator&) = delete;
    Operator(Operator&&) = delete;

    static Operator& CREATE_OPERATOR() {
        static Operator instance; // инициализируется только один раз
        return instance;   
    }

    void AddItem(Item&& item) {
        // при перемещении также перемещаются указатели
        storage.push_back(std::move(item));
    }

    Item& findItem(std::size_t id) {
        Iterator end = storage.end();
        for(Iterator iter = storage.begin(); iter != end; iter++) {
            if (iter->getId() == id) return *iter;
        }
        throw std::string("Object not found");
    }

    bool delItem(std::size_t id) {
        Iterator end = storage.end();
        for(Iterator iter = storage.begin(); iter != end; iter++) {
            if (iter->getId() == id) {
                storage.erase(iter);
                return true;
            }
        }
        return false;
    }

    void SaveToFileOther() {
        std::string name;
        std::cout << "Enter File name : " ;std::cin >> name;
        std::ofstream file(name);
        for(auto & iter : storage) {
            file << iter.getName() << " " << iter.getId() << " ";
        }
    }

    std::string modifyItem(std::size_t id) {
        Iterator end = storage.end();
        std::size_t id_;
        std::string name_;
        for(auto iter = storage.begin(); iter != end; iter++) {
            if (iter->getId() == id) {
                if (typeid(Computer).name() == typeid(*iter).name()) {
                    std::cout << "Input name : "; std::cin >> name_; 
                    std::cout << "Input id : "; std::cin >> id_;
                    storage.erase(iter);
                    storage[id] = Computer(name_, id_);
                    return "Object modif";
                } 
                else if (typeid(Processor).name() == typeid(*iter).name()) {
                    double freq; int cors;
                    std::cout << "Input name : "; std::cin >> name_; 
                    std::cout << "Input id : "; std::cin >> id_;
                    std::cout << "Enter Count cors : " ; std::cin >> cors;
                    std::cout << "Enter frequency : "; std::cin >> freq;
                    storage[id] = Processor(name_, id_,freq, cors);
                    return "Object modif";
                }
            } else {
                continue;
            }
        }
        return std::string("Object add succsesfuly");
    }

    std::ofstream saveToFile(std::string nFile) {
        std::ofstream oFile(nFile);
        Iterator end = storage.end();
        for(Iterator iter = storage.begin(); iter != end; ++iter) {
            oFile << iter->getName() <<  " " << iter->getId() << "\n"; 
        }
        return oFile;
    }

    std::vector<Item> loadFromFile(std::string nFile) {
        std::vector<Item> Storage;
        std::ifstream iFile(nFile, std::ios::binary);
        std::string line;
        if (!iFile.is_open()) {
            throw std::string(" file not was opened ");
        }
        while (std::getline(iFile, line)) {
            Storage.push_back(deserialize(line));
        }
        storage = Storage;
        return Storage;
    }

    void printObjects() {
        for(auto & it : storage) {
            std::cout << "NAME " << it.getName() << " ID: "  << it.getId();
        }
    }

    static Item deserialize(const std::string& str) {
        int arrayProd[10];
        int id;
        size_t pos = str.find(' ');
        std::string name = str.substr(0, pos);
        
        id = std::stoi(str.substr(pos + 1));
        
        if (name == "Computer") {
            Computer cp = Computer(name, id);
            return cp;
        }
        else if (name == "Processos") {
            Processor pr = Processor(name, id, 0.0, 0);
            return pr;
        }
        throw std::string("object not defined ! ");

    }

private:
    Operator(std::string nameFile_) {nameFile = nameFile_;}
    Operator(){}
    ~Operator(){}
    std::vector<Item> storage;
    std::string nameFile;
    using Iterator = std::vector<Item>::iterator;
};

bool __fastcall LogicProgram(int& choise, std::string nameFile, Operator & oper) {
    std::string name;
    size_t id;
    int other_choise;
    bool t;
    clock_t start_time = clock();
    std::cout << "Select a menu item: " << std::endl;
    std::cout << "1) Input object" << std::endl;
    std::cout << "2) Delete object" << std::endl;
    std::cout << "3) Save object" << std::endl;
    std::cout << "4) Modify object " << std::endl;
    std::cout << "5) Exit" << std::endl;
    std::cout << "6) print objects" << std::endl;
    std::cout << "7) Save to file with oter name " << std::endl;
    std::cout << ">> ";
    std::cin >> choise;
    do {
        switch (choise)
        {
        case 1:
            std::cout << "Which object should be added ? " << std::endl;
            std::cout << "1) Computer " << std::endl;
            std::cout << "2) Processor " << std::endl;
            std::cout << "3) Any Object " << std::endl;
            std::cout << "4) return to base menu" << std::endl;
            std::cout << ">> "; std::cin >> other_choise;
            if (other_choise == 0b1) {
                std::cout << "Enter the computer manufacturer : "; std::cin >> name;
                std::cout << "Enter id object : "; std::cin >> id;
                oper.AddItem(Computer(name, id));
                std::cout << "Computer succsesfuly added ! " << std::endl;
                break;
            } 
            else if (other_choise == 0b10) {
                std::size_t count;
                double frequency;
                std::cout << "Enter the computer manufacturer : "; std::cin >> name;
                std::cout << "Enter id object : "; std::cin >> id;
                std::cout << "Enter frecuency pricessor : "; std::cin >> frequency;
                std::cout << "Enter quantyti cors : "; std::cin >> count;
                oper.AddItem(Processor(name, id, frequency, count));
                std::cout << "Processor succsesfuly added ! " << std::endl;
                std::cout << std::endl;
                break;
            } 
            else if (other_choise == 0b11) {
                std::string f;
                std::cout << "Enter id object : "; std::cin >> id;
                std::cout << "Enter name object : "; std::cin >> name;
                std::cout << "Enter dop property ";
                std::cin >> f;
                AnyObject obj = AnyObject(name, id);
                obj.setProperty(f);
                
                std::cout << "Object sucsessfuly added! " << std::endl;
                break;
            }
            else if (other_choise == 0b100) {
                LogicProgram(choise, nameFile, oper);
                break;
            }
            break;
        case 2:
            std::cout << "Enter id object which need remove : "; std::cin >> id;
            t = oper.delItem(id);

            if (t) std::cout << "Object was remove ! ";
            else  std::cout << "Object not found ! " << std::endl;
            system("pause");
            LogicProgram(choise, nameFile, oper);

        case 3:
            oper.saveToFile(nameFile);
            std::cout << "Objects success saved! " << std::endl;
            LogicProgram(choise, nameFile, oper);
        case 4: 
            std::cout << "Enter id : "; std::cin >> id;
            oper.modifyItem(id);
            std::cout << "Object was mofidy !" << std::endl;       
            LogicProgram(choise, nameFile, oper);
        case 5:
            oper.saveToFile(nameFile);
            choise = 0;
            break;
        case 6:
            oper.printObjects();
            std::cout << std::endl;
            LogicProgram(choise, nameFile, oper);
        case 7: 
            oper.SaveToFileOther();
            std::cout << "Saved sucseefuly !" << std::endl;
            LogicProgram(choise, nameFile, oper);
        default:

            break;
        }
        start_time = clock();
        
    } while (choise != 0);
    return true;
}


int main(int argc, char* argv[])
{
    std::string nFile = "data.txt";  // файл с данными
    Operator& oper = Operator::CREATE_OPERATOR();
  
    //oper.loadFromFile(nFile);        // Подгружает информацию из файла при запуске программы

    TODO : // основная программа
    int ch = 0;
    LogicProgram(ch, nFile, oper);
    

    return 0;
}