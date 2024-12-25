// https://www.geeksforgeeks.org/problems/kth-distance3757/1?itm_source=geeksforgeeks

class Solution {
  public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++) {
            // Check if the element exists in the map
            if (mp.find(arr[i]) != mp.end()) {
                // Check if the distance between indices is <= k
                if (i - mp[arr[i]] <= k) {
                    return true;
                }
            }
            // Update the index of the current element
            mp[arr[i]] = i;
        }

        return false;
    }
};