class Solution {
public:
    vector<int> twoDifference(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // Map to store numbers and their indices
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // Check for both possible cases: nums[i] - target and nums[i] + target
            if (mp.find(nums[i] - target) != mp.end()) {
                ans.push_back(mp[nums[i] - target]);
                ans.push_back(i);
                return ans;
            }
            if (mp.find(nums[i] + target) != mp.end()) {
                ans.push_back(mp[nums[i] + target]);
                ans.push_back(i);
                return ans;
            }

            // Store the current number and its index
            mp[nums[i]] = i;
        }

        return ans; // Return empty vector if no pair is found
    }
};
