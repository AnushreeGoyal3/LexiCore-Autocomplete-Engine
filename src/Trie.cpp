#include "Trie.h"

TrieNode::TrieNode() {

    isEnd = false;

    for(int i=0;i<26;i++)
        children[i] = nullptr;
}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(string word) {

    TrieNode* curr = root;

    for(char c : word) {

        if(c<'a' || c>'z')
            continue;

        int idx = c - 'a';

        if(curr->children[idx] == nullptr)
            curr->children[idx] = new TrieNode();

        curr = curr->children[idx];
    }

    curr->isEnd = true;
}

bool Trie::search(string word) {

    TrieNode* curr = root;

    for(char c : word) {

        if(c<'a' || c>'z')
            return false;

        int idx = c - 'a';

        if(curr->children[idx] == nullptr)
            return false;

        curr = curr->children[idx];
    }

    return curr->isEnd;
}

bool Trie::startsWith(string prefix) {

    TrieNode* curr = root;

    for(char c : prefix) {

        if(c<'a' || c>'z')
            return false;

        int idx = c - 'a';

        if(curr->children[idx] == nullptr)
            return false;

        curr = curr->children[idx];
    }

    return true;
}

void Trie::dfs(
        TrieNode* node,
        string current,
        vector<string>& result) {

    if(node->isEnd)
        result.push_back(current);

    for(int i=0;i<26;i++) {

        if(node->children[i]) {

            dfs(
                node->children[i],
                current + char('a'+i),
                result
            );
        }
    }
}

vector<string> Trie::autocomplete(string prefix) {

    TrieNode* curr = root;

    for(char c : prefix) {

        int idx = c - 'a';

        if(curr->children[idx] == nullptr)
            return {};

        curr = curr->children[idx];
    }

    vector<string> result;

    dfs(curr,prefix,result);

    return result;
}