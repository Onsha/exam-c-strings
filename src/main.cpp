#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

bool is_not_letter(char c)
{
    if (!isalpha(c)) {
        return true;
    }
    
    return false;
}

bool sort_by_length(const string& a, const string& b)
{
    return ((b.length() > a.length()) && (b[0] >= a[0]));
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
        return EXIT_FAILURE;
    }
    
    strncpy(path, filepath.c_str(), sizeof(path));
    path[sizeof(path) - 1] = 0;
    
    file.open(path, fstream::in);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл: " << filepath << endl;
        return EXIT_FAILURE;
    }
    
    while (!file.eof()) {
        file >> word;

        for (string::size_type i = 0; i < word.length(); ++i) {
            word[i] = tolower(word[i]);
        }
        
        word.erase(remove_if(word.begin(), word.end(), is_not_letter), word.end());
        words.push_back(word);
    }
    
    file.close();

    sort(words.begin(), words.end());
    sort(words.begin(), words.end(), sort_by_length);
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));
        
    return EXIT_SUCCESS;
}
