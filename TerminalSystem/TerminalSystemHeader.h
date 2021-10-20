#pragma once

#include <iostream>

class TerminalSystem
{
private:

	std::string ExistingUserLogin = "";
	std::string ExistingUserPassword = "";
	std::string ExistingUserLoginChecker = "";
	std::string ExistingUserPasswordChecker = "";
	std::string NewUserLogin = "";
	std::string NewUserLoginChecker = "";
	std::string NewUserPasswordChecker = "";
	std::string NewUserPassword = "";
	std::string UserChoice = "";
	int MaxLoginTries = 0;
	int UserFileSelection = 0;



public:

	TerminalSystem();
	~TerminalSystem();

	int LoginScreen();
	void ExistingUserLoginValidation();
	void NewUserCreationScreen();
	void TerminalInfoScreen();
	void ClassifiedInfo();
	void NasaArchives();
	void MilitaryFiles();
};

