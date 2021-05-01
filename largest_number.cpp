/*

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

//////////////// Notes ///////////////////
/*
1) (condition) ? (if_true) : (if_false)
2) (int)log10(x) + 1 will give the number of digits in the number x
*/

int mySort(int a, int b)
{
  long long int ab = b==0 ? a*10 : a * pow(10, (int)log10(b)+1) + b;
  long long int ba = a==0 ? b*10 : b * pow(10, (int)log10(a)+1) + a;

  return ab>ba?1:0;
}

string Solution::largestNumber(const vector<int> &A) 
{
    string ans = "";
    vector <int> arr = A;
    
    sort(arr.begin(), arr.end(), mySort);
    
    for(int i=0; i<arr.size(); i++)
    {
        ans += to_string(arr[i]);
    }
    
    if(ans[0] == '0')
        return "0";
    
    return ans; 
}
