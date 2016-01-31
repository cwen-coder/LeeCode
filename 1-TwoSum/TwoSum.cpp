/*************************************************************************
	> File Name: TwoSum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月31日 星期日 18时28分45秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> twoSum(vector<int> &nums,int target) {
    vector<int> res;
    int len = nums.size();
    map<int,int> mp;
    int find;
    for(int i = 0; i < len; i++) {
        find = mp[target - nums[i]];
        if(find) {
            res.push_back(find);
            res.push_back(i+1);
            break;
        }
        mp[nums[i]] = i+1;
    }
    return res;
}

int main() {
    int C[] = {1,3,5,1};
    vector<int> num;
    for(int i = 0; i < 4; i++) {
        num.push_back(C[i]);
    }
    vector<int> result = twoSum(num,2);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
