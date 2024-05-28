bool checkElementsUniqueness(int* arr, int n) {
    int t =1;
    for (int i =0; i< n-1; i++) {
        for (int j = i+1; j <n;j++){
            if (arr[i]!=arr[j])
            t = t*1;
            else {t = t*0;
            goto end;}
        }
}
end: if (t == 1)
return true;
else return false;}