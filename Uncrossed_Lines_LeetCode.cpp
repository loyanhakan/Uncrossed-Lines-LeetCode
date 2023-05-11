using namespace std;
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int a = nums1.size();
        int b = nums2.size();

        vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

        for( int i = 1; i <= a; i++)
        {
            for( int j = 1; j <= b; j++)
            {
                if( nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[a][b];
    }
};
