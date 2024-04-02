#include <iostream>
#include <variant>
#include <map>

class Processor {
    private:
        std::string name_;
        int         coresCount_;
        int         flowCount_;
        int         heatOut_;
        bool        isWork_;
    public:
        Processor(std::string& name, int& coresCount, int& flowsCount, int& heatOut, bool& isWork): 
        name_(name), coresCount_(coresCount), flowCount_(flowsCount), heatOut_(heatOut),  isWork_(isWork) {}
        Processor() = default;
        ~Processor() = default;
        
        std::string getName()          {return this->name_;}
        void setName(std::string name) {this->name_ = name;}

        int getCoresCount()            {return this->coresCount_;}
        void setCoresCount(int cores)  {this->coresCount_ = cores;}

        int getFlowCount()             {return this->flowCount_;}
        void setFlowCount(int flows)   {this->flowCount_ = flows;}

        int getHeatOut()               {return this->heatOut_;}
        void setHeatOut(int heat)      {this->heatOut_ = heat;}

        int getIsWork()                {return this->isWork_;}
        void setIsWork(bool work)      {this->isWork_ = work;}

        void getInfo() {
            std::cout << "PROCESSOR\n\n";
            std::cout << "Processor name: " << this->name_       << "\n" 
                      << "Cores count: "    << this->coresCount_ << "\n" 
                      << "Flows count: "    << this->flowCount_  << "\n"
                      << "Heat out: "       << this->heatOut_    << "\n";
            if (this->isWork_) {std::cout << "Processor is OK\n";} 
            else               {std::cout << "Processor is NOT OK\n";}
        }

        void edit() {
            int  comandNumber;
            char yesOrNo;
            std::cout << "---PROCESSOR MENU---\n\n";
            std::cout << "What you want to change?\n\t" 
                      << "1) Name\n\t"
                      << "2) Cores count\n\t"
                      << "3) Flows count\n\t"
                      << "4) Heat out\n\t"
                      << "5) Workble?\n\t" 
                      << "6) Exit\n"
                      << "Press any key (1-6): ";
            std::cin >> comandNumber;
            switch (comandNumber)
            {
            case 1:
                std::cout << "Enter new processor name: ";
                std::cin  >> this->name_;
                std::cout << "New name: '" << this->name_ << "'\n";
                this->edit();
                break;
            case 2:
                std::cout << "Enter new cores count: ";
                std::cin  >> this->coresCount_;
                std::cout << "New cores count: '" << this->coresCount_ << "'\n";
                this->edit();
                break; 
            case 3:
                std::cout << "Enter new flows count: ";
                std::cin  >> this->flowCount_;
                std::cout << "New flows count: '" << this->flowCount_ << "'\n";
                this->edit();
                break;
            case 4:
                std::cout << "Enter new heat out: ";
                std::cin  >> this->heatOut_;
                std::cout << "New heat out: '" << this->heatOut_ << "'\n";
                this->edit();
                break;
            case 5:
                std::cout << "Is the processor still working? (Y or N): ";
                std::cin  >> yesOrNo;
                if      ((yesOrNo == 'Y') || (yesOrNo == 'y')) {std::cout << "Processor is still working\n";          this->isWork_ = true; } 
                else if ((yesOrNo == 'n') || (yesOrNo == 'N')) {std::cout << "Processor doesn't working. Repare it\n";this->isWork_ = false;}
                this->edit();
                break;
            case 6:
                this->getInfo();
                break;
            default:
                this->edit();
                break;
            }
        }
};

class GraphCard {
    private:
        std::string cardName_;
        int         videoMemory_;
        int         heatOut_;
        bool        isWork_;
    public:
        GraphCard(std::string &name, int &memory, int &heat, bool &work): cardName_(name), videoMemory_(memory), heatOut_(heat), isWork_(work) {}
        GraphCard() = default;
        ~GraphCard() = default;
        
