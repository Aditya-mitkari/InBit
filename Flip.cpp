/*
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

    Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.

For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].

*/

//////////// Notes //////////
/*
use the principle of kadane's algorithm
keep a sum, +1 when 0 and -1 when 1
when sum gets -ve reset sum and pointer 
*/

vector<int> Solution::flip(string A) 
{
  vector<int> ans;
  int sum = 0;
  int maxSum = INT_MIN;
  int left = 1;
  int right = 1;
  int maxLeft;
  int maxRight;

  for(int i=0; i<A.length(); i++)
  {
    if(A[i] == '1')
    {
      sum -= 1;
      if(sum < 0)
      {
        left = i+2;
        right = i+2;
        sum = 0;
      }
    }
    else
    {
      sum += 1;
      if(sum > maxSum)
      {
        maxSum = sum;
        right = i+1;
        maxLeft = left;
        maxRight = right;
      }
    }
  }

  if(maxSum > 0)
  {
    ans.push_back(maxLeft);
    ans.puhs_back(maxRight);
  }

  return ans;
}
