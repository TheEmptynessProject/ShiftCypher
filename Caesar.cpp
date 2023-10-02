#include <iostream>
#include <string>
using namespace std;

string encrypt(const string& text, int shift) {
    string encrypted = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encrypted += static_cast<char>((c - base + shift) % 26 + base);
        }
        else {
            encrypted += c;
        }
    }
    return encrypted;
}

string decrypt(const string& encrypted, int shift) {
    return encrypt(encrypted, 26 - shift);
}

void bruteForceDecrypt(const string& encrypted, int length, int mode) {
    for (int i = 0; i < 26; ++i) {
        string decrypted = decrypt(encrypted, i);
        cout << "Shift " << i << ": " << decrypted << endl;

        if (mode == 0) {
            string valid;
            cout << "Is the decrypted message valid? (yes/no): ";
            cin >> valid;

            if (valid == "yes") {
                cout << "Shift " << i << " is valid: " << decrypted << endl;
                return;
            }
        }
    }
}

int main() {
    int mode;
    cout << "Choose a mode (0 - Validate on Each Print, 1 - Validate at the End): ";
    cin >> mode;

    if (mode != 0 && mode != 1) {
        cout << "Invalid mode selection. Exiting." << endl;
        return 1;
    }

    int length;
    cout << "Enter the length of the text: ";
    cin >> length;

    string text;
    cin.ignore();
    cout << "Enter the text: ";
    getline(cin, text);

    string encryptedText = encrypt(text, length);
    cout << "Encrypted message: " << encryptedText << endl;

    //string decryptedText = decrypt(encryptedText, length);
    //cout << "Decrypted message: " << decryptedText << endl;

    bruteForceDecrypt(encryptedText, length, mode);

    return 0;
}
