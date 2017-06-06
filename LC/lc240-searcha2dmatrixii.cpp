#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
		vector<int> row=matrix[0];
		int l=0, r=row.size();
		int mid;
		while(l<r){
			mid=l+(r-l)/2;
			if(row[mid]==target)
				return true;
			if(row[mid]<target){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		int endc=mid;
		l=0; r=matrix.size();
		while(l<r){
			mid=l+(r-l)/2;
			if(matrix[mid][0]==target){
				return true;
			}
			if(matrix[mid][0]<target){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		int endr=mid;
		for(int i=0;i<=endr;i++){
			vector<int> v=matrix[i];
			l=0;
			r=endc+1;
			while(l<r){
				mid=l+(r-l)/2;
				if(v[mid]==target)
					return true;
				if(v[mid]<target)
					l=mid+1;
				else
					r=mid;
			}
		}
		return false;
    }

};
int main(){return 0;}
