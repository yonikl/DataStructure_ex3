//
// Created by 97253 on 09/12/2022.
//

#ifndef DATASTRUCTURE_EX3_TRIE_H
#define DATASTRUCTURE_EX3_TRIE_H


// C++ program to demonstrate auto-complete feature
// using Trie data ure.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE];
    TrieNode* parent;
    // isWordEnd is true if the node represents
    // end of a word
    bool isWordEnd;
};


TrieNode *getNode();
bool isLastNode(TrieNode* root);
bool insertT(TrieNode *root, string key);
TrieNode* search(TrieNode* root,string key);
bool delT(TrieNode *root, string key);
bool delR(TrieNode *prev, TrieNode* root, string key, int ind);
bool searchT(TrieNode *root, string key);
void suggestionsRec(TrieNode* root, string currPrefix);
int printAutoSuggestionsT(TrieNode* root, string query);
void printT(TrieNode *t, int level);
int returnIndex(char key);
bool doesHaveChildren(TrieNode* node);


class Trie
{
    TrieNode* root;

public:
    Trie() { root = getNode(); }
    bool insert(string wrd) { return insertT(root, wrd); }
    bool delW(string wrd) { return delT(root, wrd); }
    int printAutoSuggestions(string wrd) { return printAutoSuggestionsT(root, wrd); }
    bool search(string key) { return searchT(root, key); }
    void printTrie() { printT(root, 0); }
};


#endif //DATASTRUCTURE_EX3_TRIE_H
