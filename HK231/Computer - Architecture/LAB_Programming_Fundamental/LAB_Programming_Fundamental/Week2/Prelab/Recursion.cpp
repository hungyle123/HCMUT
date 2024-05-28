// Question 1

int gcdRecursion(int p, int q)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    if (p == 0) return q;
    else if (q == 0) 
    return p; 
    else { 
        if (p > q) 
        return gcdRecursion(p-q,q); 
        else if (p <= q) 
        return gcdRecursion(p,q-p);}
    // END YOUR EMPLEMENTATION [1]
}
int gcdIteration(int p, int q)
{
    // BEGIN YOUR IMPLEMENTATION [2]
   while ((p > 0) && (q > 0)) { 
       if (p > q) p = p - q; 
       else if (p <= q) q = q -p; } 
       if ( p == 0) 
       return q; 
       else return p;
    // END YOUR EMPLEMENTATION [2]
}


/****************************************************************************************************/

// Question 2
int strLen(char* str,int t = 0)     
{ 
    if (str[t] == '\0')
    return t;
    else return strLen(str,t + 1);
}

/****************************************************************************************************/

// Question 3

void printPattern(int n,int t = 0,int k = 0) // k = 0 là trừ hết lần 1 1 là trừ 2 là cộng
{ if ((n == 0)&&(k==0))
    cout << n;
    else 
{   if ( k == 0) {
    t = n;
    k = 1;
    cout << n<<' ';
}
    if (n <= 0)
    k = 2;
    if (k == 1){
        cout << n-5<<' ';
        printPattern(n-5,t,k);
    }
    if (k == 2){
        if (t != n +5)
       {cout<< n + 5<<' ';
        printPattern(n+5,t,k);
        }
        else 
        cout << t;}
}
}

