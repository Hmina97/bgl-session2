
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_LENGTH 10



//vérifier si le nombre d'argument egale à 2 si le retour est -1 alors il y a un erreur sinon y a pas d'erreur
static int check_args(int argc, char * argv[]){
  if (argc != 3) {
    return -1;
  }

  int n = strtol(argv[1], NULL, 10);
  if (n <= 0) {
    return -1;
  }
  return n;
}
float average(float tab[], int n ){
    
    float sum = 0;
    float moy = 0;
    for( int i = 0;i<n;i++)
    {
      sum += tab[i]; 
    }
    
     moy = sum/n;// la moyenne de tableau tab
     
    printf("Average = %f", moy);

    return moy;

}


float ec_type(float tab[],int n){

    float accum = 0;
    float m = average(tab,n);
    for(int i = 0; i<n;i++){
     
      accum += (tab[i] - m) * (tab[i] - m);


    }
    double stdev = sqrt(accum / n-1);//l'écart type

     
    return 
}



void  main(int argc, char * argv[])
{





  //----------------------- ouverture du fichier de données CSV ------------------------------
    FILE* fp = fopen("Dataset1.csv", "r");
 
    if (!fp)
        printf("Ouverture fichier impossible %s\n !",argv[0]);
 
    else {
        
        char buffer[1024];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
 
            int i ;
            if (row == 1){

             for( i = 0;i < 1000;i++){
                if (buffer[i] == "Families") {
                    int indice = i;
                    break;
                }   

            }
             }

               

            char* value = strtok(buffer, ",");
 
            while (value) {
                // Column 1
                
                
 
                // Column Families
                if (column == i) {
                    printf("\tAccount No. :");
                }
 
                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }
 
            printf("\n");
        }
 
        // Close the file
        fclose(fp);
    }
    return 0;
}



