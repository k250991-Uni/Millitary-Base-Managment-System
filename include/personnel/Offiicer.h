#ifndef OFFICER_H
#define OFFICER_H
# include "Person.h"
#include <string>
using namespace std;

//officer class
class Officer : public Person {
    private:
    string specialization;
    string commandCenter;
    int yearOfService;
    static int officerCount;
    public:
    Officer(const string& name,const string& sNumber,const strong& rank,double salry, const string& spec, const string& cmdCenter,int years);
    ~Officer{};

    //override
    void display() const override ;
    void saveToFile(const string& filename) const override;
    void loadFromFile(const string& filename) const override ;
    string getEntityType() const override { return "Officer";}
    string getPersonType() const override { return "Officer";}
    
    //getters
    string getSpecialization() const { return specialization;}
    string getCommandCenter() const { return commandCenter;}
    int getYearsOFService() const { return yearOfService ;}
    static int getOfficerCount() { return officerCount; }

    //setters
    void setSpecialiazation(const string& spec);
    void setCommandCenter(const string& cmdCenter);
    void setYearsOfService(int years);

    //promotion
    void promote(const string& newrank);

    //operators
    bool operator<(const Officer& ohter) const;
    bool operator==(const Officer& other) const;

    // stream operators 
    friend ostream& operator<< (ostream & out, const Officer& officer);
};
#endif