#include <iostream>
#include <vector>

using namespace std;

int busca_menor(vector<int> vetor)
{   
    int menor = vetor[0];
    
    for (int i = 1; i < (int) vetor.size(); i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    } return menor;
}

int busca_menor_apos(vector<int> vetor)
{   
    int menor = vetor[0];

    for (int i = 1; i < (int) vetor.size(); i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
            return i;
        }
    }
}

int busca_menor_apartir(vector<int> vetor, int inicio)
{   
    int menor = vetor[0];

    for (int i = inicio; i < (int) vetor.size(); i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
            return i;
        }
    } return -1;
}


int busca_melhor_se (vector<int> vetor)
{
    int menor = 100;
    int menor_apos = -1;

    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] > 0 && vetor[i] < menor) {
            menor = vetor[i];
            menor_apos = i;
        }
    } return menor_apos;
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

    cout << "Digite um para comecar percorrer: ";
    int inicio{};
    cin >> inicio;

    int menor = busca_menor(vetor);
    cout << menor << '\n';
    int menor_pos = busca_menor_apos(vetor);
    cout << menor_pos << '\n';
    int menor_apartir = busca_menor_apartir(vetor, inicio);
    cout << menor_apartir << '\n';
    int melhor_se = busca_melhor_se(vetor);
    cout << melhor_se << '\n';
}
