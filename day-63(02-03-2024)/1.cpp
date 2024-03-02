class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <long long, vector<long long>, greater<long long>> pq;
        for(auto i : nums)
            pq.push(i);
        int ans = 0;
        while(pq.size() > 1)
        {
            long long  a =pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            if(a >= k)
                return ans;
            ans++;
            pq.push(min(a,b)*2 + max(a,b));
                
        }
        return ans;
    }
};