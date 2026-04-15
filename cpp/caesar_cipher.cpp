#include <iostream>
#include <string>
using namespace std;

// Function to shift a single character by the given key
char shiftChar(char c, int key) {
    // For lowercase letters (a-z)
    if (c >= 'a' && c <= 'z') {
        return 'a' + (c - 'a' + key) % 26;
    }
    // For uppercase letters (A-Z)
    else if (c >= 'A' && c <= 'Z') {
        return 'A' + (c - 'A' + key) % 26;
    }
    // Leave all other characters (numbers, symbols, spaces, etc.) unchanged
    return c;
}

// Function to encrypt or decrypt the entire string
string caesarCipher(string text, int key, bool decrypt = false) {
    string result = "";
    
    // For decryption, we use negative key (reverse shift)
    if (decrypt) {
        key = -key;
    }
    
    // Shift each character one by one
   for (int i = 0; i < text.length(); i++) {
    	result += shiftChar(text[i], key);
	}
    
    return result;
}

int main() {
    string message;
    int key;
    char choice;
    
    cout << "=== Caesar Cipher Program ===\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    cin.ignore();  // Clear the input buffer
    
    cout << "Enter the message: ";
    getline(cin, message);
    
    cout << "Enter the key (shift number 1-25): ";
    cin >> key;
    
    // Make sure key is within 0-25 range
    key = key % 26;
    if (key < 0) key += 26;
    
    string output;
    
    if (choice == '1') {
        output = caesarCipher(message, key, false);
        cout << "\nEncrypted Message:\n" << output << endl;
    }
    else if (choice == '2') {
        output = caesarCipher(message, key, true);
        cout << "\nDecrypted Message:\n" << output << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

