#include <string>
#include <iostream>

class Beverage {
public:
    std::string GetDescription() {
        if (HasMilk()){
            description_ += ", Milk";
        }
        if (HasSoy()) {
            description_ += ", Soy";
        }
        if (HasWhip()) {
            description_ += ", Whip";
        }
        if (HasMocha()) {
            description_ += ", Mocha";
        }
        return description_;

    }
    virtual double Cost() {
        double condiment_cost = 0;
        if (HasMilk()){
            condiment_cost += milk_cost_; 
        }
        if (HasSoy()) {
            condiment_cost += soy_cost_;
        }
        if (HasWhip()) {
            condiment_cost += whip_cost_;
        }
        if (HasMocha()) {
            condiment_cost += mocha_cost_;
        }
        return condiment_cost;
    }

    bool HasMilk() const {
        return has_milk_;
    }
    bool HasMocha() const {
        return has_mocha_;
    }
    bool HasSoy() const {
        return has_soy_;
    }
    bool HasWhip() const {
        return has_whip_;
    }
    double GetMilkCost() const {
        return milk_cost_;
    }
    double GetWhipCost() const {
        return whip_cost_;
    }
    double GetSoyCost() const {
        return soy_cost_;
    }
    double GetMochaCost() const {
        return mocha_cost_;
    }
    void SetMilkCost(double cost){
        milk_cost_ = cost;
    }
    void SetSoyCost(double cost){
        soy_cost_ = cost;
    }
    void SetWhipCost(double cost){
        whip_cost_ = cost;
    }
    void SetMochaCost(double cost){
        mocha_cost_ = cost;
    }
    void SetMilk(bool need){
        has_milk_ = need;
    }
    void SetSoy(bool need){
        has_soy_ = need;
    }
    void SetWhip(bool need){
        has_whip_ = need;
    }
    void SetMocha(bool need){
        has_mocha_ = need;
    }
private:
    double milk_cost_ = 0.10;
    double whip_cost_ = 0.10;
    double soy_cost_ = 0.15;
    double mocha_cost_ = 0.20;
    bool has_milk_ = false;
    bool has_whip_ = false;
    bool has_soy_ = false;
    bool has_mocha_ = false;
protected:
    std::string description_;
};

class DarkRoast : public Beverage {
public: 
    DarkRoast() {
        description_ = "Dark Roast";
    }
    double Cost() {
        return Beverage::Cost() + 0.99;
    }
};

class Espresso : public Beverage {
public: 
    Espresso() {
        description_ = "Espresso";
    }
    double Cost() {
        return Beverage::Cost() + 1.99;
    }
};

class HouseBlend : public Beverage {
public: 
    HouseBlend() {
        description_ = "HouseBlend";
    }
    double Cost() {
        return Beverage::Cost() + 0.89;
    }
};

void offer() {
    Beverage* beverage = new Espresso();
    std::cout << beverage->GetDescription() << " costs $" << beverage->Cost() << std::endl;

    Beverage* beverage2 = new DarkRoast();
    beverage2->SetMocha(true);
    beverage2->SetWhip(true);
    std::cout << beverage2->GetDescription() << " costs $" << beverage2->Cost() << std::endl;
    
    Beverage* beverage3 = new HouseBlend();
    beverage3->SetSoy(true);
    beverage3->SetMocha(true);
    beverage3->SetWhip(true);
    std::cout << beverage3->GetDescription() << " costs $" << beverage3->Cost() << std::endl;
}

int main() {
    offer();
}