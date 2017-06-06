#include<iostream>
#include<vector>
using namespace std;
class TrieNode {
public:
    // Initialize your data structure here.
    bool eow;
	char chr;
	vector<TrieNode*> child;
    TrieNode(char c) {
        eow=false;
		chr=c;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode('\0');
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* n=root;
		TrieNode* nn;
        for(int i=0;i<word.length();i++){
            char t=word[i];
			bool found=false;
			for(int j=0;j<n->child.size();j++){
				if(n->child[j]->chr==t){
					found=true;
					nn=n->child[j];
					break;
				}
			}
			
			if(!found){
				nn=new TrieNode(t);
				n->child.push_back(nn);
			}
			n=nn;
        }
        n->eow=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* n=root;
        for(int i=0;i<word.length();i++){
            TrieNode* nn;
			char t=word[i];
			bool found=false;
			for(int j=0;j<n->child.size();j++){
				if(n->child[j]->chr==t){
					found=true;
					nn=n->child[j];
					break;
				}
			}
			if(!found){
				return false;
            }
			n=nn;
        }
        if(n->eow)
            return true;
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
	//	if(prefix=="cba")
	//		cout<<"";
        TrieNode* n=root;
		TrieNode* nn;
        for(int i=0;i<prefix.length();i++){
            char t=prefix[i];
			bool found=false;
			for(int j=0;j<n->child.size();j++){
				if(n->child[j]->chr==t){
					found=true;
					nn=n->child[j];
					break;
				}
			}
            if(!found)
                return false;
			n=nn;
        }
        return true;
    }
private:
	TrieNode* root;
};

int main(){
	Trie trie;
	string line;/*
	while(!getline(cin, line)){
		string in=line.substr(1,line.length()-1);
		if(line[0]=='0'){
			trie.insert(in);
		}else if(line[0]=='1'){
			cout<<trie.search(in)<<endl;
		}else if(line[0]=='2'){
			cout<<trie.startWith(in)<<endl;
		}
	}*/
	trie.insert("");
	trie.insert("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	trie.insert("aababc");
	trie.insert("babb");
	trie.insert("aba");
	trie.insert("bab");
	trie.insert("c");
	cout<<trie.search("")<<endl;
	cout<<trie.search("aba")<<endl;
	cout<<trie.startsWith("aaaaaaaaaaaaaaa")<<endl;
	cout<<trie.startsWith("ab")<<endl;
	cout<<trie.startsWith("a")<<endl;
	cout<<trie.startsWith("aba")<<endl;
	cout<<trie.startsWith("abc")<<endl;
	cout<<trie.startsWith("cba")<<endl;
	cout<<trie.search("abc")<<endl;
	cout<<trie.search("aab")<<endl;
return 0;}
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
