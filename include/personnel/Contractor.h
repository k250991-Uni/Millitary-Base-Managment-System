#ifndef CONTRACTOR_H
#define CONTRACTOOR_H

#include "Person.h"
#include<string>
#include <ctime>
using namespace std;

//contractor class 
class Contractor : public Person {
    private:
    string companyNmae;
    string securityClearanceLevel;
    string contractEndDate;
    bool isClearancevalid;
    double contractvalue;
    static int contarctValue;
    static int contractorCount;

    public:
    Contractor(const string& name,const string& sNumber,double salary,const string& company,const string& clearance,const string&endDate,double cValue);
    ~Contractor();

    //overide virtual func
    void display() const override;
    void saveToFile(const string& filename) const override;
    void loadFromFile(const string& filename) override ;
    string getEntityType() const override { return "Contarctor";}
    string getPersonType() const override { return "Contarctor";}

    //getter
    string getCompanyName() const { return companyName; }
    string getSecurityClearanceLevel() const {{ return securityClearanceLevel;}}
    string getContatractEndDate() const { return contractEndDate;}
    bool getIsClearanceValid() const { return isClearancevalid;}
    double getContarctValue() const { return contractvalue;}
    static int getConatractorCount() { return contractorCount; }
    

    //setters
    void setCompanyName(const string& company);
    void setSecurityClearanceLevel(const string & clearance);
    void setConstractEndDate(const string& date);
    void setContractvalue(double value);

    // Clearance validation
    bool validateClearance();
    void updateClearanceStatus(bool valid);
    bool isClearanceLevelValid(const string& level) const;

    // contarct mangment
    bool isContractExpiring(int daysThreshold = 30) const ;
    void renewContract(const string& newEndDate);

    //operator
    bool operator<(const Contractor& other ) const ;
    bool operator==(const Contractor& other) const ;

    //stream operaotor
    friend ostream& operator << (ostream & out , const Contractor& contractor);


};
#endif