#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <stdexcept>
#include <limits>
#include "encryption.h"

using namespace std;

void login();
void signup();
void reset();
void close();

Encryption encrypt = Encryption();

int main()
{

    bool is_valid_input = false;
    int choice = 0;

    while (!is_valid_input)
    {
        std::string answer{};

        std::string message{
            R"(--------------------------------------------------------------------
------------------------ Welcome to S7S app ------------------------
--------------------------------------------------------------------

Please choose one of the following options:
1 -> login
2 -> signup
3 -> reset password
4 -> exit
)"};

        std::cout << message;
        std::getline(std::cin, answer);

        try
        {
            choice = std::stoi(answer);

            if (choice < 1 || choice > 4)
            {
                std::cout << "Please select a valid option\n";
            }
            else
            {
                is_valid_input = true;
            }
        }
        catch (const std::invalid_argument &e)
        {
            system("cls");
            std::cout << "\"" << answer << "\""
                      << " is invalid please select a valid option catch\n";
        }
    }

    switch (choice)
    {
    case 1:
        system("cls");
        login();
        break;
    case 2:
        system("cls");
        signup();
        break;
    case 3:
        system("cls");
        reset();
        break;
    case 4:
        system("cls");
        close();
        break;
    }

    return 0;
}

void close()
{
    std::cout << "Thanks for visiting us <3\n";
}

void login()
{
    std::string message{
        R"(-----------------------------------------------------------------------
------------------------ Welcome to login page ------------------------
-----------------------------------------------------------------------
)"};

    std::string user_name, password, user_check, pass_check;

    system("cls");

    std::ifstream input("users.txt");

    if (input.is_open())
    {
        bool is_empty = (input.get(), input.eof());
        if (!is_empty)
        {
            int is_found{};

            std::cout << message;
            std::cout << "Kindly enter your username : ";
            std::getline(std::cin, user_name);
            std::cout << "password : ";
            std::getline(std::cin, password);
            password = encrypt.hash(password);

            while (input >> user_check >> pass_check)
            {
                if (user_check == user_name && pass_check == password)
                {
                    is_found = 1;
                    break;
                }
            }
            input.close();
            if (is_found)
            {
                // DONE BUG when calling main() catch is no longer triggered
                system("cls");
                std::cout << "Nice to see you back " << user_name << ", access approved!!\n";
                main();
            }
            else
            {
                // DONE BUG when calling main() catch is no longer triggered
                system("cls");
                std::cout << "Sorry user_name or password is wrong, please try again\n";
                main();
            }
        }
        else
        {
            cout << "No users registered please signup and try again\n";
            main();
        }
    }
}

void signup()
{
    int is_found{};
    std::string user_name, password, add_user_check, add_pass_check;

    std::string message{
        R"(------------------------------------------------------------------------
------------------------ Welcome to signup page ------------------------
------------------------------------------------------------------------
)"};

    std::cout << message;

    std::cout << "Note: Username should not contain spaces and password should be at least 8 characters long\n\n";

    std::cout << "Choose a username :";
    std::getline(std::cin, user_name);
    std::cout << "Choose a password :";
    std::getline(std::cin, password);

    password = encrypt.hash(password);

    std::ifstream check_user("users.txt");
    while (check_user >> add_user_check >> add_pass_check)
    {
        if (user_name == add_user_check)
        {
            is_found = 1;
            break;
        }
    }
    check_user.close();
    if (!(is_found))
    {
        std::ifstream check("users.txt");
        bool is_empty = (check.get(), check.eof());

        check.close();

        std::ofstream add("users.txt", ios::app);

        if (is_empty)
        {
            add << ' ' << user_name << ' ' << password << "\n";
        }
        else
        {
            add << user_name << ' ' << password << "\n";
        }
        add.close();

        system("cls");

        std::cout << "Welcome to our Family!\n";
        main();
    }
    else
    {
        system("cls");
        std::cout << "User already exists try another one\n";
        main();
    }
}

void reset()
{
    std::string message{
        R"(-----------------------------------------------------------------------
------------------------ Welcome to reset page ------------------------
-----------------------------------------------------------------------
)"};

    std::cout << message;
    std::cout << "Did you forget your password? No worries we are here to help\n\n";
    int is_found{};
    std::string user_name, search_user, search_password;

    std::ifstream search("users.txt");
    bool is_empty = (search.get(), search.eof());
    if (!is_empty)
    {
        std::cout << "Enter the user name you remember: ";
        std::getline(std::cin, user_name);

        while (search >> search_user >> search_password)
        {
            if (search_user == user_name)
            {
                is_found = 1;
                break;
            }
        }
        search.close();
        if (is_found)
        {
            std::cout << "User found but we don't have enough informations to recover your account, sorry about that\n";
        }
        else
        {
            system("cls");
            std::cout << "User not found\n";
            main();
        }
    }
    else
    {
        system("cls");
        cout << "No users registered please signup and try again\n";
        main();
    }
}
