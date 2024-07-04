#include <iostream>
#include <string>
using namespace std;

int main(){
    while (true) {
        string option;
        string msg;
        string key;
        string edited_msg = "";
        string edited_key = "";
        string encrypted_msg = "";
        string decrypted_msg = "";
        cout << " " << endl; //this line is only to make the message appear correctly when the loop works
        //menu and welcome message
        cout << "---+----+----+----+----+---" << endl;
        cout << "Welcome To Vigenere Cipher!" << endl;
        cout << "---+----+----+----+----+---" << endl;
        cout << "Menu Options:" << endl;
        cout << "1)Cipher a message" << endl;
        cout << "2)Decipher a message" << endl;
        cout << "3)Exit" << endl;
        cout << "enter choice from 1,2,3: ";
        cin >> option;


        //##############################################################################################################
        if (option == "1") {
            cout << "enter message: " << endl;
            getline(cin, msg);
            getline(cin, msg);
            cout << "enter key: " << endl;
            getline(cin, key);
            //take only alphabet from message and turn it to upper case
            for (char i: msg) {
                if (isalpha(i)) {
                    edited_msg += toupper(i);
                }
            }
            //take only alphabet from key and turn it to upper case
            for (char l: key) {
                if (isalpha(l)) {
                    edited_key += toupper(l);
                }
            }
            for (int j = 0; j < edited_msg.length(); ++j) {
                //repeating the key until the message ends
                char corresponding_key = edited_key[j % (edited_key.length())];
                int change = corresponding_key - 'A';
                encrypted_msg += 'A' + (edited_msg[j] - 'A' + change) % 26;
            }
            cout << "encrypted message: " << encrypted_msg;


            //##########################################################################################################
        } else if (option == "2") {
            cout << "enter message: " << endl;
            getline(cin, msg);
            getline(cin, msg);
            cout << "enter key: " << endl;
            getline(cin, key);
            for (char i: msg) {
                if (isalpha(i)) {
                    edited_msg += toupper(i);
                }
            }
            for (char l: key) {
                if (isalpha(l)) {
                    edited_key += toupper(l);
                }
            }
            for (int j = 0; j < edited_msg.length(); ++j) {
                char corresponding_key = edited_key[j % (edited_key.length())];
                int change = corresponding_key - 'A';
                decrypted_msg += 'A' + (edited_msg[j] - 'A' - change + 26) % 26;
            }
            cout << "decrypted message: " << decrypted_msg;


            //##########################################################################################################
        } else if (option == "3") {
            cout << "thanks for using our program!";
            break;
        }


            //##########################################################################################################
        else {
            cout << "ERROR! enter 1 or 2 or 3 only";
        }


        //##############################################################################################################
    }
    return 0;
}
