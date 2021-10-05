#include <iostream>

bool existe(int vet[], int size, int value)
{
    for (int i = 0; i < size; i++) {
        if (vet[i] == value) {
            return true;
        }
    } return false;
}


int repeticao(int vet[], int size, int x)
{
    int contador = 0;

    for (int i = 0; i < size; i++) {
        if (vet[i] == x) {
            contador++;
        }
    } return contador; 
}

int procura_valor(int vet[], int size, int x)
{
    for (int i = 0; i < size; i++) {
        if (vet[i] == x) {
            return i;
        }
    } return -1;
}

int procura_valor_apartir(int vet[], int size, int x, int inicio)
{
    for (int i = inicio; i < size; i++) {
        if (vet[i] == x) {
            return i;
        }
    } return -1;
}


#define size 10

int main()
{
    int vet[size] = {-10, -10, -50, -67, -95, 1, 3, 20, 49, 75};

    std::cout << "Digite um numero: ";
    int x{};
    std::cin >> x;

    std::cout << "Digite um para comecar percorrer: ";
    int inicio{};
    std::cin >> inicio;

    std::cout << existe(vet, size, x) << '\n';
    std::cout << repeticao(vet, size, x) << '\n';
    std::cout << procura_valor(vet, size, x) << '\n';
    std::cout << procura_valor_apartir(vet, size, x, inicio) << '\n';


}