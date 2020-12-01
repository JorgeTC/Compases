#include "MathGen.h"
#include <math.h>


void
Base3(int n, bool list[64][2], int len)
{
   if (n >= pow(3, len))
      return;
   long int multiplo = pow(3, len - 1);
   int division;
   for (int i = len - 1; i >= 0; i--) {
      division = n / multiplo;
      switch (division) {
      case 0: // nada
         list[len - 1 - i][0] = false;
         break;
      case 1: // figura
         list[len - 1 - i][0] = true;
         list[len - 1 - i][1] = true;
         break;
      case 2: // silencio
         list[len - 1 - i][0] = true;
         list[len - 1 - i][1] = false;
         break;
      }
      n = n % multiplo;
      multiplo /= 3;
   }
}

void
Base2(int n, bool list[], int len)
{
   if (n >= pow(2, len))
      return;
   int multiplo;
   for (int i = len - 1; i >= 0; i--) {
      multiplo = pow(2, i);
      list[len - 1 - i] = bool(n >= multiplo);
      n = n % multiplo;
   }
}

int
LowestDescomposicion(bool Descomposicion[7])
{
   int index = 0;

   for (int i = 0; i < 7; i++) {
      if (Descomposicion[i])
         index = i;
   }
   return index;
}
