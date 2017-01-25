
int GCD(long long a, long long b){
    if(a == 0) return b;
    return GCD( b%a, a);
}

int LCM(long long a, long long b, long long p){
    if( a%p == 0) return ( (a/p) * b);
    return ( (b/p) * a);
}
