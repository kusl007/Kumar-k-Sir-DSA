#include <bits/stdc++.h>
using namespace std;

bool boolConsecutiveTriplets(vector<int> nums){
	int n = nums.size();

	map<int, int> prefix;
	map<int, int> suffix;
	
	for(int i=1;i<=n;i++){
	    suffix[nums[i]]++;
	}
	
	for(int i = 2; i <= n-1; i++){
	    
	    suffix[nums[i]]--;
	    
		if(prefix.find(nums[i]-1) != prefix.end() and suffix.find(nums[i]+1) != suffix.end())
		return true;
		
	    prefix[nums[i]]++;
	}

	return false;
}

int main()
{
	int n;
	cin>>n;

	vector<int> nums(n+1);

	for(int index = 1; index <= n; index++){
		cin>>nums[index];
	}

	cout << boolConsecutiveTriplets(nums);

	return 0;
}