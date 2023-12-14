//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
   int binarySearch(vector<int> nums,int s, int e,int k){
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] == k) return mid;
            else if(nums[mid] > k) e = mid - 1;
            else s = mid + 1;
        }
        return -1;
    }
    int getPivot(vector<int> nums){
        int low = 0,high = nums.size()-1;
       
       while(low < high)
       {
           int mid = low+ (high-low)/2;
           if(nums[mid] >= nums[0]) low = mid+1;
           else   high = mid;
           
       }
       return low;
    }
    int Search(vector<int> vec, int target) {
    
     int pivot = getPivot(vec);
      int n = vec.size();
      if(target >= vec[pivot] && target <= vec[n-1])
        return binarySearch(vec,pivot,n-1,target);
      else
        return binarySearch(vec,0,pivot - 1,target); 
}