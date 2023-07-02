/*               
    TITLE  ======>>>

                    Security System Project in C++

    CODER  ======>>>

                     MOHIT SAINI


    So, Let's get stared.........                                                                                                                              */


#include<iostream>
#include<fstream> 
#include<sstream> 
#include<string>  

using namespace std;

int main() {
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout<<endl; cout<<endl; cout<<endl; cout<<endl; cout<<endl;
    cout<<"___________________________________________________________________________________"<<endl; cout<<endl; cout<<endl; cout<<endl;
    cout << "      Security System    " << endl;


    // Display the menu and prompt for user input

    cout << "__________________________________" << endl;
    cout << "|          1.Register            |" << endl;
    cout << "|          2.Login               |" << endl;
    cout << "|          3.Change Password     |" << endl;
    cout << "|__________4.End Program_________|" << endl;

    do {
        cout << endl << endl;
        cout << "Enter your choice: ";
        cin >> a;
        switch (a) {
            case 1: {
                // User Registration
                cout << "____________________________" << endl << endl;
                cout << "|---------Register----------|" << endl;
                cout << "|___________________________|" << endl << endl;
                cout << "Please enter username: ";
                cin >> name;
                cout << "Please enter the password: ";
                cin >> password0;
                cout << "Please enter your age: ";
                cin >> age;

                // Store user registration information in a file                
                ofstream of1;
                of1.open("file.txt");
                if (of1.is_open()) {
                    of1 << name << "\n";
                    of1 << password0;
                    cout << "Registration Completed" << endl;
                }
                of1.close();
                break;
            }

            // User Login
            case 2: {
                i = 0;
                cout << "__________________________" << endl << endl;
                cout << "|-------Login-------------|" << endl;
                cout << "|_________________________|" << endl << endl;

                ifstream of2;
                of2.open("file.txt");
                cout << "Please enter the username: ";
                cin >> user;
                cout << "Please enter the password: ";
                cin >> pass;

                if (of2.is_open()) {
                    while (!of2.eof()) {
                        while (getline(of2, text)) {
                            istringstream iss(text);
                            iss >> word;
                            creds[i] = word;
                            i++;
                        }

                        // Successful login
                        if (user == creds[0] && pass == creds[1]) {
                            cout << "-----Congratulation: Log in successfully completed-----" << endl << endl;

                            cout << "Details: " << endl;
                            cout << "Username: " + name << endl;
                            cout << "Password: " + pass << endl;
                            cout << "Age: " + age << endl;
                        } else {
                            // Incorrect credentials
                            cout << endl << endl;
                            cout << "Incorrect credentials" << endl;
                            cout << "|     1. Press 2 to Login                |" << endl;
                            cout << "|     2. Press 3 to change password      |" << endl;
                            break;
                        }
                    }
                }
                of2.close();
                break;
            }

            case 3: {
                // Change Password
                i = 0;
                cout << "------------Change Password-------------------" << endl;

                ifstream of0;
                of0.open("file.txt");
                cout << "Enter the old password: ";
                cin >> old;

                if (of0.is_open()) {
                    while (getline(of0, text)) {
                        istringstream iss(text);
                        iss >> word1;
                        cp[i] = word1;
                        i++;
                    }

                    if (old == cp[1]) {
                        // Old password matches, prompt for new password
                        of0.close();
                        ofstream of1("file.txt");
                        if (of1.is_open()) {
                            cout << "Enter your new password: ";
                            cin >> password1;
                            cout << "Enter your password again: ";
                            cin >> password2;

                            if (password1 == password2) {
                                // Update the password in the file
                                of1 << cp[0] << "\n";
                                of1 << password1;
                                cout << "Password changed successfully" << endl;
                            } else {
                                // New passwords do not match
                                of1 << cp[0] << "\n";
                                of1 << old;
                                cout << "Password does not match" << endl;
                            }
                        }
                        of1.close();
                    } else {
                        // Invalid old password
                        cout << "Please enter a valid password" << endl;
                    }
                }
                of0.close();
                break;
            }

            case 4: {
                // End the program
                cout << "-----------Thank you!------------" << endl;
                break;
            }

            default: {
                // Invalid choice
                cout << "Please enter a valid choice among 1, 2, 3, 4" << endl;
                break;
            }
        }
    } while (a != 4);


    cout<<endl; cout<<endl; cout<<endl; cout<<endl; cout<<endl; cout<<endl;
    cout<<"___________________________________________________________________________________"<<endl;
    return 0;
}
