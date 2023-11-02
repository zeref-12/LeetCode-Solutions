//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector <int> ans;
        int rowbegin = 0, rowend = row - 1;
        int colbegin = 0, colend = col - 1;
        int count =0, total = row*col ;

        while(count < total)
        {
            for(int i = colbegin; count < total && i<=colend; i++)
            {
              ans.push_back(matrix[rowbegin][i]); count++;
            } rowbegin++;

            for(int i = rowbegin;count < total && i<= rowend; i++)
            {
               ans.push_back(matrix[i][colend]); count++;
            } colend--;

            for(int i = colend; count < total && i>= colbegin; i--)
            {
                ans.push_back(matrix[rowend][i]); count++;
            } rowend--;

            for( int i= rowend; count < total &&  i>= rowbegin ;i--)
            {
                ans.push_back(matrix[i][colbegin]); count++;
            } colbegin++;
        }
      return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends