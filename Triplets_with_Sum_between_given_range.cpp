/*
Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.

*/


//************************ nlog(n) aproach ***************************
//sort the array, keep pointer 'a' on index 0 (min), 'c' on index N-1 (max) and 'b' on pointer at mid max-min/2
// if a+b+c > 2 then move c to left and recompute b
// if a+b+c < 1 then move a to right and recompute b
// stop with diff btw index of a & c is less than 2

int Solution::solve(vector<string> &A) 
{
	sort(A.begin(), A.end());
	
	int aIndex = 0;
  int cIndex = A.size()-1;
  int bIndex = (aIndex + cIndex)/2;
	
	while(cIndex-aIndex > 1)
	{
		float a = stod(A[aIndex]);
		float b = stod(A[bIndex]);
		float c = stod(A[cIndex]);
		
		float sum = a+b+c;
		
		if(sum > 2)
			cIndex -= 1;
		else if(sum < 1)
			aIndex += 1;
		else
			return 1;
		
		bIndex = (aIndex + cIndex)/2;
		
	}
	
	return 0;
}
	
//************************ log(n) aproach ***************************
	
	
	
	
