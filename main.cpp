#include <iostream>
#include <variant>
#include <map>
#include <string>

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
        
        std::string getName()              {return this->name_;}
        void setName(std::string name)     {this->name_ = name;}

        int getCoresCount()                {return this->coresCount_;}
        void setCoresCount(int coresCount) {this->coresCount_ = coresCount;}

        int getFlowCount()                 {return this->flowCount_;}
        void setFlowCount(int flowsCount)  {this->flowCount_ = flowsCount;}

        int getHeatOut()                   {return this->heatOut_;}
        void setHeatOut(int heatOut)       {this->heatOut_ = heatOut;}

        int getIsWork()                    {return this->isWork_;}
        void setIsWork(bool isWork)        {this->isWork_ = isWork;}

        static Processor create() {
            Processor processor = Processor();
            std::cout << "Add processor name: ";
            std::cin  >> processor.name_;
            std::cout << "Add processor cores count: ";
            std::cin  >> processor.coresCount_;
            std::cout << "Add processor flows count: ";
            std::cin  >> processor.flowCount_;
            std::cout << "Add processor heat out: ";
            std::cin  >> processor.heatOut_;
            processor.isWork_ = true;
        }

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
        std::string name_;
        int         videoMemory_;
        int         heatOut_;
        bool        isWork_;
    public:
        GraphCard(std::string &name, int &videoMemory, int &heatOut, bool &isWork): 
                  name_(name), videoMemory_(videoMemory), heatOut_(heatOut), isWork_(isWork) {}
        GraphCard() = default;
        ~GraphCard() = default;
        
        std::string getName()                {return this->name_;}
        void setName(std::string name)   {this->name_ = name;}

        int  getVideoMemory()                {return this->videoMemory_;}
        void setVideoMemory(int videoMemory) {this->videoMemory_= videoMemory;}

        int  getHeatOut()                    {return this->heatOut_;}
        void setHeatOut(int heatOut)         {this->heatOut_ = heatOut;}

        bool getIsWork()                     {return this->isWork_;}
        void setIsWork(bool isWork)          {this->isWork_ = isWork;}

        static GraphCard create() {
            GraphCard graphcard = GraphCard();
            std::cout << "Add graph card name: ";
            std::cin  >> graphcard.name_;
            std::cout << "Add graph card video memory: ";
            std::cin  >> graphcard.videoMemory_;
            std::cout << "Add graph card heat out: ";
            std::cin  >> graphcard.heatOut_;
            graphcard.isWork_ = true;
        }

        void getInfo() {
            std::cout << "VIDEOCARD\n\n";
            std::cout << "Card name: "        << this->name_        << "\n" 
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
                std::cin  >> this->name_;
                std::cout << "New name: '" << this->name_ << "'\n";
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
        std::string name_;
        int         resolution_;
        bool        isWork_;
        bool        onOff_;
    public:
        Monitor(std::string &name, int &gerz, bool &work, bool &onoff): name_(name), resolution_(gerz),  isWork_(work), onOff_(onoff) {}
        Monitor() {
            std::cout << "Add name of new monitor: ";
            std::cin  >> this->name_;
        };
        ~Monitor() = default;
        
        std::string getName()             {return this->name_;}
        void setName(std::string name)    {this->name_ = name;}

        int  getResolution()              {return this->resolution_;}
        void setReslution(int resolution) {this->resolution_ = resolution;}

        bool getIsWork()                  {return this->isWork_;}
        void setIsWork(bool isWork)       {this->isWork_ = isWork;}

        bool getOnOff()                   {return this->onOff_;}
        void setOnOff(bool onOff)         {this->onOff_ = onOff;}

        static Monitor create() {
            Monitor monitor = Monitor();
            std::cout << "Add monitor name: ";
            std::cin  >> monitor.name_;
            std::cout << "Add monitor resolution: ";
            std::cin  >> monitor.resolution_;
            monitor.isWork_ = true;
            monitor.onOff_ = false;
        }
        
        void getInfo() {
            std::cout << "MONITOR\n\n";
            std::cout << "Monitor name: "       << this->name_ << "\n"
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
                std::cin  >> this->name_;
                std::cout << "New name: '" << this->name_ << "'\n";
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

        static Computer create() {
            Computer computer = Computer();
            std::cout << "Add monitor for new computer: ";
            computer.monitor_ = Monitor::create();
            std::cout << "Add new graph card for new computer: ";
            computer.graphCard_ = GraphCard::create();
            std::cout << "Add new processor for new computer: ";
            computer.processor_= Processor::create();
        }

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

        static Sizes create() {
            Sizes sizes = Sizes();
            std::cout << "Add size a: ";
            std::cin  >> sizes.a_;
            std::cout << "Add size b: ";
            std::cin  >> sizes.b_;
            std::cout << "Add size c: ";
            std::cin  >> sizes.c_;
            return sizes;
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

        static Position create(){
            Position position = Position();
            std::cout << "Add coordinate x: ";
            std::cin  >> position.x_;
            std::cout << "Add coordinate y: ";
            std::cin  >> position.y_;
            return position;
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

class Furneture {
    enum Material {
        MATERIAL_WOOD, 
        MATERIAL_STEEL, 
        MATERIAL_PLASTIC, 
        MATERIAL_MIXED
    };
    std::string name_;
    Sizes       sizes_;
    Material    material_;
    Position    position_;
public:
    Furneture(Material& material, const Sizes& sizes, Position& position) :sizes_(sizes), material_(material), position_(position) {};
    Furneture() = default;
    ~Furneture() = default;

    Sizes getsizes()                     {return this->sizes_;}
    void setSizes(Sizes& sizes)          {this->sizes_ = sizes;}

    Material getMaterial()               {return this->material_;}
    void setMaterial(Material& material) {this->material_ = material;}
 
    Position getPosition()               {return this->position_;}
    void setPosition(Position& position) {this->position_ = position;}

    void createMaterial() {
        std::cout << "What is the furniture made of?";
        std::cout << "1) wood\n\t"
                  << "2) steel\n\t"
                  << "3) plastic\n\t"
                  << "4) mixed\n"
                  << "Press any key(1-4)";
        int materialNumber;
        std::cin  >> materialNumber;
        switch (materialNumber)
        {
        case 1:
            this->material_ = MATERIAL_WOOD;
            break;
        case 2:
            this->material_ = MATERIAL_STEEL;
            break;
        case 3:
            this->material_ = MATERIAL_PLASTIC;
            break;
        case 4:
            this->material_ = MATERIAL_MIXED;
            break;
        default:
            createMaterial();
            break;
        }
    }

    static Furneture create() {
        Furneture furneture = Furneture();
        std::cout << "Add name of new furneture: ";
        std::cin  >> furneture.name_;
        std::cout << "Add sizes of new furneture: ";
        furneture.sizes_ = Sizes::create();
        furneture.createMaterial();
        std::cout << "Add position of new furneture: ";
        furneture.position_ = Position::create();
        return furneture;
    }

    void getInfo() {
        std::cout << "FURNETIRE\n\t";
        std::cout << "Material: ";
        switch (this->material_)
        {
        case 0:
            std::cout << "wood\n\t";
            break;
        case 1:
            std::cout << "steel\n\t";
            break;
        case 2:
            std::cout << "plastic\n\t";
            break;
        case 3:
            std::cout << "mixed\n\t"; 
            break;
        }
        this->sizes_.getInfo();
        this->position_.getInfo();
    }

    void editMaterial() {
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
    }

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
            this->editMaterial();
            break;
        case 2:
            this->sizes_.edit();
            this->edit();
            break;
        case 3:
            this->position_.edit();
            this->edit();
            break;
        case 4:
            this->getInfo();
            break;
        default:
            break;
        }
    }
};

std::map<std::string, std::variant<Computer, Processor, GraphCard, Monitor, Furneture>> inventory{};
auto getInfo = [](auto obj) {obj.edit();};


Monitor createNewMonitor() {
    Monitor monitor = Monitor();
    monitor.edit();
    return monitor;
}

Furneture createNewFurneture() {
    Furneture furneture = Furneture();
    furneture.edit();
    return furneture; 
}

void addObjectMenu() {
    int commandNumber;
    std::string inventoryNumber;
    std::cout << "What you want to add?\n\t";
    std::cout << "1) Processor\n\t" 
              << "2) Graph card\n\t"
              << "3) Monitor\n\t"
              << "4) Computer\n\t"
              << "5) Some furneture\n\t"
              << "6) Exit\n"
              << "Press any key (1-6): ";
    std::cin >> commandNumber;
    switch (commandNumber)
    {
    case 1:
        std::cout << "Enter inventory number of new processor: ";
        std::cin  >> inventoryNumber;
        inventory.insert({inventoryNumber, Processor::create()});
        addObjectMenu();
        break;
    case 2:
        std::cout << "Enter inventory number of new graph card: ";
        std::cin  >> inventoryNumber;
        inventory.insert({inventoryNumber, GraphCard::create()});
        addObjectMenu();
        break;
    case 3:
        std::cout << "Enter inventory number of new monitor: ";
        std::cin  >> inventoryNumber;
        inventory.insert({inventoryNumber, Monitor::create()});
        addObjectMenu();
        break;
    case 4:
        std::cout << "Enter inventory number of new computer: ";
        std::cin  >> inventoryNumber;
        inventory.insert({inventoryNumber, Computer::create()});
        addObjectMenu();
        break;
    case 5:
        std::cout << "Enter inventory number of new furneture: ";
        std::cin  >> inventoryNumber;
        inventory.insert({inventoryNumber, Furneture::create()});
        addObjectMenu();
        break;
    case 6:
        break;
    default:
        addObjectMenu();
        break;
    }
}

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
        for (auto [key, value]: inventory){std::visit(getInfo, value);}
        break;
    case 2:
        addObjectMenu();
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
    inventory.insert({"a228", Furneture::create()});
    return 0;
}