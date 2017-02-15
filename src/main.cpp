
#include "AppMain.h"


int main(int argc, char **argv) {
	AppMain app;
	app.create();
	app.configure(argc, argv);
	app.initialize();
	app.start();
}
