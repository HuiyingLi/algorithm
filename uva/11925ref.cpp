#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//#define n 1023
int a[1023+10];
int n;
int hd;

bool check() {
    for (int i = 1; i <= n; i++) {
        if (a[(hd+i-1)%n] != i) return false;
    }
    return true;
}

int stk[1000000];

void show() {
    for (int i = 0 ;i < n; i++) {
        printf("%d ", a[(hd+i)%n]);
    }puts("");
}

int main() {
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        hd = 0;
        int top = 0;
        while (true) {
            if (check()) break;
            if (a[hd] > a[(hd+1)%n] && (!(a[hd] == n && a[(hd+1)%n] == 1))) {
                stk[top++] = 1;
                //printf("1");
                swap(a[hd], a[(hd+1)%n]);
                continue;
            } else {
                a[(hd-1+n)%n] = a[(hd+n-1)%n];
                stk[top++] = 2;
                //show();
                //printf("2");
                hd = (hd-1+n)%n;
            }
        }
        for (int i = top-1; i >= 0; i--) printf("%d", stk[i]);
        puts("");
    }
    return 0;
}
