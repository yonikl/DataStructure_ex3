//
// Created by 97253 on 09/12/2022.
//

#include "Trie.h"

TrieNode *getNode()
{
    TrieNode *pNode =  new TrieNode;

    pNode->isWordEnd = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}
int returnIndex(char key) {return (int)key - (int)'a';}

bool searchT(TrieNode *root, string key)
{
    auto it = root;
    for (int i = 0; i < key.length(); i++)
    {
        if (!it->children[returnIndex(key[i])])
            return false;

        it = it->children[returnIndex(key[i])];
    }

    return (it->isWordEnd);
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
