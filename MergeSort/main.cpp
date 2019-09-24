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

void intercalar(vector<int>& A, int *W,int inicio,int meio, int fim){

    for(int k=inicio;k<=fim;k++){
        W[k]=A[k];
    }
    int i=inicio,j=meio+1;

    for(int k=inicio;k<=fim;k++){
        if(i>meio){A[k]=W[j++];}
        else if(j>fim){A[k]=W[i++];}
        else if(W[i]<W[j]){A[k]=W[i++];}
        else A[k] = W[j++];
    }
}

void Merge_Sort(vector<int>& A, int *W,int inicio, int fim){

    if(inicio<fim){
        int meio = (inicio+fim)/2;
        Merge_Sort(A,W,inicio,meio);//primeira metade
        Merge_Sort(A,W,meio+1,fim);//segunda metade
        intercalar(A,W,inicio,meio,fim);
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

    int W[A.size()];//vetor auxiliar

    clock_t begin = clock();
    Merge_Sort(A,W,0,A.size()-1);
    clock_t end = clock();

    for(int i=0; i<count;i++){//PRINTA SAIDA
        cout<<A[i]<<" ";
    }

    double elapsed_secs = (double)(end - begin)*1000 / CLOCKS_PER_SEC;

	printf("\nTempo de processamento = %f\n", elapsed_secs);

    return 0;
}
