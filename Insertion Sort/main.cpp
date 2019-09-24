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


void Insertion_Sort(vector<int>& A){
    int x,j;

    for(int i=1;i< A.size(); i++){
        x = A[i];
        j=i-1;
        while((j>=0)&&A[j] > x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
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
    Insertion_Sort(A);
    clock_t end = clock();

    for(int i=0; i<count;i++){//PRINTA SAIDA
        cout<<A[i]<<" ";
    }

    double elapsed_secs = (double)(end - begin)*1000 / CLOCKS_PER_SEC;

	printf("\nTempo de processamento = %f\n", elapsed_secs);

    return 0;
}
