#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include "ILoggable.h" // need for login func
#include <iostream>
#include <string>
using namespace std;

class BaseEntity : public ILoggable {
    protected:
    int entityID;
    string name;
    string dateCreated;
    string lastModified;
    static int entityCounter;

    BaseEntity(const string&n = ""); // for derived cllass only
   public:
   virtual ~BaseEntity();

   virtual void display() const = 0;
   virtual void saveToFile(const string& filename) const = 0;
   virtual void loadFromFile(const string& filenmae) = 0;
   virtual string getEntityType() const = 0;

   //getters
   int getID() const { return entityID; }
   std::string getName() const { return name;}
   std::string getDateCreated() const { return dateCreated;}
   string getLastModified() const { return lastModified;}
   static int getTotalEntities() { return entityCounter; }

   //setters
   void setName(const string&n);
   void updateLastModified();

   //ILoagable implementation 
   void logActivity(string msg) override;

   //operators
   bool operator==(const BaseEntity& other )const;
   bool operator!=(const BaseEntity& othere) const;
   friend ostream& operator<< (ostream& out,const BaseEntity&entity);
   friend istream& operator>>(istream& in,BaseEntity&entity);

};
#endif