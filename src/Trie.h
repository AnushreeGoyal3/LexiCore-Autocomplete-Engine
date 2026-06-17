#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode();
};

class Trie {
private:
    TrieNode* root;

    void dfs(TrieNode* node,
             string current,
             vector<string>& result);

public:
    Trie();

    void insert(string word);

    bool search(string word);

    bool startsWith(string prefix);

    vector<string> autocomplete(string prefix);
};

#endif