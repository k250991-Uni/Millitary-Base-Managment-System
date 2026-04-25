#ifndef CONTRACTOR_H
#define CONTRACTOR_H

#include "Person.h"
#include<string>
#include <ctime>
using namespace std;

//contractor class 
class Contractor : public Person {
    private:
    string companyName;
    string securityClearanceLevel;
    string contractEndDate;
    bool isClearanceValid;
    double contractValue;
    static int contractorCount;

    public:
    Contractor(const string& name,const string& sNumber,double salary,const string& company,const string& clearance,const string&endDate,double cValue);
    ~Contractor();

    //overide virtual func
    void display() const override;
    void saveToFile(const string& filename) const override;
    void loadFromFile(const string& filename) override ;
    string getEntityType() const override { return "Contractor";}
    string getPersonType() const override { return "Contractor";}

    //getter
    string getCompanyName() const { return companyName; }
    string getSecurityClearanceLevel() const { return securityClearanceLevel;}
    string getContractEndDate() const { return contractEndDate;}
    bool getIsClearanceValid() const { return isClearanceValid;}
    double getContractValue() const { return contractValue;}
    static int getContractorCount() { return contractorCount; }
    
    //setters
    void setCompanyName(const string& company);
    void setSecurityClearanceLevel(const string & clearance);
    void setContractEndDate(const string& date);
    void setContractValue(double value);

    // contarct mangment
    bool isContractExpiring(int daysThreshold = 30) const ;
    void renewContract(const string& newEndDate);

    private:
    bool isClearanceLevelValid(const string& level) const;

    //operator
    bool operator<(const Contractor& other ) const ;
    bool operator==(const Contractor& other) const ;
};
#endif