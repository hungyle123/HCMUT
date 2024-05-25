#include <iostream>

using namespace std;
long fac(long x){
    if ((x == 1) || (x == 0))
    return 1;
    else return x*fac(x-1);
}


int main(int narg, char** argv)
{
    int N;
    cin >> N;
    long result;
    // call function calculateFactorial in here and assign value to the variable result
    result = fac(N);

    cout << result << endl;
    return 0;
}
