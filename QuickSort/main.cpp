#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

/*--ESSA VERSÃO É IMPLEMENTADA PARA VETOR DE ENTRADA INDEXADO EM 0--*/

/*O algoritmo utiliza a classe vector para armazenar o vetor de entrada lido a partir de um arquivo .txt


Arquivo de entrada.txt: vetor de entrada, um em cada linha.
    exemplo: 4
             6
             7
             3
             5
             1
             2
             8

*/

void trocar(vector<int>& A,int i, int j){
    int aux=A[i];
    A[i]=A[j];
    A[j]=aux;
}


int separar(vector<int>& A,int esquerda, int direita){
    int i =esquerda+1;
    int j =direita;
    int pivo= A[esquerda];

    while(i<=j){
        if(A[i]<=pivo){i++;}
        else if(A[j]>pivo){j--;}
        else if(i<=j){
            trocar(A,i,j);
            i++;
            j--;
        }
    }
    trocar(A,esquerda,j);
    return j;
}

void Quick_Sort(vector<int>& A,int esquerda, int direita){

    if(esquerda<direita){
        int j = separar(A,esquerda, direita);
        Quick_Sort(A, esquerda, j-1);
        Quick_Sort(A, j+1, direita);
    }

}

int main(){

    vector <int> A;
    int count=0, aux=0;
    ifstream arquivo;

    arquivo.open("entrada.txt");

    if(arquivo.is_open()){
        while(!arquivo.eof()){
           arquivo >> aux;
           A.push_back(aux);
           count++;
        }
        arquivo.close();
    } else {cout << "Não foi possível abrir o arquivo!";}


    clock_t begin = clock();
    Quick_Sort(A,0,A.size()-1);
    clock_t end = clock();

    for(int i=0; i<count;i++){//PRINTA SAIDA
        cout<<A[i]<<" ";
    }

    double elapsed_secs = (double)(end - begin)*1000 / CLOCKS_PER_SEC;

	printf("\nTempo de processamento = %f\n", elapsed_secs);

    return 0;
}
