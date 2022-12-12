//
// Created by 97253 on 09/12/2022.
//

#include "Trie.h"
#include <list>

TrieNode *getNode()
{
    TrieNode *pNode =  new TrieNode;
    pNode->parent = nullptr;
    pNode->isWordEnd = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}
int returnIndex(char key) {return (int)key - (int)'a';}

// search for the node at the end of the given key and returns it if this path exists
TrieNode* search(TrieNode *root, string key)
{
    auto it = root;
    for (int i = 0; i < key.length(); i++)
    {
        // if the path doesn't exist
        if (!it->children[returnIndex(key[i])])
            return nullptr;

        it = it->children[returnIndex(key[i])];
    }

    return it;
}

// return if this key exists in this trie as word
bool searchT(TrieNode *root, string key)
{
    auto result = search(root,key);
    return result && result->isWordEnd;
}

// inserting the key to the trie
bool insertT(TrieNode *root, string key)
{
    if(searchT(root,key)) // if the key already exists
        return false;
    auto pRoot= root;

    for (char i : key)
    {
        int j = returnIndex(i);
        if (!pRoot->children[j]) { // if this path doesn't exist
            pRoot->children[j] = getNode();
            pRoot->children[j]->parent = pRoot;
        }
        pRoot = pRoot->children[j];
    }

    // mark last node as end word
    pRoot->isWordEnd = true;
    return true;
}

// deleting the key from the trie
bool delT(TrieNode *root, string key)
{
    if(!searchT(root, key)) return false; // if the key doesn't exist
    auto node = search(root,key); // go to the end of the key
    node->isWordEnd = false;
    if(doesHaveChildren(node))return true; // if this node have another path through
    while (node != root && !doesHaveChildren(node)){ // go up and delete nodes until coming to root or the node have another path through
        node = node->parent;
        delete node->children[returnIndex(key.back())];
        node->children[returnIndex(key.back())] = nullptr;
        key.pop_back();
    }
    return true;

}
// recursive function to print the subtree of given node
void printT(TrieNode *t, int level)
{
    if(!doesHaveChildren(t)) // go back if there isn't path to continue
        return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (t->children[i] != nullptr) {//check if it's not empty
            for (int j = level ; j > 0; j--) {//print the spaces
                cout << "   ";
            }
            cout << (char)(i + 'a') << ":" << endl;
            printT(&(*t->children[i]), level + 1);
        }
    }
}
// returns if the given node have children or not
bool doesHaveChildren(TrieNode* node){
    for (auto & i : node->children)
        if (i != nullptr) return true;
    return false;
}
// returns the number of possible strings from the given string
int printAutoSuggestionsT(TrieNode* root, string query)
{
    return printAutoSuggestions(search(root, query), query);
}

// recursive function to count and print all the words that they are the continuation of the query
int printAutoSuggestions(TrieNode *node, string query){
    int counter = 0;
    if(!node) return 0;
    if(node->isWordEnd){ // print if this node is end of a word
        counter += 1;
        cout << query << endl;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++){
        if (node->children[i] != nullptr){
            auto temp = query;
            temp.push_back((char)(i + 'a')); // adding the alphabet representation of the node to the query
            counter += printAutoSuggestions(node->children[i], temp);
        }
    }
    return counter;
}