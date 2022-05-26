#include "Dispatcher.h"
int main() {
	Dispatcher dispatcher;
	FireDepartment fireDepartment;
	Ambulance ambulance;
	Police police;
	dispatcher.subscribe(&fireDepartment);
	dispatcher.subscribe(&ambulance);
	dispatcher.subscribe(&police);
	dispatcher.notify("The house is on fire! And somebody is hurt!");

	dispatcher.unsubscribe(&ambulance);
	dispatcher.notify("Somebody hurt and robbed!");
	return 0;
}