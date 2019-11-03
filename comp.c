#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "question4_REC.c"
#include "question4_Dyn.c"

#define searched_value 34

//tableau de 100 elements
// int donnees[] = {3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,
//                   3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,
//                   3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,
//                   3,5,6,8,7,2,4,59,69,};

// tableau des sommes à trouver                  
int sommes[] ={3,5,6,8,7,2,4,59,69}; 



float resultats [3][10] ;



 int main(){
   float execRec=0;
   float execDyn=0;
   int k=0;

   // test pour la merthode rec 
    for(int k=0 ; k<10 ;k++ ){
          struct timeval stop, start;
          gettimeofday(&start, NULL);
           

         // appel de la fonction recursive
         int r = recursive((k+1)*10, searched_value);
         resultats[0][k]=(double)(k+1)*10;
          execRec =(double) (stop.tv_sec - start.tv_sec) * 1000 + (double) (stop.tv_usec - start.tv_usec) / 1000;
          printf("Duration Rec MS %'.3f\n",execRec );
         resultats[1][k]=execRec;      
    }



//    // test pour dynamique  
//      
//       for( k=0 ;k<10 ;k++ ){
         
//           struct timeval stop, start;

//           // recuperation du tems de debut
//           gettimeofday(&start, NULL);
//           resultats[0][k]=(k+1)*10;
            
//          // appel de la fonct rec
//           int r = dynamic((k+1)*10, searched_value);

//           // recuperation du tems de debut
//           gettimeofday(&stop, NULL);

//           //calcul du temps d'execution
//           execDyn =(double) (stop.tv_sec - start.tv_sec) * 1000 + (double) (stop.tv_usec - start.tv_usec) / 1000;
//           resultats[2][k]=execDyn;
//     }
   
    
      // print results table 
 printf("\n");
     for( k=0 ;k<10 ;k++ ){
          printf("  %.0f    |" ,resultats[0][k]);
     }
     printf("\n");
     for(int k=0 ;k<10 ;k++ ){
          printf("  %.3f |" ,resultats[2][k]);
     }
      printf("\n");
    return(0);
 }
