#include <iostream>
#include <vector>
#include <string>


class CityEstablishment {
public:
    virtual std::string notify() {
        return "";
    }

    virtual std::string getword() {
        return word;
    }

private:
    std::string word;

};

class FireDepartment : public CityEstablishment {
public:
    std::string notify() override {
        return "Firemen are called";
    }

private:
    std::string word = "fire";
};

class Ambulance : public CityEstablishment {
public:
    std::string notify() override {
        return "Ambulance is called";
    }

private:
    std::string word = "injury";
};

class Police : public CityEstablishment {
public:
    std::string notify() override {
        return "Police is called";
    }

private:

    std::string word = "crime";
};

class Dispatcher {
public:
    void subscribe(CityEstablishment *establishment) {
        subs.push_back(establishment);


    }


    std::string notify(std::string sentence) {
        std::string final = "";
        for (auto est: subs) {
            auto is_in = sentence.find(est->getword());
            if (is_in != std::string::npos) {
                final += est->notify();
                final += "\n";
            }
        }
        return final;
    }

    void unsubscribe(CityEstablishment *establishment) {
        int counter = 0;
        for (auto elem : subs){

            if (elem == establishment){
                subs.erase(subs.begin() + counter);
            }
            counter += 1;
        }

    }

private:
    std::vector<CityEstablishment *> subs;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
