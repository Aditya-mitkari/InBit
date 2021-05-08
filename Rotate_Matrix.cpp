/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]

Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]
*/

void swap(vector<vector<int>> &A, int i, int j, int cols)
{
  int ni = j;
  int nj = cols-i;
  int temp = A[ni][nj];
  int temp2;
  A[ni][nj] = A[i][j];
  
  for(int cnt=0; cnt<3; cnt++)
  {
    i = ni;
    j = nj;
    ni = j;
    nj = cols-i;
    temp2 = A[ni][nj];
    A[ni][nj] = temp;
    temp = temp2;
  }
}

void Solution::rotate(vector<vector<int>> &A)
{
  const int rows = A[0].size()-1;
  const int cols = A[1].size()-1;

  if(rows == 0 || cols == 0)
    return;
  
  for(int i=0; i<= rows/2; i++)
  {
    for(int j=i; j<= cols-i-1; j++)
    {
      swap(A, i, j, cols);
    }
  }
}
