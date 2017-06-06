#include<iostream>
#include<sstream>
#include<stack>
#include<string>
using namespace std;

int main(){
	string line;
	getline(cin,line);
	stringstream ss(line);
	int n;
	ss>>n;
	for(int i=0;i <n;i++){
		getline(cin, line);
		if(line.length()==0){
			cout<<"Yes\n";
			continue;
		}
		bool flag=true;
		stack<char> stk;
		for(int k=0;k<line.length();k++){
			if(line[k]=='('||line[k]=='['){
				stk.push(line[k]);
			}else if(line[k]==')'){
				if(!stk.empty()&&stk.top()=='(')
					stk.pop();
				else{
					flag=false;
					break;
				}
			}else if(line[k]==']'){
				if(!stk.empty()&&stk.top()=='[')
					stk.pop();
				else{
					flag=false;
					break;
				}
			}
		}
		if(!stk.empty())
			flag=false;
		if(flag)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}
