#include <iostream>
#include <cstring>
using namespace std;

/*
function 1: opening account
function 2: deposit (put money)
function 3: withdrawal (take money out)
function 4: checking all customers account
*/

const int NAME_LEN=20;

void ShowMenu(void);
void MakeAccount(void);
void Deposit(void);
void Withdrawal(void);
void ShowAllAccInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAWAL, SHOW, EXIT};

typedef struct
{
  int accID;
  int balance;
  char cusName[NAME_LEN];
} Account;

Account accArr[100];
int accNum = 0;

int main(void)
{
  int choice;

  while(1)
  {
    ShowMenu();
    cout << "option: ";
    cin >> choice;
    cout << endl;

    switch(choice)
    {
      case MAKE:
        MakeAccount();
        break;

      case DEPOSIT:
        Deposit();
        break;

      case WITHDRAWAL:
        Withdrawal();
        break;

      case SHOW:
        ShowAllAccInfo();
        break;

      case EXIT:
        return 0;

      default:
        cout <<" prohibited access... "<<endl;
    }
  }
  return 0;
}


void ShowMenu(void){
  cout << "-------------M E N U-------------" << endl;
  cout << "1. Make Account"<<endl;
  cout << "2. Deposit Money"<<endl;
  cout << "3. Withdraw Money"<<endl;
  cout << "4. Show All Account Info"<<endl;
  cout << "5. Exit Program" << endl;
}

void MakeAccount(void)
{
  int id;
  char name[NAME_LEN];
  int balance;

  cout << "  [MAKE ACCOUNT]  " << endl;
  cout << " accID: ";
  cin >> id;
  cout << " Name: ";
  cin >> name;
  cout << " balance: ";
  cin >> balance;
  cout << endl;

  accArr[accNum].accID = id;
  accArr[accNum].balance = balance;
  strcpy(accArr[accNum].cusName, name);
  accNum++;
}

void Deposit(void)
{
  int money;
  int id;

  cout << "  [DEPOSIT]  " << endl;
  cout << " accID: ";
  cin >> id;
  cout << " Deposit Money: ";
  cin >> money;


  for(int i=0; i < accNum; i++)
  {
    if(accArr[i].accID == id)
    {
      accArr[i].balance += money;
      cout << " DEPOSIT COMPLETED " << endl;
      return;
    }
  }
  cout << " INVALID ID " << endl;
}

void Withdrawal(void)
{
  int money;
  int id;

  cout << "  [WITHDRAW]  " << endl;

  cout << " accID: ";
  cin >> id;
  cout << " Withdraw Money: ";
  cin >> money;

  for(int i=0; i < accNum; i++)
  {
    if(accArr[i].accID ==id){
      if(accArr[i].balance < money){
        cout << " LACK OF MONEY " << endl;
        return;
      }
      accArr[i].balance -= money;
      cout << " WITHDRAW COMPLETED " << endl;
      return;
    }
  }
  cout << " INVALID ID " << endl;
}

void ShowAllAccInfo(void)
{
  int id;
  char name;
  int balance;

   for(int i=0; i < accNum; i++){
    cout << " ID: " << accArr[i].accID << endl;
    cout << "name: " << accArr[i].cusName << endl;
    cout << "balance: " << accArr[i].balance << endl;
  }
}

