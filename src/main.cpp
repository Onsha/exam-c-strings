#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <locale>
#include <string.h>

using namespace std;

bool is_not_alphanum(char c)
{
    locale utf8("en_US.UTF_8");
    
    if (!isalnum(c, utf8)) {
        return false;
    }
    
    return true;
}

int main()
{
    string filepath, word;
    char path[1024];
    fstream file;
    vector<string> words;
    
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
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word.erase(remove_if(word.begin(), word.end(), is_not_alphanum), word.end());
        words.push_back(word);
    }
    
    sort(words.begin(), words.end());
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));
    
    file.close();
    
    return 1;
}
