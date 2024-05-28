long int Power(int a,int b){
    if (b == 0)
    return 1;
    else return a*Power(a,b-1);
}
int count(int a){
    if (a / 2 == 0)
    return 1;
    else return 1 + count (a/2);
}
long int convert(int a,int t,int c){
    if (c == t)
    return (a % 2)*Power(10,t);
    return (a % 2)*Power(10,c)+convert(a/2,t,c+1);
}
long int decimalToBinary(int decimal_number)
{   int t = count(decimal_number);
    
	return convert(decimal_number,t,0);
}