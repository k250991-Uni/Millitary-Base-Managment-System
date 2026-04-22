#ifndef ILOGGABLE_H
#define ILOGGABLE_H

#include <string>
using namespace std;

// Interface for logging functionality
class ILoggable{
    public:
    virtual ~ILoggable(){} 
    
    //pure virtual function
    virtual void logActivity(string msg) = 0;

};
#endif