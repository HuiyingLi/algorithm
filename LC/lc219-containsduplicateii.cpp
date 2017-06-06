#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> past;
        for(int i=0;i<nums.size();i++){
            if(i-k-1>=0){
                past.erase(nums[i-k-1]);
            }
            if(past.find(nums[i])!=past.end())
                return true;
            past.insert(nums[i]);
        }
        return false;
    }
};
