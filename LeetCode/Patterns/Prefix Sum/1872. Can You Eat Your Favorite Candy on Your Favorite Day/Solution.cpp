class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> prefixSum(n);
        prefixSum[0] = candiesCount[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + candiesCount[i];
        }
        
        vector<bool> ans;
        for (const auto& query : queries) {
            long long favCandy = query[0];
            long long favDay = query[1];
            long long dailyCap = query[2];
            
         
            long long minCandiesBefore = favDay; 
            
            long long maxCandiesIncluding = (favDay + 1) * dailyCap;
            
      
            long long prevCandiesSum = (favCandy == 0) ? 0 : prefixSum[favCandy - 1];
            long long totalCandies = prefixSum[favCandy];
            
            bool canEatFav = (maxCandiesIncluding > prevCandiesSum) && (minCandiesBefore < totalCandies);
            
            ans.push_back(canEatFav);
        }
        return ans;
    }
};
