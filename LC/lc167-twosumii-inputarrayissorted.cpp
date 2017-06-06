class Solution {

public:

    vector<int> twoSum(vector<int>& n, int target) {

        vector<int> ans;

        int r=n.size()-1;

        int l=0;

        while(l<r){

            if(n[l]+n[r]<target){

                l++;

            }else if(n[l]+n[r]>target){

                r--;

            }else if(n[l]+n[r]==target){

                ans.push_back(l+1);

                ans.push_back(r+1);

                return ans;

            }

        }

        return ans;

    }

};
