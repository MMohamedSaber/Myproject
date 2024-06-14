#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsShowScreen.h"

using namespace std;


class clsWithdrawScreen :protected clsShowScreen
{



private:


    static  void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }


public:


    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t Withdraw Screen ");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient ClientToWithdraw = clsBankClient::Find(AccountNumber);
        _PrintClient(ClientToWithdraw);


        double Amount = 0;
        cout << "\nPlease enter WithDraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction?[ y , n] ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (ClientToWithdraw.Withdraw(Amount))
            {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << ClientToWithdraw.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << ClientToWithdraw.AccountBalance;

            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }


    }
};

