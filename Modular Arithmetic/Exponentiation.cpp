#include <bits/stdc++.h>
#include <vector>

using namespace std;
long long MOD = 10*10*10*10*10*10*10*10*10 + 7;

// Plan: solve using binary exponentiation;

long long solverRecursive(long long a, long long b, long long m){
    if(b == 0) 
        return 1;

    // long long res = solverRecursive(a, b/2, m);
    
    if(b%2 == 0) 
        return solverRecursive(a, b/2, m) * solverRecursive(a, b/2, m);

    else return a * solverRecursive(a, (b-1)/2, m) * solverRecursive(a, (b-1)/2, m);
}

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    // a %= MOD;
    long long res = binpow(a, b / 2) % MOD;
    if (b % 2 == 1)
        return (((res * res )%MOD) * a) % MOD;
    else
        return (res * res) % MOD;
}

// Para o MOD funcionar tem que impedir que o valor de qualquer multiplicação passe do número de MOD

int main(void){
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        // cout << solverRecursive(a, b, 1000000007) % 1000000007 << endl;
        cout << MOD << endl << binpow(a, b) % MOD << endl;
    }
    return 0;
}