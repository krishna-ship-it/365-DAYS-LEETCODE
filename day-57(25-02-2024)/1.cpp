class MakeFactors {
    public:
    vector<int> getFactors(int n){
        vector<int> temp;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                temp.push_back(i);
                while(n % i == 0)
                    n /= i;
            }
        }
        if(n != 1)
            temp.push_back(n);
        return temp;
    }
};
class Graph{
    vector<vector<int>> adjMat;
    int s;
public:
    Graph(int n){
        s = n;
        adjMat.resize(n);
    }

    void makeEdge(int e, int d){
        adjMat[e].push_back(d);
        adjMat[d].push_back(e);
    }

    bool checkForComponents(){
        vector<int> visit(s, false);
        queue<int> que;
        que.push(0);
        visit[0] = true;
        while(!que.empty()){
            int t = que.front();
            que.pop();
            for(int i = 0; i < adjMat[t].size(); i++){
                if(visit[adjMat[t][i]] == false){
                    que.push(adjMat[t][i]);
                    visit[adjMat[t][i]] = true;
                }
            }
        }
        int i = 0;
        while(i < s){
            if(visit[i] == false)
                return false;
            i++;
        }
        return true;
    }

};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        unordered_map<int, int> factorIndexMap;
        MakeFactors factObj;
        Graph gObj(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                return false;
            vector<int> factors = factObj.getFactors(nums[i]);
            for(int f : factors){
                if(factorIndexMap.count(f) > 0)
                    gObj.makeEdge(i, factorIndexMap[f]);
                else
                    factorIndexMap[f] = i;
            }
        }
        return gObj.checkForComponents();
    }
};