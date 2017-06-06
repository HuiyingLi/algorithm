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

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode('\0');
    }

    // Inserts a word into the trie.
    void addWord(string word) {
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
		vector<TrieNode*> ns;
		vector<TrieNode*> nns;
		ns.push_back(root);
		for(int i=0;i<word.length();i++){
			char t=word[i];
			nns.clear();
			for(int j=0;j<ns.size();j++){
				vector<TrieNode*> child=ns[j]->child;
				if(t=='.'){
					nns.insert(nns.end(),child.begin(),child.end());
					continue;
				}
				for(int k=0;k<child.size();k++){
					if(child[k]->chr==t){
						nns.push_back(child[k]);
					}
				}
			}
			if(nns.size()==0)
				return false;
			ns=nns;
		}
		bool ef=false;
		for(int i=0;i<ns.size();i++){
			if(ns[i]->eow){
				return true;
			}
		}
		return false;
    }
private:
	TrieNode* root;
};

int main(){
	WordDictionary trie;
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
//	trie.addWord("");
	trie.addWord("aababc");
	trie.addWord("babb");
	trie.addWord("aba");
	trie.addWord("bab");
	trie.addWord("bcb");
	trie.addWord("babc");
	trie.addWord("cc");
	cout<<trie.search("")<<endl;
	cout<<trie.search("aba")<<endl;
	cout<<trie.search("abc")<<endl;
	cout<<trie.search("aab")<<endl;
	cout<<trie.search("bab.")<<endl;
	cout<<trie.search("b.b")<<endl;
	cout<<trie.search("a..")<<endl;
	cout<<trie.search("c.")<<endl;
	cout<<trie.search("..c")<<endl;
	cout<<trie.search(".")<<endl;
/*
	trie.addWord("bad");
	trie.addWord("dad");
	trie.addWord("mad");
	cout<<trie.search("pad")<<endl;
	cout<<trie.search("bad")<<endl;
	cout<<trie.search(".ad")<<endl;
	cout<<trie.search("b..")<<endl;
*/
return 0;}
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
