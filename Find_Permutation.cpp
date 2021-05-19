/*

Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.
D means the next number is smaller, while I means the next number is greater.

Notes
    Length of given string s will always equal to n - 1
    Your solution should run in linear time and space.

Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]

*/
/*
Algo:
create a array A with numbers 1 to n ( in assending order )
keep 2 pionters Imax & Imin at the max and min values i.e the start and end of array A.
when s[i] is I i.e the next number should be incresing, place the min value using at the Imin index at the corespoinding i index of the ans vector. Incriment Imin.
similarly when S[i] is D i.e the next number should be decresing, place the max value using the Imax index at the coresponding i index of the ans vector. Decremtn Imax
Append the last remaning value in the ans vector
*/

vector<int> Solution::findPerm(const string A, int B) 
{
    vector<int> res; 
    int minIndex = 0;
    int maxIndex = B-1;
    int arr[B] = {};
    
    for(int i=0; i<B; i++)
        arr[i] = i+1;
    
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] == 'D')
        {
            res.push_back(arr[maxIndex]);
            maxIndex -= 1;
            //continue;
        }
        else
        {
            res.push_back(arr[minIndex]);
            minIndex += 1;
        }
    }
    
    res.push_back(arr[maxIndex]);
    
    return res;
}

