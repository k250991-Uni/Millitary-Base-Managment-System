#ifndef PERSON_H
#define PERSON_H
#include "core/BaseEntity.h"
#include <string>
#include <vector>
using namespace std;

class Person : public BaseEntity {
    protected:
    string serviceNumber;
    string rank;
    double salary;
    vector<string> assignedWeapons;
    string currentPosition;
    // for dericved classs only
    Person(const string&name,const string& sNumbber,const string& r,double sal);
    public:
    virtual ~Person();

    virtual void display() const  = 0;
    virtual string getPersonType() const = 0;

    //geters
    string getservooceNumber() const { return serviceNumber;
    }
    string getRank() const { return rank;
    }
    double getSalary()const { return salary;}
    string getCurrentPosition() const { return currentPosition; }
    vector<string> getAssigneedWeapons()const { return assignedWeapons; }

    //setters
    void setRank(const string & newRank);
    void setSalary(double newSalary);
    void setCurrentPosition(const string& newPosition);
    void addAssignedWeapon(const string& weaponID);

    //service number validaiton
    static bool isValidServiceNumber(const string& sNumber);

    //operators
    bool operator < (const Person& other ) const ;
    bool operator==(const Person& other) const;
};
#endif