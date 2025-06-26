/*
    SIMPLE SOCIAL NETWORK PROJECT - INTERNSHIP TASK
    -----------------------------------------------
    Project Type: Console-Based Application
    Language     : C++
    Technologies : File I/O, Classes, STL (vector, map), Basic Menus

    PROJECT PLAN (Step-by-Step Development)

    Step 1: Project Setup and Main Menu
    Step 2: Create User Profile
    Step 3: View Profile
    Step 4: Add Friend
    Step 5: View Friend List
    Step 6: Post a Message
    Step 7: View My Posts

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Create a new user profile and store in users.txt
void createProfile() {
    string name, username, bio;
    int age;

    cout << "\n--- Create Profile ---\n";
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Choose a username (no spaces): ";
    cin >> username;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Write a short bio: ";
    cin.ignore();
    getline(cin, bio);

    ofstream outFile("users.txt", ios::app);
    if (outFile.is_open()) {
        outFile << username << "," << name << "," << age << "," << bio << "\n";
        outFile.close();
        cout << "✅ Profile created successfully!\n";
    } else {
        cout << "❌ Error: Could not save profile.\n";
    }
}

// View profile by searching in users.txt
void viewProfile() {
    string username, line;
    cout << "\n--- View Profile ---\n";
    cout << "Enter username to search: ";
    cin >> username;

    ifstream inFile("users.txt");
    bool found = false;

    while (getline(inFile, line)) {
        string u, n, b;
        int a;
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        size_t pos3 = line.find(",", pos2 + 1);

        u = line.substr(0, pos1);
        n = line.substr(pos1 + 1, pos2 - pos1 - 1);
        a = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        b = line.substr(pos3 + 1);

        if (u == username) {
            cout << "\n👤 Username : " << u;
            cout << "\n📛 Name     : " << n;
            cout << "\n🎂 Age      : " << a;
            cout << "\n📝 Bio      : " << b << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "❌ Profile not found.\n";
    }
}

// Add a friend by saving their username
void addFriend() {
    string username, friendUsername;
    cout << "\n--- Add Friend ---\n";
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter friend's username: ";
    cin >> friendUsername;

    ofstream outFile("friends_" + username + ".txt", ios::app);
    if (outFile.is_open()) {
        outFile << friendUsername << "\n";
        outFile.close();
        cout << "✅ Friend added successfully!\n";
    } else {
        cout << "❌ Error: Could not add friend.\n";
    }
}

// View a user's friend list
void viewFriendList() {
    string username, line;
    cout << "\n--- View Friend List ---\n";
    cout << "Enter your username: ";
    cin >> username;

    ifstream inFile("friends_" + username + ".txt");
    if (!inFile) {
        cout << "❌ No friends found or user does not exist.\n";
        return;
    }

    cout << "\n👥 Friend List for " << username << ":\n";
    while (getline(inFile, line)) {
        cout << "- " << line << "\n";
    }
}

// Allow user to post a message
void postMessage() {
    string username, message;
    cout << "\n--- Post a Message ---\n";
    cout << "Enter your username: ";
    cin >> username;
    cin.ignore();
    cout << "Enter your message: ";
    getline(cin, message);

    ofstream outFile("posts_" + username + ".txt", ios::app);
    if (outFile.is_open()) {
        outFile << message << "\n";
        outFile.close();
        cout << "✅ Message posted successfully!\n";
    } else {
        cout << "❌ Error: Could not post message.\n";
    }
}

// View all posts by a user
void viewPosts() {
    string username, line;
    cout << "\n--- View My Posts ---\n";
    cout << "Enter your username: ";
    cin >> username;

    ifstream inFile("posts_" + username + ".txt");
    if (!inFile) {
        cout << "❌ No posts found or user does not exist.\n";
        return;
    }

    cout << "\n📝 Posts by " << username << ":\n";
    while (getline(inFile, line)) {
        cout << "- " << line << "\n";
    }
}

// Display main menu
void showMenu() {
    cout << "\n==============================" << endl;
    cout << "  SIMPLE SOCIAL NETWORK (C++) " << endl;
    cout << "==============================" << endl;
    cout << "1. Create Profile" << endl;
    cout << "2. View Profile" << endl;
    cout << "3. Add Friend" << endl;
    cout << "4. View Friend List" << endl;
    cout << "5. Post a Message" << endl;
    cout << "6. View My Posts" << endl;
    cout << "7. Exit" << endl;
    cout << "==============================" << endl;
}

int main() {
    int choice;

    do {
        showMenu();
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1: createProfile(); break;
            case 2: viewProfile(); break;
            case 3: addFriend(); break;
            case 4: viewFriendList(); break;
            case 5: postMessage(); break;
            case 6: viewPosts(); break;
            case 7: cout << "👋 Exiting program. Goodbye!\n"; break;
            default: cout << "❌ Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
