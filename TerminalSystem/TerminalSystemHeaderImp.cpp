#include "TerminalSystemHeader.h"

#include <iostream>
#include <typeinfo>


TerminalSystem::TerminalSystem()
{
	MaxLoginTries = 5;
	ExistingUserLogin = "1";
	ExistingUserPassword = "2";

}

TerminalSystem::~TerminalSystem()
{

}

int TerminalSystem::LoginScreen()
{

	std::cout << "Terminal System v 1.8.00765." << std::endl << std::endl;
	std::cout << "1. Usuário existente." << std::endl << "2. Novo usuário." << std::endl << std::endl;
	std::cout << "Digite o que deseja fazer: ";
	do
	{
		std::cin >> UserChoice;
		if ((UserChoice == "1"))
		{
			ExistingUserLoginValidation();
			return 0;
		}
		else if ((UserChoice == "2"))
		{
			NewUserCreationScreen();
			return 0;
		}
		else
		{
			std::cout << "Opção inválida. Tente novamente." << std::endl;
		}
	} while (true);

		
	return 0;
}

void TerminalSystem::ExistingUserLoginValidation()
{
	do
	{
		std::cout << "Digite seu usuário: ";
		std::cin >> ExistingUserLoginChecker;
		std::cout << "Digite sua senha: ";
		std::cin >> ExistingUserPasswordChecker;
		
		if ((ExistingUserLogin == ExistingUserLoginChecker) && (ExistingUserPassword == ExistingUserPasswordChecker))
		{
			std::cout << "Logado com sucesso." << std::endl;
			TerminalInfoScreen();
			break;
		}
		else if ((ExistingUserLogin != ExistingUserLoginChecker) && (ExistingUserPassword != ExistingUserPasswordChecker))
		{
			MaxLoginTries -= 1;
			if (MaxLoginTries == 0)
			{
				std::cout << "Número máximo de tentaivas alcançadas. Usuário bloqueado." << std::endl;
				break;
			}
			std::cout << "Usuário ou senha incorretos. Você possui " << MaxLoginTries << " Tentativas restantes." << std::endl;
		}

	} while (true);

}

void TerminalSystem::NewUserCreationScreen()
{
	std::cout << std::endl << "Bem vindo a criação de usuário." << std::endl << std::endl;
	std::cout << "Digite o nome de usuário: ";
	std::cin >> NewUserLogin;
	std::cout << "Digite a senha: ";
	std::cin >> NewUserPassword;
	std::cout << "Usuário criado com sucesso. Para confirmar a criação e acessar o terminal, utilize seu novo usuário para fazer login." << std::endl << std::endl;
	do
	{
		std::cout << "Insira seu novo usuário: ";
		std::cin >> NewUserLoginChecker;
		std::cout << "Insira sua senha: ";
		std::cin >> NewUserPasswordChecker;
		if ((NewUserLogin == NewUserLoginChecker) && (NewUserPassword == NewUserPasswordChecker))
		{
			std::cout << std::endl << "Usuário confirmado com sucesso, acessando terminal." << std::endl;
			TerminalInfoScreen();
			break;
		}
		else
		{
			std::cout << "Informações incorretas, tente novamente." << std::endl;
		}

	} while (true);
}

void TerminalSystem::TerminalInfoScreen()
{
	std::cout << "test \n";
}


