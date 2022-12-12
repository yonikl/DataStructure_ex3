/*
Name: Raz Leibovitch
 Id:209521863
 Name: Yonatan Klein
 Id: 322961764
 */
#include <iostream>
#include <string>
#include "Trie.h"

using namespace std;


int main()
{

	char ch;
	string wrd;
	Trie tr;
	int comp;

	cout << "\nTRIE PROGRAM" << endl;
	cout << "\nChoose one of the following" << endl;
	cout << "a: add a new word" << endl;
	cout << "d: delete an word" << endl;
	cout << "s: check if an word exists " << endl;
	cout << "c: complete the possible word name " << endl;
	cout << "p: print trie" << endl;
	cout << "e: exit " << endl;
	do
	{
		cin >> ch;

		switch (ch)
		{
		case 'a'://inset new word to the tree
			cout << "Enter a word to insert " << endl;
			cin >> wrd;
			if (!tr.insert(wrd))
				cout << "ERROR\n";
			break;
		case 'd'://delete word from the tree
			cout << "Enter a word to del " << endl;
			cin >> wrd;
			if (!tr.delW(wrd)) cout << "ERROR\n";//if the word dose not exists
			break;
		case 's'://search word in the tree
			cout << "Enter a word to search " << endl;
			cin >> wrd;
			if (tr.search(wrd))
				cout << "exists\n";
			else
				cout << "does not exist\n";
			break;

		case 'c'://print all the suggestion to word in the tree
			cout << "Enter a prefix to complete " << endl;
			cin >> wrd;
			comp = tr.printAutoSuggestions(wrd);

			if (comp == 0)//if the word not in the tree
				cout << "No string exist with this prefix\n";
			break;
		case 'p': tr.printTrie(); break;//print all the tree
		case 'e':cout << "bye " << endl; break;//finish
		default: cout << "ERROR " << endl;  break;
		}//switch
	} while (ch != 'e');
    return 0;
}
/*
TRIE PROGRAM

Choose one of the following
a: add a new word
d: delete an word
s: check if an word exists
c: complete the possible word name
p: print trie
e: exit
a
Enter a word to insert
abcd
a
Enter a word to insert
abbd
a
Enter a word to insert
abxd
p
a:
   b:
      b:
         d:
      c:
         d:
      x:
         d:
d
Enter a word to del
abbd
p
a:
   b:
      c:
         d:
      x:
         d:
s
Enter a word to search
abcd
exists
c
Enter a prefix to complete
ab
abcd
abxd
e
bye

 */