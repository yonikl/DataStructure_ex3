//
// Created by 97253 on 09/12/2022.
//

#include "Trie.h"

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

TrieNode* search(TrieNode *root, string key)
{
    auto it = root;
    for (int i = 0; i < key.length(); i++)
    {
        if (!it->children[returnIndex(key[i])])
            return nullptr;

        it = it->children[returnIndex(key[i])];
    }

    return it;
}

bool searchT(TrieNode *root, string key)
{
    auto result = search(root,key);
    return result && result->isWordEnd;
}
bool insertT(TrieNode *root, string key)
{
    if(searchT(root,key))
        return true;
    auto pRoot= root;

    for (int i = 0; i < key.length(); i++)
    {
        int j = returnIndex(key[i]);
        if (!pRoot->children[j]) {
            pRoot->children[j] = getNode();
            pRoot->children[j]->parent = pRoot;
        }
        pRoot = pRoot->children[j];
    }

    // mark last node as leaf
    pRoot->isWordEnd = true;
    return true;
}

bool delT(TrieNode *root, string key)
{
    if(!searchT(root, key)) return false;
    auto node = search(root,key);
    node->isWordEnd = false;
    if(doesHaveChildren(node))return true;
    while (node != root && !doesHaveChildren(node)){
        node = node->parent;
        delete node->children[returnIndex(key.back())];
        node->children[returnIndex(key.back())] = nullptr;
        key.pop_back();
    }
    return true;

}

void printT(TrieNode *t, int level)
{
    if(!doesHaveChildren(t))
        return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (t->children[i] != nullptr) {//check if the list not empty
            for (int j = level ; j > 0; j--) {//print the spaces
                cout << "   ";
            }
            cout << (char)(i + 'a') << ":" << endl;
            printT(&(*t->children[i]), level + 1);
        }
    }
}

bool doesHaveChildren(TrieNode* node){
    for (auto & i : node->children)
        if (i != nullptr) return true;
    return false;
}

int printAutoSuggestionsT(TrieNode* root, string query)
{
    return printAutoSuggestions(search(root, query), query);
}

int printAutoSuggestions(TrieNode *node, string query){
    int counter = 0;
    if(!node) return 0;
    if(node->isWordEnd){
        counter += 1;
        cout << query << endl;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++){
        if (node->children[i] != nullptr){
            auto temp = query;
            temp.push_back((char)(i + 'a'));
            counter += printAutoSuggestions(node->children[i], temp);
        }
    }
    return counter;
}