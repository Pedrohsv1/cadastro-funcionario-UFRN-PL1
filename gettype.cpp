#include <iostream>
#include "gettype.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

using namespace std;

// Função para capturar tecla (multiplataforma)
int getKey() {
    #ifdef _WIN32
        return _getch();
    #else
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt); // salva config atual
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // modo raw
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar(); // lê caractere
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restaura config
        return ch;
    #endif
}

int getType() {
    int option = 0;
    bool running = true;

    while (running) {
        system("clear"); // ou "cls" no Windows
        cout << "Use ← e → para escolher. Pressione Enter para confirmar.\n\n";

        if (option == 0) {
            cout << ">> Desenvolvedor <<    Gerente       Estagiario   \n";

        } else if (option == 1) {
            cout << "   Desenvolvedor    >> Gerente <<    Estagiario   \n";

        } else {
            cout << "   Desenvolvedor       Gerente    >> Estagiario <<\n";

        }

        int key = getKey();

        #ifdef _WIN32
                if (key == 224) { // tecla especial (seta)
                    key = getKey();
                    if (key == 75 && option > 0) {option = (option - 1) % 3;
                    } else if (key == 75 && option == 0) option = 2; // seta esquerda

                    if (key == 77) option = ( option + 1 ) % 3; // seta direita
                } else if (key == 13) { // Enter
                    running = false;
                }
        #else
                if (key == 27) { // tecla ESC
                    key = getKey();
                    cout << option << endl;
                    if (key == 91) {
                        key = getKey();

                        if (key == 68 && option > 0) {option = (option - 1) % 3;
                        } else if (key == 68 && option == 0) option = 2; // seta esquerda

                        if (key == 67) option = ( option + 1 ) % 3; // seta direita
                    }
                } else if (key == 10) { // Enter (Linux)
                    running = false;
                }
        #endif

    }

    if(option == 0){ 
        cout << "Você escolheu Desenvolvedor." << endl;
    } else if(option == 1){
        cout << "Você escolheu Gerente." << endl;
    } else {
        cout << "Você escolheu Estagiario." << endl;
    }

    return option;
}
