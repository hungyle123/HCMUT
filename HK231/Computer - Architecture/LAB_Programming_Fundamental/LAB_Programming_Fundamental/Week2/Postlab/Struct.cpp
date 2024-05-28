// Question 1

int compareObjectClass(const SCP &objA, const SCP &objB) {
    
    if (objA.objClass > objB.objClass)
    return 1;
    else if (objA.objClass < objB.objClass)
    return -1;
    else return 0;
}

/**********************************************************************************************/

// Question 2

SCP** sortDatabase(SCP** arr, int n) {
    SCP* t =new SCP;
    for (int i = 0; i<n-1;i++){
        for (int j =i;j<n;j++) {
        if ((arr[i]->id)>(arr[j]->id)){
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }}
    return arr;
}