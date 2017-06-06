#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int l=0, r=height.size()-1;
		int ma=0;
		while(l<r){
			if(height[l]<height[r]){
				int h=height[l];
				int area=h*(r-l);
				if(area>ma){
					ma=area;
				}
				while(l+1<height.size()&&height[l+1]<height[l]) 
					l++;
				l++;
			}else{
				int h=height[r];
				int area=h*(r-l);
				if(area>ma)
					ma=area;
				while(r-1>=0&&height[r-1]<height[r])
					r--;
				r--;
			}
		}
		return ma;
    }
};
int main(){
	int arr[7]={1,5,3,7,4,6,3};
	vector<int> in(arr, arr+7);
	Solution s;
	cout<<s.maxArea(in)<<endl;
	return 0;
}
