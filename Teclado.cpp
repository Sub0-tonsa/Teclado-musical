/*
    nome: Teclado.cpp
    autor: Giovanni tonsa
    data: 23/03/2026
    descricao: Programa que simula um teclado musical por teclas
*/

#include <stdio.h>
#include <windows.h>

int oitava = 4;
int duracao = 300;
char ultimaNota[20] = "Nenhuma";

void tocarNota(int frequencia, int tempo, const char nome[]) {
    system("cls");

    printf("=====================================\n");
    printf("         TECLADO MUSICAL C++         \n");
    printf("=====================================\n\n");

    printf("Oitava atual : %d\n", oitava);
    printf("Duracao      : %d ms\n", duracao);
    printf("Ultima nota  : %s\n\n", nome);

    printf("        W   E       T   Y   U\n");
    printf("        #   #       #   #   #\n");
    printf("    A   S   D   F   G   H   J\n");
    printf("    C   D   E   F   G   A   B\n\n");

    printf("Z = Oitava -      X = Oitava +\n");
    printf("C = Curta         V = Media         B = Longa\n");
    printf("Q = Sair\n\n");

    Beep(frequencia, tempo);
}

int getFrequenciaBase(char tecla) {
    switch (tecla) {
        case 'A': case 'a': return 261; // C
        case 'W': case 'w': return 277; // C#
        case 'S': case 's': return 293; // D
        case 'E': case 'e': return 311; // D#
        case 'D': case 'd': return 329; // E
        case 'F': case 'f': return 349; // F
        case 'T': case 't': return 370; // F#
        case 'G': case 'g': return 392; // G
        case 'Y': case 'y': return 415; // G#
        case 'H': case 'h': return 440; // A
        case 'U': case 'u': return 466; // A#
        case 'J': case 'j': return 493; // B
        default: return 0;
    }
}

void getNomeNota(char tecla, char nome[]) {
    switch (tecla) {
        case 'A': case 'a': sprintf(nome, "C"); break;
        case 'W': case 'w': sprintf(nome, "C# / Db"); break;
        case 'S': case 's': sprintf(nome, "D"); break;
        case 'E': case 'e': sprintf(nome, "D# / Eb"); break;
        case 'D': case 'd': sprintf(nome, "E"); break;
        case 'F': case 'f': sprintf(nome, "F"); break;
        case 'T': case 't': sprintf(nome, "F# / Gb"); break;
        case 'G': case 'g': sprintf(nome, "G"); break;
        case 'Y': case 'y': sprintf(nome, "G# / Ab"); break;
        case 'H': case 'h': sprintf(nome, "A"); break;
        case 'U': case 'u': sprintf(nome, "A# / Bb"); break;
        case 'J': case 'j': sprintf(nome, "B"); break;
        default: sprintf(nome, "Nenhuma");
    }
}

int ajustarOitava(int frequenciaBase) {
    if (oitava == 3) return frequenciaBase / 2;
    if (oitava == 5) return frequenciaBase * 2;
    if (oitava == 6) return frequenciaBase * 4;
    if (oitava == 7) return frequenciaBase * 8;
    return frequenciaBase; // oitava 4
}

void desenharTela() {
    system("cls");

    printf("=====================================\n");
    printf("         TECLADO MUSICAL C++         \n");
    printf("=====================================\n\n");

    printf("Oitava atual : %d\n", oitava);
    printf("Duracao      : %d ms\n", duracao);
    printf("Ultima nota  : %s\n\n", ultimaNota);

    printf("        W   E       T   Y   U\n");
    printf("        #   #       #   #   #\n");
    printf("    A   S   D   F   G   H   J\n");
    printf("    C   D   E   F   G   A   B\n\n");

    printf("A = C      W = C# / Db\n");
    printf("S = D      E = D# / Eb\n");
    printf("D = E\n");
    printf("F = F      T = F# / Gb\n");
    printf("G = G      Y = G# / Ab\n");
    printf("H = A      U = A# / Bb\n");
    printf("J = B\n\n");

    printf("Z = Oitava -      X = Oitava +\n");
    printf("C = Curta         V = Media         B = Longa\n");
    printf("Q = Sair\n");
}

void tecladoLivre() {
    char tecla;
    char nome[20];
    int frequenciaBase, frequenciaFinal;

    strcpy(ultimaNota, "Nenhuma");

    while (1) {
        desenharTela();
        printf("\nDigite uma tecla: ");
        scanf(" %c", &tecla);

        if (tecla == 'q' || tecla == 'Q') {
            break;
        }

        if (tecla == 'z' || tecla == 'Z') {
            if (oitava > 3) oitava--;
            continue;
        }

        if (tecla == 'x' || tecla == 'X') {
            if (oitava < 7) oitava++;
            continue;
        }

        if (tecla == 'c' || tecla == 'C') {
            duracao = 150;
            continue;
        }

        if (tecla == 'v' || tecla == 'V') {
            duracao = 300;
            continue;
        }

        if (tecla == 'b' || tecla == 'B') {
            duracao = 600;
            continue;
        }

        frequenciaBase = getFrequenciaBase(tecla);

        if (frequenciaBase != 0) {
            getNomeNota(tecla, nome);
            frequenciaFinal = ajustarOitava(frequenciaBase);
            sprintf(ultimaNota, "%s%d", nome, oitava);
            tocarNota(frequenciaFinal, duracao, ultimaNota);
        } else {
            printf("\nTecla invalida!\n");
            Beep(120, 150);
            Sleep(700);
        }
    }
}

void mostrarMenu() {
    printf("=====================================\n");
    printf("         PROJETO TECLADO             \n");
    printf("=====================================\n\n");
    printf("1 - Abrir teclado musical\n");
    printf("2 - Sair\n\n");
    printf("Escolha: ");
}

int main() {
    int opcao;

    puts("Projeto Teclado Musical - Giovanni Tonsa");

    do {
        system("cls");
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                tecladoLivre();
                break;
            case 2:
                printf("\nSaindo...\n");
                Sleep(700);
                break;
            default:
                printf("\nOpcao invalida!\n");
                Sleep(1000);
        }
    } while (opcao != 2);

    return 0;
}