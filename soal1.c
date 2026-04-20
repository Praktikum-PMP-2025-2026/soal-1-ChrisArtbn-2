#include <stdio.h>

int main() {
    int N;
    long long total;

    if (scanf("%d", &N) != 1) return 0;
    
    long long A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    
    for (int i = 0; i < N; i++) {
        long long angka_selanjutnya = 0;
        if (A[i] == -1) {
            for (int j = i + 1; j < N; j++) {
                if (A[j] != -1) {
                    angka_selanjutnya = A[j];
                    break;}
                }

            if (i == 0) {
                A[i] = angka_selanjutnya;
            } 
            else {
                A[i] = (A[i-1] + angka_selanjutnya) / 2;
            }
        }
    }
    
    printf("RECOVERED");
    for (int i = 0; i < N; i++) {
        printf(" %lld", A[i]);
    }
    printf("\n");
    
    long long sum_total = A[0];
    long long sum_sekarang = A[0];
    
    for (int i = 1; i < N; i++) {
        if (sum_sekarang < 0) {
            sum_sekarang = A[i];
        } else {
            sum_sekarang += A[i];
        }
        if (sum_sekarang > sum_total) {
            sum_total = sum_sekarang;
        }
    }
    printf("MAX_SUM %lld\n", sum_total);
}
