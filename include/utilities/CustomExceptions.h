#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;
class MilitaryException: public exception {
    protected:
    string message;
    public:
    MilitaryException(const string& msg = "Unknown military system error"):message(msg){}
    virtual ~MilitaryException(){
    }
    virtual const char* what() const noexcept override{ return message.c_str();}
};

// for personnel related exception 
class PersonnelException : public MilitaryException{
    public:
    PersonnelException(const string& msg = "Personnel error occured"):MilitaryException("PERSONNEL ERROR:" + msg){}
};
class InvalidRankException : public PersonnelException{
    public:
    InvalidRankException(const string& rank):PersonnelException("Invalid rank "+ rank){

    }
};
class PersonnelNotFoundException : public PersonnelException{
public:
PersonnelNotFoundException(int id):PersonnelException("Personnel with ID"+ to_string(id) + " not found"){

}
};
//for logistics related
class LogisticsException: public MilitaryException{
 public:
 LogisticsException(const string&msg = " Logistics error occured"):MilitaryException("LOGISTICS ERROR: "+  msg){}
};
class InsufficientSupplyException : public LogisticsException{
   public:
   InsufficientSupplyException(const string& item,int required,int available):LogisticsException(item + " insufficient. Requied: " + to_string(required) + ",Available:" + to_string(available)){}
};
class WeaponException : public LogisticsException{
    public:
    WeaponException(const string&msg = " Weapon error occured"):LogisticsException("WEAPON ERROR: " + msg ){}
};

// for operation related
class OperationException : public MilitaryException{
public:
OperationException(const string& msg = "Operation error occured"):MilitaryException("OPERATION ERROR: "+ msg){}
};

class InvalidOperationStatusException : public OperationException {
    public:
    InvalidOperationStatusException(const string& status): OperationException("Invalid operation status: "+ status){}
};

// for files
class FileException : public MilitaryException{
public:
FileException(const string& msg = "File error occured"):
MilitaryException("FILE ERROR: "+ msg){}

};
class FileNotFoundException : public FileException{
    public:
    FileNotFoundException(const string& filename):
    FileException("File not found: " + filename){}
};
// for validation

class ValidationException : public MilitaryException {
    public :
    ValidationException(const string& msg = "Validation failed") : MilitaryException("VALIDATION ERROR: "+ msg){}
};
#endif