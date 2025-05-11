#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool usernameExists(const string& username) {
    ifstream file("users.txt");
    string fileUsername, filePassword;

    while (file >> fileUsername >> filePassword) {
        if (fileUsername == username) {
            return true;
        }
    }
    return false;
}

void registerUser() {
    string username, password;

    cout << "Register New User\n";
    cout << "Enter username: ";
    cin >> username;
    if (usernameExists(username)) {
        cout << "Username already exists. Please try another one.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}
void loginUser() {
    string username, password;

    cout << "Login\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string fileUsername, filePassword;
    
    while (file >> fileUsername >> filePassword) {
        if (fileUsername == username && filePassword == password) {
            cout << "Login successful!\n";
            return;
        }
    }

    cout << "Invalid username or password.\n";
}

int main() {
    int choice;

    while (true) {
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }

    return 0;
}
