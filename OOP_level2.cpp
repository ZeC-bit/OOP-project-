
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
  private:
    int accID;
    int balance;
    char * cusName;
  
  public:
    Account(int ID, int money, char * name)
      : accID(ID), balance(money)
    {
      cusName = new char[strlen(name)+1];
        strcpy(cusName, name);
  }
  
  int GetAccID() { return accID; }
  
  
  