        std::string getName()           {return this->cardName_;}
        void setName(std::string name)  {this->cardName_ = name;}

        int getVideoMemory()            {return this->videoMemory_;}
        void setVideoMemory(int memory) {this->videoMemory_= memory;}

        int getHeatOut()                {return this->heatOut_;}
        void setHeatOut(int heat)       {this->heatOut_ = heat;}

        bool getIsWork()                {return this->isWork_;}
        void setIsWork(bool work)       {this->isWork_ = work;}

        void getInfo() {
            std::cout << "VIDEOCARD\n\n";
            std::cout << "Card name: "        << this->cardName_    << "\n" 
                      << "Card vide memory: " << this->videoMemory_ << " GB\n" 
                      << "Card heat out: "    << this->heatOut_     << " Vt\n";
            if (this->isWork_) {std::cout << "Videocard is OK\n";} else {std::cout << "Videocard is NOT OK\n";}
        }
        void edit() {
            int comandNumber;
            char yesOrNo;
            std::cout << "---GRAPHCARD MENU---\n\n";
            std::cout << "What you wnt to change?\n\t"
                      << "1) Name\n\t"
                      << "2) Video memory size\n\t"
                      << "3) Heat out\n\t"
                      << "4) Workable?\n\t"
                      << "5) Exit\n" 
                      << "Press any key (1-5): ";
            std::cin  >> comandNumber;
            switch (comandNumber)
            {
            case 1:
                std::cout << "Enter new graphcard name: ";
                std::cin  >> this->cardName_;
                std::cout << "New name: '" << this->cardName_ << "'\n";
                this->edit();
                break;
            case 2:
                std::cout << "Enter new video memory size: ";
                std::cin  >> this->videoMemory_;
                std::cout << "New cores count: '" << this->videoMemory_ << "'\n";
                this->edit();
                break; 
            case 3:
                std::cout << "Enter new heat out: ";
                std::cin  >> this->heatOut_;
                std::cout << "New heat out: '" << this->heatOut_ << "'\n";
                this->edit();
                break;
            case 4:
                std::cout << "Is the graphcard still working?(Y or N): ";
                std::cin  >> yesOrNo;
                if      ((yesOrNo == 'n') || (yesOrNo == 'N')) {std::cout << "Graph card doesn't work. Repare it\n"; this->isWork_ = false;} 
                else if ((yesOrNo == 'y') || (yesOrNo == 'Y')) {std::cout << "Graph card is still working.\n";       this->isWork_ = true; }
                this->edit();
                break;
            case 5:
                this->getInfo();
                break;
            }
        }
};

class Monitor {
    private: 
        std::string monitorName_;
        int         resolution_;
        bool        isWork_;
        bool        onOff_;
    public:
        Monitor(std::string &name, int &gerz, bool &work, bool &onoff): monitorName_(name), resolution_(gerz),  isWork_(work), onOff_(onoff) {}
        Monitor() = default;
        ~Monitor() = default;
        
        std::string getName()          {return this->monitorName_;}
        void setName(std::string name) {this->monitorName_ = name;}

        int getResolution()            {return this->resolution_;}
        void setReslution(int gerz)    {this->resolution_ = gerz;}

        bool getIsWork()               {return this->isWork_;}
        void setIsWork(bool work)      {this->isWork_ = work;}

        bool getOnOff()                {return this->onOff_;}
        void setOnOff(bool onoff)      {this->onOff_ = onoff;}
        
        void getInfo() {
            std::cout << "MONITOR\n\n";
            std::cout << "Monitor name: "       << this->monitorName_ << "\n"
                      << "Monitor resolution: " << this->resolution_  << "\n";
            if (this->onOff_)  {std::cout << "Monitor is ON";} else {std::cout << "Monitor is OFF";}
            if (this->isWork_) {std::cout << "Monitor is OK";} else {std::cout << "Monitor is NOT OK";}
        }

