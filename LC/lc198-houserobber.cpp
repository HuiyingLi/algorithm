class Solution {

public:

    int rob(vector<int>& nums) {

        if(nums.size()==0)

            return 0;

        for(int i=0;i<nums.size();i++){

            if(i==0){

                continue;

            }

            if(i==1){

                nums[i]=(nums[i-1]>nums[i])?nums[i-1]:nums[i];

                continue;

            }

            nums[i]=(nums[i-1]>nums[i]+nums[i-2])?nums[i-1]:nums[i]+nums[i-2];

        }

        return nums[nums.size()-1];

    }

};
