#include <iostream>
#include <vector>
#include <algorithm> // Para sort
#include <numeric>   // Para accumulate

using namespace std;

// Función para verificar si es escalera
bool esEscalera(const vector<int>& dados) {
    for (int i = 0; i < 6; ++i) {
        if (dados[i] != i + 1) {
            return false;
        }
    }
    return true;
}

// Función para verificar si es sexteto
bool esSexteto(const vector<int>& dados, int& valor) {
    valor = dados[0];
    for (int i = 1; i < 6; ++i) {
        if (dados[i] != valor) {
            return false;
        }
    }
    return true;
}

// Función para calcular la puntuación de un lanzamiento
int calcularPuntuacion(vector<int>& dados) {
    sort(dados.begin(), dados.end());

    if (esEscalera(dados)) {
        return -1;
    }

    int valorSexteto;
    if (esSexteto(dados, valorSexteto)) {
        return valorSexteto == 6 ? 0 : valorSexteto * 10;
    }

    return accumulate(dados.begin(), dados.end(), 0);
}

// Función para imprimir los dados
void imprimirDados(const vector<int>& dados) {
    for (int dado : dados) {
        cout << dado << " ";
    }
    cout << endl;
}

int main() {
    vector<int> dados = {1, 2, 3, 4, 5, 6};

    cout << "Dados: ";
    imprimirDados(dados);

    int puntuacion = calcularPuntuacion(dados);
    cout << "Puntuacion: " << puntuacion << endl;

    return 0;
}
