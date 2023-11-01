class Solution{
    //Function to count the frequency of all elements from 1 to N in the array.
    public static void frequencyCount(int arr[], int N, int P)
    {
       HashMap<Integer,Integer>frequencyMap = new HashMap<>();
        
        for(int i=0;i<N;i++){
            if(arr[i] >= 1 && arr[i] <=N){
                frequencyMap.put(arr[i],frequencyMap.getOrDefault(arr[i],0)+1);
            }
        }
        
        for(int i=1;i<=N;i++){
            arr[i-1] = frequencyMap.getOrDefault(i,0);
        }     
    }
}
