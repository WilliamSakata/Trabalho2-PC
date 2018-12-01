#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <values.h>

const int infinity = MAXINT/2;

float **alocamat(int lin, int col);
void inicializaMat(float **mat, int nVertices);
void imprimeMat(float **mat, int nVertices);

int main(){
  FILE *arq;
  char nomeArq[20];
  int tamMat, i, j, k;
  float w;//w=weight
  float **matrizadj, **matrizdist;

  printf("Digite o nome do arquivo a ser aberto:");
  fgets(nomeArq, 20, stdin);
  //scanf("%s", nomeArq);

  arq=fopen(nomeArq,"r");

  if(arq==NULL){
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }else{
    fscanf(arq, "%d", &tamMat);
    matrizadj = alocamat(tamMat, tamMat);
    matrizdist = alocamat(tamMat, tamMat);

    inicializaMat(matrizadj, tamMat);
    inicializaMat(matrizdist, tamMat);

    while(fscanf(arq, "%d, %d, %f", &i,&j,&w)!=EOF){
      matrizadj[i-1][j-1]=w;
    }

    for(k=0;k<tamMat;k++){
      for(i=0;i<tamMat;i++){
        if(i!=k&&matrizadj[i][k]<infinity){
          for(j=0;j<tamMat;j++){
            if(matrizadj[i][j]>matrizadj[i][k]+matrizadj[k]]j){
              matrizdist[i][j]=matrizadj[i][k]+matrizadj[k][j];
            }
          }
        }
      }
    }

  }
  free(matrizadj);
  free(matrizdist);
}

void inicializaMat(float **mat, int nVertices){
  int i, j;
    for(i=0;i<nVertices;i++){
      for(j=0;j<nVertices;j++){
        if(i==j){
          mat[i][j]=0;
        }else{
          mat[i][j]= infinity;
        }
      }
    }
}

float **alocamat(int lin, int col){
  int i;
  float **m;

  m=(float**)malloc(sizeof(float*)*col);
  for(i=0;i<lin;i++){
    m[i]=(float*)malloc(sizeof(float)*col);
  }
}

void imprimeMat(float **mat, int nVertices){
  int i,j;

  printf("\n");

  for(i=0;i<nVertices;i++){
    for(j=0;j<nVertices;j++){
      printf("%.2f ", mat[i][j]);
    }
    printf("\n");
  }

}
