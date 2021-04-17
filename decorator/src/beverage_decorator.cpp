#ifndef DECORATOR_BEVERAGE_HPP_
#define DECORATOR_BEVERAGE_HPP_
#include <string>
#include <iostream>

class Beverage {
public:
    virtual std::string GetDescription(){
        return description_;
    }
    virtual double Cost() = 0;

protected:
    std::string description_ = "Unknown Beverage";

};

class CondimentDecorator : public Beverage {
public:
    virtual std::string GetDescription() = 0;
};

class DarkRoast : public Beverage {
public:
    DarkRoast(){
        description_ = "DarkRoast";
    }
    double Cost() override {
        return 0.99;
    }
};

class Espresso: public Beverage {
public:
    Espresso(){
        description_ = "Espresso";
    }
    double Cost() override {
        return 1.99;
    }
};

class HouseBlend: public Beverage {
public:
    HouseBlend(){
        description_ = "House Blend Coffee";
    }
    double Cost() override {
        return 0.89;
    }
};

class Mocha : public CondimentDecorator {
public:
    Mocha(Beverage* beverage){
        this->beverage = beverage;
    }
    std::string GetDescription() override {
        return beverage->GetDescription() + ", Mocha";
    }
    double Cost() override {
        return 0.20 + beverage->Cost();
    }
private:
    Beverage* beverage;
};

class Soy : public CondimentDecorator {
public:
    Soy(Beverage* beverage){
        this->beverage = beverage;
    }
    std::string GetDescription() override {
        return beverage->GetDescription() + ", Soy";
    }
    double Cost() override {
        return 0.15 + beverage->Cost();
    }
private:
    Beverage* beverage;
};

class Whip : public CondimentDecorator {
public:
    Whip(Beverage* beverage){
        this->beverage = beverage;
    }
    std::string GetDescription() override {
        return beverage->GetDescription() + ", Whip";
    }
    double Cost() override {
        return 0.10 + beverage->Cost();
    }
private:
    Beverage* beverage;
};


void offer(){
    Beverage* beverage = new Espresso();
    std::cout << beverage->GetDescription() << " costs $" << beverage->Cost() << std::endl;
    
    Beverage* beverage2 = new DarkRoast();
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    std::cout << beverage2->GetDescription() << " costs $" << beverage2->Cost() << std::endl;
    
    Beverage* beverage3 = new HouseBlend();
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    std::cout << beverage3->GetDescription() << " costs $" << beverage3->Cost() << std::endl;
}

int main(){
    offer();
}
#endif