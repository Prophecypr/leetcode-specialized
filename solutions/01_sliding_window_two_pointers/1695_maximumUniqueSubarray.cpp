/*
 * 1695. Maximum Erasure Value
 * 不定长滑动窗口 · 求最长/最大（基础）
 *
 * 思路：
 *   求无重复元素子数组的最大和。用 unordered_set 维护窗口内的元素。
 *   当窗口中已有重复元素（st.contains(x)），收缩左边界直到无重复。
 *   更新 ans = max(ans, sum)。
 *
 * 用 set 不用 map：
 *   本题不关心每个元素的出现次数，只关心是否出现过。
 *   unordered_set 更简洁，contains() 是 C++20 方法。
 *
 * 复杂度：
 *   时间 O(n) 空间 O(n)
 */

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int ans = 0, sum = 0, left = 0;

        for (int x : nums) {
            // 重复出现 → 收缩左边界直到 remove x
            while (st.contains(x)) {
                st.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            st.insert(x);
            sum += x;
            ans = max(ans, sum);
        }

        return ans;
    }
};
