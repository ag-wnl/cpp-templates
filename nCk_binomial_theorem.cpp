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
