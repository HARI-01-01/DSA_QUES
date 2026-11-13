class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // {maximum value, number of elements}
        deque<pair<int, int>> dq;

        long long cost = 0;
        long long ans = 0;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            int x = nums[i];
            int cnt = 1;

            // Merge blocks whose maximum is <= x
            while (!dq.empty() && dq.front().first <= x) {

                cost += 1LL * (x - dq.front().first)
                        * dq.front().second;

                cnt += dq.front().second;

                dq.pop_front();
            }

            dq.push_front({x, cnt});

            // Reduce window until cost <= k
            while (cost > k) {

                cost -= dq.back().first - nums[j];

                dq.back().second--;

                if (dq.back().second == 0) {
                    dq.pop_back();
                }

                j--;
            }

            // All subarrays [i ... i], [i ... i+1] ... [i ... j]
            ans += (j - i + 1);
        }

        return ans;
    }
};