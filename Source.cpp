#include <iostream>
#include <vector>
#include <string>


class Subscriber {
public:
    void Add(std::string str) { keyWord.push_back(str); }
    void InstallStat(bool el) { status = el; }
    bool check() { return status; }
    void notify(const std::string& str) {
        std::string Temp = str;
        for (size_t i = 0; i < keyWord.size(); i++) {
            if (Temp.find(keyWord[i]) != -1) {
                std::cout << outstr << std::endl;
                break;
            }
        }
    };
protected:
    std::vector<std::string> keyWord;
    std::string outstr;
    bool status = false;
};

class Dispatcher {
public:
    void subscribe(Subscriber* r) {
        r->InstallStat(1);
        Services.push_back(r);
    }
    void unsubscribe(Subscriber* r) {
        r->InstallStat(0);
        for (size_t i = 0; i < Services.size(); i++) {
            if (!Services[i]->check()) {
                Services.erase(Services.begin() + i);
            }
        }
    }

    void notify(const std::string& str) { 
        for (size_t i = 0; i < Services.size(); i++) Services[i]->notify(str);
    }

private:
    std::vector<Subscriber*> Services;
};


class Police : public Subscriber {
public:
    Police() {
        keyWord.push_back("fight");
        outstr = "Police is called";
        status = false;
    }
};

class FireDepartment : public Subscriber {
public:
    FireDepartment() {
        keyWord.push_back("fire");
        outstr = "Fire Department is called";
        status = false;
    }
};

class Ambulance : public Subscriber {
public:
    Ambulance() {
        keyWord.push_back("hurt");
        outstr = "Ambulance is called";
        status = false;
    }
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
	
	return 0;
}