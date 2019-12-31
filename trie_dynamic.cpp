#include<bits/stdc++.h>
using namespace std;
/* zakładamy że stringi mają tylko małe litery */

class Trie{ 
	private:
		struct Node { 
			Node *letters[26];
			bool end;
		};
		Node* root;
	public:
		void setNewNode(Node* node) { 
			for(int i = 0; i < 26; i++) 
				node->letters[i] = NULL;
			node->end = false;
		} 
		Trie() { 
			root = (Trie::Node* )malloc(sizeof(Node));
			setNewNode(root);
		}
		void Add(string s) { 
			AddIter(root, s, 0);		
		}
		void AddIter(Node* currNode, string &s, int i) { 
			if(i == s.length()) { 
				currNode->end = true;	
				return;
			}
			if(currNode->letters[s[i]-'a'] == NULL) { 
				currNode->letters[s[i]-'a'] = (Trie::Node* )malloc(sizeof(Node));
				setNewNode(currNode->letters[s[i]-'a']);
			}
			AddIter(currNode->letters[s[i]-'a'],s, i+1);
		} 
		bool check(string s){
			checkHelper(root, s, 0);
		}
		bool checkHelper(Node* currNode, string &s, int i){
			if(i == s.length())
				return currNode->end == true;
			if(currNode->letters[s[i]-'a'] == NULL)
				return false;
			else
				checkHelper(currNode->letters[s[i]-'a'], s, i+1);
		}
};
int main(){
	Trie drzewko;
	for(int i=0; i<10; i++){
		int a; cin>>a;
		string tekst;
		cin>>tekst;
		if(a == 1)
			drzewko.Add(tekst);
		else
			cout<<drzewko.check(tekst);
	}
	return 0;
}