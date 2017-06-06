#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class Solution{
public:
	int vis[300];
	int lengthOfLongestSubstring(string s){
		memset(vis,-1,sizeof(vis));
		int mcnt=-1;
		int start=0;
		int ic;
		for(ic=0;ic<s.length();ic++){
			char c=s.at(ic);
			int ind=c-'\0';
			if(vis[ind]!=-1){
				if(ic-start>mcnt)	
					mcnt=ic-start;
				int newstart=vis[ind]+1;
				for(int k=start; k<newstart-1;k++)
					vis[s.at(k)-'\0']=-1;
				start=newstart;
				vis[ind]=ic;
			}else{
				vis[ind]=ic;
			}
		}
		if(ic-start>mcnt)
			mcnt=ic-start;
		return mcnt;
	}
};

int main(){
	Solution s;
	ifstream in;
	in.open("testgen_lc3.in");
	string line;
	while(!in.eof()){
		getline(in,line);
		line=line.substr(1,line.length()-2);
		cout<<line<<endl;
		cout<<s.lengthOfLongestSubstring(line)<<endl;
	}
	return 0;
}
