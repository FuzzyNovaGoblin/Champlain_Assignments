#include <string>

using namespace std;

class Product{
protected:
    int section;
    string name;
    int calories;
    int count;
public:
    virtual string displayInfo() = 0;
    Product(string name, int section);
};

class TempControlled : public Product{
protected:
    int temp;
public:
    TempControlled(string name, int section, int temp);
};

class Meat : public TempControlled{
public:
   Meat(string name, int section, int temp = 34);
};

class Produce : public TempControlled{
public:
   Produce(string name, int section, int temp = 34);
};

class DryFood : public Product{
public:
   DryFood(string name, int section);
};
