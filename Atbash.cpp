#include <iostream>
#include <string>
using namespace std;
string encryptAtbash(const string& plaintext) {
    string ciphertext = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char reversed = 'z' - (c - base);
            ciphertext += reversed;
        }
        else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

string decryptAtbash(const string& ciphertext) {
    return encryptAtbash(ciphertext);
}

int main() {
    string message;
    cout << "Enter a message to encrypt: ";
    getline(cin, message);

    string encrypted = encryptAtbash(message);
    string decrypted = decryptAtbash(encrypted);

    cout << "Original message: " << message << endl;
    cout << "Encrypted message: " << encrypted << endl;
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
