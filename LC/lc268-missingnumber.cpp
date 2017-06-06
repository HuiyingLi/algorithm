#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& ns) {
		if(ns.size()==0)
			return 0;
		int i=0;
		int last=-1;
		while(i<ns.size()){
			if(ns[i]==-1){
				i++;
				continue;
			}
			if(ns[i]!=i){
				int tmp=(ns[i]==ns.size()?-1:ns[ns[i]]);
				ns[i]==ns.size()?last=ns[i]:ns[ns[i]]=ns[i];
				ns[i]=tmp;
			}else{
				i++;
			}
		}
		if(last==-1)
			return ns.size();
		for(int i=0;i<ns.size();i++)
			if(ns[i]==-1)
				return i;
		return -1;
    }
};
int main(){
	int arr[6]={6,1,0,3,4,2};
	vector<int> v(arr,arr+6);
	Solution s;
	cout<<s.missingNumber(v)<<endl;
	return 0;
}
