/*

  Harjoitus 1

  Optimoi sini-funktion käsittely. Älä muuta kääntäjäoptioita.
  Vertaa alkuperäistä ja optimoitua versiota:

  - kuinka paljon enemmän muistia optimoitu versio kuluttaa?
  - kuinka paljon nopeammin optimoitu versio toimii?

  Käännös: gcc sin.c -lm -o sin

*/

#include <stdio.h>
#include <time.h>
#include <math.h>

#define DEG_TO_RAD(A) (A / 57.296)
#define ITERATIONS 1000000


int main()
{
  clock_t t1, t2;
  unsigned i, a, k;
  double val; // memoryAmount;
  double sinValues[360];

  for (k = 0; k < 360; k++)
  {
    sinValues[k] = sin(DEG_TO_RAD(k));
  }
  //memoryAmount = sizeof(double) * 360.0;
  printf("%d bytes of memory reserved. \n", sizeof(double) * 360);

  // printf("%lf bytes of memory reserved. \n", memoryAmount);
  
  t1 = clock();
  for (i = 0; i < ITERATIONS; ++i)
    {
      for (a = 0; a < 360; ++a)
	{
	  /*
	    OptimizeIt!
	  */

      val = sinValues[a];
	}
    }
  t2 = clock();
  printf("%.1fs\n", (t2 - t1) / (float)CLOCKS_PER_SEC);

  return 0;
}
