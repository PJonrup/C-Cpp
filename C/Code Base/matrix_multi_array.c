

// ------------- Multidimentional Array -------------

void print(int m, int n, int mat[][n]) {    // This should be okay in todays C compilers.
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", mat[i][j]);
        }
    }
}

int main(void) {

    int arr[3][2] = {{10, 20}, {30, 40}, {50, 60}};     // stored as [10][20][30][40][50][60] in memory
    int arr2[3][2] = {10, 20, 30, 40, 50, 60};           // This works too.
    int arr3[][2] = {10, 20, 30, 40, 50, 60};            // This works too but only for the first element even if we use arr[][2][2].

    print(3, 2, arr);   // This is the best way to send multidimension arrays without using pointers.

    return 0;
}