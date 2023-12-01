//fract_total takes in numerator and denominator we want to calculate using modular inverse

long long pow_mod(long long base, long long exp) {
    base %= MOD;
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)  // if n is odd
            result = result * base % MOD;
        base = base * base % MOD;
        exp /= 2;  // divide by two
    }
    return result;
}

long long mod_inv(long long n) { return pow_mod(n, MOD - 2); }

long long frac_total(long long num, long long denom) {
    return ((num % MOD) * mod_inv(denom)) % MOD;
}
