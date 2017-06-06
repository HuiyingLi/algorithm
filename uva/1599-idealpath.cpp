#include<iostream>
#include<sstream>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std;

class mypair{
	public:
	long b;
	long c;
	mypair(long b, long c){
		this->b=b;
		this->c=c;
	}
};


long m,n;
long dist[100001];
//int G[100001][100001];
map<long,vector<mypair> > G;

/*
long bfs(){
	memset(dist,-1,sizeof(dist));
	queue<long> q;
	q.push(n);
	long d=-1;
	bool found=false;
	map<long,vector<mypair> >::iterator it;
	//get all connections
	while(q.size()>0){
		d++;
		long qsize=q.size();
		for(long k=0;k<qsize;k++){
			long rm=q.front();
			q.pop();
			dist[rm]=d;
			if((it=G.find(rm))!=G.end()){
				vector<mypair> l=it->second;
				set<long> sl;
				for(long i=0;i<l.size();i++){
					mypair p=l[i];
					if(p.b==1){
						found=true;
	//					dist[1]=d;
					}
					if(dist[p.b]==-1||d<dist[p.b])
						sl.insert(p.b);
				}
				for(set<long>::iterator it=sl.begin();it!=sl.end();it++){ q.push(*it);}
			}
		}
	}
	return d;
}
*/

long rbfs(){
	memset(dist, -1,sizeof(dist));
	vector<long>q;
	q.push_back(n);
	long d=-1;
	bool found=false;
	map<long, vector<mypair> >::iterator it;
	while(q.size()>0){
		d++;
		//process current nodes in queue
		for(long k=0;k<q.size();k++){
			long rm=q[k];
			dist[rm]=d;
			if(rm==1){
				found=true;
			}
		}
		if(found)
			break;
		//find all the connections
		vector<long>nq;
		set<long>sl;
		for(long k=0; k<q.size();k++){
			long rm=q[k];
			if((it=G.find(rm))!=G.end()){
				vector<mypair> l=it->second;
				for(long i=0;i<l.size();i++){
					mypair p=l[i];
					if(dist[p.b]==-1||d+1<dist[p.b]){
						sl.insert(p.b);
					}
				}
			}
		}
		for(set<long>::iterator it=sl.begin();it!=sl.end();it++) nq.push_back(*it);
		q=nq;
	}
	return d;
}

/*
vector<long> bfs2(long d){
	map<long, vector<long> > ii;
	for(long i=0; i<100001; i++){
		if(dist[i]!=-1){
			ii[dist[i]].push_back(i);
		}
	}
	vector<long> path;
	path.push_back(1);
	vector<long> color;
	for(long i=1;i<=d;i++){
		long min=10000000000;
		long minrm=-1;
		vector<long>rl = ii.find(d-i)->second;
		for(long j=1;j<rl.size();j++)i{//for each node whose dist to n is d-i.
			long b=rl[j];
			long c=-1;
			vector<mypair> pl=G.find(path.back())->second;
			for(long k=0;k<pl.size();k++){
				if(pl[k].b==b){
					c=pl[k].c;	
					break;
				}
			}
			if(c!=-1&&c<min){
				min=c;
				minrm=b;
			}
		}
		color.push_back(min);
		path.push_back(minrm);
	}
	return color;
}*/
vector<long> bfs(long d){
	vector<long>q;
	q.push_back(1);
	vector<long>color;
	int cnt=0;
	while(cnt<d){
		cnt++;
		//find all the connections
		vector<long> nq;
		long minc=10000000000;
		long minrm=-1;
		for(int i=0;i<q.size();i++){
			vector<mypair> pl=G.find(q[i])->second;
			for(int j=0;j<pl.size();j++){//for each connected rm
				mypair p=pl[j];
				if(dist[p.b]==d-cnt){//if its distance to n is d-cnt
					if(p.c!=-1&&p.c<minc){
						nq.clear();
						minc=p.c;
						minrm=p.b;
						nq.push_back(p.b);
					}else if(p.c!=-1&&p.c==minc){
						nq.push_back(p.b);
					}
				}
			}
		}
		color.push_back(minc);
		q=nq;
	}
	return color;	
}
int main(){
	string line;
	while(getline(cin, line)){
		stringstream ss(line);
		ss>>n;
		ss>>m;
		for(long i=0;i<m;i++){
			getline(cin,line);
			stringstream sss(line);
			long a,b,c;
			sss>>a;
			sss>>b;
			sss>>c;
			G[a].push_back(mypair(b,c));
			G[b].push_back(mypair(a,c));
		}
		vector<long> color=bfs(rbfs());
		for(int i=0;i<color.size();i++)cout<<color[i]<<" ";
	}
}
