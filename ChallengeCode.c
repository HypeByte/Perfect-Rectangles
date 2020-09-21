#include <stdio.h>

#include <stdbool.h>


struct coordinate {

   int x;
   int y;

};

bool checkIfQuad(struct coordinate quad[4]) {

   //2,5 15,5 15,5 2,5
   for (int h = 0; h < 4; h++) {

      struct coordinate bank[3];

      for (int left = 0; left < h; left++) {
         bank[left] = quad[left];
      }

      for (int right = h + 1; right < 4; right++) {
         bank[right - 1] = quad[right];
      }

      for (int check = 0; check < 3; check++) {
         int xCheck = 0;
         int yCheck = 0;
         if (quad[h].x == bank[check].x && quad[h].y == bank[check].y) {
            return false;
            break;
         }
         if (quad[h].x == bank[check].x) {
            xCheck++;
         }
         if (quad[h].y == bank[check].y) {
            yCheck++;
         }
         if (xCheck == 2) {
            return false;
            break;
         }
         if (yCheck == 2) {
            return false;
            break;
         }
      }

   }

   return true;

}

bool check(struct coordinate snap[4]) {

   if (snap[0].x == snap[3].x && snap[0].y == snap[1].y && snap[1].x == snap[2].x && snap[2].y == snap[3].y) {
      return true;
   }

   return false;

}

struct coordinate * dissect(struct coordinate snap[4]) {

   static struct coordinate output[4];
   struct coordinate xMaxR;
   struct coordinate finalBankR[2];

   xMaxR = snap[0];

   for (int i = 1; i < 4; i++) {

      if (snap[i].x > xMaxR.x) {
         xMaxR = snap[i];

      } else if (snap[i].x == xMaxR.x) {
         finalBankR[0] = snap[i];

      }

   }

   finalBankR[1] = xMaxR;

   if (finalBankR[1].y > finalBankR[0].y) {

      output[1] = finalBankR[1];
      output[2] = finalBankR[0];

   } else {

      output[1] = finalBankR[0];
      output[2] = finalBankR[1];

   }

   struct coordinate xMinL;
   struct coordinate finalBankL[2];

   xMinL = snap[0];

   for (int t = 1; t < 4; t++) {

      if (snap[t].x < xMinL.x) {
         xMinL = snap[t];

      } else if (snap[t].x == xMinL.x) {
         finalBankL[0] = snap[t];

      }

   }

   finalBankL[1] = xMinL;

   if (finalBankL[1].y < finalBankL[0].y) {

      output[3] = finalBankL[1];
      output[0] = finalBankL[0];

   } else {

      output[3] = finalBankL[0];
      output[0] = finalBankL[1];

   }

   return output;

}

int main(void) {

   void algorithm();
   struct coordinate epic[4];
   epic[0].x = 10;
   epic[0].y = 20;
   epic[1].x = 20;
   epic[1].y = 20;
   epic[2].x = 20;
   epic[2].y = 10;
   epic[3].x = 10;
   epic[3].y = 20;
   algorithm();

}

