#include <stdio.h>

int main() {

  unsigned int x = 5;
  signed int   y = -4;

  if ( x > y )
    printf( "%d é maior do que %d\n", x, y );
  else
    printf( "%d é menor ou igual ao valor de %d\n", x, y );

}
