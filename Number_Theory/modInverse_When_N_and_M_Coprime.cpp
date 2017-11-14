ll ext_gcd ( ll A, ll B, ll *XX, ll *YY ){
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *XX = x2; *YY = y2;
    return r2;
}
ll mi( ll a, ll m ){
    ll x, y;
    ext_gcd( a, m , &x, &y );
    x %= m;
    while( x < 0 ) x += m;
    return x;

}
