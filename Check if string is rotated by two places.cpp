class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string s1, string s2)
    {
        // Your code here
        int n=s1.length();
        if(n==2) return s1==s2;
        for(int i=0;i<n;i++){
            if( s1[(i+2)%n]==s2[i] || s1[(n+i-2)%n]==s2[i] ) continue;
            else return false;
        }
        return true;
    }

};
