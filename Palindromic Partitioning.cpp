class Solution{
public:
bool generatePalindrome(string& s,
                        vector<vector<bool> >& pal)
{
    int n = s.size();
 
    // Initialize the palindrome matrix for single
    // characters
    for (int i = 0; i < n; i++) {
        pal[i][i] = true;
    }
 
    // Iterate over different lengths of substrings
    for (int len = 2; len <= n; len++) {
        // Iterate over the starting positions of substrings
        // of current length
        for (int i = 0; i <= n - len; i++) {
 
            // Calculate the ending position of the
            // substring
            int j = i + len - 1;
 
            // Check if the characters at the starting and
            // ending positions are equal and if the
            // substring between them is a palindrome or a
            // single character
            if (s[i] == s[j]
                && (len == 2 || pal[i + 1][j - 1])) {
 
                // Mark the substring from i to j as a
                // palindrome
                pal[i][j] = true;
            }
        }
    }
}
   int palindromicPartition(string s)
{
    if (s.empty())
        return 0;
    int n = s.size();
 
    // 2D vector to store whether substring [i, j] is a
    // palindrome
    vector<vector<bool> > pal(n, vector<bool>(n, false));
 
    generatePalindrome(s, pal);
 
    // vector to store minimum cuts required to make
    // substring [i, n-1] palindromic
    vector<int> palindromicPartition(n, INT_MAX);
 
    // There is no cut required for single character
    // as it is always palindrome
   palindromicPartition[0] = 0;
 
    // Iterate over the given string
    for (int i = 1; i < n; i++) {
 
        // Check if string 0 to i is palindrome.
        // Then minCut require will be 0.
        if (pal[0][i]) {
           palindromicPartition[i] = 0;
        }
        else {
            for (int j = i; j >= 1; j--) {
 
                // If s[i] and s[j] are equal and the inner
                // substring [i+1, j-1] is a palindrome or
                // it has a length of 1
                if (pal[j][i]) {
 
                    // Update the minimum cuts required if
                    // cutting at position 'j+1' results in
                    // a smaller value
                    if (palindromicPartition[j - 1] + 1 < palindromicPartition[i])
                        palindromicPartition[i] = palindromicPartition[j - 1] + 1;
                }
            }
        }
    }
 
    // Return the minimum cuts required for the entire
    // string 's'
    return palindromicPartition[n - 1];
} 
};
