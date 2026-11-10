#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

unordered_map<char, string> encryptionAlphabet = {
    {'A', "是"}, {'B', "你"}, {'C', "猪"}, {'D', "深"}, {'E', "探"}, {'F', "吗"},
    {'G', "多"}, {'H', "中"}, {'I', "文"}, {'J', "字"}, {'K', "入"}, {'L', "让"},
    {'M', "们"}, {'N', "符"}, {'O', "看"}, {'P', "少"}, {'Q', "个"}, {'R', "我"},
    {'S', "猴"}, {'T', "狗"}, {'U', "英"}, {'V', "豚"}, {'W', "水"}, {'X', "蝠"}, 
    {'Y', "蝙"}, {'Z', "鹰"}
};

unordered_map<string, char> decryptionMap;

void initializeDecryptionMap() {
    for (const auto &pair : encryptionAlphabet) {
        decryptionMap[pair.second] = pair.first;
    }
}

string encryptText(const string &text) {
    string encryptedText;
    for (char c : text) {
        char upperC = toupper(c);
        if (encryptionAlphabet.find(upperC) != encryptionAlphabet.end()) {
            encryptedText += encryptionAlphabet[upperC];
        } else {
            encryptedText += upperC;
        }    
    }
    return encryptedText;
}

string decryptText(const string &text) {
    string decryptedText;
    for (size_t i = 0; i < text.size();) {
        bool found = false;
        for (auto &pair : decryptionMap) {
            string mandarinChar = pair.first;
            if (text.substr(i, mandarinChar.size()) == mandarinChar) {
                decryptedText += decryptionMap[mandarinChar];
                i += mandarinChar.size();
                found = true;
                break;
            }
        }
        if (!found) {
            decryptedText += text[i];
            i++;
        }
    }
    return decryptedText;
}

string readFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open input file: " << filename << std::endl;
        return "";
    }
    string text, line;
    while (getline(inFile, line)) {
        text += line + "\n";
    }
    inFile.close();
    return text;
}

void writeFile(const string &filename, const string &content) {
    ofstream file(filename);
    if(!file) {
        cerr<<"Error opening file:" << filename << endl;
        return;
    }
    file << content;
    file.close();
}

int main() {
    initializeDecryptionMap();

    string fileName;
    cout << "Please provide the name of the file. It should end in .txt: ";
    cin >> fileName;

    string inputText = readFromFile(fileName);
    if (inputText.empty()) {
        cerr << "Error: File not found or empty!" << endl;
        return 1;
    }

    char choice;
    cout << "Please type (E) for Encryption or (D) for Decryption: ";
    cin >> choice;

    if (toupper(choice) == 'E') {
        string encryptedText = "encrypted_" + fileName;
        writeFile(encryptedText, encryptText(inputText));
        cout << "File has been successfully encrypted. File saved as " << encryptedText << endl;
    } else if (toupper(choice) == 'D') {
        string decryptedText = "decrypted_" + fileName;
        writeFile(decryptedText, decryptText(inputText));
        cout << "File has been successfully decrypted. File saved as " << decryptedText << endl;
    } else {
        cerr << "Error: Invalid input, please type (E) or (D).";
        return 1;
    }
    return 0;
}