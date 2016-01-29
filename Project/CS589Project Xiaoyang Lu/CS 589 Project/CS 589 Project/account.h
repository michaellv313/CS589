

#pragma once
#include <string>
using namespace std;

class account
{
public:

	// ================================
	// Original Account Member
	// ================================
		
	account();
	int open(int, int, int);
	int deposit (int) ;
	int withdraw (int);
	int balance();
	int lock(int);
	int unlock(int);
	int login(int);
	int logout();
	int pin(int);
	int show_balance(){ return x1; };//testing oriented method

private:

	// ================================
	// Original Account Member
	// ================================

	int x1;                // balance
	int x2;                // is locked
	int x3;                // pin #
	int x4;                // state
	int x5;                // account #
	int x6;                // penalty
	int x7;                // minimum balance
	int k;
	int num;        //maximum # of attempts with incorrect pin

public:

	// ================================
	// Testing Methods
	// ================================

	int test_get_x1() { return x1; }	// show_balance
	int test_get_x2() { return x2; }	// isLocked
	int test_get_x3() { return x3; }	// show_pin
	int test_get_x4() { return x4; }	// show_state
	int test_get_x5() { return x5; }	// show_account
	int test_get_x6() { return x6; }	// show_penalty
	int test_get_x7() { return x7; }	// show_minimumBalance
	int test_get_k() { return k; }		
	int test_get_num() { return num; }	// show_maximumAttempts

	void test_set_x1(const int &x1) { this->x1 = x1; }
	void test_set_x2(const int &x2) { this->x2 = x2; }
	void test_set_x3(const int &x3) { this->x3 = x3; }
	void test_set_x4(const int &x4) { this->x4 = x4; }
	void test_set_x5(const int &x5) { this->x5 = x5; }
	void test_set_x6(const int &x6) { this->x6 = x6; }
	void test_set_x7(const int &x7) { this->x7 = x7; }
	void test_set_k(const int &k) { this->k = k; }
	void test_set_num(const int &num) { this->num = num; }

	string test_show_state() {
		switch (x4) 
		{
		case -1:
			return "START";
		case 0:
			return "IDLE";
		case 1:
			return "CHECK PIN";
		case 2:
			if (0 == x2 && x1 < x7) { return "OVERDRAWN"; }
			if (0 == x2 && x1 >= x7) { return "READY"; }
			if (1 == x2) { return "LOCKED"; }
		}
		return "UNKNOWN";
	}
};