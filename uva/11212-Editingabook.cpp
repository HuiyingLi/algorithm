#include<iostream>
#include<sstream>
#include<queue>
#include<vector>
#include<map>
#include<string.h>
using namespace std;
/**
class point{
	public:
	int v[10];
	int d;
	point(int* vec, int dist){
		memcpy(v,vec,sizeof(v));
		d=dist;
	}
};
**/
//int vis[998765432];
map<long, int> vis;
int mL;
long pp[]={100000000,10000000,1000000,100000,10000,1000,100,10,1};

//long ans[]={1,12,123,1234,12345,123456,1234567,12345678,123456789};
int visited(vector<int> in){
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
			cout<<"Chunk:";
			for(int k=0;k<l;k++){
				t.push_back(origin[i+k]);
				cout<<t[k]<<" ";
			}
			cout<<endl;
			int i1=-1;
			int i2=-1;
			if(t[0]>1&&t[l-1]<mL){
				//two options: put before after t[0]-1 or before t[-1]+1
				vector<int> ts(origin);
			//	int ts[10];
			//	memcpy(ts,origin, sizeof(ts));
				ts.erase(ts.begin()+i,ts.begin()+i+l);
		//		for(int b=i;b<mL-l-i;b++){
			//		ts[b]=ts[b+l];
			//	}
				for(int b=0;b<mL-l;b++){
					if(ts[b]==t[0]-1)
						i1=b+1;
					if(ts[b]==t[l-1]+1)
						i2=b;
				}
				if(i1!=-1){
					ts.insert(ts.begin()+i1, t.begin(),t.end());
			//		int tmp[10];
			//		memcpy(tmp,ts,sizeof(ts));
			//		for(int b=mL-l-1;b>=i1;b--){
			//			ts[b+l]=ts[b];
			//		}
			//		for(int b=i1;b<i1+l;b++){
			//			ts[b]=t[b-i1];
			//		}
					if(visited(ts)==-1){
						if(3*(d+1)+digit_compare(ts)<=3*(mL-1)){
							moves.push_back(ts);
							for(int b=0;b<mL;b++)
								cout<<ts[b]<<" ";
							cout<<endl;
//							vis.insert(std::pair<vector<int>,int>(ts,d+1));
							visit(ts,d+1);
						}
					}
			//		memcpy(ts,tmp,sizeof(tmp));
					ts.erase(ts.begin()+i1,ts.begin()+i1+t.size());
					
				}
				if(i2!=-1){
					ts.insert(ts.begin()+i2,t.begin(),t.end());
		//			int tmp[10];
		//			memcpy(tmp,ts,sizeof(ts));
		//			for(int b=mL-l-1;b>=i2;b--){
		//				ts[b+l]=ts[b];
		//			}
		//			for(int b=i2;b<i2+l;b++){
		//				ts[b]=t[b-i2];
		//			}
					if(visited(ts)==-1){
						if(3*(d+1)+digit_compare(ts)<=3*(mL-1)){
							moves.push_back(ts);
							for(int b=0;b<mL;b++)
								cout<<ts[b]<<" ";
							cout<<endl;
					//		vis.insert(std::pair<vector<int>,int>(ts,d+1));
							visit(ts,d+1);
						}
					}
				//	memcpy(ts,tmp,sizeof(tmp));
//					ts.erase(ts.begin()+i2,ts.begin()+i2+t.size());
				}
			}
			if(i1==-1&&i2==-1){
//			if(false){
//			cout<<"chunk:";
//			for(int b=0;b<t.size();b++) cout<<t[b]<<" ";
//			cout<<endl;
				//int ts[10];
				vector<int> ts(origin);
//				memcpy(ts,origin, sizeof(ts));
				//vector<int> ts(origin);
//				for(int b=i;b<mL-l-i;b++){
//					ts[b]=ts[b+l];
//				}
				ts.erase(ts.begin()+i,ts.begin()+i+l);
				for(int k=0;k<=mL-l;k++){
					if(k>0&&k<mL-l&&ts[k]==ts[k-1]+1) 
						continue;
					vector<int>::iterator it=ts.begin();
					ts.insert(it+k,t.begin(),t.end());
			//		int tmp[10];
			//		memcpy(tmp,ts,sizeof(ts));
			//		for(int b=mL-l-1;b>=k;b--){
			//			ts[b+l]=ts[b];
			//		}
			//		for(int b=k;b<k+l;b++){
			//			ts[b]=t[b-k];
			//		}
					if(visited(ts)==-1){
						if(3*(d+1)+digit_compare(ts)<=3*(mL-1)){
							moves.push_back(ts);
							for(int b=0;b<mL;b++)
								cout<<ts[b]<<" ";
							cout<<endl;
//							vis.insert(std::pair<vector<int>,int>(ts,d+1));
							visit(ts,d+1);
						}
					}
					//memcpy(ts,tmp,sizeof(tmp));
					ts.erase(ts.begin()+k,ts.begin()+k+t.size());
				}
			}
		}
	}
	return moves;
