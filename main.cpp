#include <iostream>
#include <string>
#include <vector>

void speak (){
    std::cout << " AaAAaaA";
}

class Subscribes{
public:
    virtual void notify(std::string word_) = 0;
    bool sub = 0;
};
class FireDepartment : public Subscribes{
    std::string word = "Fire";
public:
    void notify(std::string word_){
        if(word == word_)
            speak();
    }
};
class Ambulance : public Subscribes{
    std::string word = "Help";
public:
    void notify(std::string word_){
        if(word == word_)
            speak();
    }
};
class Police : public Subscribes{
    std::string word = "Kill";
public:
    void notify(std::string word_){
        if(word == word_)
            speak();
    }
};

class Dispatcher{
public:
    Dispatcher(){}
    void subscribe (Subscribes& pomogite){
        bool tmp = 0;
        for(auto i : services){
            if (&pomogite == i)
                tmp = 1;
            break;
        }
        if(!tmp)
            services.push_back(&pomogite);
        pomogite.sub = 1;
    }
    void unsubscribe (Subscribes& pomogite){
        bool tmp = 0;
        int counter;
        for(int  i = 0; i < services.size() ; i++){
            if (&pomogite == services[i])
                tmp = 1;
            counter = i;
            break;
        }
        if(tmp)
            std::swap(services[counter],services[services.size() - 1]);
            services.pop_back();
        pomogite.sub = 0;
    }
    void notify(const std::string word){
        for(auto i : services){
            if(i->sub == 1){
                i->notify(word);
            }
        }
    }
protected:
    std::vector<Subscribes*> services ;
};

int main() {
    Dispatcher dispatcher;
    FireDepartment fireDepartment;
    Ambulance ambulance;
    Police police;
    dispatcher.subscribe(fireDepartment);
    dispatcher.subscribe(ambulance);
    dispatcher.subscribe(police);
    dispatcher.notify("Fire");
    dispatcher.unsubscribe(fireDepartment);
    dispatcher.notify("Fire");
    return 0;
}
