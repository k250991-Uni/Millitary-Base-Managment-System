# pragma once
# include <string>
# include "core/BaseEntity.h"

class Equipment : public BaseEntity {
    protected:
        std::string equipmentCode;
        int quantity;
        double unitCost;
        std::string location;
        std::string condition;
        std::string lastServiceDate;

    public:
        Equipment(const std::string& name, const std::string& code, int qty, double cost, const std::string& loc);

        virtual void display() const = 0;
        virtual std::string getEquipmentType() const = 0;
        virtual bool validateCondition(const std::string& cond) const = 0;

        std::string getEquipmentCode() const;
        int getQuantity() const;
        double getUnitCost() const;
        double getTotalValue() const;
        std::string getCondition() const;
        std::string getLastServiceDate() const;
        std::string getLocation() const;

        void setCondition(const std::string& newCondition);
        void setLocation(const std::string& loc);
        void updateLastServiceDate();
        void addStock(int amount);
        void removeStock(int amount);
        bool hasAdequateStock(int required) const;

        bool operator<(const Equipment& other) const;
        bool operator==(const Equipment& other) const;

        friend std::ostream& operator<<(std::ostream& out, const Equipment& equipment);

        virtual ~Equipment();
};