#include <stdio.h>
#include <stdlib.h>

// #define searched_value 69
// #define cardinal 10


int donnees[] = {3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,
                  3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,
                  3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,
                  3,5,6,8,7,2,4,59,69,};


int dynamic(int cardinal, int searched_value){
    
    int dyn_tab[cardinal+1][searched_value+1];

    int i=0;
    int j=0;
    // initialisation du tableau dynamique
    for (i=0 ; i<cardinal+1 ;i++){
        for(j=0; j<searched_value+1 ;j++){
            if (j==0)dyn_tab[i][j] =0;
            else dyn_tab[i][j] =-1;
        }
    }


    // remplissage du tableau dynamique

    int index1 =0;
    int index2 =0;
    int val1=0;
    int val2=0;

    for (i=1 ; i<cardinal+1 ;i++){
        
        for(j=1; j<searched_value+1 ;j++){
            //dyn_tab[i,j] =-1;
            index1 =j;
            index2 = j-donnees[i]-1;
            if(index1<0){
                val1= -1; 
            }
            else{
                val1 =dyn_tab[i-1][index1];


            }

            if(index2<0){
                val2= -1; 
            }
            else{
                val2 =dyn_tab[i-1][index2];


            }


            if(val1>=0 || val2>=0){
                if(val1>val2){
                    dyn_tab[i][j]= val1;
                }else{
                    dyn_tab[i][j]= val2+1;
                }
            }
        }
    }

    printf("solution == %d \n" , dyn_tab[cardinal][searched_value]);

    return 0;

} 