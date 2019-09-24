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

void Selection_Sort(vector<int>& A){

    for(int i=0;i<A.size();i++){
        int menor=i;
        for(int j=i+1;j<A.size();j++){//busca menor elemento
            if(A[j]<A[menor]){
                menor=j;
            }
        }
        trocar(A,i,menor);
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
    Selection_Sort(A);
    clock_t end = clock();

    for(int i=0; i<count;i++){//PRINTA SAIDA
        cout<<A[i]<<" ";
    }

    double elapsed_secs = (double)(end - begin)*1000 / CLOCKS_PER_SEC;

	printf("\nTempo de processamento = %f\n", elapsed_secs);

    return 0;
}
