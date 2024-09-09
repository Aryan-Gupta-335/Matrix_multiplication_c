#include<stdio.h>
#include<stdlib.h>
int main(){
    int row1,col1,row2,col2;
    printf("Enter row 1: ");
    scanf("%d",&row1);
    printf("Enter col 1: ");
    scanf("%d",&col1);
    printf("Enter row 2: ");
    scanf("%d",&row2);
    printf("Enter col 2: ");
    scanf("%d",&col2);
    if(col1!=row2){
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }
    int **m1=(int**)malloc(row1*sizeof(int*));
    for(int i=0;i<row1;i++){
        m1[i]=(int*)malloc(col1*sizeof(int));
    }
    printf("Enter elements of the first matrix:\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("Enter element matrix1 [%d] [%d]: ",i,j);
            scanf("%d",&m1[i][j]);
        }
    }
    printf("First matrix:\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("%d ",m1[i][j]);
        }
        printf("\n");
    }
    int **m2=(int**)malloc(row2*sizeof(int*));
    for(int i=0;i<row2;i++){
        m2[i]=(int*)malloc(col2*sizeof(int));
    }
    printf("Enter elements of the second matrix:\n");
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            printf("Enter element matrix2 [%d] [%d]: ",i,j);
            scanf("%d",&m2[i][j]);
        }
    }
    printf("Second matrix:\n");
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            printf("%d ",m2[i][j]);
        }
        printf("\n");
    }
    int **rm=(int**)malloc(row1*sizeof(int*));
    for(int i=0;i<row1;i++){
        rm[i]=(int*)malloc(col2*sizeof(int));
    }
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            rm[i][j]=0;
            for(int k=0;k<col1;k++){
                rm[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    printf("Resultant matrix:\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            printf("%d ",rm[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<row1;i++){
        free(m1[i]);
        free(rm[i]);
    }
    for(int i=0;i<row2;i++){
        free(m2[i]);
    }
    free(m1);
    free(m2);
    free(rm);
    return 0;
}
