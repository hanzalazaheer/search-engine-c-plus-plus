

#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <vector>
#include <iomanip>
using namespace std;

void login();
void registr();
void forgot();
void menu();
void search_engine_page();
void search();
void add_keywords();
void check_keywords();
void Edit_keyword();
void project_page();

char ch;
int i;
int count = 0;

int main()
{
        if (count == 1)
        {
                search_engine_page();
        }
        else
        {
                project_page();
                menu();
        }
        return 0;
}

void project_page()
{
        cout << "                 ____________________________________________________________________________________________________\n";
        cout << "                 |                                                                                                  |\n";
        cout << "                 |                                 Project:      SEARCH ENGINE                                      |\n";
        cout << "                 |                                                                                                  |\n";
        cout << "                 |                                 Submitted to: Mr. Naveed Abbas                                   |\n";
        cout << "                 |                                                                                                  |\n";
        cout << "                 |                                        submitted by                                              |\n";
        cout << "                 |                                                                                                  |\n";
        cout << "                 |                                 Name:         M Hanzala Zaheer                                   |\n";
        cout << "                 |                                 Roll no:      22014198-060                                       |\n";
        cout << "                 |                                                                                                  |\n";
        cout << "                 |                                 Name:         Gul e Raana                                        |\n";
        cout << "                 |                                 Roll no:      22014198-049                                       |\n";
        cout << "                 |                                                                                                  |\n";
        cout << "                 |                                 Name:         Iqra Aslam                                         |\n";
        cout << "                 |                                 Roll no:      22014198-044                                       |\n";
        cout << "                 |                                                                                                  |\n";
        cout << "                 |__________________________________________________________________________________________________|\n";

        cout << "\n\n\n                 ";
        system("pause");
}
void Edit_keyword()
{
        // Declare variables
        string keyword;
        string line;
        string new_keyword;
        vector<string> keywords_vec;
        bool keyword_exists;
        int index = 0;

        // Open the file in read mode
        ifstream file("keywords.txt");

        // read each line and store it in a vector

        while (getline(file, line))
        {
                keywords_vec.push_back(line);
        }

        // Close the file
        file.close();

        // Get the keyword to edit
        cout << "Enter the keyword you want to edit: ";
        getline(cin, keyword);
        ifstream readf("keywords.txt");

        while (getline(readf, line))
        {
                // Check if the keyword is equal to the line
                if (keyword == line)
                {
                        keyword_exists = true;
                        break;
                }
        }
        readf.close();
        if (keyword_exists == false)
        {
                cout << keyword << " keyword does not exist in database\n";
                system("pause");
                search_engine_page();
        }

        // Find the index of the keyword in the vector
        for (int i = 0; i < keywords_vec.size(); i++)
        {
                if (keywords_vec[i] == keyword)
                {
                        index = i;
                        break;
                }
        }
		if (keyword_exists == true){
		
        // If the keyword was found, ask the user for the new keyword
                cout << "Enter the new keyword: ";
                getline(cin, new_keyword);

                // Replace the old keyword with the new keyword
                keywords_vec[index] = new_keyword;

                // Open the file in write mode
                ofstream file("keywords.txt");

                // Write the new keywords to the file
                for (string keyword : keywords_vec)
                {
                        file << keyword << endl;
                }

                // Close the file
                file.close();
        }
        system("pause");
        search_engine_page();
}
void check_keywords()
{
        system("cls");
        cout << "List of Keywords\n\n";
        string line;
        ifstream read("keywords.txt");
        while (getline(read, line))
        {
                cout << line << endl;
        }
        cout << "\n";
        system("pause");
        search_engine_page();
}
void add_keywords()
{
        // Declare variables
        string keyword;
        string line;
        int num_keywords;

        cout << "How many keywords do you want to add? ";
        cin >> num_keywords;
        cin.ignore();
        // Create a file to store the keywords
        ofstream file("keywords.txt", ios::app);
        for (int i = 0; i < num_keywords; i++)
        {
                // Get input from the user
                cout << "Enter keyword no " << i + 1 << " : ";
                getline(cin, keyword);
                // Write the keyword to the file in the next line
                file << keyword << endl;
        }
        // Close the file
        file.close();
        system("pause");
        search_engine_page();
}

