#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <string.h>

using namespace std;

bool is_not_alphanum(char c)
{
    if (!isalnum((int)c)) {
        return true;
    }
    
    return false;
}

int main()
{
    string filepath, word;
    char path[1024];
    fstream file;
    vector <string> words;
    
    cout << "Укажите путь к файлу: ";
    cin >> filepath;
    
    if (filepath.empty()) {
        cout << "Путь к файлу не указан." << endl;
        return 0;
    }
    
    strncpy(path, filepath.c_str(), sizeof(path));
    path[sizeof(path) - 1] = 0;
    
    file.open(path, fstream::in);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл: " << filepath << endl;
        return 0;
    }
    
    while (!file.eof()) {
        file >> word;
        word.erase(remove_if(word.begin(), word.end(), is_not_alphanum), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
    }
    
    for (int i = 0; i < (int)words.size(); i++) {
        cout << words.at(i) << endl;
    }
    
    file.close();
    
    return 1;
}
