# pragma once
# include <string>
# include "Equipment.h"

class Weapon : public Equipment {
    private:
        std::string weaponType;
        std::string caliber;
        int ammunition;
        int magazineCapacity;
        bool isLocked;
        std::string lastServiceDate;
        static int weaponCount;

    public:
        Weapon(const std::string& name, const std::string& code, const std::string& type,
               int qty, double cost, const std::string& loc, int ammo, int magCap, const std::string& cal);

        void saveToFile(const std::string& fileName) const;
        void loadFromFile(const std::string& fileName);

        void setWeaponType(const std::string& type);
        void setCaliber(const std::string& cal);
        void addAmmunition(int amount);
        void removeAmmunition(int amount);
        void lockWeapon();
        void unlockWeapon();
        void performMaintenance();
        bool validateCondition(const std::string& cond) const override;

        std::string getEquipmentType() const override;
        std::string getEntityType() const override;
        std::string getWeaponType() const;
        std::string getCaliber() const;
        int getCurrentAmmunition() const { return ammunition; }
        int getMaxAmmunitionCapacity() const { return magazineCapacity; }
        int getAmmunitionPercentage() const;
        int getWeaponCount();
        bool isWeaponLocked() const;
        bool hasAdequateAmmunition(int required) const;
        bool canBeIssued() const;

        bool operator<(const Weapon& other) const;
        bool operator==(const Weapon& other) const;

        void display() const override;
        
        friend std::ostream& operator<<(std::ostream& out, const Weapon& weapon);

        ~Weapon();
};