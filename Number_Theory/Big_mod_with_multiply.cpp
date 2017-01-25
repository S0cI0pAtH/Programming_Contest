
typedef long long ll;
const ll mod = 1e9 + 7;

ll multiply ( ll a , ll b, ll m)
{
    if (b == 0) return 0;

    ll temp = multiply ( a, b/2, m ) %m;

    if (b%2 == 0)
    {
        return ( temp + temp )%m;
    }
    else
    {
        return ( ( ( temp + temp ) % m ) + a%m ) %m;
    }
}

ll BM( ll b, ll p, ll m )
{
    if (p == 0)
        return 1;

    ll temp = BM( b, p/2, m ) % m;

    if ( p % 2 == 0 )
    {
        return multiply( temp, temp , m)%m;
    }
    else
    {
        return (multiply( ( b % m) , multiply ( temp, temp , m ), m ) ) %m;
    }
}
