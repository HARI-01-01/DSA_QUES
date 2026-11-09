class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        int n = arrival.size();

        // {finish_time, server_id}
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> busy;

        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        vector<int> freq(k, 0);

        for (int i = 0; i < n; i++) {

            int time = arrival[i];

            // Release completed servers
            while (!busy.empty() && busy.top().first <= time) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // All servers busy
            if (available.empty()) continue;

            int preferred = i % k;

            // Find next available server
            auto it = available.lower_bound(preferred);

            // Circular wrapping
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            available.erase(it);

            freq[server]++;

            busy.push({time + load[i], server});
        }

        int maxi = *max_element(freq.begin(), freq.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (freq[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};