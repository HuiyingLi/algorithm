#include<iostream>
#include<sstream>
#include<set>
using namespace std;

int pow2[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
set<int> numset;
int N;
int nm=0;
int exc=0;
bool dfs(int v, int d, int maxd){
	if(d==maxd){
		if(numset.find(N)!=numset.end())
			return true;
		else
			return false;
	}
	int cm=*(numset.rbegin());
	if(cm*pow2[maxd-d]<N)
		return false;
	set<int>::reverse_iterator it;
	for(it=numset.rbegin(); it!=numset.rend();it++){
		set<int>::reverse_iterator it2;
		int n1=*it;
		for(it2=it;it2!=numset.rend();it2++){
			int n2=*it2;
			int a=n1+n2;
			if(numset.find(a)==numset.end()){
//				if(a>N)
//					exc++;
//				if(exc<2){
				numset.insert(a);
				if(dfs(a,d+1, maxd))
					return true;
				numset.erase(a);
//				}
//				if(a>N)
//					exc--;
			}
			int b=n1-n2;
			if(b>0){
//				if(nm<5){
					if(numset.find(b)==numset.end()){
						nm++;
						numset.insert(b);
						if(dfs(a,d+1,maxd))
							return true;
						numset.erase(b);
						nm--;
					}
//				}
			}

		}
	}
	return false;
}

void ida(){
	int maxd=0;
	while(true){
		if(dfs(1,0,maxd)){
			cout<<maxd<<endl;
			return;
		}
		maxd++;
	}
}

int main(){
	string line;
	while(true){
		getline(cin, line);
		stringstream ss(line);
		ss>>N;
		if(N==0)
			break;
		numset.clear();	
		numset.insert(1);
		ida();
	}
	return 0;
}
