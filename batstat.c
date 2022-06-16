
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10


float average(float tab[], int n ){
    
    float sum = 0;
    float moy = 0;
    for( int i = 0;i<n;i++)
    {
      sum += tab[i]; 
    }
    
     moy = sum/n;
     
     printf("Average = %f", moy);


}




void  main(int argc, char * argv[])
{
  //----------------------- ouverture du fichier de données CSV ------------------------------
    FILE* fp = fopen("Dataset1.csv", "r");
 
    if (!fp)
        printf("Can't open file\n");
 
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

               
 
            // Splitting the data
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



