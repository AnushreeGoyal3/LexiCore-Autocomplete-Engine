#include <iostream>
#include <fstream>
#include <algorithm>

#include "src/Trie.h"


using namespace std;

string toLowerCase(string s) {

    transform(
        s.begin(),
        s.end(),
        s.begin(),
        ::tolower
    );

    return s;
}

int main() {

    Trie trie;

    ifstream file("data/words.txt");

    if(!file.is_open()) {

        cout<<"Dictionary file not found\n";
        return 0;
    }

    string word;

    while(file >> word) {

        word = toLowerCase(word);

        trie.insert(word);
    }

    file.close();

    cout<<"Dictionary Loaded Successfully\n";

    while(true) {

        string prefix;

        cout<<"\nEnter Prefix (or exit): ";

        cin>>prefix;

        prefix = toLowerCase(prefix);

        if(prefix=="exit")
            break;

        vector<string> suggestions =
                trie.autocomplete(prefix);

        if(suggestions.empty()) {

            cout<<"No Suggestions Found\n";
            continue;
        }

        cout<<"\nSuggestions:\n";

        int count = 0;

        for(auto &s : suggestions) {

            cout<<s<<"\n";

            count++;

            if(count==10)
                break;
        }
    }

    return 0;
}