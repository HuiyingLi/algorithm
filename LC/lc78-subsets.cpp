#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	vector<vector<int> >ans;
	vector<int> res;
	vector<int> n;
	void dfs(int d){
		if(d==n.size()){
			ans.push_back(res);
			return;
		}
		
	
		res.push_back(n[d]);
		dfs(d+1);
		res.pop_back();
			
		dfs(d+1);
	
	}
    vector<vector<int> > subsets(vector<int>& nums) {
        
		n=nums;
		ans.clear();
		res.clear();
		if(nums.size()==0){
            ans.push_back(res);
            return ans;
		}
		dfs(0);
		return ans;
    }
};
int main(){
	int arr[3]={1,2,3};
	vector<int> v(arr, arr+3);
	Solution s;
	s.subsets(v);
	return 0;}
