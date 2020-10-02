#include<bits/stdc++.h>

using namespace std;

class Trie{ 
	private:
		struct Node {
			Node(){
				this->end = false;
				for(int i = 0; i < 26; i++)
					this->letters[i] = NULL;
			}
			Node *letters[26];
			bool end;
		};
		Node* root;
	public:
		Trie() { 
			root = new Node();
		}
		void addHelper(Node* root, string s){
			for(int i = 0; i <= s.size(); i++){
				if(i == s.size()){
					root->end = true;
					return;
				}
				if(root->letters[s[i]-'a'] == NULL){
					root->letters[s[i]-'a'] = new Node();
					root = root->letters[s[i]-'a'];
				}
				else
					root = root->letters[s[i]-'a'];
			}
		}
		void add(string s){
			addHelper(root, s);
		}
		bool check(string s){ // check if substring
			return checkHelper(root, s);
		}
		bool checkHelper(Node* root, string s){
			for(int i = 0; i < s.size(); i++){
				if(root->letters[s[i]-'a'] == NULL)
					return false;
				root = root->letters[s[i]-'a'];
			}
			return true;
		}
};
int main(){
	Trie drzewko;
	string a;
	cin >> a;
	drzewko.add(a);
	cout << drzewko.check("siema");
	return 0;
}
