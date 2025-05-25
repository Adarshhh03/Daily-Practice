class Solution {
public:
//Intuition 
// Step 1)FInd the first smaller number from the back,i.e breakng point which has chances of giving next permutation
// Step 2)Now find first next greater element than it from the right and swap them.
// Step 3)Reverse the part next to the breaking point as it the biggest part now for the new left side after swapping
   vector<int> nextPermutation (vector<int> &A) {
              int ind = -1;
         int n = A.size();
         for(int i = n - 2;i>=0; i--) { 
            if(A[i] < A[i+1]) {
            ind = i; 
            break;
            }
   }
    if(ind == -1){
         reverse(A.begin(), A.end()); 
         return A;
   }
       for(int i = n-1;i>ind; i--) { 
              if(A[i]>A[ind]) { 
                     swap(A[i], A[ind]); 
                     break;
              }
        }
    reverse(A.begin()+ind+ 1, A.end()); 
    return A;
    }
};