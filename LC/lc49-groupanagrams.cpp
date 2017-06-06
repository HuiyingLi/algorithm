#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		unordered_map<string,vector<string>> mm;
		for(int i=0; i<strs.size();i++){
			string s=strs[i];
			int vocab[26]={0};
			for(int j=0;j<s.length();j++){
				vocab[s[j]-'a']++;
			}
			string key="";
			for(int j=0;j<26;j++){
				if(vocab[j]!=0){
					char a='a'+j;
					key+=a+to_string(vocab[j]);
				}
			}
			if(mm.find(key)==mm.end()){
				vector<string> v;
				mm[key]=v;
			}
			mm[key].push_back(s);
		}	
		for(unordered_map<string,vector<string>>::iterator it=mm.begin();it!=mm.end();it++){
		ans.push_back(it->second);
		}
		return ans;

	}
};
int main(){
	string arr[3]={"ab","aa","ba"};
	vector<string> v(arr, arr+3);
	Solution s;
	s.groupAnagrams(v);
	return 0;
}
