//97p 1번문제
#include <stdio.h>

int main() {
    int i, j;
    int rows = 5; 

    for (i = 2; i <= rows; i++) {       
        for (j = 1; j <= i; j++) {       
            printf("%d ", j);
        }
        printf("\n"); 
    }

    return 0;
}


//97p 2번문제

#include <stdio.h>

int main() {
    int i, j;
    int rows = 5; 

    for (i = 0; i < rows; i++) {        
        for (j = 5; j > i; j--) {      
            printf("%d ", j);
        }
        printf("\n"); 
    }

    return 0;
}





//97p 3번문제

#include <stdio.h>

int main() {
    int i, j, k;
    int rows = 5; 

    for (i = 1; i <= rows; i++) {          
        for (j = 1; j <= rows - i; j++) {  
            printf("  ");  
        }
        for (k = i; k >= 1; k--) {         
            printf("%d ", k);
        }
        printf("\n"); 
    }

    return 0;
}


//97p 4번문제

#include <stdio.h>

int main() {
    int i, j, k, rows = 5;

    for (i = 1; i <= rows; i++) {       
        for (j = 1; j <= rows - i; j++) 
            printf("  ");

        for (k = i; k >= 1; k--)        
            printf("%d ", k);

        for (k = 2; k <= i; k++)        
            printf("%d ", k);

        printf("\n"); 
    }

    return 0;
}