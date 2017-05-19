ll fact[MAX];
void factorial( int md ){
    fact[0] = fact[1] = 1;
    for( int i = 2; i <= md; i++ ){
        fact[i] = ( fact[i-1] * i ) % md;
    }
}

ll lucas_theorm( ll n , ll r, ll p ){ // p must be prime & small , n, r can be large
    ll ans = 1;
    while( n || r ){
        if( n % p < r % p ) return 0;
        ans *= ((fact[n%p] % p * BM( fact[r%p], p - 2, p ))%p * BM( fact[n%p - r%p], p -2, p )  ) %p;
        ans %= p;
        n /= p;
        r /= p;
    }
    return ans;
}


