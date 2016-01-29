#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <conio.h>
#include "account.h"
using namespace std;



account *accObj;


int * readInt() {
	string buffer;
	cin.clear(); cin.sync();
	cin >> buffer;
	cin.clear(); cin.sync();

	int *r = new int;
	if (sscanf(buffer.c_str(), "%d", r) ==1) {
		return r;
	}
	return nullptr;
}

int readKey() {
	return _getch();
}

void resetAccObj() {
	delete accObj;
	accObj = new account();
	accObj->test_set_x1(0);
	accObj->test_set_x3(0);
	accObj->test_set_x5(0);
}

// ======================================
// Interface
// ======================================

void outputTitle() {
	cout 
		<< "        ----------------------------------------------------------" << endl 
		<< "        *                     CS 589 Project                     *" << endl 
		<< "        *                        Writen by                       *" << endl 
		<< "        *                       Xiaoyang Lu                      *" << endl 
		<< "        ----------------------------------------------------------" << endl << endl;
}

void showAccountStatus() {
	cout << "       account object state by calling all test methods" << endl << endl
		<< setw(20) << "Balance: " << setw(6) << accObj->test_get_x1() << endl
		<< setw(20) << "Locked: " << setw(6) << accObj->test_get_x2() << endl
		<< setw(20) << "Pin: " << setw(6) << accObj->test_get_x3() << endl
		<< setw(20) << "EFSM State: " << setw(6) << accObj->test_get_x4() << endl
		<< setw(20) << "Account: " << setw(6) << accObj->test_get_x5() << endl
		<< setw(20) << "Penalty: " << setw(6) << accObj->test_get_x6() << endl
		<< setw(20) << "Minimum Balance:: " << setw(6) << accObj->test_get_x7() << endl
		<< setw(20) << "Attempt Times: " << setw(6) << accObj->test_get_k() << endl
		<< setw(20) << "Maximum Attempts: " << setw(6) << accObj->test_get_num() << endl 
		<< setw(20) << "Current State: " << setw(6) << accObj->test_show_state() << endl << endl;
}

int uiFunc_open() {
	// Show all menu elements
	system("cls");
	outputTitle();
	showAccountStatus();

	// Guide
	cout << " ** Execute account::open() ** " << endl
		<< " Please input the following value:" << endl
	
	// Initial balance.
		<< " -- Initial balance: ";
	int *initialBalance = nullptr;
	while (nullptr == (initialBalance = readInt())) { 
		cout << "    Invalid integer! Please re-input Initial balance: ";
	}

	// Pin number.
	cout << " -- Pin number: ";
	int *pinNumber = nullptr;
	while (nullptr == (pinNumber = readInt())) {
		cout << "    Invalid integer! Please re-input Pin number: ";
	}

	// Account Number.
	cout << " -- Account number: ";
	int *accNumber = nullptr;
	while (nullptr == (accNumber = readInt())) {
		cout << "    Invalid integer! Please re-input Account number: ";
	}

	int returnValue = accObj->open(*initialBalance, *pinNumber, *accNumber);
	cout << endl << "    The value returned by the method is: " 
		<< returnValue << endl << endl;
	showAccountStatus();
	cout << endl << "Press any key to continue.";
	
	return readKey();
}

int uiFunc_deposit() {
	// Show all menu elements
	system("cls");
	outputTitle();
	showAccountStatus();

	// Guide
	cout << " ** Execute account::deposit() ** " << endl
		<< " Please input the following value:" << endl
	
	// Initial balance.
		<< " -- Deposit amount: ";
	int *depositAmount = nullptr;
	while ((depositAmount = readInt())== nullptr) { 
		cout << "    Invalid integer! Please re-input Deposit amount: ";
	}

	int returnValue = accObj->deposit(*depositAmount);
	cout << endl << "    The value returned by the method is: " 
		<< returnValue << endl << endl;
	showAccountStatus();
	cout << endl << "Press any key to continue.";
	
	return readKey();
}

int uiFunc_withdraw() {
	// Show all menu elements
	system("cls");
	outputTitle();
	showAccountStatus();

	// Guide
	cout << " ** Execute account::withdraw() ** " << endl
		<< " Please input the following value:" << endl;
	
	// Initial balance.
		cout << " -- Withdraw amount: ";
	int *withdrawAmount = nullptr;
	while ((withdrawAmount = readInt()) == nullptr) { 
		cout << "    Invalid integer! Please re-input Withdraw amount: ";
	}

	int returnValue = accObj->withdraw(*withdrawAmount);
	cout << endl << "    The value returned by the method is: " 
		<< returnValue << endl << endl;
	showAccountStatus();
	cout << endl << "Press any key to continue.";
	
	return readKey();
}

int uiFunc_balance() {
	// Show all menu elements
	system("cls");
	outputTitle();
	showAccountStatus();

	// Guide
	cout << " ** Execute account::balance() ** " << endl << endl;

	int returnValue = accObj->balance();
	cout << "OUTPUT: " << returnValue << endl << endl;
	cout << endl << "    The value returned by the method is: " 
		<< returnValue << endl << endl;
	showAccountStatus();
	cout << endl << "Press any key to continue.";
	
	return readKey();
}

