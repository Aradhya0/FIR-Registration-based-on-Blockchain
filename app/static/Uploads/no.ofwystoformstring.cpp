class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = target.size(),m = words[0].size(),MOD=1e9+7;
        vector<long> dp(m+1,1);
        vector<vector<int>> letterCount(m,vector<int>(26,0));
        // Counting letter count for each column
        for(int i=0;i<words.size();i++){
            for(int j=0;j<m;j++){
                int c = words[i][j]-'a';
                letterCount[j][c]++;
            }
        }
        // filling dp as per above formula
        for(int i=0;i<n;i++){
            vector<long> temp(m+1,0); //temp dp for next level
            int curr = target[i]-'a';
            for(int j=1;j<=m;j++){
                temp[j]=(temp[j-1]+(letterCount[j-1][curr]*dp[j-1]))%MOD;
            }
            dp = temp;
        }
        return dp[m];
    }
};
