#include<iostream>
#include<vector>
#define INT_MAX 2147483647
using namespace std;
class Solution {
public:
    int e1, e2;
    vector<int> n1;
    vector<int> n2;
    int find(int k, int s1, int s2){
        int p=k/2;
        int v1=INT_MAX, v2=INT_MAX;
        if(k==1){
			if(s1<e1)
				v1=n1[s1];
			if(s2<e2)
				v2=n2[s2];
            return min(v1,v2);
		}
		int d1=p,d2=p;
        if(s1+p<=e1){
            v1=n1[s1+p-1];
        }else {
			if(s1<e1){
				v1=n1[e1-1];
				d1=e1-s1;
			}else
				d1=0;
		}
        if(s2+p<=e2){
            v2=n2[s2+p-1];
		}else{
			if(s2<e2){
				v2=n2[e2-1];
				d2=e2-s2;
			}else
				d2=0;
		}
        if(v1<v2){
            return find(k-d1,s1+p,s2);
        }else if(v1>v2){
            return find(k-d2,s1,s2+p);
        }else{
            if(d1+d2==k) return v1;
            return find(k-d1-d2,s1+p,s2+p);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1;
        n2=nums2;
        e1=nums1.size();
        e2=nums2.size();
        int k=(e1+e2+1)/2;
        int m1=find(k,0,0);
        double ans=m1;
        cout<<m1<<endl;
        if((e1+e2)%2==0){
            int m2=find(k+1,0,0);
            cout<<m2<<endl;
            ans=(m1+m2)/2.0;
        }
        if(m1==42){
            cout<<"[";
            for(int i=0;i<e1;i++)
                cout<<n1[i]<<",";
            cout<<"]"<<endl<<"[";
            for(int i=0;i<e2;i++)
                cout<<n2[i]<<",";
            cout<<"]"<<endl;
        }
        return ans;
    }
};
int main(){
	int a1[4]={1,15,27,42};
	int a2[20]={11,12,19,28,33,39,40,42,49,50,57,58,73,77,86,90,93,94,95,98};
	vector<int> v1(a1,a1+4);
	vector<int> v2(a2,a2+20);
	Solution s;
	cout<<"ans:"<<s.findMedianSortedArrays(v1,v2)<<endl;
	return 0;
}
