#include <stdio.h>

#define VACIO ' '
#define BLANCO 'B'
#define NEGRO 'N'

typedef struct {
    char tipo;
    char color;
}Pieza;

Pieza tablero [8][8];

void inicializarTablero(){
    char orden[]= { 'T', 'C', 'A', 'Q', 'K', 'A', 'C', 'T',};

    for (int i = 0; i < 8; i++){
        tablero[7][i].tipo = orden[i];
        tablero[7][i].color = NEGRO;

        tablero[6][i].tipo = 'P';
        tablero[6][i].color = NEGRO;

        tablero[1][i].tipo = 'P';
        tablero[1][i].color = BLANCO;

        tablero[0][i].tipo = orden[i];
        tablero[0][i].color = BLANCO;

        for(int j = 2; j < 6; j++){
            tablero[j][i].tipo = VACIO;
            tablero[j][i].color = VACIO;
        }
    }
}

void imprimirTablero(){
    printf("    A    B    C    D    E    F    G    H\n");
    for (int i = 7; i >= 0; i--){
        printf("  +---+---+---+---+---+---+---+---+---+---+\n");
        printf("%d", i + 1);
        for (int j = 0; j < 8; j++){
            if (tablero[i][j].tipo == VACIO)
                printf(" |  ");
            else
                printf(" | %c%c", tablero[i][j].tipo, tablero[i][j].color);
        }
        printf(" |\n");
    }
    printf("  +---+---+---+---+---+---+---+---+---+---+\n");
}

void moverPieza (int oi, int oj, int di, int dj){
    tablero[di][dj] = tablero[oi][oj];
    tablero[oi][oj].tipo = VACIO;
    tablero[oi][oj].color = VACIO;
}

int main(){
    inicializarTablero();
    char turno = BLANCO;
    int opcion;

    while(1){
        imprimirTablero();
        printf("Turno de las piezas %s.\n", turno == BLANCO? "blancas" : "negras");
        printf("Opciones:\n 1: Mover una pieza\n 0: Rendirse\n");
        printf("Ingrese un numero: ");
        scanf("%d", &opcion);

        if(opcion == 0){
            printf("El juegador de piezas %s se rinde.\n", turno == BLANCO? "blancas" : "negras");
            break;
        } else if (opcion == 1){
            char ori[3], des [3];
            printf("Inserte la coordenada de origen (ej: E2): ");
            scanf("%s", ori);
            printf("Inserte la coordenada de destino (ej: E4): ");
            scanf("%s", des);

            int oi = ori[1] - '1';
            int oj = ori[0] - 'A';
            int di = des[1] - '1';
            int dj = des[0] - 'A';

            if (oi < 0 || oi > 7 || oj < 0 || oj > 7 || di < 0 || di > 7 || dj < 0 || dj > 7){
                printf("Movimiento fuera de rango.\n");
                continue;
            }
            if (tablero[oi][oj].color != turno){
                printf("Esa pieza no te pertenece.\n");
                continue;
            }
            moverPieza(oi, oj, di, dj);
            turno = (turno == BLANCO) ? NEGRO : BLANCO;
        }
    }
    return 0;
}
