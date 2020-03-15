#include <stdio.h>
#include <algorithm>

using namespace std;

struct Skok {
    long lewo = 0;
    long prawo = 0;

};

int main() {
    long n = 0, s = 0;
    scanf("%ld %ld", &n, &s);

    Skok skoki[n - 1];

    for (long i = 0; i < n - 1; i++) {
        long l, p;
        scanf("%li %li", &l, &p);

        skoki[i].lewo = l;
        skoki[i].prawo = p;
    }

    //printf("%li%li", n, s);
    for (long i = 7; i < 11; i++) {
      printf("%li%li", skoki[i].lewo, skoki[i].prawo);
    }
}
