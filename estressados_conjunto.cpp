#include <iostream>
#include <vector>

using namespace std;

vector<int> exclusivos(const vector <int> & vetor)
{
    vector <int> repetido;
    bool aux;
    
    for (int i = 0; i < (int) vetor.size(); ++i) {
        aux = false;
        for (int x = 0; x < i; ++x) {
            if (vetor[i] == vetor[x]) {
                aux = true;
                break;
            }
        }
        if (aux == false) {
            repetido.push_back(vetor[i]);
        }
    } 

    return repetido;
}

vector<int> diferentes(const vector <int> & vetor)
{
    vector <int> repetido;
    bool aux;

    for (int i = 0; i < (int) vetor.size(); ++i) {
        for (int x = 0; x < i; ++x) {
            if (vetor[i] == repetido[x] || vetor[i] * -1 == repetido[x]) {
                aux = true;
                break;
            }
        }
        if (aux == true) {
            aux = false;
            continue;
        } else {
            if (vetor[i] < 0) {
                repetido.push_back(vetor[i] * -1);
            } else {
                repetido.push_back(vetor[i]);
            }
        }
    } 

    return repetido;
}

vector<int> abandonados(const vector <int> & vetor)
{
    bool aux;
    vector<int> vetor2;
    vector<int> vetor3;

    for (int i = 0; i < (int) vetor.size(); ++i) {
        for (int x = 0; x < (int) vetor2.size(); ++x) {
            if (vetor[i] == vetor2[x]) {
                aux = true;
                vetor3.push_back(vetor[i]);
                break;
            }
        }
        if (aux == true) {
            aux = false;
            continue;
        } else {
            vetor2.push_back(vetor[i]);
        }
    } 

    return vetor3;
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
    
    vector<int> exclusivo = exclusivos(vetor);
    cout << exclusivo << '\n';

    vector<int> diferente = diferentes(vetor);
    cout << diferente << '\n';

    vector<int> abandonado = abandonados(vetor);
    cout << abandonado << '\n';
}