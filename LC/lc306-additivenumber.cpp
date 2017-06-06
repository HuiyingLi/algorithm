#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
	string num;
	string add(string s1, string s2){
		string ans="";
		int l1=s1.length();
		int l2=s2.length();
		int l=l1<l2?l1:l2;
		int carry=0;
		for(int i=0;i<l;i++){
			int ind1=l1-i-1;
			int ind2=l2-i-1;
			int a1=s1[ind1]-'0';
			int a2=s2[ind2]-'0';
			int sum=a1+a2+carry;
			carry=sum/10;
			char rem='0'+sum%10;
			ans=rem+ans;
		}
		if(l1>l2){
			for(int i=l1-l2-1;i>=0;i--){
				int sum=carry+s1[i]-'0';
				carry=sum/10;
				char rem='0'+sum%10;
				ans=rem+ans;
			}
		}
		if(l1<l2){
			for(int i=l2-l1-1;i>=0;i--){
				int sum=carry+s2[i]-'0';
				carry=sum/10;
				char rem='0'+sum%10;
				ans=rem+ans;
			}
		}
		if(carry!=0)
			ans="1"+ans;
		return ans;
	}
    bool isAdditiveNumber(string num) {
		this->num=num;
		if(num.length()<3)
			return false;
		string op1, op2;
		for(int i=1;i<num.length()/2+1&&i<num.length();i++){
			op1=num.substr(0,i);
			if(op1[0]=='0'&&op1.length()>1)
				continue;
			for(int j=op1.length()+1;j<=op1.length()+(num.length()-op1.length())/2+2&&j<num.length();j++){
				op2=num.substr(op1.length(),j-op1.length());
				if(op1=="1980"&&op2=="1982")
					cout<<endl;
				if(op2[0]=='0'&&op2.length()>1) continue;
				string c1=op1, c2=op2;
				bool ileg=false;
				int k=op1.length()+op2.length();
				while(k<num.length()){
					string sum=add(c1,c2);
					if(k+sum.length()>num.length()){
						ileg=true;
						break;
					}
					string c=num.substr(k,sum.length());
					if(c==sum){
						c1=c2;
						c2=sum;
						k+=sum.length();
					}else{
						ileg=true;
						break;
					}
				}
				if(ileg)
					continue;
				if(k==num.length())
					return true;
			}
		}
		return false;	
    }
};

int main(){
	Solution s;
//	cout<<s.add("0","0")<<endl;
	string line;
	while(getline(cin, line)){
		line=line.substr(1,line.length()-2);
		cout<<s.isAdditiveNumber(line)<<endl;
	}
	return 0;}
