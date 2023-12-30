// 1418. Display Table of Food Orders in a Restaurant
// https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/description/
class Solution {
public:
    static bool cmp(vector<string> &a,vector<string> &b)
    {
        return stoi(a[0]) < stoi(b[0]);
    }
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<string,unordered_map<string,int>> table;

        set<string> s;
        for(int i=0;i<orders.size();i++)
            s.insert(orders[i][2]);
        for(int i=0;i<orders.size();i++)
        {
            if(table.find((orders[i][1])) != table.end())
            {
                table[orders[i][1]][orders[i][2]]++;
            }
            else
            {
                unordered_map<string,int> m;
                m[orders[i][2]]++;
                table[orders[i][1]] = m ;
            }
        }
        vector<vector<string>> v;
          vector<string> z;
        z.push_back("Table");
        for(auto x : s)
            z.push_back(x);
        v.push_back(z);
        for(auto i: table)
        {
            int k = 0;
            vector<string> ans;
            ans.push_back(i.first);
            for(auto x : s)
            {
                ans.push_back(to_string(table[i.first][x]));
            }
            v.push_back(ans);
        }
        sort(v.begin()+1,v.end(),cmp);
        return v;
        

    }
};