//Header files
#include<iostream>
#include<string>
using namespace std;
//Function prototype
string encrypt(string message,int key);
string decrypt(string message, int key);

// convert lower case to capital before encrypt

int main()
{
   //Variables for input store
   string msg,option;
   int key;
   //Prompt for option
   cout << "Do you wish to encrypt or decrypt a message?" << endl;;
   cin >> option;
   //error check
   while (option != "encrypt"&&option != "decrypt") {
       cout << "Error!!!Option should be encrypt/decrypt. Please Re-enter ";
       cout << "Do you wish to encrypt or decrypt a message?" << endl;;
       cin >> option;
   }
   cin.ignore();
   //Prompt for message
   cout << "Enter your message:" << endl;
   getline(cin, msg);
   //Prompt for key
   cout << "Enter the key number (1-26)" << endl;
   cin >> key;
   //Error check
   while (key < 1 || key>26) {
       cout << "Error!!!Key must be 1...26 Please Re-enter. ";
       //Prompt for key
       cout << "Enter the key number (1-26)" << endl;
       cin >> key;
   }
   //Check for encryption or decryption
   if (option == "encrypt"){
       cout << "Your translated text is: " << encrypt(msg, key) << endl;;
   }
   else {
       cout << "Your translated text is: " << decrypt(msg, key)<<endl;
   }
   return 0;
}
//Method to encrypt message
string encrypt(string message, int key) {
   //Loop to get each character of message
   for (int i = 0; message[i] != ' '; ++i) {
       //get character
       char ch = message[i];
       //Check for alphabet
       if (ch >= 'a' && ch <= 'z'){
           //Add with keys
           ch = ch + key;
           //If it not in alphabet then generate start from a
           if(!(ch >= 'a' && ch <= 'z')) {
               ch = ch - 'z' + 'a' - 1;
           }
           //Change the shifted character
           message[i] = ch;
       }
       //Capital letter checker
       else if (ch >= 'A' && ch <= 'Z') {
           ch = ch + key;

           if(!(ch >= 'A' && ch <= 'Z')) {
               ch = ch - 'Z' + 'A' - 1;
           }

           message[i] = ch;
       }
   }
   //Return encrypted message
   return message;
}
//Method to decrypt message
string decrypt(string message, int key) {
   //Loop to get each character of message
   for (int i = 0; message[i] != ' '; ++i) {
       //get character
       char ch = message[i];
       //Check for alphabet
       if (ch >= 'a' && ch <= 'z') {
           ch = ch - key;
           //If it not in alphabet then generate start from a
           if (!(ch >= 'a' && ch <= 'z')) {
               ch = ch + 'z' - 'a' + 1;
           }

           message[i] = ch;
       }
       //Capital conversion
       else if (ch >= 'A' && ch <= 'Z') {
           ch = ch - key;

           if (!(ch >= 'A' && ch <= 'Z')) {
               ch = ch + 'Z' - 'A' + 1;
           }

           message[i] = ch;
       }
   }
   //Return message
   return message;
}
