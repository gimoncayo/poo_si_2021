#include <iostream>
#include <vector>

using namespace std;

vector<int> invertido(const vector <int> & vetor)
{   
    vector <int> novo_vetor{};
    for (int i = (int) vetor.size() - 1; i >= 0; --i) {
        novo_vetor.push_back(vetor[i]);
    } 
    
    return novo_vetor;
} 

void invertido_auxiliar(vector <int> & vetor)
{
    int auxiliar;
    int size = (int) vetor.size();
    for (int i = 0; i < size / 2; ++i) {
        auxiliar = vetor[i];
        vetor[i]= vetor[(size - 1) - i];
        vetor[(size - 1) - i] = auxiliar;
    }
}

int sorteio(const vector <int> & vetor)
{
    int sorte = rand() % (int) vetor.size();
    int n = vetor[sorte];

    return n;
}

void embaralha(vector <int> & vetor)
{
    for (int i = 0; i < (int) vetor.size(); ++i) {
        int n = rand() % (int) vetor.size();
        
        int aux = vetor[i];
        vetor[i] = vetor[n];
        vetor[n] = aux;
    }
}

void ordenar(vector <int> & vetor)
{
    for (int i = 0; i < vetor.size(); ++i) {
        for (int x = i; x < vetor.size(); ++x) {
            if (vetor[i] > vetor[x]) {
                int aux = vetor[i];
                vetor[i] = vetor[x];
                vetor[x] = aux;
            }
        }
    }
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> & vetor)
{
    os << "[";
    for (int i = 0; i < (int) vetor.size(); ++i)
    {
        os << vetor[i];
        if (i != (int) vetor.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
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
    
    vector<int> inverter = invertido(vetor);
    cout << inverter << '\n';

    invertido_auxiliar(vetor);
    cout << vetor << endl;

    int sortear = sorteio(vetor);
    cout << sortear << '\n';

    embaralha(vetor);
    cout << vetor << endl;

    ordenar(vetor);
    cout << vetor << endl;
}