void algorithm() {
   bool firstCheck = false;
   bool checkInfo;
   int sum = 0;
   int rectPos = 1;
   struct coordinate trueBank[100][4];
   struct coordinate input[8];
   input[0].x = 10;
   input[0].y = 10;
   input[1].x = 10;
   input[1].y = 5;
   input[2].x = 3;
   input[2].y = 10;
   input[3].x = 3;
   input[3].y = 5;
   input[4].x = 15;
   input[4].y = 10;
   input[5].x = 15;
   input[5].y = 5;
   input[6].x = 2;
   input[6].y = 10;
   input[7].x = 2;
   input[7].y = 5;
   struct coordinate col1[7];
   struct coordinate col2[7];
   struct coordinate col3[7];
   struct coordinate quadSnap[4];

   for (int i = 0; i < 8; i++) {

      for (int left = 0; left < i; left++) {
         col1[left] = input[left];
         col2[left] = input[left];
         col3[left] = input[left];
      }

      for (int right = i + 1; right < 8; right++) {
         col1[right - 1] = input[right];
         col2[right - 1] = input[right];
         col3[right - 1] = input[right];
      }

      for (int Icol1 = 0, Icol2 = 0, Icol3 = 0; Icol1 < 7; Icol3++) {

         if (Icol3 == 7) {
            Icol3 = 0;
            Icol2++;

         }

         if (Icol2 == 7) {
            Icol2 = 0;
            Icol1++;
         }

         if (Icol1 == 7) {
            break;
         }

         if (Icol3 == Icol2 || Icol2 == Icol1 || Icol3 == Icol1) {
            continue;
         }

         quadSnap[0] = input[i];
         quadSnap[1] = col1[Icol1];
         quadSnap[2] = col2[Icol2];
         quadSnap[3] = col3[Icol3];

         if (checkIfQuad(quadSnap)) {

            struct coordinate * memSnap = dissect(quadSnap);
            if (checkIfQuad(memSnap)) {

               if (check(memSnap)) {

                  if (rectPos == 1 && firstCheck == false) {
                     trueBank[0][0].x = memSnap -> x;
                     trueBank[0][0].y = memSnap -> y;
                     trueBank[0][1].x = (memSnap + 1) -> x;
                     trueBank[0][1].y = (memSnap + 1) -> y;
                     trueBank[0][2].x = (memSnap + 2) -> x;
                     trueBank[0][2].y = (memSnap + 2) -> y;
                     trueBank[0][3].x = (memSnap + 3) -> x;
                     trueBank[0][3].y = (memSnap + 3) -> y;

                     printf("testing.. (%i,%i) (%i,%i) (%i,%i) (%i,%i)\n", memSnap -> x, memSnap -> y, (memSnap + 1) -> x, (memSnap + 1) -> y, (memSnap + 2) -> x, (memSnap + 2) -> y, (memSnap + 3) -> x, (memSnap + 3) -> y);
                     firstCheck = true;
                     sum++;
                  } else {

                     for (int b = 0; b < rectPos; b++) {

                        if (memSnap -> x == trueBank[b][0].x && memSnap -> y == trueBank[b][0].y && (memSnap + 1) -> x == trueBank[b][1].x && (memSnap + 1) -> y == trueBank[b][1].y && (memSnap + 2) -> x == trueBank[b][2].x && (memSnap + 2) -> y == trueBank[b][2].y && (memSnap + 3) -> x == trueBank[b][3].x && (memSnap + 3) -> y == trueBank[b][3].y) {

                           checkInfo = false;
                           break;

                        } else if (b == (rectPos - 1)) {

                           checkInfo = true;

                        }

                     }

                     if (checkInfo) {

                        trueBank[rectPos][0].x = memSnap -> x;
                        trueBank[rectPos][0].y = memSnap -> y;
                        trueBank[rectPos][1].x = (memSnap + 1) -> x;
                        trueBank[rectPos][1].y = (memSnap + 1) -> y;
                        trueBank[rectPos][2].x = (memSnap + 2) -> x;
                        trueBank[rectPos][2].y = (memSnap + 2) -> y;
                        trueBank[rectPos][3].x = (memSnap + 3) -> x;
                        trueBank[rectPos][3].y = (memSnap + 3) -> y;
                        printf("True.. (%i,%i) (%i,%i) (%i,%i) (%i,%i)\n", memSnap -> x, memSnap -> y, (memSnap + 1) -> x, (memSnap + 1) -> y, (memSnap + 2) -> x, (memSnap + 2) -> y, (memSnap + 3) -> x, (memSnap + 3) -> y);

                        rectPos++;
                        sum++;

                     }

                  }

               }

            }

         }

      }

   }

   printf("number of rectangles parallel are %i\n", sum);

}
