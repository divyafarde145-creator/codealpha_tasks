#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool usernameExists(string username) {
    ifstream file("users.txt");
    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username)
            return true;
    }
    return false;
}

void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << "Username already exists!\n";
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
    string storedUsername, storedPassword;
    bool found = false;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Login successful!\n";
    else
        cout << "Invalid username or password!\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Login & Registration System ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            registerUser();
        else if (choice == 2)
            loginUser();
        else if (choice == 3)
            cout << "Thank you!\n";
        else
            cout << "Invalid choice!\n";

    } while (choice != 3);

    return 0;
}
