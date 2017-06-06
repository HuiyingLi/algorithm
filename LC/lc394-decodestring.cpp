#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution{
public:
	string s;
	int pos;
	string build(int b){
		int i=b;
		string ans="";
		while(i<s.length()){
			if(s[i]<'a'&&s[i]!=']'){
				int l=0;
				while(s[i+l]<'a'&&s[i+l]!='[')
					l++;
				// till end of the number part
				int r=atoi(s.substr(i,l).c_str());
				
				string rs=build(i+l+1);//peeled off []
				for(int k=0;k<r;k++)
					ans+=rs;
				i=pos;
			}else if(s[i]==']'){
				pos=i;
				return ans;	
			}else{
				ans+=s[i];
			}
			i++;
		}
		return ans;
	}
	string decodeString(string s){
		this->s=s;
		return build(0);
	}
};
int main(){
	Solution s;
	cout<<s.decodeString("3[a]2[bc]");
return 0;}
