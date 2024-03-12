#include <iostream>
#include <string>

class Subject {

public:
std::string name;
std::string location;
std::string serialN;
    void set_name(std::string subj_name){
        name = subj_name;
    }
    std::string get_name(){
        return name;
    }
    void set_location(std::string subj_location){
        location = subj_location;

    }
    std::string get_location(){
        return location;
    }

    void set_serialN(std::string subj_serialN){
        serialN = subj_serialN;

    }
    std::string get_serialN(){
        return serialN;
    }

    void Print(){
        std::cout << "Name " << name << "\nLocation " <<  location << "\nSerial number " << serialN <<std::endl;
    }
};

int main() {
    Subject *smt = new Subject;

    // Добавление нового предмета
    std::string newSubjectName, newLocation, newSerialNumber;
    std::cout << "Enter the name of the new subject: ";
    std::cin >> newSubjectName;
    std::cout << "Enter the location of the new subject: ";
    std::cin >> newLocation;
    std::cout << "Enter the serial number of the new subject: ";
    std::cin >> newSerialNumber;

   smt->set_name(newSubjectName);
   smt->set_location(newLocation);
   smt->set_serialN(newSerialNumber);

   smt->Print();

Subject *two = new Subject;

    // Добавление нового предмета
    std::string newSubjectName1, newLocation1, newSerialNumber1;
    std::cout << "Enter the name of the new subject: ";
    std::cin >> newSubjectName1;
    std::cout << "Enter the location of the new subject: ";
    std::cin >> newLocation1;
    std::cout << "Enter the serial number of the new subject: ";
    std::cin >> newSerialNumber1;

   two->set_name(newSubjectName1);
   two->set_location(newLocation1);
   two->set_serialN(newSerialNumber1);

   two->Print();


    // Удаление предмета
    //std::string subjectToDelete;
    //std::cout << "Enter the name of the subject to delete: ";
    //std::cin >> subjectToDelete;

    delete smt;
    smt->Print();
    two->Print();



    return 0;
}