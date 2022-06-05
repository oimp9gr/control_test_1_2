#include <iostream>
#include <vector>
using namespace std;

class Subs {
private:
	const string word;
public:
	string name;
	Subs(string _name, string _word) : name(_name), word(_word) {}

   virtual bool CheckWord(string str){
	   if (str.find(word) != string::npos) {
		   //если есть слово
		   return true;
	   }
	   //если нет слова
	   else return false;
   }
   virtual void notify() {
	   cout << name << " is called!"<<endl;
   }

};

class Ambulance: public Subs {
public:
	Ambulance():Subs("Ambulance", "hurt") {}
	
};

class Police : public Subs {
public:
	Police() :Subs("Police", "attack") {}
	
};

class FireDepartment : public Subs {
public:
	FireDepartment() :Subs("Fire Dep", "fire") {}
	
};

class Dispatcher {

public:
	vector<Subs*> subs;
	Dispatcher() {}
	void subscribe(Subs* sub){
		subs.push_back(sub);
	}
	void unsubscribe(Subs* sub) {
		int index = 0;
		for (int i = 0; i < subs.size(); i++) {
			if (subs[i]->name == sub->name) index = i;
		}
		for (int i = index; i < subs.size()-1; i++) {
			subs[i] = subs[i + 1];
		}
		subs.pop_back();
	}
	void notify(string str) {
		for (int i = 0; i < subs.size(); i++) {
			if (subs[i]->CheckWord(str) == true) subs[i]->notify();
		}
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
	dispatcher.notify("The house is on fire! And somebody is hurt! ");


}