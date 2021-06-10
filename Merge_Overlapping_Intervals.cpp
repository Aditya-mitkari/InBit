/*
Merge Overlapping Intervals

    Asked in:  
    Google
    Amazon

Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

*/
/*
Algo:
1. Sort the vector based on the 1st element of the interval
2. maintian a Interval temp and create a return vector res
3. init temp with A[0]
4. if temp.end > A[i].start and temp.end < A[i].end then temp.end = A[i].end
5. if temp.end < A[i].start push temp in res
*/

int mySort(Interval a, Interval b)
{
  if(a.start > b.start)
    return 0;
  else
    return 1;
}

vector<Interval> Solution::merge(vector<Interval> &A) 
{
  sort(A.begin(), A.end(), mySort);

  vector<Interval> res;

  Interval temp;
  temp.start = A[0].start;
  temp.end = A[0].end;

  for(int i=1; i<A.size(); i++)
  {
    if(temp.end < A[i].start)
    {
      res.push_back(temp);
      temp.start = A[i].start;
      temp.end = A[i].end;
    }
    else if(temp.end >= A[i].start && temp.end < A[i].end)
    {
      temp.end = A[i].end;
    }
  }

  res.push_back(temp);
  
  return res;
}
