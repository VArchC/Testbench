#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include VAC_IFACE

#ifndef NBITS
#define NBITS 8
#endif

int main()
{
  int ra, rk, a, b;
  unsigned int ecount = 0, ccount = 0;
  float error = 0, rerror = 0, mrerror = 0;
  printf ("Dumping %d-bit computations:\n", NBITS);

  vac_newSection();
  for (a = 0; a < (1<<NBITS); a++) {
    for (b = 0; b < (1<<NBITS); b++) {
      ra = (a * b);
      vac_activate(VAC_APPROX_KULKARNI_MUL);
      rk = (a * b);
      vac_deactivate(VAC_APPROX_KULKARNI_MUL);

      if (ra != rk) {
        ecount++;
        error = (float)abs(ra - rk)/(float)ra;
        rerror += error;
        if (error > mrerror) {
          mrerror = error;
        }
      }
      ccount++;
    }
  }
  vac_newSection();

  printf("Total %u/%u = %f%%\n", ecount, ccount, (float)ecount/(float)ccount*100.);
  printf("Mean relative error %f%% (%f/%u)\nMax relative error: %f%%\n\n", rerror/(float)ccount*100, rerror, ccount, mrerror*100);

  return 0;
}
