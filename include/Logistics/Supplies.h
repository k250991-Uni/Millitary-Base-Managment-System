# pragma once
# include <string>
# include "Equipment.h"

class Supplies : public Equipment {
    private:
        std::string supplyType;
        std::string expirationDate;
        int minStockLevel;
        std::string supplier;
        static int supplyCount;
        
    public:
        Supplies(const std::string& name, const std::string& code, const std::string& type,
                 int qty, double cost, const std::string& loc, const std::string& expDate,
                 int minStock, const std::string& supp);

        void saveToFile(const std::string& fileName) const;
        void loadFromFile(const std::string& fileName);
        bool validateCondition(const std::string& cond) const override;

        std::string getEquipmentType() const override;
        std::string getEntityType() const;

        std::string getSupplyType() const;
        std::string getExpirationDate() const;
        int getMinStockLevel() const;
        std::string getSupplier() const;
        int getSupplyCount() const;
        void setSupplyType(const std::string& type);
        void setExpirationDate(const std::string& date);
        void setMinStockLevel(int level);
        void setSupplier(const std::string& supp);
        void updateQuantity(int change);
        bool isExpired() const;
        bool isLowOnStock() const;
        bool isExpiringSoon(int dayThreshold) const;
        int getDaysUntilExpiration() const;
        int getReorderQuantity() const;
        void consumeSupply(int amount);
        void replenishSupply(int amount);

        bool operator<(const Supplies& other) const;
        bool operator==(const Supplies& other) const;
        Supplies operator+(const Supplies& other) const;

        void display() const override;

        friend std::ostream& operator<<(std::ostream& out, const Supplies& supplies);

        ~Supplies();
};