int uiFunc_lock() {
	// Show all menu elements
	system("cls");
	outputTitle();
	showAccountStatus();

	// Guide
	cout << " ** Execute account::lock() ** " << endl
		<< " Please input the following value:" << endl;
	
	// Initial balance.
		cout << " -- Pin number: ";
	int *pinNumber = nullptr;
	while ((pinNumber = readInt()) == nullptr) { 
		cout << "    Invalid integer! Please re-input Pin number: ";
	}

	int returnValue = accObj->lock(*pinNumber);
	cout << endl << "    The value returned by the method is: " 
		<< returnValue << endl << endl;
	showAccountStatus();
	cout << endl << "Press any key to continue.";
	
	return readKey();
}

int uiFunc_unlock() {
	// Show all menu elements
	system("cls");
	outputTitle();
	showAccountStatus();

	// Guide
	cout << " ** Execute account::unlock() ** " << endl
		<< " Please input the following value:" << endl;
	
	// Initial balance.
		cout << " -- Pin number: ";
	int *pinNumber = nullptr;
	while ((pinNumber = readInt()) == nullptr ) { 
		cout << "    Invalid integer! Please re-input Pin number: ";
	}

	int returnValue = accObj->unlock(*pinNumber);
	cout << endl << "    The value returned by the method is: " 
		<< returnValue << endl << endl;
	showAccountStatus();
	cout << endl << "Press any key to continue.";
	
	return readKey();
}

int uiFunc_login() {
	// Show all menu elements
	system("cls");
	outputTitle();
	showAccountStatus();

	// Guide
	cout << " ** Execute account::login() ** " << endl
		<< " Please input the following value:" << endl;
	
	// Initial balance.
		cout << " -- Account number: ";
	int *accNumber = nullptr;
	while ((accNumber = readInt()) == nullptr ) { 
		cout << "    Invalid integer! Please re-input Account number: ";
	}

	int returnValue = accObj->login(*accNumber);
	cout << endl << "    The value returned by the method is: " 
		<< returnValue << endl << endl;
	showAccountStatus();
	cout << endl << "Press any key to continue.";
	
	return readKey();
}

int uiFunc_pin() {
	// Show all menu elements
	system("cls");
	outputTitle();
	showAccountStatus();

	// Guide
	cout << " ** Execute account::pin() ** " << endl
		<< " Please input the following value:" << endl;
	
	// Initial balance.
		cout << " -- Pin number: ";
	int *pinNumber = nullptr;
	while ((pinNumber = readInt()) == nullptr) { 
		cout << "    Invalid integer! Please re-input Pin number: ";
	}

	int returnValue = accObj->pin(*pinNumber);
	cout << endl << "    The value returned by the method is: " 
		<< returnValue << endl << endl;
	showAccountStatus();
	cout << endl << "Press any key to continue.";
	
	return readKey();
}

int uiFunc_logout() {
	// Show all menu elements
	system("cls");
	outputTitle();
	showAccountStatus();

	// Guide
	cout << " ** Execute account::logout() ** " << endl << endl;

	int returnValue = accObj->logout();
	cout << endl << "    The value returned by the method is: " 
		<< returnValue << endl << endl;
	showAccountStatus();
	cout << endl << "Press any key to continue.";
	
	return readKey();
}



bool uiMainMenu() {
	// Show all menu elements
	system("cls");
	outputTitle();
	showAccountStatus();
	
	cout 
		<< "       DRIVER for the account" << endl << endl 
		<< "    0. open" << endl 
		<< "    1. deposit" << endl 
		<< "    2. withdraw" << endl 
		<< "    3. balance" << endl 
		<< "    4. lock" << endl 
		<< "    5. unlock" << endl 
		<< "    6. login" << endl 
		<< "    7. pin" << endl 
		<< "    8. logout" << endl << endl 
		<< "       Testing-related functions" << endl << endl
		<< "    a. reset account object" << endl;

	

	cout << endl << "    q. quit" << endl << endl << ">>>";

	// Make choice
	switch (readKey()) {
	case '0':
		uiFunc_open();
		break;
	case '1':
		uiFunc_deposit();
		break;
	case '2':
		uiFunc_withdraw();
		break;
	case '3':
		uiFunc_balance();
		break;
	case '4':
		uiFunc_lock();
		break;
	case '5':
		uiFunc_unlock();
		break;
	case '6':
		uiFunc_login();
		break;
	case '7':
		uiFunc_pin();
		break;
	case '8':
		uiFunc_logout();
		break;

	case 'a':		// Reset account object
		resetAccObj();
		break;
	
	case 'q':
		return false;
		break;
	}

	return true;
}

// ======================================
// Program Entrance
// ======================================

int main(int argc, char *argv[]) {
	accObj = new account();
	accObj->test_set_x1(0);
	accObj->test_set_x3(0);
	accObj->test_set_x5(0);

	
		while (uiMainMenu()) { }
	

	return 0;
}