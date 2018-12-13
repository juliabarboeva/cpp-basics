#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string path = "/Users/juliabarboevaicloud.com/Documents/";
    path += "cpp-basics/07-strings/07-strings/text.txt";
    ifstream fin(path);
    if (!fin) {
        cout << "File \"text.txt\" not found.";
        return 1;
    }
    
    string word;
    cout << "Write a word: ";
    cin >> word;
    cout << endl;
    
    string line;
    while (getline(fin, line)) {	
        string sentence = "";
        for (size_t i = 0; i < line.length(); i++) {
            if (sentence != "" || line[i] != ' ')
                sentence += line[i];
            
            if (line[i] == '.' || line[i] == '?' || line[i] == '!') {
                if (sentence.find(word) != string::npos)
                    cout << sentence << endl;
                sentence = "";
            }
        }
    }
    
    fin.close();
    return 0;
}
