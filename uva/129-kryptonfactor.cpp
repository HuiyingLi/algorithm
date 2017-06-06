#include<iostream>
#include<sstream>
using namespace std;
int L;
int N;
int n;
string ans;
bool ish(string s){
	if(s.length()<2)
		return true;
	else{
		int l=s.length();
		for(int i=l-2;i>=0;i-=2){
			string t=s.substr(i,l-i);
			string t1=t.substr(0,t.length()/2);
			string t2=t.substr(t.length()/2,t.length()/2);
			if(t1==t2)
				return false;			
		}
		return true;
	}
}
void print(string s){
	int g=0;
	for(int i=0;i<s.length();i++){
		if(i!=0&&i%4==0){
			g++;
			if(g!=0&&g%16==0)
				cout<<endl;
			else
				cout<<" ";
		}
		cout<<s[i];
	}
	cout<<endl;
	cout<<s.length()<<endl;
}
void dfs(){
	if(N==n){
		print(ans);
		return;
	}else if(N<n){
		for(int i=0;i<L;i++){
			char c='A'+i;
			string t=ans;
			if(ish(ans+c)){
				ans+=c;
//				print(ans);
				N++;
				dfs();
				ans=t;
			}
			if(N>=n)
				break;
		}
	}
}
	
int main(){
	string line;
	while(1){
		getline(cin, line);
		stringstream ss(line);
		ss>>n;
		ss>>L;
		if(n==0&&L==0){
			break;
		}
		N=0;
		ans="";
		dfs();
	}	
}
