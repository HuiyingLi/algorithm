#include<iostream>
#include<sstream>
using namespace std;

int T;
string src;
string dest;
int cind[110];
int solve(){
	int szs=0, sos=0, dzs=0, dos=0;
	int res=0,l=0;
	for(int i=0;i<src.length();i++){
		if(src[i]=='1') 
			sos++;
		else if(src[i]=='0')
			szs++;
		else if(src[i]=='?'){
			res++;
			cind[l]=i;
			l++;
		}
		if(dest[i]=='1')
			dos++;
		else if(dest[i]=='0')
			dzs++;
	}
	int nc=res;
	int difz=dzs-szs;
	int difo=dos-sos;
	if(difz>nc)
		return -1;
	if(difz>0){
		for(int i=0;i<l&&difz;i++){
			if(dest[cind[i]]=='0'){
				src[cind[i]]='0';
				difz--;
			}
		}
		for(int i=0;i<l&&difz;i++){
			if(src[cind[i]]=='?'){
				src[cind[i]]='0';
				difz--;
			}
		}
	}
	for(int i=0;i<l;i++){
		if(src[cind[i]]=='?'){
			src[cind[i]]='1';
			difo--;
		}
	}
	for(int i=0;i<src.length()&&difo;i++){
		if(dest[i]=='1'&&src[i]=='0'){
			src[i]='1';
			difo--;
			res++;
		}
	}
	int exc=0;
	for(int i=0;i<src.length();i++){
		if(dest[i]!=src[i])
			exc++;
	}
	res+=exc/2;
	return res;
}
int main(){
	string line;
	getline(cin, line);
	stringstream ss(line);
	ss>>T;
	for(int t=0;t<T;t++){
		getline(cin, src);
		getline(cin, dest);
		cout<<"Case "<<t+1<<": "<<solve()<<endl;
	}
	return 0;
}

