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
  
  void Deposit(int money)
  {
    balance += money;
  }
  
  int Withdraw(int money)
  {
    if(balance<money)
      return 0;
    
    balance -= money;
    return money;
  }
  
  void ShowAccInfo()
  {
    cout << "Account ID: " << accID << endl;
    cout << "Name: " << cusName << endl;
    cout << "Balance: " << balance << endl;
  }
  
  
  ~Account()
  {
    delete []cusName;
  }
};

Account * accArr[100];
int accNum=0;

int main(void)
{
  int choice;

 while(1)
  {
    ShowMenu();
    cout << "Option: ";
    cin >> choice;
    cout << endl;

    switch(choice)
    {
      case MAKE:
        MakeAccount();
        break;
      case DEPOSIT;
        DepositMoney();
        break;
      case WITHDRAW;
        WithdrawMoney();
        break;
      case INQUIRE;
        ShowAllAccInfo();
        break;
      case EXIT:
        for(int i=0; i<accNum; i++)
          delete accArr[i];
        return 0;
      default:
        cout << "Illegal Selection...Please Go back ^^" << endl;
    }
  }
  return 0;
}

