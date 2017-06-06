#include<iostream>
#include<sstream>
#include<queue>
#include<vector>
#include<map>
#include<string.h>
using namespace std;
map<long, int> vis;
int mL;
long pp[]={100000000,10000000,1000000,100000,10000,1000,100,10,1};


bool ordered(vector<int> in){
	if(mL==1)
		return true;
	for(int i=1;i<mL;i++){
		if(in[i]!=in[i-1]+1)
			return false;
	}
	return true;
}

//long ans[]={1,12,123,1234,12345,123456,1234567,12345678,123456789};
int visited(vector<int> in){
	return -1;
	long hs=0;
	for(int i=0;i<mL; i++){
		hs+=pp[9-mL+i]*in[i];
	}
	map<long,int>::iterator it=vis.find(hs);
	if(it!=vis.end())
		return it->second;
	else
		return -1;
}
void visit(vector<int> in, int d){
	long hs=0;
	for(int i=0;i<mL; i++){
		hs+=pp[9-mL+i]*in[i];
	}
	vis.insert(std::pair<long,int>(hs,d));
}

int digit_compare(vector<int>in){
	int c=0;
	for(int i=1;i<mL;i++){
		if(in[i]!=in[i-1]+1)
			c++;
	}
	return c;
}

vector<vector<int> > expand(vector<int> origin, int d){
	vector<vector<int> > moves;
	for(int i=0;i<mL;i++){
		if(i>0&&origin[i]==origin[i-1]+1)//prune
			continue;
		for(int l=mL-1;l>=1;l--){
			vector<int> t;
			if(i+l>mL||(i+l<mL&&origin[i+l-1]==origin[i+l]-1))
				continue;
	//		cout<<"Chunk:";
			for(int k=0;k<l;k++){
				t.push_back(origin[i+k]);
	//			cout<<t[k]<<" ";
			}
		//	cout<<endl;
			int i1=-1;
			int i2=-1;
			if(t[0]>1&&t[l-1]<mL){
				vector<int> ts(origin);
				ts.erase(ts.begin()+i,ts.begin()+i+l);
				for(int b=0;b<mL-l;b++){
					if(ts[b]==t[0]-1)
						i1=b+1;
					if(ts[b]==t[l-1]+1)
						i2=b;
				}
				if(i1!=-1){
					ts.insert(ts.begin()+i1, t.begin(),t.end());
					if(3*(d+1)+digit_compare(ts)<=3*(mL-1)){
						moves.push_back(ts);
					//	for(int b=0;b<mL;b++)
					//		cout<<ts[b]<<" ";
					//	cout<<endl;
					}
					ts.erase(ts.begin()+i1,ts.begin()+i1+t.size());
					
				}
				if(i2!=-1){
					ts.insert(ts.begin()+i2,t.begin(),t.end());
				//	if(visited(ts)==-1){
					if(3*(d+1)+digit_compare(ts)<=3*(mL-1)){
						moves.push_back(ts);
					//	for(int b=0;b<mL;b++)
						//	cout<<ts[b]<<" ";
					//	cout<<endl;
			//			visit(ts,d+1);
					}
			//	}
				}
			}
			if(i1==-1&&i2==-1){
		//	cout<<"chunk:";
		//	for(int b=0;b<t.size();b++) cout<<t[b]<<" ";
		//	cout<<endl;
				vector<int> ts(origin);
				ts.erase(ts.begin()+i,ts.begin()+i+l);
				for(int k=0;k<=mL-l;k++){
					if(k>0&&k<mL-l&&ts[k]==ts[k-1]+1) 
						continue;
					vector<int>::iterator it=ts.begin();
					ts.insert(it+k,t.begin(),t.end());
					if(3*(d+1)+digit_compare(ts)<=3*(mL-1)){
						moves.push_back(ts);
					//	for(int b=0;b<mL;b++)
				//			cout<<ts[b]<<" ";
				//		cout<<endl;
					}
					ts.erase(ts.begin()+k,ts.begin()+k+t.size());
				}
			}
		}
	}
	return moves;
}

bool dfs(vector<int> p, int d, int bound){
	if(d==bound)
		return ordered(p);
	if(3*d+digit_compare(p)>3*bound)
		return false; 
	vector<vector<int> >moves=expand(p,d);
	for(vector<vector<int> >::iterator it=moves.begin();it!=moves.end();it++){
		vector<int> np=*it;
		if(dfs(np, d+1, bound))
			return true; 
	}
	return false;
}

int ida_star(vector<int> start){
	int bound=0;
	//visit(start,0);
	while(bound<mL){
		if(dfs(start, 0, bound)){
			return bound;	
		}
		bound++;
//		cout<<"=====bound:"<<bound<<endl;
	}
	return -1;
}
	
int main(){
	int C=1;
	while(true){
		string line;
		getline(cin, line);
		stringstream ss(line);
		ss>>mL;
		if(mL==0)break;
		vis.clear();
		getline(cin,line);
		stringstream ss1(line);
		int num;
		vector<int> in;
//		int in[10];
		for(int i=0;i<mL;i++){
			ss1>>num;
		//	in[i]=num;
			in.push_back(num);
		}
	//	cout<<"Case "<<C<<": "<<bfs(in)<<endl;
		cout<<"Case "<<C<<": "<<ida_star(in)<<endl;
		C++;
	}
	return 0;
}
