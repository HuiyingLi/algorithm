#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int ss=0;
		int ispos=nums[0]>=0?1:0;
		vector<int> simp;
		for(int i=0;i<nums.size(); i++){
			if(ispos&&nums[i]<0||((!ispos)&&nums[i]>=0)){
				simp.push_back(ss);
				ss=0;
				ispos=nums[i]>=0?1:0;
			}
			ss+=nums[i];
		}
		simp.push_back(ss);
		int l=-1;
		int r=-1;
		int sum=0;
		int maxsum=-65534;
		int conti=0;
		for(int i=0;i<simp.size();i++){
			if(simp[i]>=0){
				if(i+1<simp.size()&&simp[i]>=-1*simp[i+1]){//can be left
					l=1;
				}else if(i+1<simp.size()&&simp[i]<-1*simp[i+1]){
					l=-1;
				}
				if(i-1>=0&&simp[i]>=-1*simp[i-1]){//can be right
					r=1;
				}else if(i-1>=0&&simp[i]<-1*simp[i-1]){
					r=-1;
				}
				if(l==-1&&r==-1){
					if(sum>maxsum)
						maxsum=sum;
					if(simp[i]>maxsum)
						maxsum=simp[i];
					sum=0;
				}else if(l==1&&r==-1){
					if(sum>maxsum)
						maxsum=sum;
					sum=simp[i];
					conti=1;
				}else if(l==-1&&r==1){
					sum+=simp[i];
					if(conti)
						sum+=simp[i-1];
				}else if(l==1&&r==1){
					sum+=simp[i];
					if(conti)
						sum+=simp[i-1];
				}
			}
		}
		if(sum>maxsum)
			maxsum=sum;
		return maxsum;
    }
};
int main(){
	string line;
	Solution s;
	ifstream f("testgen_lc53.in");
	while(getline(f,line)){
		line=line.substr(1,line.length()-2);
		for(int i=0;i<line.length();i++){
			if(line[i]==',')
				line[i]=' ';
		}
		stringstream ss(line);
		int n;
		vector<int> num;
		for(int i=0;i<15;i++){
			ss>>n;
			num.push_back(n);
		}
		cout<<s.maxSubArray(num)<<endl;
	}
	return 0;
}
