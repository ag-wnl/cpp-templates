// Modified Sieve, smallest prime factors used to factorize number
const int MAXX = 2e5 + 5;
int spf[MAXX]

void sieve () {
    for(int i=1; i<MAXX; i++) spf[i] = i;

    for(int i=2; i<MAXX; i++) {
        for(int j=2*i; j<MAXX; j+=i) {
            if(spf[j] == j) spf[j] = i;
        }
    }
}

//return prime factors of a number n
vector<int> factorize(int n) {
    vector<int> primes;
    while(n!=1) {
        int x = spf[n];
        while(n%x == 0) n = n/x;
        primes.push_back(x);
    }
    return primes;
}
