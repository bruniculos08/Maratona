#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Plan: solve using binary exponentiation;

long long solverRecursive(long long a, long long b, long long m){
    if(b==0) return 1;
    if(b==1) return a % m;
    if(b%2 == 0) return solverRecursive(a, b/2, m) * solverRecursive(a, b/2, m)% m;
    else return a * solverRecursive(a, (b-1)/2, m) * solverRecursive(a, (b-1)/2, m) % m;
}

int main(void){
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        cout << solverRecursive(a, b, 1000000007) % 1000000007 << endl;
    }
    return 0;
}