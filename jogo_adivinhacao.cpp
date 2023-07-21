#include<iostream>
#include<Windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8); // Configuração para UTF-8

    cout << "**************************************\n";
    cout << "* Bem-vindos ao jogo da adivinhação! *\n";
    cout << "**************************************\n";

    cout << "Escolha o seu nível de dificuldade: " << endl;
    cout << "Fácil (F), M[edio (M) ou Difícil (D)" << endl;
    char dificuldade;
    cin >> dificuldade;
    int numero_tentativas;
    if(dificuldade == 'F') numero_tentativas = 15;
    if(dificuldade == 'M') numero_tentativas = 10;
    if(dificuldade == 'D') numero_tentativas = 5;

    srand(time(NULL));
    int numero_secreto = rand() % 100;
    bool nao_acertou = true;
    int tentativas = 0;
    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numero_tentativas; tentativas++){
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;
        double pontos_perdidos = abs(chute - numero_secreto)/2.0;
        pontos = pontos - pontos_perdidos;
        cout << "O valor do seu chute é: " << chute << endl;
        bool acertou = chute == numero_secreto;
        bool maior = chute > numero_secreto;

        if(acertou){
            cout << "Parabéns! você acertou o número secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if(maior){
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }
        else{
            cout << "Seu chute foi menor que o número secreto!" << endl;
        }
    }
    cout << "Fim do jogo!" << endl;
    if(nao_acertou){
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Você acertou o número secreto em " << tentativas << " tentativas!" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos" << endl;
    }

}

