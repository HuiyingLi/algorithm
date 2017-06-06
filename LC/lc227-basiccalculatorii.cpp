#include<iostream>
#include<stdlib.h>

using namespace std;

class Solution{
public:
	int calculate(string s){
		string prevsign="";
		int prevop=0, curop=0;
		bool empty=true;
		bool viscurop=false;
		string cursign="";
		int i=0;
		while(i<s.length()){
			if(s[i]==' '){
				i++;
			}else if(s[i]<='9'&&s[i]>='0'){
				int b=i;
				while(s[i]>='0'&&s[i]<='9')
					i++;
				int val=atoi(s.substr(b,i-b).c_str());
				if(!viscurop){
					curop=val;
					viscurop=true;
				}else{
					if(cursign=="+"){
						curop=curop+val;
					}else if(cursign=="-"){
						curop=curop-val;
					}else if(cursign=="*"){
						curop=curop*val;
					}else if(cursign=="/"){
						curop=curop/val;
					}
					cursign="";
				}
			}else if(s[i]=='+'||s[i]=='-'){
				if(!empty){
					int ev;
					if(prevsign=="+"){
						ev=prevop+curop;
					}else{
						ev=prevop-curop;
					}
					prevsign=s[i];
					prevop=ev;
				}else{
					prevop=curop;
					prevsign=s[i];
					empty=false;
				}
				viscurop=false;
				cursign="";
				i++;
			}else if(s[i]=='*'||s[i]=='/'){
				cursign=s[i];
				i++;
			}
		}
		if(!empty){
			if(prevsign=="+"){
				curop=curop+prevop;
			}else{
				curop=prevop-curop;
			}
		}
		return curop;
	}
};
int main(){
	string in="33*33/59*29";
	Solution s;
	cout<<s.calculate(in)<<endl;
return 0;}
