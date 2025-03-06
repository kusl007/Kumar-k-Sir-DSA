class Solution {
    public:
         vector<int> twoSum(vector<int>& nums, int target) {
           // we will use a pair 
           // we want indices as outputs so when we sort the vector to apply 2 pointer approach
           // The original indices are lost so we make use of vector of pair 
           // in each pair we store nums[i],i
           vector<pair<int,int>> vec;
           int n = nums.size();
           for(int i = 0;i<nums.size();i++)
           {
               vec.push_back({nums[i],i});
           }
           sort(vec.begin(),vec.end());
           int i = 0;
           int j = n-1;
           while(i<j)
           {
               int sum = vec[i].first + vec[j].first;
               if(sum==target)
               {
                   return {vec[i].second,vec[j].second};
               }
               else if(sum<target)
               {
                   i++;
               }
               else{
                   j--;
               }
           }
        return {-1,-1};   
        }
    };