        void edit() {
            int comandNumber;
            char yesOrNo;
            std::cout << "---MONITOR MENU---\n\n";
            std::cout << "What you want to change?\n\t"
                      << "1) Name\n\t"
                      << "2) Resolution\n\t"
                      << "3) On or off?\n\t"
                      << "4) Workable?\n\t"
                      << "5) Exit\n" 
                      << "Press any key (1-5): ";
            std::cin  >> comandNumber;
            switch (comandNumber)
            {
            case 1:
                std::cout << "Enter new monitor name: ";
                std::cin  >> this->monitorName_;
                std::cout << "New name: '" << this->monitorName_ << "'\n";
                this->edit();
                break;
            case 2:
                std::cout << "Enter new resolution: ";
                std::cin  >> this->resolution_;
                std::cout << "New resolution: '" << this->resolution_ << "'\n";
                this->edit();
                break; 
            case 3:
                if (this->isWork_) {
                    std::cout << "What you want to do: ON or OFF (Y or N)";
                    std::cin  >> yesOrNo;
                    if      ((yesOrNo == 'y') || (yesOrNo == 'Y')) {this->onOff_ = true;  std::cout << "You ON monitor\n"; } 
                    else if ((yesOrNo == 'n') || (yesOrNo == 'N')) {this->onOff_ = false; std::cout << "You OFF monitor\n";}
                } else {
                    std::cout << "Repare monitor befor work with them\n";
                }
                this->edit();
                break;
            case 4:
                std::cout << "Is the monitor still working?(Y or N): ";
                std::cin  >> yesOrNo;
                if      ((yesOrNo == 'n') || (yesOrNo == 'N')) {std::cout << "Monitor doesn't work. Repare it\n"; this->isWork_ = false;} 
                else if ((yesOrNo == 'y') || (yesOrNo == 'Y')) {std::cout << "Monitor is still working.\n";       this->isWork_ = true; }
                this->edit();
                break;
            case 5:
                this->getInfo();
                break;
            }
        }
};

class Computer {
    private:
        Monitor   monitor_;
        GraphCard graphCard_;
        Processor processor_;
        bool      isWork_;
        bool      onOff_;
    public:
        Computer(Monitor& screen, GraphCard& card, Processor& procc) :
            monitor_(screen), graphCard_(card), processor_(procc) {
                if (monitor_.getIsWork() && processor_.getIsWork() && graphCard_.getIsWork()) {
                    this->setIsWork(true);
                } else {
                    this->setIsWork(false);
                }
                this->onOff_ = false;
            }
        Computer() = default;
        ~Computer() = default;

        Monitor& getMonitor()                   {return this->monitor_;}
        void setMonitor(Monitor& monitor)       {this->monitor_ = monitor;}

        GraphCard& getGraphCard()               {return this->graphCard_;}
        void setGraphCard(GraphCard& graphCard) {this->graphCard_ = graphCard;}

        Processor& getProcessor()               {return this->processor_;}
        void setProcessor(Processor& processor) {this->processor_ = processor;}

        bool getIsWork()                        {return this->isWork_;}
        void setIsWork(bool isWork)             {this->isWork_ = isWork;}

        void getInfo() {
            std::cout << "COMPUTER\n\n";
            this->monitor_.getInfo();
            this->graphCard_.getInfo();
            this->processor_.getInfo();
            if (this->onOff_)  {std::cout << "Computer is ON\n";} else {std::cout << "Computer is OFF\n";}
            if (this->isWork_) {std::cout << "Computer is OK\n";} else {std::cout << "Something is wrong, check components and fix them";}
        }

