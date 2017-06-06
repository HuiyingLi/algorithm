#include<iostream>
#include<vector>

using namespace std;

string preproc(string in){
	string l;
	int i;
	for(i=0;i<in.length();i++){
		if(in.at(i)!=' '&&in.at(i)!='\n')
			l+=in[i];
	}
	return l;

}

int MIN=-100000;
int eval(string oexpr){
	string expr=preproc(oexpr);
	vector<int> varvals=vector<int>(26);
	int j;
	for(j=0;j<26; j++){
		varvals[j]=MIN;
	}
	vector<int> done;
	char varname=' ';
	int lastvar=0;
	string lastuniop="";
	string lastbiop="";
	bool occupied=false;//no more room for uniop flag
	int i=0;
	while(i<expr.length()){
		if(expr[i]<='z'&&expr[i]>='a'){//is var
			varname=expr[i];
			if(varvals[expr[i]-'a']!=MIN)
				lastvar=varvals[expr[i]-'a'];
			else
				lastvar=expr[i]-'a'+1;
			if(lastuniop!=""){
				if(lastuniop=="++")
					lastvar++;
				if(lastuniop=="--")
					lastvar--;
				lastuniop="";
				occupied=true;
			}
			varvals[expr[i]-'a']=lastvar;
			i++;
		}else if(i<expr.length()-1&&!occupied&&(expr.substr(i,2)=="++"||expr.substr(i,2)=="--")){
			if(varname!=' ' && expr[i]=='+'){
				varvals[varname-'a']++;
				occupied=true;
			}else if(varname!=' '&&expr[i]=='-'){
				varvals[varname-'a']--;
				occupied=true;
			}else if(varname==' '){
				lastuniop=expr.substr(i,2);
			}
			i+=2;
		}else if(expr[i]=='+'||expr[i]=='-'){
			done.insert(done.begin(),lastvar);
			varname=' ';
			occupied=false;
			if(lastbiop!=""){//evaluate last subexpression
				if(lastbiop=="+"){
					int v=done[0]+done[1];
					done.clear();
					done.insert(done.begin(),v);
				}else if(lastbiop=="-"){
					int v=done[1]-done[0];
					done.clear();
					done.insert(done.begin(),v);
				}
			}
			lastbiop=expr[i];
			i++;
		}	
	}	
	int res;
	if(lastbiop=="+"){
		res=done[0]+lastvar;
	}else if(lastbiop=="-"){
		res=done[0]-lastvar;
	}else{
		res=lastvar;
	}
	cout<<"Expression: "<<oexpr<<endl;
	cout<<"    value = "<<res<<endl;
	int k;
	for(k=0;k<26;k++){
		if(varvals[k]!=MIN){
			char c='a'+k;
			cout<<"    "<<c<<" = "<<varvals[k]<<endl;
		}
	}
	return res;
}
int main(){
	string line;
	while(getline(cin, line)){
		eval(line);
	}	
}
