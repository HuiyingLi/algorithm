//#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		stack<string> stk;
		for(int i=0;i<tokens.size();i++){
			string c=tokens[i];
			if(c!="+"&&c!="-"&&c!="*"&&c!="/"){
				stk.push(c);
				continue;
			}	
			string a=stk.top();
			stk.pop();
			string b=stk.top();
			stk.pop();
			int op1=stoi(a);
			int op2=stoi(b);

			if(c=="+"){
				stk.push(to_string(op1+op2));
			}else if(c=="-"){
				stk.push(to_string(op2-op1));
			}else if(c=="*"){
				stk.push(to_string(op1*op2));
			}else if(c=="/"){
				stk.push(to_string(op2/op1));
			}
		}
		string ans=stk.top();
		return stoi(ans);
    }
};

int main(){return 0;}
