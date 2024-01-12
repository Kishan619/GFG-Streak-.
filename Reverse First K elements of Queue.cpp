class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> st;
        for(int i=0;i<k;i++){
            st.push(q.front());
            q.pop();
        }
        int temp = q.size();
        while(st.size()){
            q.push(st.top());
            st.pop();
        }
        while(temp--){
            int a = q.front();
            q.pop();
            q.push(a);
        }
        return q;
        // add code here.
    }
};