void search()
{
        // Declare variables
        string keyword;
        string line;
        fstream file;

        // Prompt the user for a keyword
        cout << "Enter a keyword: ";
        cin >> keyword;

        // Open the file in read mode
        file.open("keywords.txt", ios::in);

        // Search for the keyword in the file
        while (getline(file, line))
        {
                // If the line contains the keyword, print it
                if (line.find(keyword) != string::npos)
                {
                        cout << line << endl;
                }
        }

        // Close the file
        file.close();
        system("pause");
        search_engine_page();
}
void search_engine_page()
{
        int op;
        system("cls");

        cout << "                        ________________________________________________________________________________\n";
        cout << "                        |                                                                              |\n";
        cout << "                        |                                Search Engine                                 |\n";
        cout << "                        |______________________________________________________________________________|\n\n";
        cout << "                         ______________________________________________________________________________\n";
        cout << "                        |                                                                              |\n";
        cout << "                        |                              1. Search                                       |\n";
        cout << "                        |                              2. Add keywords or Queries                      |\n";
        cout << "                        |                              3. Keywords List                                |\n";
        cout << "                        |                              4. Edit Keywords                                |\n";
        cout << "                        |                              5. Log Out                                      |\n";
        cout << "                        |______________________________________________________________________________|\n\n";

        cout << "                         ----> Enter your choice: ";
        cin >> op;

        cin.ignore();
        switch (op)
        {
        case 1:
                // search
                system("cls");
                search();

                break;
        case 2:
                // add keywords
                system("cls");
                add_keywords();
                break;
        case 3:
                // check keywords
                system("cls");
                check_keywords();
                break;
        case 4:
                // edit keywords
                system("cls");
                Edit_keyword();
                break;
        case 5:
                // logout
                menu();
                break;
        default:
                cout << "\n                         Enter a valid option!\n"
                     << endl
                     << "                         ";
                system("pause");
                search_engine_page();
                break;
        }
}
void menu()
{
        system("cls");
        int choice;
        cout << "                        ________________________________________________________________________________\n";
        cout << "                        |                                                                              |\n";
        cout << "                        |                                Search Engine                                 |\n";
        cout << "                        |______________________________________________________________________________|\n\n";
        cout << "                         ______________________________________________________________________________\n";
        cout << "                        |                                                                              |\n";
        cout << "                        |                              1. LOGIN                                        |\n";
        cout << "                        |                              2. REGISTER                                     |\n";
        cout << "                        |                              3. FORGOT PASSWORD (or) USERNAME                |\n";
        cout << "                        |                              4. Exit                                         |\n";
        cout << "                        |______________________________________________________________________________|\n\n";

        cout << "                         ----> Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
                login();
                break;
        case 2:
                registr();
                break;
        case 3:
                forgot();
                break;
        case 4:

                cout << "                         Thanks for using this program.\n\n\n\n";
                break;
        default:
                cout << "                         Enter a valid option!\n"
                     << endl;
                cout << "                         ";
                system("pause");
                menu();
        }
}

void login()
{

        string user, u;
        char pass[100], p[100];
        system("cls");
        cout << "                        ________________________________________________________________________________\n";
        cout << "                        |                                                                              |\n";
        cout << "                        |                                Log in                                        |\n";
        cout << "                        |______________________________________________________________________________|\n\n";
        cout << "\n                             Enter Email address: ";
        cin >> user;
        cout << endl
             << "                             Enter Password:      ";
        ch = '\0';
        i = 0;
        while ((ch = _getch()) != '\r')
        {
                if (ch == '\b' && i > 0)
                {
                        cout << "\b \b";
                        i--;
                }
                else
                {
                        pass[i++] = ch;
                        cout << '*';
                }
        }
        cout << endl;
        pass[i] = '\0';
        ifstream input("database.txt");
        while (input >> u >> p)
        {
                if (u == user && strcmp(p, pass) == 0)

                {
                        count = 1;
                        system("cls");
                }
        }
        input.close();
        if (count == 1)
        {
                cout << "                        ________________________________________________________________________________\n";
                cout << "                        |                                                                              |\n";
                cout << "                        |                                DASHBOARD                                     |\n";
                cout << "                        |______________________________________________________________________________|\n\n";
                cout << "\n                           Hello! " << user << "\n\n                           [LOGIN SUCCESSFUL]\n                           Thanks for logging in..\n\n\n                           ";

                system("pause");
                main();
        }
        else
        {
                cout << "\n                         LOGIN ERROR\n                         Please check your username and password\n\n\n                         ";
                system("pause");
                menu();
        }
}

void registr()
{

        string reguser;
        char regpass[100], cp[100];
        system("cls");
up:
        cout << "                        ________________________________________________________________________________\n";
        cout << "                        |                                                                              |\n";
        cout << "                        |                                Sign Up                                       |\n";
        cout << "                        |______________________________________________________________________________|\n\n";
        cout << "\n                             Enter Email address:    ";
        cin >> reguser;
        cout << endl
             << "                             Enter Password:         ";
        ch = '\0';
        i = 0;
        while ((ch = _getch()) != '\r')
        {
                if (ch == '\b' && i > 0)
                {
                        cout << "\b \b";
                        i--;
                }
                else
                {
                        regpass[i++] = ch;
                        cout << '*';
                }
        }
        regpass[i] = '\0';
        cout << endl
             << "                             Enter Confirm Password: ";
        ch = '\0';
        i = 0;
        while ((ch = _getch()) != '\r')
        {
                if (ch == '\b' && i > 0)
                {
                        cout << "\b \b";
                        i--;
                }
                else
                {
                        cp[i++] = ch;
                        cout << '*';
                }
        }
        cp[i] = '\0';
        cout << endl;
        if (strcmp(regpass, cp) == 0) // 0 mtlb true
        {
                ofstream reg("database.txt", ios::app);
                reg << reguser << ' ' << regpass << endl;
                system("cls");
                cout << "                        ________________________________________________________________________________\n";
                cout << "                        |                                                                              |\n";
                cout << "                        |                                Sign Up                                       |\n";
                cout << "                        |______________________________________________________________________________|\n\n";
                cout << "\n                               Registration Sucessful\n\n\n                               ";
                system("pause");
                menu();
        }
        else
        {
                cout << "\n                             Sign Up failed! Invalid passwords, Try again\n\n                             ";
                system("pause");
                system("cls");
                goto up;
        }
}

void forgot()
{
        system("cls");
        cout << "                        ________________________________________________________________________________\n";
        cout << "                        |                                                                              |\n";
        cout << "                        |                                Help Center                                   |\n";
        cout << "                        |______________________________________________________________________________|\n\n";
        cout << "\n                           Forgotten ? We're here for help\n";
        cout << "                           Mail us: 22014198-060@uog.edu.pk" << endl
             << endl
             << endl
             << "                           ";
        system("pause");
        menu();
}
