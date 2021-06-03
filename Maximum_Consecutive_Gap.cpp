/*
Maximum Consecutive Gap

    Asked in:  
    Hunan Asset

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 

Return 0 if the array contains less than 2 elements.

    You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
    You may also assume that the difference will not overflow.

*/

// trival methiod 1: nlog(n)
//sort the array and find the max diff. successive elements

int Solution::maximumGap(const vector<int> &A) 
{
  if(A.size() < 2)
    return 0;
    
  vector<int> arr = A;
  int maxGap = 0;
  sort(arr.being(), arr.end());

  for(int i=1; i<arr.size(); i++)
  {
    maxGap = std::max(maxGap, arr[i]-arr[i-1]);
  } 

  return maxGap; 
}
//-------------------------------------------------------------------------------------------------------------------

// Best method : linear space and time compliexity 
//algo:
//find max and min value 
//find avg. gap, max-min/no. of intervals
//create buckets of avg. gap size (no. of buckets = no. elements)
//insert elements into bucket by finding where they lie, using A[i]-min/gap
//note: dont insert max and min values
//compare the max and min elements of the successive buckets (handle the min and max values)
//max of the above is the res.



int Solution::maximumGap(const vector<int> &A)
{
  //if only one element is there in the list
  if(A.size() < 2)
    return 0;

  //find max and min in A  
  int max = -1;
  int min = INT_MAX;
  
  for(int i=0; i<A.size(); i++)
  {
    max = std::max(max, A[i]);
    min = std::min(min, A[i]);
  }
  // all elements are same
  if(max == min)
    return 0;

  int gap = ceil(float(max-min)/(A.size()-1.0));

  int maxBucket[A.size()];
  int minBucket[A.size()];

  n_fill(maxBucket, A.size(), -1);
  n_fill(minBucket, A.size(), INT_MAX);

  //putting elements in bucket
  for(int i=0; i<A.size(); i++)
  {
    if(A[i] == min || A[i] == max)
      continue;

    int index = ceil(float(A[i]-min)/gap);

    maxBucket[index] = std::max(maxBucket[index], A[i]);
    minBucket[index] = std::min(minBucket[index], A[i]);
  }

  //find max interval
  int prev = min;
  int maxGap = 0;
  
  for(int i=0; i<A.size(); i++)
  {
    if(maxBucket[i] != -1 )
    {
      maxGap = std::max(maxGap, minBucket[i]-prev);
      prev = maxBucket[i];
    }
  }
  maxGap = std::max(maxGap, max-prev);

  return maxGap;
  
}
