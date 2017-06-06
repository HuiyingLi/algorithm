#include<iostream>
#include<vector>

using namespace std;
class Solution{
public:
	vector<int> n;
	int z,t,o;
	void moveall(){
		while(n[z]==0){
			z++;
		}
		while(n[t]==2)
			t--;
		o=t;
		while(n[o]==1)
			o--;
	}
	void swap(int i, int j){
		int tmp=n[i];
		n[i]=n[j];
		n[j]=tmp;
	}
	void sortColors(vector<int>&nums){
		this->n=nums;
		z=0; 
		o=n.size()-1;
		t=n.size()-1;
		moveall();
		while(n[o]==2){
		    swap(o,t);
			moveall();
		}
		while(z<o){
		    
			if(n[z]==2){
				swap(z,t);
				moveall();
				if(z>o) 
					break;
			}
			if(n[z]==1){
				swap(z,o);
				moveall();
				if(z>o)
					break;
			}
			while(n[o]==2){
				swap(o,t);
				moveall();
				if(z>o)
					break;
			}
			while(n[o]==2){
				swap(o,t);
				moveall();
			}
			moveall();
		}
		nums=n;
		for(int i=0;i<n.size()-1;i++){
		    if(nums[i]>nums[i+1]){
		        cout<<"[";
		        for(int j=0;j<nums.size();j++)
		            cout<<nums[j]<<",";
		        cout<<"]"<<endl;
		        break;
		    }
		}
	}
};
int main(){
	int arr[5]={0,2,1,2,2};
	vector<int> v(arr,arr+5);
	Solution s;
	s.sortColors(v);
	
	return 0;}
