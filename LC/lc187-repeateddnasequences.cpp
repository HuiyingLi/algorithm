#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ans;
		unordered_map<unsigned long, int> dict ;
		int i=10;
		if(s.length()<10)
			return ans; 
		unsigned long mask=(((ULONG_MAX)<<40)^ULONG_MAX);//mask is 24 0s and 40 1s
		string b=s.substr(0,10);
		unsigned long c=0;
		for(int i=0;i<10;i++){
			c<<=4;
			if(s[i]=='A'){
				c|=(1<<3);
			}else if(s[i]=='C'){
				c|=(1<<2);
			}else if(s[i]=='G'){
				c|=(1<<1);
			}else{
				c|=1;
			}
		}	
		c&=mask;
		cout<<hex<<c<<endl;
		while(i<s.length()){
			if(dict.find(c)==dict.end()){
				dict[c]=1;
			}else{
				dict[c]++;
				if(dict[c]==2)
					ans.push_back(s.substr(i-10,10));
			}
			c<<=4;
			if(s[i]=='A'){
				c|=(1<<3);
			}else if(s[i]=='C'){
				c|=(1<<2);
			}else if(s[i]=='G'){
				c|=(1<<1);
			}else{
				c|=1;
			}
			c&=mask;
		//	cout<<"s[i]:"<<i<<endl<<hex<<c<<endl;
			i++;
		}
		if(dict.find(c)!=dict.end()){
			dict[c]++;
			if(dict[c]==2)
			    ans.push_back(s.substr(i-10,10));
		}
		return ans;
    }
};
int main(){
	Solution s;
	s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
return 0;}
