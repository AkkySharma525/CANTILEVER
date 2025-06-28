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
  Step 8: Delete Account
  Step 9: Delete My Posts
  Step 10: Remove Friend

  Author: Akshit Sharma
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>  // For remove()

using namespace std;

// Create a new user profile
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

// Post a message to posts_<username>.txt
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

// Delete a user account from users.txt and remove their files
void deleteAccount() {
    string username, line;
    cout << "\n--- Delete Account ---\n";
    cout << "Enter your username: ";
    cin >> username;

    ifstream inFile("users.txt");
    ofstream tempFile("temp.txt");
    bool found = false;

    while (getline(inFile, line)) {
        if (line.find(username + ",") != 0) {
            tempFile << line << "\n";
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();
    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (found) {
        remove(("friends_" + username + ".txt").c_str());
        remove(("posts_" + username + ".txt").c_str());
        cout << "✅ Account deleted successfully along with posts and friends.\n";
    } else {
        cout << "❌ Account not found.\n";
    }
}

// View all saved profiles from users.txt
void viewAllProfiles() {
    ifstream inFile("users.txt");
    string line;
    int count = 0;

    cout << "\n--- All User Profiles ---\n";

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

        cout << "\n👤 Username : " << u;
        cout << "\n📛 Name     : " << n;
        cout << "\n🎂 Age      : " << a;
        cout << "\n📝 Bio      : " << b;
        cout << "\n--------------------------\n";
        count++;
    }

    if (count == 0) {
        cout << "❌ No profiles found.\n";
    }
}


// Delete all posts of a user
void deletePosts() {
    string username;
    cout << "\n--- Delete My Posts ---\n";
    cout << "Enter your username: ";
    cin >> username;

    if (remove(("posts_" + username + ".txt").c_str()) == 0) {
        cout << "✅ All posts deleted successfully.\n";
    } else {
        cout << "❌ No posts found to delete.\n";
    }
}

// Remove a specific friend from friend list
void removeFriend() {
    string username, friendToRemove, line;
    cout << "\n--- Remove Friend ---\n";
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter the friend's username to remove: ";
    cin >> friendToRemove;

    ifstream inFile("friends_" + username + ".txt");
    ofstream tempFile("temp.txt");
    bool found = false;

    while (getline(inFile, line)) {
        if (line != friendToRemove) {
            tempFile << line << "\n";
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();
    remove(("friends_" + username + ".txt").c_str());
    rename("temp.txt", ("friends_" + username + ".txt").c_str());

    if (found) {
        cout << "✅ Friend removed successfully.\n";
    } else {
        cout << "❌ Friend not found in your list.\n";
    }
}

// Show the main menu
void showMenu() {
    cout << "\n==============================\n";
    cout << "  SIMPLE SOCIAL NETWORK (C++) \n";
    cout << "==============================\n";
    cout << "1. Create Profile\n";
    cout << "2. View Profile\n";
    cout << "3. Add Friend\n";
    cout << "4. View Friend List\n";
    cout << "5. Post a Message\n";
    cout << "6. View My Posts\n";
    cout << "7. Delete Account\n";
    cout << "8. Delete My Posts\n";
    cout << "9. Remove a Friend\n";
    cout << "10. View All Profiles\n";
    cout << "11. Exit\n";
    cout << "==============================\n";
}

int main() {
    int choice;

    do {
        showMenu();
        cout << "Enter your choice (1-10): ";
        cin >> choice;

        switch (choice) {
            case 1: createProfile(); break;
            case 2: viewProfile(); break;
            case 3: addFriend(); break;
            case 4: viewFriendList(); break;
            case 5: postMessage(); break;
            case 6: viewPosts(); break;
            case 7: deleteAccount(); break;
            case 8: deletePosts(); break;
            case 9: removeFriend(); break;
            case 10: viewAllProfiles(); break;
            case 11: cout << "👋 Exiting program. Goodbye!\n"; break;
            default: cout << "❌ Invalid choice. Try again.\n";
        }

    } while (choice != 10);

    return 0;
}
