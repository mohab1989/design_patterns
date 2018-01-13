#include<iostream>
#include<vector>

#include<design_patterns_version.h>

class Subject{
    // 1. "independant functionality"
    std::vector<class Observer*> views; // 3. coupled only to "interface"
    int value;
    
    public:
    void attach(Observer* obs){
        views.push_back(obs);
    }

    void setVal(int val){
        value = val;
        notify();
    }

    int getVal(){
        return value;
    }
    void notify();
};


class Observer{
    // 2. "dependant functionality"
    Subject* model;
    int denom;

public:
    Observer(Subject *mod,int div){
        model = mod;
        denom = div;
        // 4. Observers register themselves with Subject
        model->attach(this);
    }

    //pure virtual funcion
    virtual void update() = 0;

protected:
    Subject * getSubject(){
        return model;
    }
    int getDivisor(){
        return denom;
    }
};

class DivObserver: public Observer{
public:
    DivObserver(Subject* mod, int div): Observer(mod, div) {}
    void update(){
        // 6. "pull" information of interest
        int v = getSubject()->getVal(), d = getDivisor();
        std::cout << v << " mod " << d << " is " << v / d << std::endl;
    }
};

class ModObserver: public Observer{
public:
    ModObserver(Subject* mod, int div): Observer(mod, div){}
    void update(){
        int v = getSubject()->getVal(), d = getDivisor();
        std::cout << v << " mod " << d << " is " << v % d << std::endl;
    }
};
