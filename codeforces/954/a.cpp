#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int main(){
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		vector<int> nums(3);
		cin>>nums[0];
		cin>>nums[1];
		cin>>nums[2];

		sort(nums.begin(), nums.end());
		int a = nums[1];

		cout<<abs(a-nums[0])+abs(a-nums[1])+abs(a-nums[2])<<endl;
	}

	return 0;
}