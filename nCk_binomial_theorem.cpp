long long pwr( long long a, int pw )
{
    long long ret = 1;
    long long x = a;
    for( int i = 1; i <= pw; i <<= 1 ) {
        if( i & pw ) ( ret *= x ) %= mod;
        ( x *= x ) %= mod;
    }
    return ret;
}
 
long long mdiv( long long a, long long b ) {
    return a * ( pwr( b, mod - 2 ) ) % mod;
}
 
long long cnk( long long n, long long k )
{
    long long ret = 1;
    for( int i = 0; i < k; i++ ) {
        ret = ( ret * ( long long )( n - i ) ) % mod;
        ret = ( mdiv( ret, i + 1 ) ) % mod;
    }
    return ret;
}


// for nCr without MOD given, change long double to ll if no precision need:
long double ncr(ll n, ll  r) {
    int i;
    long double p=1.0, q=1.0, ans=1.0;
    if(r > n) {
        return 0.0;
    }

    if(r == n) {
        return 1.0;
    }

    for(i=0; i<r; i++) {
        p = n-i;
        q = i+1;
        ans*=(p/q);
    }

    return ans;
}
