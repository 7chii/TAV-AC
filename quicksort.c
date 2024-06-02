#include <stdio.h>
#include <time.h>

double time1, timediff;

//add numeros aleatorios no array
void pop(int vec[], int a){
    for (int i = 0; i < a; i++)  
        vec[i]=rand();
}
//func troca de posicao de ponteiros
void troca(int* x, int* y) {  
    int hold = *x;  
    *x = *y;  
    *y = hold;  
}
//funcao de particao (def do pivot)
int div(int vec[], int b, int q) {  
    int pivot = vec[q];  
    int index = (b - 1);  
  
    for (int i = b; i <= q - 1; i++) {  
        if (vec[i] < pivot) {  
            index++;  
            troca(&vec[index], &vec[i]);  
        }  
    }  
    troca(&vec[index + 1], &vec[q]);  
    return (index + 1);  
}  
void quickSort(int vec[], int b, int q) {  
    if (b < q) {  
        int in = div(vec, b, q);  
        quickSort(vec, b, in - 1);  
        quickSort(vec, in + 1, q);  
    }  
}  
  
//print array 
void printVec(int vec[], int a) {    
    //FILE *f = fopen("qsUnsortMega","wb"); 
    for (int i = 0; i < a; i++){
        printf("| %d |", vec[i]);  
        // if (f == NULL) { 
	  //  fprintf(stderr,"File exists.\n");}
    //int num = vec[i];
    //char tex[50];
   // snprintf(tex, 50, " | %d |,",num);
   // fprintf(f,tex); 
    };
   // fclose(f); 
}
void printVecB(int vec[], int a) {    
    FILE *f = fopen("qsSortMega","wb"); 
    for (int i = 0; i < a; i++){
        printf("| %d |", vec[i]);  
         if (f == NULL) { 
	    fprintf(stderr,"File exists.\n");}
    int num = vec[i];
    char tex[50];
    snprintf(tex, 50, " | %d |,",num);
    fprintf(f,tex); 
    };
    fclose(f); 
}
int main() {  
    //val para 1000000 elementos
    int num = 1000000;
    static int vec[1000000];
    //int num;
    //printf("insira num:\n");
   // scanf(" %d",&num);
    time1 = (double) clock();
    time1 = time1/CLOCKS_PER_SEC;
    //int vec[num];

    pop(vec, num);
    int p = sizeof(vec) / sizeof(vec[0]);

    printVec(vec, p);
    quickSort(vec, 0, p - 1);  
    printVec(vec, p);  
    timediff = ((double) clock()/CLOCKS_PER_SEC)-time1;
    printf("tempo d execucao: %f.",timediff);  
} 