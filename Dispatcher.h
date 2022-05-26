#pragma once
#include <string>
#include <vector>
#include <iostream>
class Subscriber {
protected:
	bool is_subbed;
	std::string key_word;
public:
	void sub_user() {
		is_subbed = true;
	}
	void unsub_user() {
		is_subbed = false;
	}
	virtual void setKeyWord() = 0;
	virtual void called() = 0;

	bool key_check(const std::string& str) {
		if (str.find(key_word) != std::string::npos) {
			called();
			return true;
		}
		return false;
	}
	
};
class Dispatcher {
private:
	std::vector<Subscriber*> subs;
public:
	void subscribe(Subscriber* sub) {
		sub->sub_user();
		subs.push_back(sub);
	}
	void unsubscribe(Subscriber* sub) {
		sub->unsub_user();
		for (size_t i = 0; i < subs.size(); i++)
		{
			if (subs[i] == sub) {
				for (size_t j = i; j < subs.size() - 1; j++)
				{
					subs[j] = subs[j + 1];
				}
				subs[subs.size() - 2] = subs[subs.size() - 1];
				subs.resize(subs.size() - 1);
			}
		}
	}
	void notify(const std::string& s) {
		for (size_t i = 0; i < subs.size(); i++)
		{
			subs[i]->key_check(s);
		}
	}
};
class FireDepartment: public Subscriber {
public:
	FireDepartment() {
		setKeyWord();
	}
protected:

	void setKeyWord() {
		key_word = "fire";
	}
	void called() {
		std::cout << "Fire Department is called\n";
	}
};
class Ambulance: public Subscriber {
public:
	Ambulance() {
		setKeyWord();
	}
protected:
	
	void setKeyWord() {
		key_word = "hurt";
	}
	void called() {
		std::cout << "Ambulance is called\n";
	}
};
class Police: public Subscriber {
public:
	Police() {
		setKeyWord();
	}
protected:
	
	void setKeyWord() {
		key_word = "rob";
	}
	void called() {
		std::cout << "Police is called\n";
	}
};