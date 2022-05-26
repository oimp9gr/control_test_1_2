#include <iostream>
#include <vector>

class Subscriber {
public:
    void Add(std::string to_add){
        key_words.push_back(to_add);
    }
    void sub(){
        is_subscribed = 1;
    }
    void unsub(){
        is_subscribed = 0;
    }
    bool check (){
        return is_subscribed;
    }
    void notify (std::string check) {
        for (auto key_word : key_words) {
            if (check.find(key_word) != std::string::npos) {
                std::cout << output << '\n';
                break;
            }
        }
    };
protected:
    std::vector<std::string> key_words;
    std::string output;
    bool is_subscribed = false;
};

class Dispatcher{
public:
    void subscribe(Subscriber* sub){
        sub->sub();
        subscribers.push_back(sub);
    }
    void unsubscribe(Subscriber* sub){
        sub->unsub();
        for (size_t i = 0; i < subscribers.size(); i++){
            if (!subscribers[i]->check()){
                subscribers.erase(subscribers.begin() + i);
            }
        }
    }
    void notify(std::string to_notify) {
        for (auto i : subscribers) {
            i->notify(to_notify);
        }
    }
private:
    std::vector<Subscriber*> subscribers;
};

class Ambulance : public Subscriber{
public:
    Ambulance() {
        key_words.push_back("hurt");
        output = "Ambulance is called";
        is_subscribed = false;
    }
private:

};

class Police : public Subscriber{
public:
    Police() {
        key_words.push_back("fight");
        output = "Police is called";
        is_subscribed = false;
    }
private:
};

class FireDepartment : public Subscriber{
public:
    FireDepartment() {
        key_words.push_back("fire");
        output = "Fire Department is called";
        is_subscribed = false;
    }
private:
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
    ambulance.Add("broken");
    dispatcher.unsubscribe(&ambulance);
    dispatcher.notify("And somebody is broken!");
// Fire Department is called
// Ambulance is called
    return 0;
}
