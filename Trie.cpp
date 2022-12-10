//
// Created by 97253 on 09/12/2022.
//

#include "Trie.h"

TrieNode *getNode()
{
    TrieNode *pNode =  new TrieNode;

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

    if(it->isWordEnd)return it;
    return nullptr;
}

bool searchT(TrieNode *root, string key)
{
    return search(root,key) != nullptr;
}
bool insertT(TrieNode *root, string key)
{
    if(searchT(root,key))
        return true;
    auto pRoot= root;

    for (int i = 0; i < key.length(); i++)
    {
        if (!pRoot->children[returnIndex(key[i])]) {
            pRoot->children[returnIndex(key[i])] = getNode();
            pRoot->children[returnIndex(key[i])]->parent = pRoot;
        }
        pRoot = pRoot->children[returnIndex(key[i])];
    }

    // mark last node as leaf
    pRoot->isWordEnd = true;
    return true;
}

bool delT(TrieNode *root, string key)
{
    auto node = search(root, key);
    if(!node) return false;
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

bool doesHaveChildren(TrieNode* node){
    for (auto & i : node->children)
        if (i != nullptr) return true;
    return false;
}