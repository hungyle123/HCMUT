int findMax(int *vals, int numEls) {
    int k =vals[0];
    for (int i =0; i< numEls; i++){
         if (vals[i]>=k) k = vals[i];
    }
    return k;
}
