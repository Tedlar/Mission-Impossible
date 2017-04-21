/*
 * AppMain.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef APPMAIN_H_
#define APPMAIN_H_

#include <src/interfaces/IGUI.h>
#include <src/interfaces/ILogic.h>
Q_DECLARE_METATYPE(uint16_t)

//!  App Main class
/*!

*/
class AppMain {
public:
	//! destructor
	/*!
	*/
	~AppMain();

	//! create AppMain fields
	/*!
	*/
	void create();

	//! configure app main fields - use after create
	/*!
	*/
	void configure(int& argc, char **argv);
	//! initialize fields - use after configure
	/*!
	*/
	void initialize();

	//! start fields
	/*!
	*/
	void start();

private:
	//! variable holding GUI
	/*!
	*/
	std::shared_ptr<IGUI>   gui_;

	//! variable holding logic
	/*!
	*/
	std::shared_ptr<ILogic> logic_;

private:
	//! create GUI
	/*!
	*/
	void createGUI();

	//! create Logic
	/*!
	*/
	void createLogic();


	//! configure GUI
	/*!
	*/
	void configureGUI(int argc, char **argv);

	//! initialize GUI
	/*!
	*/
	void initializeGUI();

	void startGUI();

};

#endif // APPMAIN_H_
