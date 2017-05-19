
// range ( a -> b )
//( b - a ) <= 10 ^ 5  inclusive
ll a, b;
vector< ll > primes, divi[100005];
bool check[MAX+20];

void sieve(){
    for( int i = 2; i * i <= MAX; i++ ){
        if( check[i] ) continue;
        for( int j = i * i ; j <= MAX; j += i ){
            check[j] = true;
        }
    }
    for( int i = 2; i <= MAX; i++ ){
        if( !check[i] ) primes.pb( i );
    }
}

void gen_div(){

    if( a == 1 ) a++;
    for( auto pr : primes ){
        ll first = a / pr;
        if( a % pr ) first++;
        first *= pr;

        for( ll i = first; i <= b; i += pr ){
            ll num = i;
            while( num % pr == 0 ){
                divi[i-a].pb( pr );
                num /= pr;
            }
        }

    }
}


