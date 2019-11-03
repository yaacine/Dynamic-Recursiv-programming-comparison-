#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0




int smallest_sol_index = -1 ;
int smallest_sol_len = -1 ;

int all_solutions [100][100] ; // store 10 solutions max in a set of len elements
int nb_sol = 0 ;

  int path[] = {0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,};

int sub_sum_set(int n,int sum){
    


int donnees[] = {3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,
                  3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,
                  3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,
                  3,5,6,8,7,2,4,59,69,};

      
  

    if((sum==0)){

            int count =0 ;

            for(int i=0;i<=n;i++){
               // solution[i]=path[i];
                all_solutions[nb_sol][i]=path[i];
                // count nb elements involved
                count = count + path[i]; // additionner 0+1+1 where involved
            }

                if(count>smallest_sol_len){

                    smallest_sol_len = count ;
                    smallest_sol_index = nb_sol ; // active solution
                }
            nb_sol++;
        return true ;//need a push here
    }
    if(sum<0){
        return false ;
    }
    if(n<=-1){

        return false;
    }
    else{
            int var1,var2; //separer permet de g�nerer tout les cas

            path[n]=1;
        var1=sub_sum_set(n-1,sum-donnees[n]);
                path[n]=0;
            var2=sub_sum_set(n-1, sum);

            return var1||var2 ;


    }

}



int recursive(int len ,int searched_value)
{


//initialiser path à chaque appel
for (int l=0;l<100;l++){
    path[l]=0;
}

// initialiser All_solutions



int donnees[] = {3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,
                  3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,
                  3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,3,5,6,8,7,2,4,59,69,
                  3,5,6,8,7,2,4,59,69,};

int max_sol =len;
int max = len-1 ;
 nb_sol = 0 ;


    for(int i =0;i<100;i++){
        for(int j=0;j<=100;j++){

            all_solutions[i][j] = 0 ;
        }
    }

    int bool = sub_sum_set(max,searched_value);

    printf("\n test : last element in donnees* %d * \n",donnees[5]);

    if(bool){
        printf("la valeur est trouve \n");
            for(int y=0;y<nb_sol;y++){

                for(int i=0;i<=max ;i++){
                    printf("===> %d  \n" ,all_solutions[y][i]);
                if(all_solutions[y][i]){
                        printf("+ %d",donnees[i]);
                    }
                }
                    printf(" = %d \n",searched_value);

                }

                printf("\n \n the Biggest solution is : \n");

                for(int t=0;t<=max;t++){
                    if(all_solutions[smallest_sol_index][t]){
                        printf("+ %d",donnees[t]);
                    }
                }
                 printf(" = %d \n",searched_value);
                 


    }
    else{
        printf("la valeur n'est pas trouve \n");
    }

    
    return 0;
}


