bool completeNum(int N)
{
    int k =0;
    for (int i =1; i <N;i++){
        if (N % i ==0)
        k = k + i;
    }
    if (k == N)
    return true;
    else return false;
}
