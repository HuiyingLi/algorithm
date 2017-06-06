#include<iostream>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
		int maxlen=0;
		int st, e;
		for(int i=0;i<s.length();i++){
			int k;
			//i is the index of the rightmost letter of the left part
			bool fe=true, fo=true;
			int ke=0, ko=0;
			for(k=1;k<=s.length()/2+2&&(fe||fo);k++){
				//if even
				if(fe){
					if(i-k+1<0||i+k>=s.length()){
						fe=false;
						ke=k-1;
					}else if(s[i-k+1]!=s[i+k]){
						fe=false;
						ke=k-1;
					}
				}
				//if odd
				if(fo){
					if(i-k+1<0||i+k+1>=s.length()){
						fo=false;
						ko=k-1;
					}else if(s[i-k+1]!=s[i+k+1]){
						fo=false;
						ko=k-1;
					}
				}
			}
			if(ko>maxlen-1){
				maxlen=ko;
				st=i-maxlen+1;
				e=i+maxlen+1;
			}
			if(ke>maxlen){
				maxlen=ke;
				st=i-maxlen+1;
				e=i+maxlen;
			}
		}
		if(maxlen==0)
			return s.substr(0,1);
		return s.substr(st,e-st+1);
    }
};
int main(){
	Solution s;
	cout<<s.longestPalindrome("baabbabb")<<endl;;
	
	return 0;
}
