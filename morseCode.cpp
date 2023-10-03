#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, string> mapMorse = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
    {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}
};

map<string, char> rmapMorse;

string encryptToMorse(const string& thing) {
    string morseCode = "";
    for (char c : thing) {
        if (mapMorse.find(toupper(c)) != mapMorse.end()) {
            if (morseCode != "")
                morseCode += " ";
            morseCode += mapMorse[toupper(c)];
        }
    }
    return morseCode;
}

string decryptFromMorse(const string& morseCode) {
    string thing = "";
    string thinggggg;
    string idk;

    for (char c : morseCode) {
        if (c == ' ') {
            if (thinggggg != "") {
                if (idk != "") {
                    if (rmapMorse.find(idk) != rmapMorse.end()) {
                        thing += rmapMorse[idk];
                    }
                    else {
                        thing += idk;
                    }
                    idk = "";
                }
                thinggggg += " ";
                thing += thinggggg;
                thinggggg = "";
            }
            else if (idk != "") {
                if (rmapMorse.find(idk) != rmapMorse.end()) {
                    thing += rmapMorse[idk];
                }
                else {
                    thing += idk;
                }
                idk = "";
            }
        }
        else if (c == '/' || c == '|') {
            if (thinggggg != "") {
                if (idk != "") {
                    if (rmapMorse.find(idk) != rmapMorse.end()) {
                        thing += rmapMorse[idk];
                    }
                    else {
                        thing += idk;
                    }
                    idk = "";
                }
                thing += thinggggg;
                thinggggg = "";
            }
            else if (idk != "") {
                if (rmapMorse.find(idk) != rmapMorse.end()) {
                    thing += rmapMorse[idk];
                }
                else {
                    thing += idk;
                }
                idk = "";
            }
            thing += c;
        }
        else {
            idk += c;
        }
    }

    if (thinggggg != "") {
        if (idk != "") {
            if (rmapMorse.find(idk) != rmapMorse.end()) {
                thing += rmapMorse[idk];
            }
            else {
                thing += idk;
            }
        }
        thing += thinggggg;
    }
    else if (idk != "") {
        if (rmapMorse.find(idk) != rmapMorse.end()) {
            thing += rmapMorse[idk];
        }
        else {
            thing += idk;
        }
    }

    return thing;
}

int main() {
    for (const auto& pair : mapMorse) {
        rmapMorse[pair.second] = pair.first;
    }

    string message;
    cout << "Enter a message to encrypt to Morse code: ";
    getline(cin, message);

    string morseCode = encryptToMorse(message);
    string decryptedMessage = decryptFromMorse(morseCode);

    cout << "Original message: " << message << endl;
    cout << "Morse code: " << morseCode << endl;
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}
