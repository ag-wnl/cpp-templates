ll mod = 1e9 + 7;
 
string gud;
vector<ll> gudPref(1e5);
 
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
 
 
 
struct hasher {
	string s;
	ll p = 30;
	int n;
 
	vector<ll> pref;
	vector<ll> powP;
	vector<ll> invPowP;
 
	hasher(string inpString) {
		s = inpString; 
		n = s.size();
 
		pref.resize(n);
		powP.resize(n);
		invPowP.resize(n);
		calc();
		calcPref();
	}
 
	void calc() {
		ll curPow = 1;
		for(int i=0; i<n; i++) {
			powP[i] = curPow;
			curPow = (curPow*p) % mod;
		}
 
		invPowP[n-1] = mdiv(1LL, powP[n-1]);
		for(int i=n-2; i>=0; i--) {
			invPowP[i] = (p * invPowP[i+1]) % mod;
		}
	}
 
	void calcPref() {
		ll curHash = 0;
		for(int i=0; i<n; i++) {	
			gudPref[i+1] = gudPref[i] + (gud[s[i] - 'a'] == '1');
			curHash = (curHash + (s[i] - 'a' + 1) * powP[i]) % mod;
			pref[i] = curHash; 
		}
	}
 
	ll subStringHash(int l, int r) {
		ll a = pref[r];
		ll b = (l > 0) ? pref[l-1] : 0LL;
		return ((a - b + mod) * invPowP[l]) % mod;
	}
};
