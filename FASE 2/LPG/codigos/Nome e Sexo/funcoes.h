void limparTela (){
    printf("\033[2J\033[H");
}

char entradaGenero (){
    char genero;
    int ok = 1;

    while(ok){
        scanf(" %c", &genero);
        
        if(genero == 'f' || genero == 'm'){
            ok = 0;
        }else printf("Digite novamente.\n");
    }
    return genero;
}