/**
	string s=origin;
	//starting point
	for(int i=0;i<L; i++){
		for(int l=1;l<L-1;l++){
			string t;
			if(s[i+l-1]==s[i+l]-1)
				continue;
			for(int k=0;k<l;k++){
				t+=s[i+k];		
			}
			string ts=s.substr(0,i)+s.substr(i+l,L-i-l);
			//insert
			for(int k=0;k<ts.length();k++){
				if(k>0&&ts[k]==ts[k-1]+1)
					continue;
				ts.insert(k, t);
				long hs=atoi(ts.c_str());
				if(!vis[hs]){
					moves.push_back(ts);
				}
			}
		}
	}
	return moves;
**/
/**
	//first, chop
	vector<string> segs;
	list<string> segl;
	int i=0;
	while(i<L){
		int j=i;
		while(j<L&&s[j]==s[i]+1){j++;}
		string t=s.substr(i,j-i);
		segs.push_back(t);
		segl.push_back(t);
		i=j;
	}
	int flag[segs.size()]={0};
	for(int i=1; i<L-1; i++){//starting position of the chunks
		string t="";
		for(int l=i;l<L-1;l++){//length
			for(int k=0;k<l;k++){
				t+=segs[i+k];
				flag[i+k]=1;
			}
			//now that get the chunk, insert it somewhere.
			string res="";
			for(int j=0;j<segs.size();j++){
				if(flag[j]==0&&(j==0||flag[j-1]==0)){
					
				}
				
			}
		}
		
	}
**/
}

bool ordered(vector<int> in){
/**
	int l=in.size()-1;
	long hs=0;
	for(int i=0;i<mL; i++){
		hs+=pp[9-mL+i]*in[i];
	}
	if(hs-ans[l]!=0)
		return false;
	else
		return true;
**/
	if(mL==1)
		return true;
	for(int i=1;i<mL;i++){
		if(in[i]!=in[i-1]+1)
			return false;
	}
	return true;
}
void print_moves(vector<vector<int> > moves){
	for(int i=0;i<moves.size();i++){
		vector<int> v=moves[i];
		for(int j=0;j<v.size();j++)
			cout<<v[j]<<" ";
		cout<<endl;
	}
}
int bfs(vector<int> start){
	queue<vector<int> > q;
	q.push(start);
//	vis.insert(std::pair<vector<int>,int>(start,0));
	visit(start,0);
	while(!q.empty()){
		vector<int> p=q.front();
		q.pop();
		if(ordered(p)){
			return visited(p);
		}
		int d=visited(p);
		vector<vector<int> > moves=expand(p,d);
//		cout<<"======";
//		print_moves(moves);
		for(int i=0; i<moves.size();i++){
			if(ordered(moves[i]))
				return visited(moves[i]);
			q.push(moves[i]);
		}
//		cout<<"=====\n";
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
		cout<<"Case "<<C<<": "<<bfs(in)<<endl;
		C++;
	}
	return 0;
}
