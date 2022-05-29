#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Subscriber {
public:
    virtual void notify(string str_) {}
    bool sub = 0;
};
class FireDepartment : public Subscriber {
   string str = "fire";
public:
    void say() {
        cout << "Fire Department notified"<<endl;
    }

    void notify(string str_) override{
        if (str_.find(str) != string::npos) {
            say();
        }
    }
};
class Ambulance : public Subscriber {
    string str = "hurt";
public:
    void say() {
       cout << "Ambulance notified"<<endl;
    }

    void notify(string str_) override{
        if (str_.find(str) != string::npos) {
            say();
        }
    }
};
class Police : public Subscriber {
    string str = "criminal";
public:
    void say() {
        cout << "Police notified"<<endl;
    }

    void notify(string str_) override{
        if (str_.find(str) != string::npos) {
            say();
        }
    }
};

class Dispatcher {
  vector<Subscriber*> systems;
public:
    bool tmp = 0;
    void subscribe(Subscriber& subscr) {
        bool tmp = 0;
        for (int i = 0; i < systems.size(); i++) {
            if (&subscr == systems[i])
                tmp = 1;
            break;
        }
        if (!tmp)
            systems.push_back(&subscr);
        subscr.sub = 1;
    }
    void unsubscribe(Subscriber& sub) {
        int count;
        for (int i = 0; i < systems.size(); i++) {
            if (&sub == systems[i])
                tmp = 1;
            count = i;
            break;
        }
        
    }
    void notify(string str_) {
        for (int i = 0; i < systems.size(); i++) {
            if (systems[i]->sub == 1) {
                systems[i]->notify(str_);
            }
        }
    }
};

int main() {
    Dispatcher dispatcher;
    FireDepartment fireDepartment;
    Ambulance ambulance;
    Police police;
    dispatcher.subscribe(fireDepartment);
    dispatcher.subscribe(ambulance);
    dispatcher.subscribe(police);
    dispatcher.notify("The house is on fire! And somebody is hurt!");
    return 0;
}