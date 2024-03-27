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
        void EditProcessor() {
            int comand_number;
            char YesOrNo;
            std::cout << "What you want to change?\n\t1) Name\n\t2) Cores count\n\t3) Flows count\n\t4) Heat out\n\t5) Workble?\n\t" <<
            "6) Exit\nPress any key (1-6): ";
            std::cin >> comand_number;
            switch (comand_number)
            {
            case 1:
                std::cout << "Enter new processor name: ";
                std::cin >> this->ProcName;
                std::cout << "New name: '" << this->ProcName << "'\n";
                this->EditProcessor();
                break;
            case 2:
                std::cout << "Enter new cores count: ";
                std::cin >> this->CoresCount;
                std::cout << "New cores count: '" << this->CoresCount << "'\n";
                this->EditProcessor();
                break; 
            case 3:
                std::cout << "Enter new flows count: ";
                std::cin >> this->FlowCount;
                std::cout << "New flows count: '" << this->FlowCount << "'\n";
                this->EditProcessor();
                break;
            case 4:
                std::cout << "Enter new heat out: ";
                std::cin >> this->HeatOut;
                std::cout << "New heat out: '" << this->HeatOut << "'\n";
                this->EditProcessor();
                break;
            case 5:
                std::cout << "Is the processor still working? (Y or N): ";
                std::cin >> YesOrNo;
                if ((YesOrNo == 'Y') || (YesOrNo == 'y')) {
                    std::cout << "Processor is still working\n";
                    this->isWork = true;
                } else if ((YesOrNo == 'n') || (YesOrNo == 'N')) {
                    std::cout << "Processor doesn't working. Repare it\n";
                    this->isWork = false;
                }
                this->EditProcessor();
                break;
            case 6:
                this->GetProcessorInfo();
                break;
            default:
                this->EditProcessor();
                break;
            }
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
        void EditGraphCard() {
            int comand_number;
            char YesOrNo;
            std::cout << "What you wnt to change?\n\t1) Name\n\t2) Video memory size\n\t3) Heat out\n\t4) Workable?\n\t5) Exit\n" <<
            "Press any key (1-5): ";
            std::cin >> comand_number;
            switch (comand_number)
            {
            case 1:
                std::cout << "Enter new graphcard name: ";
                std::cin >> this->CardName;
                std::cout << "New name: '" << this->CardName << "'\n";
                this->EditGraphCard();
                break;
            case 2:
                std::cout << "Enter new video memory size: ";
                std::cin >> this->VideoMemory;
                std::cout << "New cores count: '" << this->VideoMemory << "'\n";
                this->EditGraphCard();
                break; 
            case 3:
                std::cout << "Enter new heat out: ";
                std::cin >> this->HeatOut;
                std::cout << "New heat out: '" << this->HeatOut << "'\n";
                this->EditGraphCard();
                break;
            case 4:
                std::cout << "Is the graphcard still working?(Y or N): ";
                std::cin >> YesOrNo;
                if ((YesOrNo == 'n') || (YesOrNo == 'N')) {std::cout << "Graph card doesn't work. Repare it\n"; this->isWork = false;} 
                else if ((YesOrNo == 'y') || (YesOrNo == 'Y')) {std::cout << "Graph card is still working.\n"; this->isWork = true;}
                this->EditGraphCard();
                break;
            case 5:
                this->GetGraphCardInfo();
                break;
            }
        }
};

class Monitor {
    private:
        std::string MonitorName;
        int Resolution;
        bool isWork;
        bool OnOff;
    public:
        Monitor(std::string &name, int &gerz, bool &work, bool &onoff): MonitorName(name), Resolution(gerz),  isWork(work), OnOff(onoff) {}
        Monitor() = default;
        ~Monitor() = default;
        
        std::string GetMonitorName() {return this->MonitorName;}
        void SetMonitorName(std::string name) {this->MonitorName = name;}

        int GetMonitorResolution() {return this->Resolution;}
        void SetMonitorReslution(int gerz) {this->Resolution = gerz;}

        bool GetMonitorisWork() {return this->isWork;}
        void SetMonitorisWork(bool work) {this->isWork = work;}

        bool GetMonitorOnOff() {return this->OnOff;}
        void SetMonitorOnOff(bool onoff) {this->OnOff = onoff;}
        
        void GetMonitorInfo() {
            std::cout << "MONITOR\n\n";
            std::cout << "Monitor name: " << this->MonitorName << "\n"
            << "Monitor resolution: " << this->Resolution << "\n";
            if (this->OnOff) {std::cout << "Monitor is ON";} else {std::cout << "Monitor is OFF";}
            if (this->isWork) {std::cout << "Monitor is OK";} else {std::cout << "Monitor is NOT OK";}
        }
        void PushButton() {this->OnOff = !this->OnOff;}

