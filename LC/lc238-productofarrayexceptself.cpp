#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	vector<long> productExceptSelf(vector<int>& n){
		vector<long> ans;
			
		for(int i=0;i<n.size();i++){
			if(i==0){
				ans.push_back(1);
				continue;
			}
			ans.push_back(ans[i-1]*n[i-1]);
		}
		long p=1;
		for(int i=n.size()-1;i>=0;i--){
			ans[i]*=p;
			p*=n[i];
		}
		return ans;
	}
};

int main(){return 0;}
