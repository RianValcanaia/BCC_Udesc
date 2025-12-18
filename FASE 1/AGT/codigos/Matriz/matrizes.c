#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define TAM 12
int main(){

    if(TAM % 2 == 0){
        for (int i = 0; i < TAM; i++){
            if (i<TAM/2){
                for (int j = 0; j < TAM; j++){
                    if (j >= i && j <= TAM-i-1){
                        printf(" ");
                    }else{
                        printf("#");
                    }
                }
            }else{
            for (int j = 0; j < TAM; j++){
                    if (j <= i && j >= TAM-i-1){
                        printf(" ");
                    }else{
                        printf("#");
                    }
                } 
            }
            printf("\n");
        }
    }else {
        for (int i = 0; i < TAM; i++){
            if (i<TAM/2){
                for (int j = 0; j < TAM; j++){
                    if (j > i && j < TAM-i-1){
                        printf(" ");
                    }else{
                        printf("#");
                    }
                }
            }else{
            for (int j = 0; j < TAM; j++){
                    if (j < i && j > TAM-i-1){
                        printf(" ");
                    }else{
                        printf("#");
                    }
                } 
            }
            printf("\n");
        }

    }
    printf("\n\n");

    if(TAM % 2 == 0){
        for (int i = 0; i < TAM; i++){
            if (i<TAM/2){
                for (int j = 0; j < TAM; j++){
                    if (j >= i && j <= TAM-i-1){
                        printf("#");
                    }else{
                        printf(" ");
                    }
                }
            }else{
            for (int j = 0; j < TAM; j++){
                    if (j <= i && j >= TAM-i-1){
                        printf("#");
                    }else{
                        printf(" ");
                    }
                } 
            }
            printf("\n");
        }
    }else {
        for (int i = 0; i < TAM; i++){
            if (i<TAM/2){
                for (int j = 0; j < TAM; j++){
                    if (j > i && j < TAM-i-1){
                        printf("#");
                    }else{
                        printf(" ");
                    }
                }
            }else{
            for (int j = 0; j < TAM; j++){
                    if (j < i && j > TAM-i-1){
                        printf("#");
                    }else{
                        printf(" ");
                    }
                } 
            }
            printf("\n");
        }

    }
    printf("\n\n");

    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if (j<i){
                printf(" ");
            }else{
                printf("#");
            }
        }
        printf("\n");
    }
    printf("\n\n");
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if (j>i){
                printf(" ");
            }else{
                printf("#");
            }
        }
        printf("\n");
    }

    printf("\n\n");
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if (i > j){
                printf(" ");
            }else{
                printf("#");
            }
        }
        printf("\n");
    }
    printf("\n\n");
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if (j>TAM-i-1){
                printf(" ");
            }else{
                printf("#");
            }
        }
        printf("\n");
    }
    printf("\n\n");
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if (j<TAM-i-1){
                printf(" ");
            }else{
                printf("#");
            }
        }
        printf("\n");
    }



return 0;
}