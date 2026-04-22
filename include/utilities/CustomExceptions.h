#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;
class MillitaryException: public exception {
    protected:
    string message;
    public:
    MillitaryException(const string& msg = "Unkown military system error"):message(msg){}
    virtual ~MillitaryException(){
    }
    virtual const char* what() const noexcept override{ return message.c_str();}
};

// for personnel related exception 
class PersonnelException : public MillitaryException{
    public:
    PersonnelException(const string& msg = "Personnel error occured"):MillitaryException("PERSONNEL ERROR:" + msg){}
};
class InvalidRankException : public PersonnelException{
    public:
    InvalidRankException(const string& rank):PersonnelException("Invalid rank "+ rank){

    }
};
class PerosnnalNotFoundException : public PersonnelException{
public:
PerosnnalNotFoundException(int id):PersonnelException("Personnel with ID"+ to_string(id) + " not found"){

}
};
//for logistics related
class LogisticsException: public MillitaryException{
 public:
 LogisticsException(const string&msg = " Logistics error occured"):MillitaryException("LOGISTICS ERROR: "+  msg){}
};
class InsufficientSuppyException : public LogisticsException{
   public:
   InsufficientSuppyException(const string& item,int required,int available):LogisticsException(item + " insufficient. Requied: " + to_string(required) + ",Available:" + to_string(available)){}
};
class WeaponException : public LogisticsException{
    public:
    WeaponException(const string&msg = " Weapon error occured"):LogisticsException("WEAPON ERROR: " + msg ){}
};

// for operation related
class OperationException : public MillitaryException{
public:
OperationException(const string& msg = "Operation error occured"):MillitaryException("OPERATION ERROR: "+ msg){}
};

class InvalidOperationStatusException : public OperationException {
    public:
    InvalidOperationStatusException(const string& status): OperationException("Inavlid operatioon status: "+ status){}
};

// for files
class FileExceptioon : public MillitaryException{
public:
FileExceptioon(const string& msg = "File error occured"):
MillitaryException("FILE ERROR: "+ msg){}

};
class FileNotFoundException : public FileExceptioon{
    public:
    FileNotFoundException(const string& filename):
    FileExceptioon("File not found: " + filename){}
};
// for validation

class ValidationException : public MillitaryException {
    public :
    ValidationException(const string& msg = "Validation failed") : MillitaryException("VALIDATION ERROR: "+ msg){}
};
#endif