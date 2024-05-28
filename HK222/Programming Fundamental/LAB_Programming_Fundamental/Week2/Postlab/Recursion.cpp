// Question 1

bool palindromeRecursion(string s,int n = 0,int n1 = 0,int k =-1)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    if (k == -1){
        n = s.length();
        n1 =n/2;
        k = k +1;
    }
    if (n == 1)
    return true;
    else if (s[k]==s[n-1-k]){
        if (k == n1-1)
        return true;
        else {
            k = k + 1;
            return palindromeRecursion(s,n,n1,k);}
    }
    else return false;
    // END YOUR EMPLEMENTATION [1]
}

int main()
{
    hiddenCheck();
    // BEGIN YOUR IMPLEMENTATION [2]
    string a;
    while (1>0){
        getline(cin,a);
        if (a[0]=='*')
        break;
        if (palindrome(a)==1)
        cout <<"true"<<' ';
        else cout <<"false"<<' ';
        if (palindromeRecursion(a) == 1)
        cout <<"true"<<endl;
        else cout <<"false"<<endl;
        
    }
   
    // END YOUR EMPLEMENTATION [2]
    return 0;
}


/***************************************************************************************************/


// Question 2

int countWaySumOfSquare(int x,int i = 1, int sum = 0)

{   
	int result = 0;
	int p = pow(i,2);
	if (p + sum < x){
	    result = result + countWaySumOfSquare(x,i + 1,p+sum);
	    result = result + countWaySumOfSquare(x,i + 1,sum);
	}
	if (p + sum == x)
	result = result + 1;
	return result;
}