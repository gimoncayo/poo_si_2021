#include <iostream>
#include <vector>

using namespace std;

vector<int> clonar(const vector <int> & vetor)
{   
    vector <int> novo_vetor{};
    for (int i = 0; i < (int) vetor.size(); ++i) {
        novo_vetor.push_back(vetor[i]);
    } 
    
    return novo_vetor;
} 

vector<int> homens(const vector <int> & vetor)
{
    vector <int> peguei_homem{};
    for (int i = 0; i < (int) vetor.size(); ++i) {
        if (vetor[i] > 0) {
            peguei_homem.push_back(vetor[i]);
        }
    } 

    return peguei_homem;
}

vector<int> calmos(const vector <int> & vetor)
{
    vector <int> peguei_calmos{};
    for (int i = 0; i < (int) vetor.size(); ++i) {
        if (vetor[i] > 0 && vetor[i] < 10) {
            peguei_calmos.push_back(vetor[i]);
        }
    } 

    return peguei_calmos;
}

vector<int> calmas(const vector <int> & vetor)
{
   vector <int> peguei_calmas{};
    for (int i = 0; i < (int) vetor.size(); ++i) {
        if (vetor[i] < 0 && vetor[i] > -10) {
            peguei_calmas.push_back(vetor[i]);
        }
    } 
    return peguei_calmas;
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
    
    vector<int> clone = clonar(vetor);
    cout << clone << '\n';

    vector<int> pegar_homens = homens(vetor);
    cout << pegar_homens << '\n';

    vector<int> pegar_calmos = calmos(vetor);
    cout << pegar_calmos << '\n';

    vector<int> pegar_calmas = calmas(vetor);
    cout << pegar_calmas << '\n';
}