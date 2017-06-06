#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
	int vis[10000];
	vector<vector<int> > res;
	vector<int> l;
	vector<int> nums;
	unordered_set<string> t;
	int sum;
	void dfs(int d, int sum, int j){
		if(d==3){
			if(sum==0){
				vector<int> ol;
				for(int i=0;i<3;i++)
					ol.push_back(l[i]);
				sort(ol.begin(),ol.end());
				string tp=to_string(ol[0])+","+to_string(ol[1])+","+to_string(ol[2]);
				if(t.find(tp)==t.end()){
					t.insert(tp);
					res.push_back(l);
				}
			}
			return;
		}
		for(int i=j+1;i<nums.size();i++){
			if(!vis[i]){
				vis[i]=1;
				sum+=nums[i];
				l.push_back(nums[i]);
				dfs(d+1, sum, i);
				sum-=nums[i];
				vis[i]=0;
				l.pop_back();
			}
		}
		return;
	}
	void nsq(){
		for(int i=0;i<=nums.size()-3&&nums[i]<=0;i++){
			int m=-1*nums[i];
			int l=i+1, r=nums.size()-1;
			while(l<r){
				int s=nums[l]+nums[r];
				if(nums[r]<=m){
					if(s<m){
						l++;
					}else if(s>m){
						r--;
					}else if(s==m){
						vector<int> ans;
						ans.push_back(-m);
						ans.push_back(nums[l]);
						ans.push_back(nums[r]);
						res.push_back(ans);
						while(l<nums.size()-1&&nums[l+1]==nums[l])
							l++;
						while(r>0&&nums[r-1]==nums[r]) 
							r--;
						l++;
						r--;
					}
				}else{
					if(s<m){
						l++;
					}else if(s>m){
						r--;
					}else if(s==m){
						vector<int>ans;
						ans.push_back(-m);
						ans.push_back(nums[l]);
						ans.push_back(nums[r]);
						res.push_back(ans);
						while(l<nums.size()-1&&nums[l+1]==nums[l])
							l++;
						while(r>0&&nums[r-1]==nums[r])
							r--;
						l++;
						r--;
					}
				}
			}
			while(nums[i+1]==nums[i])
				i++;

		}
	}
    vector<vector<int> > threeSum(vector<int>& nums) {
		if(nums.size()==0)
			return res;
		sum=0;
		res.clear();
		l.clear();
		t.clear();
		sort(nums.begin(),nums.end());
		this->nums=nums;
		nsq();
		return res;
    }
};
int main(){
	int arr[9]={-4,-3,-1,0,1,1,2,2,3};
	vector<int> in(arr, arr+9);
	Solution s;
	s.threeSum(in);
	return 0;}
