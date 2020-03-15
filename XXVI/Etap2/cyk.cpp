#include "cyklib.hpp"
#include <stdio.h>

using namespace std;

int main() {
  long dist = 1, greaterThen = 1, lesserThen = 1;
  long long start, lastVal, newVal, krok;
  start = circular_shift(0);
  lastVal = start;
  newVal = circular_shift(1);
  while( !(lastVal < start && newVal > start) &&
      !(lastVal < start && newVal < lastVal) &&
      !(lastVal > newVal && newVal > start) &&
      !(newVal == start) && !(newVal == lastVal)) {
    dist *= 2;
    lastVal = newVal;
    newVal = circular_shift(dist);
    greaterThen = lesserThen;
    lesserThen += dist;
  }

  if (newVal == lastVal) {
    lesserThen = dist;
  } else if (newVal == start) {
    ;
  } else {
    while (newVal != start) {
      start = newVal;
      krok = circular_shift(greaterThen);
      dist = dist / 2;
      lesserThen -= dist;
      newVal = circular_shift(dist);
      while (((krok < start && newVal < start && newVal > krok) ||
              (krok > start && (newVal > krok || newVal < start))) &&
            start != krok) {
        greaterThen = lesserThen;
        dist = dist / 2;
        lesserThen += dist;
        newVal = circular_shift(dist);
      }
    }
  }
  give_answer(lesserThen);
  return 0;
}
