#include <iostream>

class Processor {
    private:
        std::string ProcName;
        int CoresCount;
        int FlowCount;
        int HeatOut;
        bool isWork;
    public:
        Processor(std::string &name, int &cores, int &flows, int &heat, bool &work): 
        ProcName(name), CoresCount(cores), FlowCount(flows), HeatOut(heat),  isWork(work) {}
        Processor() = default;
        ~Processor() = default;
        
        std::string GetProcessorName() {return this->ProcName;}
        void SetProcessorName(std::string name) {this->ProcName = name;}

        int GetProcessCoresCount() {return this->CoresCount;}
        void SetProcessCoresCount(int cores) {this->CoresCount = cores;}

        int GetProcessFlowCount() {return this->FlowCount;}
        void SetProcessFlowCount(int flows) {this->FlowCount = flows;}

        int GetProcessHeatOut() {return this->HeatOut;}
        void SetProcessHeatOut(int heat) {this->HeatOut = heat;}

        int GetProcessorisWork() {return this->isWork;}
        void SetProcessisWork(bool work) {this->isWork = work;}

        void GetProcessorInfo() {
            std::cout << "PROCESSOR\n\n";
            std::cout << "Processor name: " << this->ProcName << "\n" 
            << "Cores count: " << this->CoresCount << "\n" 
            << "Flows count: " << this->FlowCount << "\n"
            << "Heat out: " << this->HeatOut << "\n";
            if (this->isWork) {std::cout << "Processor is OK\n";} else {std::cout << "Processor is NOT OK\n";}
        }
};

class GraphCard {
    private:
        std::string CardName;
        int VideoMemory;
        int HeatOut;
        bool isWork;
    public:
        GraphCard(std::string &name, int &memory, int &heat, bool &work): CardName(name), VideoMemory(memory), HeatOut(heat), isWork(work) {}
        GraphCard() = default;
        ~GraphCard() = default;
        
        std::string GetGraphCardName() {return this->CardName;}
        void SetGraphCardName(std::string name) {this->CardName = name;}

        int GetGraphCardVideoMemory() {return this->VideoMemory;}
        void SetGraphCardVideoMemory(int memory) {this->VideoMemory= memory;}

        int GetGraphCardHeatOut() {return this->HeatOut;}
        void SetGraphCardHeatOut(int heat) {this->HeatOut = heat;}

        bool GetGraphCardisWork() {return this->isWork;}
        void SetGraphCardisWork(bool work) {this->isWork = work;}

        void GetGraphCardInfo() {
            std::cout << "VIDEOCARD\n\n";
            std::cout << "Card name: " << this->CardName << "\n" 
            << "Card vide memory: " << this->VideoMemory << " GB\n" 
            << "Card heat out: " << this->HeatOut << " Vt\n";
            if (this->isWork) {std::cout << "Videocard is OK\n";} else {std::cout << "Videocard is NOT OK\n";}
        }
};

class Monitor {
    private:
        std::string MonitorName;
        int Resolution;
        bool isWork;
        bool OnOff;
    public:
        Monitor(std::string name, int gerz, bool work) {
            std::cout << "Enter monitor name: ";
            std::cin >> this->MonitorName;
            std::cout << "Enter monitor resolution: ";
            std::cin >> this->Resolution;
            this->isWork = true;
            this->OnOff = false;
        }
        bool GetMonitorWork() {return this->isWork;}
        void GetMonitorInfo() {
            std::cout << "MONITOR\n\n";
            std::cout << "Monitor name: " << this->MonitorName << "\n"
            << "Monitor resolution: " << this->Resolution << "\n";
            if (this->OnOff) {std::cout << "Monitor is ON";} else {std::cout << "Monitor is OFF";}
            if (this->isWork) {std::cout << "Monitor is OK";} else {std::cout << "Monitor is NOT OK";}
        }
        void PushButton() {this->OnOff = !this->OnOff;}
};

class Computer {
    private:
        Monitor monitor;
        GraphCard graphcard;
        Processor processor;
        bool isWork;
        bool OnOff;
    public:
        Computer(Monitor& screen, GraphCard& card, Processor& procc) :
            monitor(screen), graphcard(card), processor(procc) {
                if (monitor.GetMonitorWork() && processor.GetProcessorisWork() && graphcard.GetGraphCardisWork()) {
                    this->SetComputerisWork(true);
                } else {
                    this->SetComputerisWork(false);
                }
                this->OnOff = false;
            }
        void SetComputerisWork(bool work) {this->isWork = work;}
        void PushButton() {this->OnOff = !this->OnOff;}
        void GetComputerInfo() {
            this->monitor.GetMonitorInfo();
            this->graphcard.GetGraphCardInfo();
            this->processor.GetProcessorInfo();
            if (this->OnOff) {std::cout << "Computer is ON\n";} else {std::cout << "Computer is OFF\n";}
            if (this->isWork) {std::cout << "Computer is OK\n";} else {std::cout << "Something is wrong, check components and fix them";}
        }
};

struct Sizes {
    private:
        int a, b, c;
    public:
        Sizes(int size_a, int size_b, int size_c) {this->a = size_a; this->b = size_b; this->c = size_c;}
};

struct Position {
    private:
        int x, y;
    public:
        Position(int pos_x, int pos_y) { this->x = pos_x; this->y = pos_y; }
        int GetPositionX(Position& pos) {return pos.x;};
        int GetPositionY(Position& pos) {return pos.y;};
        void SetPosition(int move_x, int move_y) {this->x = move_x; this->y = move_y;};
};

class FurnetureProperties {
    enum Material {
        Wood, Steel, Plastic, Mixed
    };
    std::string furniture_name;
    Sizes sizes;
    Material material;
    Position position;
public:
    FurnetureProperties(std::string& name, Material& mat, const Sizes& s, Position& pos) :furniture_name(name), sizes(s), material(mat), position(pos) {};
    void Move(int move_x, int move_y) {
        std::cout << "Введите координаты, куда хотите переместить "+this->furniture_name;
        std::cin >> move_x >> move_y;
        this->position.SetPosition(move_x, move_y);
    };
};

class Chair {
public:
    FurnetureProperties properties;
    Chair(const FurnetureProperties& prop) :properties(prop) {};
};

class Locker {
public:
    FurnetureProperties properties;
    Locker(const FurnetureProperties& prop) :properties(prop) {};
};

class Table {
public:
    FurnetureProperties properties;
    Table(const FurnetureProperties& prop) :properties(prop) {};
};

int main()
{
    // GraphCard *graph = new GraphCard();
    // graph->SetGraphCardName(name);
    int command_number;
    std::cout << "Welcome to clasroom inventarization programm. Press 'Enter' to continue.\n";
    std::cin.ignore(1, char(13));
    while (true) {
        std::cout << "------Menu------\n";
        std::cout << "1. View information about registered items\n";
        std::cout << "2. Add new item\n";
        std::cout << "3. Work with item\n";
        std::cout << "4. Create file with info about items\n";
        std::cout << "5. Exit\n";
        std::cout << "Please, enter any comand (key's 1-4)\n";
        std::cin >> command_number;
        switch (command_number)
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
            exit;
            break;
        
        default:
            break;
        }
    };
    return 0;
}