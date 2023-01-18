#include <iostream> 
#include <stdlib.h> 
using namespace std;

// function prototypes 
void printIntroMenu(); 
void printMainMenu(); 
void start(); 
void login(); 
void createAccount(); 
void handleMainMenuSelection();
void deposit(); 
void withdraw(); 
void requestBalance(); 

// global variable (use this variable to store the user’s menu selection) 
char menuInput; 
string storedUserId,storedPassword;
double balance;

// the main function 
int main() 
{ 
// TO WRITE A WELCOME MESSAGE HERE 
cout<<"Hi! Welcome to Mr. Zamar’s ATM Machine! "<<endl;

// call the function start 
    start(); 
    return 0; 
} 

void handleMainMenuSelection()
{   
    
    cin >> menuInput;
    cout<<endl;
    switch(menuInput)
    {
        case 'd':
            deposit();
            break;
        case 'w':
            withdraw();
            break;
        case 'r':
            requestBalance();
            break;
        case 'q':
            cout<<endl;
            cout << "Thanks for stopping by!" << endl;
            exit(0);
        default:
            cout<<endl;
            cout << "Invalid input. Please try again." << endl;
            printMainMenu();
            handleMainMenuSelection();
    }
}
void deposit()
{
    double amount;
    cout << "Amount of deposit: $";
    cin >> amount;
    balance += amount;
    cout<<"\n"<< "Deposit successful. Your new balance is $" << balance << endl;
    printMainMenu();
    handleMainMenuSelection();
}
void withdraw()
{
    double amount;
    cout << "Amount of withdrawal: $";
    cin >> amount;
    if (amount > balance) {
        cout<<"\n" << "Insufficient funds. Please try again." << endl;
    } else {
        balance -= amount;
        cout<<"\n" << "Withdrawal successful. Your new balance is $" << balance << endl;
    }
    printMainMenu();
    handleMainMenuSelection();
}
void requestBalance()
{
    cout<<"\n" << "Your balance is $" << balance << endl;
    printMainMenu();
    handleMainMenuSelection();
}
void printIntroMenu() 
{ 
// WRITE CODE HERE 
    cout<<endl;
    cout << "Please select an option from the menu below: " << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";


} 
void printMainMenu() 
{ 
// WRITE CODE HERE 
    cout<<endl;
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
   

} 
void start() 
{ 
// EXPLANATION OF CODE THAT GOES HERE IS BELOW 
    // cout << "Please select an option from the menu below: " << endl;
    printIntroMenu();
    cin >> menuInput;

    switch(menuInput)
    {
        case 'l':
            login();
            break;
        case 'c':
            createAccount();
            break;
        case 'q':
            exit(0);
        default:
            cout << "Invalid input. Please try again." << endl;
            start();
    }
} 
void createAccount() 
{ 
// PHASE 2 
    cout<<endl;
    string userId, password;
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    // Store the userId and password in the data structure where you are
    // keeping track of all the accounts
    storedUserId = userId;
    storedPassword = password;
    cout<<endl;
    cout << "Thank You! Your account has been created!" << endl;
    start();
} 
void login()
{ 
// PHASE 2 
    cout<<endl;
    string userId, password;
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    // Compare the userId and password entered by the user with the
    // stored account information. If they match, grant access.
    // If they do not match, display an error message and return to the intro menu.
    // You will need to store account information in a data structure such as an array
    // or a map in order to do this comparison.
    if (userId == storedUserId && password == storedPassword) {
        cout<<endl;
        cout << "Access granted!" << endl;
        printMainMenu();
        handleMainMenuSelection();
        // you can use a similar switch statement as in the start() function
        // to handle the user's main menu selection
    } else {
        cout<<endl;
        cout << "******** LOGIN FAILED! ******** " << endl;
        start();
    }



} 
