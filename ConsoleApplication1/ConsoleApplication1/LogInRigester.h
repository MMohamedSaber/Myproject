#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "Global.h"
#include "clsDate.h"
#include "clsShowScreen.h"
#include "clsString.h" // Assuming clsString is defined elsewhere.
#include <string>
#include "clsUser.h"
using namespace std;

class LogInRigester :protected clsShowScreen
{
private:

    /*string _DateAndTime;
    string _UserName;
    string _Password;
    int _permissions;*/



//
//
//    static string _ConverUserObjectToLine()
//    {
//        string Seperator = "#//#";
//        string loginRegester = "";
//        clsDate Date;
//        loginRegester += clsDate::DateToString(clsDate()) + Seperator;
//        loginRegester += CurrentUser.UserName + Seperator;
//        loginRegester += CurrentUser.Password + Seperator;
//        loginRegester += to_string(CurrentUser.Permissions);
//
//        return loginRegester;
//    }
//
//    static LogInRigester _ConvertLinetoLogRegisterObject(string Line)
//    {
//        vector<string> vUserData;
//        vUserData = clsString::Split(Line, "#//#");
//
//        return LogInRigester(vUserData[0], vUserData[1], vUserData[2], stoi(vUserData[3]));
//
//    }
//
//    static vector<LogInRigester> _LoadUsersDataFromFile()
//    {
//        vector<LogInRigester> vUsersRegister;
//
//        fstream MyFile;
//        MyFile.open("LoginRigester.txt", ios::in);
//
//        if (MyFile.is_open())
//        {
//            string Line;
//
//            while (getline(MyFile, Line))
//            {
//                LogInRigester User = _ConvertLinetoLogRegisterObject(Line);
//                vUsersRegister.push_back(User);
//            }
//
//            MyFile.close();
//        }
//
//        return vUsersRegister; // Corrected the return statement
//    }
//    static void SaveLoginRegesterDataToFile()
//    {
//        fstream MyFile;
//        MyFile.open("LoginRigester.txt", ios::app);
//
//        string DataLine;
//
//        if (MyFile.is_open())
//        {
//            DataLine = _ConverUserObjectToLine();
//            MyFile << DataLine << endl;
//        }
//
//        MyFile.close();
//    }

    static void PrintUserRegesterRecordLine(clsUser::stLoginRegiterRecord User)
    {
        
        cout << setw(8) << left << "" << "| " << setw(25) << User.Date;
        cout << "| " << setw(25) << left << User.UserName;
        cout << "| " << setw(12) << left << User.Password;
        cout << "| " << setw(10) << left << User.Permissions;
       

    }

public:

   /* LogInRigester(const string& dateAndTime, const string& userName, const string& password, int permissions)
        : _DateAndTime(dateAndTime), _UserName(userName), _Password(password), _permissions(permissions)
    {
    }*/
   

    static void ShowLoginsRegisterScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pUsersRigisters))
        {
            return;// this will exit the function and it will not continue
        }
        vector <clsUser::stLoginRegiterRecord> vLoginsUsersRegister = clsUser::GetLoginRegisterList();
        string Title = "\t  Users Registring Screen";
        string SubTitle = "\t    (" + to_string(vLoginsUsersRegister.size()) + ") user(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date And Time ";
        cout << "| " << left << setw(25) << "User Name ";
        cout << "| " << left << setw(12) << "PassWord";
        cout << "| " << left << setw(20) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginsUsersRegister.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsUser::stLoginRegiterRecord User : vLoginsUsersRegister)
            {

                PrintUserRegesterRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
      
    };

