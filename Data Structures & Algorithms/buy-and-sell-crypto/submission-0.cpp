class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> max_p(n, 0);
        int max = 0;
        int prev = 0;
        for (int i = 0; i < prices.size(); i++) {
            int p = prices[n-i-1];
            if (prev > max) {
                max = prev;
            }
            max_p[n-i-1] = max;
            prev = p;
        }

        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            int p = max_p[i] - prices[i];
            if (p > ans) {
                ans = p;
            }
        }
        return ans;
    }
};
