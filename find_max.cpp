#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int max_current = nums[0];
    int max_global = nums[0];
    
    for (int i = 1; i < nums.size(); ++i) {
        max_current = max(nums[i], max_current + nums[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    
    return max_global;
}

int main() {
    // 示例
    vector<int> arr1 = {1, -2, 3, 5, -1};
    cout << maxSubArray(arr1) << endl;
    
    vector<int> arr2 = {1, -2, 3, -8, 5, 1};
    cout << maxSubArray(arr2) << endl;
    
    vector<int> arr3 = {1, -2, 3, -2, 5, 1};
    cout << maxSubArray(arr3) << endl;
    
    return 0;
}