#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

struct Card{
  char color;
  int value;
};
struct Hand{
  struct Card* cards;
};
