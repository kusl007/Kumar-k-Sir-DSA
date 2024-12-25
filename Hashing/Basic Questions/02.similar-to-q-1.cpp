// 3005. Count Elements With Maximum Frequency
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        int max_element=nums[0];
        for (auto i:nums){
            mp[i]++;
        }
        for(auto i:mp){
            if(i.second>maxi){
                max_element=i.first;
                maxi=i.second;
            }
        }
        int count=0;
        for (auto i:mp){
            if(i.second==maxi){
                count+=maxi;
            }
        }
        return count;
    }
};