        void EditMonitor() {
            int comand_number;
            char YesOrNo;
            std::cout << "What you want to change?\n\t1) Name\n\t2) Resolution\n\t3) On or off?\n\t4) Workable?\n\t5) Exit\n" <<
            "Press any key (1-5): ";
            std::cin >> comand_number;
            switch (comand_number)
            {
            case 1:
                std::cout << "Enter new monitor name: ";
                std::cin >> this->MonitorName;
                std::cout << "New name: '" << this->MonitorName << "'\n";
                this->EditMonitor();
                break;
            case 2:
                std::cout << "Enter new resolution: ";
                std::cin >> this->Resolution;
                std::cout << "New resolution: '" << this->Resolution << "'\n";
                this->EditMonitor();
                break; 
            case 3:
                if (this->isWork) {
                    std::cout << "What you want to do: ON or OFF (Y or N)";
                    std::cin >> YesOrNo;
                    if ((YesOrNo == 'y') || (YesOrNo == 'Y')) {this->OnOff = true; std::cout << "You ON monitor\n";} 
                    else if ((YesOrNo == 'n') || (YesOrNo == 'N')) {this->OnOff = false; std::cout << "You OFF monitor\n";}
                } else {
                    std::cout << "Repare monitor befor work with monitor\n";
                }
                this->EditMonitor();
                break;
            case 4:
                std::cout << "Is the monitor still working?(Y or N): ";
                std::cin >> YesOrNo;
                if ((YesOrNo == 'n') || (YesOrNo =='N')) {std::cout << "Monitor doesn't work. Repare it\n"; this->isWork = false;} 
                else if ((YesOrNo == 'y') || (YesOrNo == 'Y')) {std::cout << "Monitor is still working.\n"; this->isWork = true;}
                this->EditMonitor();
                break;
            case 5:
                this->GetMonitorInfo();
                break;
            }
        }
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
                if (monitor.GetMonitorisWork() && processor.GetProcessorisWork() && graphcard.GetGraphCardisWork()) {
                    this->SetComputerisWork(true);
                } else {
                    this->SetComputerisWork(false);
                }
                this->OnOff = false;
            }
        Computer() = default;
        ~Computer() = default;

        Monitor& GetComputerMonitor() {return this->monitor;}
        void SetComputerMonitor(Monitor& screen) {this->monitor = screen;}

        GraphCard& GetComputerGraphCard() {return this->graphcard;}
        void SetComputerGraphCard(GraphCard& card) {this->graphcard = card;}

        Processor& GetComputerProcessor() {return this->processor;}
        void SetComputerProcessor(Processor& proc) {this->processor = proc;}

        bool GetComputerisWork() {return this->isWork;}
        void SetComputerisWork(bool work) {this->isWork = work;}

        void PushButton() {this->OnOff = !this->OnOff;}
        void GetComputerInfo() {
            this->monitor.GetMonitorInfo();
            this->graphcard.GetGraphCardInfo();
            this->processor.GetProcessorInfo();
            if (this->OnOff) {std::cout << "Computer is ON\n";} else {std::cout << "Computer is OFF\n";}
            if (this->isWork) {std::cout << "Computer is OK\n";} else {std::cout << "Something is wrong, check components and fix them";}
        }
        void EditComputer() {
            int comand_number;
            std::cout << "what you want to change?\n\t1) Monitor\n\t2) Graphcard\n\t3) Processor\n\t4) Workable?\n\t5) ON or OFF\n\t6) Exit\n" <<
            "Press any key (1-6)";
            std::cin >> comand_number;
            switch (comand_number)
            {
            case 1:
                this->monitor.EditMonitor();
                break;
            case 2:
                this->graphcard.EditGraphCard();
                break;
            case 3:
                this->processor.EditProcessor();
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
};

struct Sizes {
    private:
        int a, b, c;
    public:
        Sizes(int size_a, int size_b, int size_c): a(size_a), b(size_b), c(size_c) {}
};

struct Position {
    private:
        int x, y;
    public:
        Position(int pos_x, int pos_y) { this->x = pos_x; this->y = pos_y; }
        Position() = default;
        ~Position() = default;
        int GetPositionX(Position& pos) {return pos.x;};
        int GetPositionY(Position& pos) {return pos.y;};
        void SetPosition(int pos_x, int pos_y) {this->x = pos_x; this->y = pos_y;}
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
    FurnetureProperties() = default;
    ~FurnetureProperties() = default;

    std::string GetFurnetureName() {return this->furniture_name;}
    void SetFurnetureName(std::string& name) {this->furniture_name = name;}

    Sizes GetFurnetureSizes() {return this->sizes;}
    void SetFurnetureSizes(Sizes& size) {this->sizes = size;}

    Material GetFurnetureMaterial() {return this->material;}
    void SetFurnetureMaterial(Material& mater) {this->material = mater;}

    Position GetFurneturePosition() {return this->position;}
    void SetFurneturePosition(Position& pos) {this->position = pos;}

    void Move(int move_x, int move_y) {
        std::cout << "Enter new coordinates: "+this->furniture_name;
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
    Processor *proc = new Processor();
    proc->EditProcessor();
    GraphCard *card = new GraphCard();
    card->EditGraphCard();
    Monitor *screen = new Monitor();
    screen->EditMonitor();
    return 0;
}