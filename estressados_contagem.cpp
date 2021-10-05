#include <iostream>
#include <vector>

using namespace std;

float stress_medio(vector<int> vetor, int size)
{
    float soma = 0;

    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] < 0) {
            vetor[i] *= -1;
        } soma = vetor[i] + soma;
    } 

    float media = (soma / size);
    
    return media;
}

int homem_ou_mulher(vector<int> vetor)
{
    int homens = 0; 
    int mulheres = 0;

    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] > 0) {
            homens++;
        } else if (vetor[i] < 0) {
            mulheres++;
        }
    }

    if (homens > mulheres && mulheres < homens) {
        return 1;
    } else if (homens < mulheres && mulheres > homens) {
        return 2;
    } else if (homens == mulheres) {
        return 3;
    }
}

int metade_mais_estressada(vector<int> vetor)
{   
    float metade = (int) vetor.size() / 2;
    float soma_primeira = 0, soma_segunda = 0;

    for (int i = 0; i < metade; i++) {
        if (vetor[i] < 0) {
            vetor[i] *= -1;
        } soma_primeira = vetor[i] + soma_primeira;
    }

    for (int i = metade; i < (int) vetor.size(); i++) {
        if (vetor[i] < 0) {
            vetor[i] *= -1;
        } soma_segunda = vetor[i] + soma_segunda;
    }

    if (soma_primeira > soma_segunda && soma_segunda < soma_primeira) {
        return 1;
    } else if (soma_primeira < soma_segunda && soma_segunda > soma_primeira) {
        return 2;
    } else if (soma_primeira == soma_segunda) {
        return 3;
    }

}

float media_stress_homens(vector<int> vetor) 
{
    float h_soma = 0, soma_m = 0, h_media = 0, media_m = 0, mulheres = 0, homens = 0;

   for (int i = 0; i < (int) vetor.size(); i++) {
       if (vetor[i] < 0) {
           vetor[i] *= -1;
           soma_m = vetor[i] = soma_m;
           mulheres++;
        } else if (vetor[i] > 0) { 
            h_soma = vetor[i] + h_soma;
            homens++;
        }
    }    

    media_m = soma_m / mulheres;
    h_media = h_soma / homens;
    
    if (h_media > media_m) {
        return h_media;
    } else {
        return -1;
    }
}


int main()
{
    int size = 0;

    cout << "Tamanho do vetor: ";
    cin >> size;

    vector <int> vetor{};
    int x;

    for (int i = 0; i < size; ++i) {
        cout << "Adicionar um numero ao vetor: ";
        cin >> x; 
        vetor.push_back(x);
    }

    float media_stress = stress_medio(vetor, size);
    cout << media_stress << '\n';

    cout << "Se a funcao retornar 1 significa que ha mais homens, 2 mais mulheres e 3 empate" << '\n';
    cout << homem_ou_mulher(vetor) << '\n';

    cout << "Se a funcao retornar 1 significa que a primeira parte e mais estressada, 2 a segunda parte e 3 empate" << '\n';
    cout << metade_mais_estressada(vetor) << '\n';

    cout << media_stress_homens(vetor) << '\n';
}