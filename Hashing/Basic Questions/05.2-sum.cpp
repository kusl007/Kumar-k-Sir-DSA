//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int>mp;
        vector<int>ans;
        for (int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                 ans.push_back(mp[nums[i]]);
                ans.push_back(i);
            }
            mp[target-nums[i]]=i;
        }
        return ans;

        
        
     
    }
};