#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class CityEstablishment {
public:
    virtual std::string notify() = 0;

    virtual bool check_is_valid(std::string& sentence) {
        std::vector<std::string> writable;

        std::stringstream ss(sentence);
        std::string item;
        while (std::getline(ss, item, ' ')) {
            writable.push_back(item);
        }
        for (const auto &word: writable) {
            for (const auto &key_word: key_words) {
                if (word == key_word) {
                    return true;
                }
            }
        }
        return false;


    }


private:
    std::vector<std::string> key_words;

};

class FireDepartment : public CityEstablishment {
public:
    std::string notify() override {
        return "Firemen are called";
    }


private:
    std::vector<std::string> key_words = {"fire", "burn", "flame"};
};

class Police : public CityEstablishment {
public:
    std::string notify() override {
        return "Police is called";
    }

private:

    std::vector<std::string> key_words = {"crime", "robbery", "murder"};
};

class Ambulance : public CityEstablishment {
public:
    std::string notify() override {
        return "Ambulance is called";
    }

private:
    std::vector<std::string> key_words = {"injury", "illness", "death"};
};

class Dispatcher {
public:
    void subscribe(CityEstablishment *establishment) {
        subs.push_back(establishment);


    }


    std::string notify(std::string sentence) {
        std::string final;
        for (auto establishment: subs) {
            if (establishment->check_is_valid(sentence)) {
                final += establishment->notify();
                final += "\n";
            }


        }
        return final;
    }

    void unsubscribe(CityEstablishment *establishment) {
        int counter = 0;
        for (auto elem: subs) {

            if (elem == establishment) {
                subs.erase(subs.begin() + counter);
            }
            counter += 1;
        }

    }

private:
    std::vector<CityEstablishment *> subs;
};
