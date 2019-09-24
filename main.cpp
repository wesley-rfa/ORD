#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>


using namespace std;

/*--ESSA VERSÃO É IMPLEMENTADA PARA VETORES DE ENTRADA E SAIDA INDEXADOS EM 0--*/

/*O algoritmo utiliza a classe vector para armazenar o vetor de entrada lido a partir de um arquivo .txt

Parâmetros: A[]: arquivo de entrada
            B[]: arquivo de saída
            C[]: vetor auxiliar
            N: Tamanho de A[]
            K= Valor Máximo contido em A

Arquivo de entrada.txt: Primeiro elemento é o K, seguido do vetor de entrada, um em cada linha.
    exemplo: 5
             4
             3
             5
             1
             2

*/

void Counting_Sort(vector<int>& A, int K){

    int N = A.size();
    int B[N];
    int C[K+1];

    for(int i=0; i<=K;i++){//ZERA O VETOR AUXILIAR
        C[i]=0;
    }

    for(int i=0; i<N;i++){//CONTAGEM DE OCORRENCIAS
        C[A[i]]++;

    }

    for(int i=0; i<K;i++){//CONTABILIZA EM QUAL POSIÇÃO DEVE SER INSERIDO
        C[i+1]=C[i+1] + C[i];

    }

    for(int i = N-1; i>=0;i--){//ORDENA
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }

    for(int i=0; i<N;i++){//PRINTA SAIDA
        cout<<B[i]<<" ";
    }

}

int main(){

    vector <int> A;
    int count=0, aux=0, K=-1;
    ifstream arquivo;

    arquivo.open("entrada.txt");

    if(arquivo.is_open()){
            arquivo >> K;
        while(!arquivo.eof()){
           arquivo >> aux;
           A.push_back(aux);
           count++;
        }
        arquivo.close();
    } else {cout << "Não foi possível abrir o arquivo!";}

    clock_t begin = clock();
    Counting_Sort(A, K);
    clock_t end = clock();

    double elapsed_secs = (double)(end - begin)*1000 / CLOCKS_PER_SEC;

	printf("\nTempo de processamento = %f\n", elapsed_secs);

    return 0;
}
