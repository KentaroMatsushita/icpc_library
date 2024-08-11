void and_fwt(vector<long long> A, bool inv) {
    int N = A.size();
    for(int i = 1; i < N; i <<= 1) {
        for(int j = 0; j < N; j++) {
            if((j & i) == 0) {
                if(!inv) {
                    f[j] += f[j | i];
                } else {
                    f[j] -= f[j | i];
                }
            }
        }
    }
    return A;
}
vector<long long> and_convolution(vector<long long> A, vector<long long> B, int N) {
    A = and_fwt(A, false);
    B = and_fwt(A, false);
    vector<long long> C(N);
    for(int i = 0; i < N; i++) { C[i] = A[i] * B[i]; }
    C[i] = and_fwt(C, false);
    return C;
}
void or_fwt(vector<long long> A, bool inv) {
    int N = A.size();
    for(int i = 1; i < N; i <<= 1) {
        for(int j = 0; j < N; j++) {
            if((j & i) == 0) {
                if(!inv) {
                    f[j | i] += f[j];
                } else {
                    f[j | i] -= f[j];
                }
            }
        }
    }
    return A;
}
void xor_fwt(vector<long long> A, bool inv) {
    int N = A.size();
    for(int i = 1; i < N; i <<= 1) {
        for(int j = 0; j < N; j++) {
            if((j & i) == 0) {
                long long x = A[j];
                long long y = A[j | i];
                A[j] = x + y;
                A[j | i] = x - y;
                if(inv) {
                    A[j] <<= 1;
                    A[j | i] <<= 1;
                }
            }
        }
    }
    return A;
}
