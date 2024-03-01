// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second<b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto i : arr)
            m[i]++;
        vector<pair<int,int>> v;
        for(auto i : m)
        {
            // cout<<i.first<<" "<<i.second<<endl;
            v.push_back(i);
        }
        sort(v.begin(),v.end(),cmp);
        // for(auto i : v)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        //     v.push_back(i);
        // }
        int cnt = 0;
        for(auto i : v)
        {
            if(i.second > k)
                break;
            else
            {
                k-=i.second;
                cnt++;
            }
        }
        cout<<"cnt = "<<cnt<<endl;
        return v.size()-cnt;
    }
};