        void edit() {
            int comandNumber;
            char yesOrNo;
            std::cout << "---COMPUTER MENU---\n\n";
            std::cout << "what you want to change?\n\t"
                      << "1) Monitor\n\t"
                      << "2) Graphcard\n\t"
                      << "3) Processor\n\t"
                      << "4) ON or OFF\n\t"
                      << "5) Exit\n" 
                      << "Press any key (1-5): ";
            std::cin >> comandNumber;
            switch (comandNumber)
            {
            case 1:
                this->monitor_.edit();
                this->edit();
                break;
            case 2:
                this->graphCard_.edit();
                this->edit();
                break;
            case 3:
                this->processor_.edit();
                this->edit();
                break;
            case 4:
                if (this->isWork_) {
                    std::cout << "ON or Off (Y or N)?: ";
                    std::cin >> yesOrNo;
                    if      ((yesOrNo == 'y') || (yesOrNo == 'Y')) {this->onOff_ = true;  std::cout << "Computer is ON\n";}
                    else if ((yesOrNo == 'n') || (yesOrNo == 'N')) {this->onOff_ = false; std::cout << "Computer is OFF\n";}
                } else {std::cout << "Repare computer before work with them\n";}
                break;
            case 5:
                this->getInfo();
                break;
            default:
                this->edit();
                break;
            }
        };
};

struct Sizes {
    private:
        int a_, b_, c_;
    public:
        Sizes(int a, int b, int c): a_(a), b_(b), c_(c) {};
        Sizes()  = default;
        ~Sizes() = default;

        int  getA()      {return this->a_;}
        void setA(int a) {this->a_ = a;}

        int  getB()      {return this->b_;}
        void setB(int b) {this->b_ = b;}
        
        int  getC()      {return this->c_;}
        void setC(int c) {this->c_ = c;}

        void getInfo() {
            std::cout << "SIZES\n\n";
            std::cout << "Size a: " << this->a_
                      << "Size b: " << this->b_
                      << "Size c: " << this->c_;
        }

        void edit() {
            int commandNumber;
            std::cout << "---SIZES MENU---\n\n";
            std::cout << "What you want to edit?\n\t" 
                      << "1) Size a\n\t"
                      << "2) Size b\n\t"
                      << "3) Size c\n\t" 
                      << "4) Exit\nPress any key (1-3): ";
            std::cin  >> commandNumber;
            switch (commandNumber)
            {
            case 1:
                std::cout << "Enret new size a: ";
                std::cin  >> this->a_;
                std::cout << "New size a: "+this->a_;
                this->edit();
                break;
            case 2:
                std::cout << "Enret new size b: ";
                std::cin  >> this->b_;
                std::cout << "New size b: "+this->b_;
                this->edit();
                break;
            case 3:
                std::cout << "Enret new size c: ";
                std::cin  >> this->c_;
                std::cout << "New size c: "+this->c_;
                this->edit();
                break;
            case 4:
                this->getInfo();
                break;
                    
            default:
                this->edit();
                break;
            }
        }
};

struct Position {
    private:
        int x_, y_;
    public:
        Position(int x, int y): x_(x), y_(y) {}
        Position() = default;
        ~Position() = default;

        void setX(int& x) {this->x_ = x;}
        int getX()        {return this->x_;}

        void setY(int& y) {this->y_ = y;}
        int getY()        {return this->y_;}

        void getInfo() {
            std::cout << "POSITION\n\n";
            std::cout << "x: " << this->x_
                      << "y: " << this->y_;
        }

        void edit() {
            int commandNumber;
            std::cout << "What you want to change?\n";
            std::cout << "What you want to change?\n\t"
                      << "1) Coordinate x\n\t"
                      << "2) Coordinate y\n\t"
                      << "3) Exit\n"
                      << "Press any key(1-3)";
            std::cin  >> commandNumber;
            switch (commandNumber)
            {
            case 1:
                std::cout << "Enter new coordinate x: ";
                std::cin  >> this->x_;
                std::cout << "New coordinate x: " + this->x_;
                this->edit();
                break;
            case 2:
                std::cout << "Enter new coordinate y: ";
                std::cin  >> this->y_;
                std::cout << "New coordinate y: " + this->y_;
                this->edit();
                break;
            case 3:
                this->getInfo();
                break;
            default:
                this->edit();
                break;
            }
        }
        
};

