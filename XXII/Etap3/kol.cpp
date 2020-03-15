#include <stdio.h>

using namespace std;

int main() {

  long long map[32] = {0};

  long p1 = -1;
  long long p1count = 0;
  long p2 = -1;
  long long p2count = 0;

  val = karta();

  while (val != 0) {
    if (p1 == -1) {
      p1 = val;
    } else if (p2 == -1 && p1 != val) {
      p2 = val;
    }
    val = karta();
  }

  for (int i = 0; i < 32; i++) {
    printf("%li ", map[i]);
  }

  unsigned int max = 2000000000;
  unsigned int base = 1;
  int i = 1;

  while (base < max) {
    base = base * 2;
    i++;
    printf("base: %i\n", base);
  }
  printf("%i", i);
}
