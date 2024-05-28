// Question 1

int check = 1;
for (int i = 0 ;i<size-1;i++){
    if (ar[i]==ar[size-1]){
    check = 0;
    goto end;}
}
end:    if (check == 0)
    return false;
    else {
        if (size == 1)
        return true;
        else return checkDuplicate(ar,size-1);
    }

/*************************************************************************************************/

// Question 2

if (m == arr[index]){
    for (int i = index;i<n;i++){
        arr[i]=arr[i+1];
    }
    n = n-1;
return index;}
else{if (index == n)
return -1;
  else  
 recursiveSearch(n ,m,arr,index+1);
}