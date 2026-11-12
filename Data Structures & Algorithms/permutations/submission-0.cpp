class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        set<int> nums_set(nums.begin(), nums.end());
        vector<int> base;
        return permute_rec(base, nums_set);
    }

    vector<vector<int>> permute_rec(vector<int>& base_nums, set<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 1) {
            set<int> numsc(nums.begin(), nums.end());
            vector<int> base_numsc(base_nums.begin(), base_nums.end());
            int num = *nums.begin();
            base_numsc.push_back(num);
            ans.push_back(base_numsc);
            return ans;
        } else {
            for (auto num : nums) {
                set<int> numsc(nums);
                vector<int> base_numsc(base_nums.begin(), base_nums.end());
                numsc.extract(num);
                base_numsc.push_back(num);
                for (auto sol : permute_rec(base_numsc, numsc)) {
                    ans.push_back(sol);
                }
            }
            return ans;
        }
    }
};