class FurnetureProperties {
    enum Material {
        MATERIAL_WOOD, 
        MATERIAL_STEEL, 
        MATERIAL_PLASTIC, 
        MATERIAL_MIXED
    };
    Sizes       sizes_;
    Material    material_;
    Position    position_;
public:
    FurnetureProperties(Material& material, const Sizes& sizes, Position& position) :sizes_(sizes), material_(material), position_(position) {};
    FurnetureProperties() = default;
    ~FurnetureProperties() = default;

    Sizes getsizes()                     {return this->sizes_;}
    void setSizes(Sizes& sizes)          {this->sizes_ = sizes;}

    Material getMaterial()               {return this->material_;}
    void setMaterial(Material& material) {this->material_ = material;}
 
    Position getPosition()               {return this->position_;}
    void setPosition(Position& position) {this->position_ = position;}

    void edit() {
        int comandNumber;
        std::cout << "---FURNETURE MENU---";
        std::cout << "What you want to change?\n\t"
                  << "1) Material\n\t"
                  << "2) Sizes\n\t"
                  << "3) Position\n\t"
                  << "4) Exit\n"
                  << "Press any key(1-4): ";
        std::cin  >> comandNumber;
        switch (comandNumber)
        {
        case 1:
            int materialNumber;
            std::cout << "What material you want to choose?\n\t"
                      << "1) Wood\n\t"
                      << "2) Steel\n\t"
                      << "3) Plastic\n\t"
                      << "4) Mixed\n\t"
                      << "5) Exit\n\t"
                      << "Press any key(1-5): ";
            std::cin  >> materialNumber;
            switch (materialNumber)
            {
            case 1:
                std::cout << "New material: wood";
                this->material_ = MATERIAL_WOOD;
                this->edit();
                break;
            case 2:
                std::cout << "New material: steel";
                this->material_ = MATERIAL_STEEL;
                this->edit();
                break;
            case 3:
                std::cout << "New material: plastic";
                this->material_ = MATERIAL_PLASTIC;
                this->edit();
                break;
            case 4:
                std::cout << "New material: mixed";
                this->material_ = MATERIAL_MIXED;
                this->edit();
                break;
            case 5:
                break;
            default:
                this->edit();
                break;
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        }
    }
};

class Chair {
public:
    FurnetureProperties furnetureProperties_;

    Chair(const FurnetureProperties& furnetureProperties) :furnetureProperties_(furnetureProperties) {};
    Chair() = default;
    ~Chair() = default;
};

class Locker {
public:
    FurnetureProperties furnetureProperties_;

    Locker(const FurnetureProperties& furnetureProperties) :furnetureProperties_(furnetureProperties) {};
    Locker() = default;
    ~Locker() = default;
};

class Table {
public:
    FurnetureProperties furnetureProperties_;

    Table(const FurnetureProperties& furnetureProperties) :furnetureProperties_(furnetureProperties) {};
    Table() = default;
    ~Table() = default;
};

std::map<std::string, std::variant<Computer, Monitor, FurnetureProperties>> inventory;

struct autoObjectMenu {
    void operator()(Computer& object) {object.edit();}
};

void Menu() {
    int commandNumber;
    std::cout << "---MAIN MENU---\n";
    std::cout << "What you want to do?\n\t"
              << "1) View registred objects\n\t"
              << "2) Add new objects\n\t"
              << "3) Edit objects\n\t"
              << "4) Delete object\n\t"
              << "5) Work with file\n\t"
              << "6) Exit\n"
              << "Press any key (1-6): ";
    std::cin >> commandNumber;
    switch (commandNumber)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    
    default:
        break;
    } 
}

int main()
{
    Computer *computer = new Computer();
    inventory["a228"] = std::variant<Computer, Monitor, FurnetureProperties>(*computer);
    return 0;
}