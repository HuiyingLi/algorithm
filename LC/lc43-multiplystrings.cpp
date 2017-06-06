#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string times(string a, char b){
		if(b=='0') return "0";
		string ans="";
		int c=0;
		int bb=b-'0';
		for(int i=a.length()-1;i>=0;i--){
			int aa=a[i]-'0';
			int v=aa*bb+c;
			c=v/10;
			v%=10;
			char vc='0'+v;
			ans=vc+ans;
		}
		if(c>0){
			char cc='0'+c;
			ans=cc+ans;
		}
		int i=0;
		while(i<ans.length()&&ans[i]=='0')i++;
		if(i==ans.length())
			return "0";
			
		return ans.substr(i,ans.length()-i);
	}
	string madd(string a, string b){
		int i=a.length()-1;
		int j=b.length()-1;
		int c=0;
		string ans="";
		while(i>=0||j>=0){
			int aa=0, bb=0;
			if(i>=0)
				aa=a[i]-'0';
			if(j>=0)
				bb=b[j]-'0';
			int v=aa+bb+c;
			c=v/10;
			v%=10;
			char vc='0'+v;
			ans=vc+ans;
			i--;
			j--;
		}
		if(c==1)
			ans="1"+ans;
		int k=0;
		while(k<ans.length()&&ans[k]=='0')k++;
		if(k==ans.length())
			return "0";

		return ans;
	}
    string multiply(string num1, string num2) {
		int m=num1.length();
		int n=num2.length();
		string prev="";
		for(int i=n-1;i>=0;i--){
			string t=times(num1, num2[i]);
			for(int k=0;k<n-i-1;k++)
				t+="0";
			prev=madd(prev,t);
		}
		return prev;	
    }
};
int main(){
	Solution s;
	s.multiply("6","8");
	return 0;}
