#include<iostream>
#include<sstream>
#include<string.h>
#include<unordered_map>
#include<unordered_set>
#include<math.h>
using namespace std;

string lookup[100][100];
unordered_map<int, int> rlook[10000];
string pz[3];
string pza[3];
int alter[3][4];
int alt;
int len[3];
char digits[11]={'*','0','1','2','3','4','5','6','7','8','9'};
void init(){
	for(int i=1; i<=99;i++){
		for(int j=1; j<=99; j++){
			int a=i*j;
			lookup[i][j]=to_string(a);
//			rlook[a][i]=j;
//			rlook[a][j]=i;
//			if(lookup[i][j].length()==4&&lookup[i][j][0]=='9'&&lookup[i][j][2]=='3')
//				cout<<i<<" "<<j<<" "<<endl;
		}
	}
//	for(int i=0;i<10000; i++){
//		if(rlook[i].size()==1)
//			cout<<i<<endl;
//	}
}

bool matchrhs(int lhs1,int lhs2){
	string r=lookup[lhs1][lhs2];
	if(r.length()!=pz[2].length())
		return false;
	bool match=true;
	for(int e=0;e<r.length();e++){
		if(pz[2][e]!='*'&&pz[2][e]!=r[e]){
			match=false;
			break;
		}
	}
	return match; 
}

unordered_set<int> getcdd(string s){
	unordered_set<int> res;
	res.insert(0);
	for(int i=0;i<s.length();i++){
		unordered_set<int> nres;
		for(unordered_set<int>::iterator it=res.begin(); it!=res.end();it++){
			int t=*it;
			t*=10;
			if(s[i]=='*'){
				for(int k=0;k<=9;k++){
					if(i==0&&k==0) continue;
					nres.insert(t+k);
				}
			}else{
				t+=s[i]-'0';
				nres.insert(t);
			}
		}
		res=nres;
	}
	return res;
}
bool isunique(){
	int found=0;
	unordered_set<int> set1=getcdd(pz[0]);
	unordered_set<int> set2=getcdd(pz[1]);
	for(unordered_set<int>::iterator it=set1.begin(); it!=set1.end(); it++){
		int l1=*it;
		for(unordered_set<int>::iterator it2=set2.begin(); it2!=set2.end(); it2++){
			int l2=*it2;
			string r=to_string(l1*l2);
			if(r.length()!=pz[2].length()) continue;
			bool flag=true;
			for(int i=0;i<r.length();i++){
				if(pz[2][i]!='*'&&pz[2][i]!=r[i]){
					flag=false;
					break;
				}
			}
			if(flag) 
				found++;
			if(found>1)
				return false;
		}
	}
	if(found==1)
		return true;
	return false;
}
bool dfs(int d,int maxalt){
//	cout<<pz[0]+" "+pz[1]+" "+pz[2]+" "<<maxalt<<endl;
//	if	(pz[0]+" "+pz[1]+" "+pz[2] =="** ** 993*")
//		cout<<endl;
	if(alt>maxalt) return false;
	if(d==len[2]){
//		if(pz[0]+" "+pz[1]+" "+pz[2]=="** ** 9*3*")
//			cout<<endl;
//		cout<<pz[0]<<" "<<pz[1]<<" "<<pz[2]<<endl;
		if(isunique()){
	//		if(alt<ans){
			pza[0]=pz[0];
			pza[1]=pz[1];
			pza[2]=pz[2];
			cout<<pza[0]<<" "<<pza[1]<<" "<<pza[2]<<endl;
			return true;
	//		}
		}
		return false;
	}/*
	for(int i=0;i<3;i++){
		for(int j=0;j<pz[i].length();j++){
			if(vis[i][j])
				continue;
			char cur=pz[i][j];
			pz[i][j]='*';
			int tmpalt=alter[i][j];
			if(!alter[i][j]&&cur!='*'){
				alter[i][j]=1;
				alt++;
			}
			vis[i][j]=1;
			dfs(d+1);
			if(tmpalt==0&&cur!='*')
				alt--;
			alter[i][j]=tmpalt;
			pz[i][j]=cur;
			vis[i][j]=0;

			for(int k=0;k<10;k++){
				if(k==0&&j==0)//no leading zeros
					continue;
				pz[i][j]='0'+k;
				int tmpalt=alter[i][j];
				if(!alter[i][j]&&cur!='0'+k){
					alter[i][j]=1;
					alt++;
				}
				vis[i][j]=1;
				dfs(d+1);
				if(tmpalt==0&&cur!='0'+k)
					alt--;
				alter[i][j]=tmpalt;
				pz[i][j]=cur;
				vis[i][j]=0;
			}
		}
	}*/
	int i,ind;
	if(d<len[0]) {
		i=0;
		ind=d;
	}
	if(d>=len[0]&&d<len[1]) {
		i=1;
		ind=d-len[0];
	}
	
	if(d>=len[1]){
		i=2;
		ind=d-len[1];
	}	
	char cur=pz[i][ind];
	for(int k=0;k<11;k++){
		if(d==0&&ind==0&&k==1)
			continue;
		int talt=alter[i][ind];
		if(cur!=digits[k]&&talt==0){
			alt++;
			alter[i][ind]++;
		}
		pz[i][ind]=digits[k];
		if(dfs(d+1,maxalt))
			return true;
		pz[i][ind]=cur;
		if(cur!=digits[k]&&talt==0){
			alt--;
			alter[i][ind]=talt;
		}
	}
	return false;	
}/*
bool dfs(int d){
	cout<<pz[0]<<" "<<pz[1]<<" "<<pz[2]<<endl;
	if(d>=ans){
		return false;
	}
	if(isunique()){
		pza[0]=pz[0];
		pza[1]=pz[1];
		pza[2]=pz[2];
		return true;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<pz[i].length();j++){//select one position to change
			char cur=pz[i][j];
			if(cur==digits[k]||vis[i][j]){
				continue;
			}
			if(j==0&&k==1)//leading zeroes
				continue;
			vis[i][j]=1;	
			pz[i][j]=digits[k];
			if(dfs(d+1))
				return true;
			vis[i][j]=0;
			pz[i][j]=cur;
		}
	}
}
*/
int main(){
	init();
	string line;
	int Case=0;
	while(true){
		getline(cin, line);
		if(line=="0")
			break;
		int o=0;
		int k=0;
		for(int i=0;i<line.length();i++){
			if(line[i]==' '){
				pz[o]=line.substr(k,i-k);
				k=i+1;
				len[o]=k-1-o;
				o++;
			}
		}
		pz[2]=line.substr(k,line.length()-k);
		len[2]=line.length()-2;
		for(int i=0;i<3;i++)pza[i]="";	
		alt=0;
		memset(alter,0,sizeof(alter));
		Case++;
		cout<<"Case "<<Case<<": ";
		int maxalt=0;
		while(maxalt<9){
			if(dfs(0,maxalt))
				break;
			maxalt++;
		}
	}
/**	
	unordered_set<int> res=getcdd("*");
	for(unordered_set<int>::iterator it=res.begin();it!=res.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
**/
	return 0;
}
