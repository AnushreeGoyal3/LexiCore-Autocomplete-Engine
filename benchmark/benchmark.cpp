#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>

#include "../src/Trie.h"

using namespace std;
using namespace chrono;

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

    vector<string> dictionary;

    ifstream file("../data/words.txt");

    string word;

    while(file >> word) {

        word = toLowerCase(word);

        trie.insert(word);

        dictionary.push_back(word);
    }

    file.close();

    string prefix = "pro";

    auto startTrie =
        high_resolution_clock::now();

    trie.autocomplete(prefix);

    auto endTrie =
        high_resolution_clock::now();

    auto trieTime =
        duration_cast<microseconds>(
            endTrie-startTrie
        );

    auto startLinear =
        high_resolution_clock::now();

    vector<string> results;

    for(auto &w : dictionary) {

        if(w.substr(0,prefix.size()) == prefix)
            results.push_back(w);
    }

    auto endLinear =
        high_resolution_clock::now();

    auto linearTime =
        duration_cast<microseconds>(
            endLinear-startLinear
        );

    cout<<"Trie Time: "
        <<trieTime.count()
        <<" us\n";

    cout<<"Linear Scan Time: "
        <<linearTime.count()
        <<" us\n";

    return 0;
}