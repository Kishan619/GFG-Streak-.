class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	     const long long mod = 1e9 + 7;
	    vector<vector<long long>> dp(N + 1, vector<long long> (2, 1));
	    
	    for(int i = N - 1; i > -1; i--){
	        dp[i][1] = dp[i + 1][0];
	        
	        int work, nowork;
	        work = dp[i + 1][1];
	        nowork = dp[i + 1][0];
	        
	        dp[i][0] = (work + nowork) % mod;
	    }
	    
	    return (dp[0][0] * dp[0][0]) % mod;
	}
};
