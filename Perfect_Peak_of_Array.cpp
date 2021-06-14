/*
Perfect Peak of Array

    Asked in:  
    Flipkart

Problem Description
Given an integer array A of size N.
You need to check that whether there exist a element which is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it.
If it exists return 1 else return 0.

NOTE:
Do not consider the corner elements i.e A[0] and A[N-1] as the answer.

Problem Constraints
3 <= N <= 105
1 <= A[i] <= 109

Input Format
First and only argument is an integer array A containing N integers.

Output Format
Return 1 if there exist a element that is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it else return 0.

Example Input
Input 1:
 A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
Input 2:
 A = [5, 1, 4, 4]

Example Output
Output 1:
 1
Output 2:
 0

Example Explanation
Explanation 1:
 A[4] = 6 is the element we are looking for.
 All elements on left of A[4] are smaller than it and all elements on right are greater.

Explanation 2:
 No such element exits.

*/
//Algo: o(n)
//max = start element 
//condition 'con' to track if we are in the 1st part or the 2nd part of the condition 
//loop from 1 to A.size()-1 and keep a track of the max element
//we we get the corrent max max it as num and condition 'con' to true
//if all the numbers are 'strictly' greater then return 1 after handelling the last element.
//else reset con and continew loop 

int Solution::perfectPeak(vector<int> &A) 
{
  int max = A[0];
  int num;
  bool con = false;
  
  for(int i=1; i<A.size()-1; i++)
  {
    if(con == false)
    {
      if(max < A[i])
      {
          num = A[i];
          con = true;
      }
    }
    else
    {
      if(num >= A[i])
        con = false;
    }

    if(max < A[i])
      max = A[i];
  }

  if(con && num > A[A.size()-1])
    return 0;

  if(con)
    return 1;

  return 0;
}
