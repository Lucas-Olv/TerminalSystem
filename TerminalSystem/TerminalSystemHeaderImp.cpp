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

	std::cout << "Terminal System v0.6.0" << std::endl << std::endl;
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
	std::cout << std::endl << "Seja bem vindo ao terminal." << std::endl;
	do
	{
		std::cout << "1. Classified Info" << std::endl;
		std::cout << "2. Nasa archives" << std::endl;
		std::cout << "3. Military files" << std::endl;
		std::cout << " Selecione uma das opções acima: ";
		std::cin >> UserChoice;

		if (UserChoice == "1")
		{
			ClassifiedInfo();
			break;
		}
		else if (UserChoice == "2")
		{
			NasaArchives();
			break;
		}
		else if (UserChoice == "3")
		{
			MilitaryFiles();
			break;
		}
		else
		{
			std::cout << "Opção inválida. Tente novamente." << std::endl;
		}

	} while (true);
}

void TerminalSystem::ClassifiedInfo()
{
	bool conditionChecker = true;
	std::cout << std::endl << "Arquivos Confidenciais. Apenas pessoas autorizadas." << std::endl;

	do
	{
		std::cout << "C: 3112  C: 9421  C:2109  C:4476" << std::endl;
		std::cout << "Digite o código do arquivo desejado: ";
		std::cin >> UserFileSelection;

		switch (UserFileSelection)
		{
		case 3112:
			std::cout << std::endl << "C:3112 - Base de Pesquisa Lunar" << std::endl;
			std::cout << "A base Lunar do governo americano denominada L-343 está localizada na cordenada ¨545$332!@#*779&*8..." << std::endl;
			std::cout << "Aviso: A visualização do arquivo assim como informações técnicas foram removidas para manter sigilo. ";
			std::cout << "Somente pessoas previamente autorizadas poderão visualizar as informações contidas nesse arquivo." << std::endl;

			conditionChecker = false;
			break;

		case 9421:
			std::cout << std::endl << "C:9421 - Ártico" << std::endl;
			std::cout << "Este arquivo foi movido." << std::endl;
			conditionChecker = false;
			break;

		case 2109:
			std::cout << std::endl << "c:2109 --. --- ...- . .-. -. -- . -. - / .-. . .--. - .. .-.. .. .- -. ... / ..-. .. .-.. . ...";
			std::cout << std::endl << "Não é possível traduzir o arquivo." << std::endl;
			conditionChecker = false;
			break;

		case 4476:
			std::cout << std::endl << "C:4476 <Corrupted File>" << std::endl;
			conditionChecker = false;
			break;

		default:

			std::cout << "Opção inválida, tente novamente." << std::endl;
			break;
		}
	} while (conditionChecker == true);
}

void TerminalSystem::NasaArchives()
{
	bool conditionChecker = true;
	std::cout << std::endl << "Arquivos NASA. Apenas funcionários autorizados." << std::endl;

	do
	{
		std::cout << "N: 2319  C: 4321  C:1094  C:9706" << std::endl;
		std::cout << "Digite o código do arquivo desejado: ";
		std::cin >> UserFileSelection;

		switch (UserFileSelection)
		{
		case 2319:
			conditionChecker = false;
			break;
		case 4321:
			conditionChecker = false;
			break;
		case 1094:
			conditionChecker = false;
			break;
		case 9706:
			conditionChecker = false;
			break;

		default:
			break;
		}
	} while (conditionChecker == true);
}

void TerminalSystem::MilitaryFiles()
{

}

