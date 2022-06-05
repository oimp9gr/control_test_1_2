#include <iostream>
#include <list>
#include <string>

class IObserver {
public:
    virtual ~IObserver() {};
    virtual void notify(const std::string& message) = 0;
};

class Dispatcher {
public:
    virtual ~Dispatcher() {}

    void subscribe(IObserver* observer) {
        list_observer_.push_back(observer);
    }

    void unsubscribe(IObserver* observer) {
        list_observer_.remove(observer);
    }

    void notify(std::string str) {
        std::list<IObserver*>::iterator iterator = list_observer_.begin();
        while (iterator != list_observer_.end()) {
            (*iterator)->notify(str);
            ++iterator;
        }
    }
private:
    std::list<IObserver*> list_observer_;
};

class Police : public IObserver {
public:
    Police() {}

    void notify(const std::string& message) override{
        //The police must always be present at the scene. They don't need key wards
    }

private:
    std::string message;
};

class FireDepartment : public IObserver {
public:
    FireDepartment(){ }
    
    void notify(const std::string& message) override {
        if (message.find(key)) {
            //they go to the scene
        }
    }

private:
    std::string message_from_subject_;
    std::string key="fire";
};

class Ambulance : public IObserver {
public:
    Ambulance() {}
    
    void notify(const std::string& message) override {
        if (message.find(key)) {
            //they go to the scene
        }
    }

private:
    std::string message;
    std::string key= "hert";
};

int main() {
Dispatcher dispatcher;
FireDepartment fireDepartment;
Ambulance ambulance;
Police police;
dispatcher.subscribe(&fireDepartment);
dispatcher.subscribe(&ambulance);
dispatcher.subscribe(&police);
dispatcher.notify("The house is on fire! And somebody is hurt!");
}