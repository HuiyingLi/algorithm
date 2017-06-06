#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;

string eq;
string neq;
int L;
int c;
bool sw0;
bool found=false;
string op[3]={"*","+","-"};
bool evaleq(){
	int nop=0;
	int i=0;
	int s=0;
	int o=0;
	int e=0;
	char prevsign='+';
	long res=0;
	vector<long> ns;
	vector<long> adds;
	neq+="+";
	while(i<neq.length()){
		if(neq[i]<'0'){
			nop++;
			long t=stol(neq.substr(s,i-s));
			ns.push_back(t);
			if(neq[i]=='+'||neq[i]=='-'){
				long ans=0;
				if(!ns.empty()){
					long tans=1;
					for(int i=0;i<ns.size();i++){
						tans*=ns[i];
					}
					ans=tans;
					ns.clear();
				}else{
					ans=stol(neq.substr(s,i-s));
				}
				if(prevsign=='-'){
					res-=ans;	
				}else{
					res+=ans;
				}
				prevsign=neq[i];
			}
			s=i+1;
		}
		i++;
	}
	neq=neq.substr(0,neq.length()-1);
	if(res==2000&&nop>1)	
		return true;
	else
		return false;	
}

void dfs(int d){
	if(d==L){
//		if(neq=="2000")
//			cout<<endl;
		if(evaleq()){
	//	if(true){
			cout<<"  "<<neq<<"="<<endl;
			found=true;
		}
//		if(neq=="2*0+6*3-3-4-4-0")
//			cout<<endl;
		return;
	}
	if(neq[c-1]!='*'&&neq[c-1]!='+'&&neq[c-1]!='-'){
		for(int i=0;i<3;i++){
			neq.insert(c,op[i]);
			c+=2;
			bool tsw0=sw0;
			if(eq[d]=='0')
				sw0=true;
			else
				sw0=false;
			dfs(d+1);
			c-=2;
			neq.erase(c,1);
			sw0=tsw0;
		}
	}
	//do nothing
	if(!sw0){
		c++;
		dfs(d+1);
		c--;
	}
}

int main(){
	string line;
	int Case=0;
	while(true){
		getline(cin,line);
		if(line[0]=='=')
			break;
		int e=0;
		while(line[e]!='=')e++;
		eq=line.substr(0,e);
		neq=eq;
		L=eq.length();
		c=1;
		found=false;
		Case++;
		cout<<"Problem "<<Case<<endl;
		dfs(1);
		if(!found){
			cout<<"  IMPOSSIBLE"<<endl;
		}
//		evaleq();
	}
}
