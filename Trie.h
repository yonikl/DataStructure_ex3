//
//class Trie crete new Trie tree and his function
//insert,remove,print,looking for Suggestions and search
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

// trie node
struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE];
    TrieNode* parent;
    // isWordEnd is true if the node represents
    // end of a word
    bool isWordEnd;
};


TrieNode *getNode();//get pointers in the size of ALPHABET
bool insertT(TrieNode *root, string key);//insert word to the tree
TrieNode* search(TrieNode* root,string key);//Return pointer to the last character in the word
bool delT(TrieNode *root, string key);//delete word from the tree
bool searchT(TrieNode *root, string key);//return true if the word exist in the tree if not return false
int printAutoSuggestionsT(TrieNode* root, string query);//print all the suggestions to the query
int printAutoSuggestions(TrieNode *node, string query);//Help function to print all suggestion
void printT(TrieNode *t, int level);//print all the tree
int returnIndex(char key);//get cher and return index in the array
bool doesHaveChildren(TrieNode* node);//check if the node have children
void removeAll(TrieNode* root);//delete all the tree

class Trie
{
    TrieNode* root;

public:
    Trie() { root = getNode(); }
    ~Trie(){ removeAll(root);}
    bool insert(string wrd) { return insertT(root, wrd); }
    bool delW(string wrd) { return delT(root, wrd); }
    int printAutoSuggestions(string wrd) { return printAutoSuggestionsT(root, wrd); }
    bool search(string key) { return searchT(root, key); }
    void printTrie() { printT(root, 0); }
};


#endif
