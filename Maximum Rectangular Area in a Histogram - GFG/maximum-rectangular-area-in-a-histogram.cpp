//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> prev(n),next(n);
        stack<int> s;
        for(int i =0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
            prev[i] = s.empty()? -1 : s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        long long area = 0;
        for(int i =0;i<n;i++)
        {
            long long l = arr[i];
            if(next[i] == -1) next[i] == n;
            long long b = next[i] - prev[i] -1;
            
            area = max(area,l*b);
        }
     return area;    
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends