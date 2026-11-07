class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        // Available: {weight, index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > available;

        // Busy: {finishTime, weight, index}
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > busy;

        // Initially, all servers are available
        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);

        long long t = 0;

        for(int i = 0; i < m; i++) {

            // Task i arrives at time i
            t = max(t, (long long)i);

            // Release all servers that have finished
            while(!busy.empty() && get<0>(busy.top()) <= t) {

                auto [finish, weight, idx] = busy.top();
                busy.pop();

                available.push({weight, idx});
            }

            // If no server is available, jump to earliest finish time
            if(available.empty()) {

                t = get<0>(busy.top());

                while(!busy.empty() && get<0>(busy.top()) <= t) {

                    auto [finish, weight, idx] = busy.top();
                    busy.pop();

                    available.push({weight, idx});
                }
            }

            // Select the best available server
            auto [weight, idx] = available.top();
            available.pop();

            ans[i] = idx;

            // Mark server as busy
            busy.push({
                t + tasks[i],
                weight,
                idx
            });
        }

        return ans;
    }
};