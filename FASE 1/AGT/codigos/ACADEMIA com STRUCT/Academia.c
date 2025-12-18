#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

struct Cliente {
    char nome[200];
    char nomePlano[50];
    char tipoAdesao[10];
    char periodo[8];
    int valor;
};

struct Personal {
    char nomePersonal[200];
    int credenciamento;
    char enderecoPersonal[200];
    int telefonePersonal;
    char emailPersonal[200];
    int cpfPersonal;
    char tipoDeContrado[50];
    float valorPersonalHr;
    int inicioDiaPersonal;
    int inicioMesPersonal;
    int inicioAnoPersonal;
};

void limparTerminal() {
    printf("\033[H\033[J"); 
    //Sequencia de ANSI
    // \033 inicia a sequencia de ANSI
    // [H joga o mouse para a posição inicial (1,1) "Home"
    // \033 inicia novamente
    //[J deleta da posição do pause até o final do terminal
}

//protótipo da função
int valor (char plano, char tipoAdesao[10], char periodo[8]);

int main(){
    setlocale(LC_ALL,""); //funcao para permitir caracteres especiais

    //variáveis globais
    char plano; // tipo primitivo
    char periodo[8], nome[200], tipoAdesao[10], nomePlano[50], outro[10];// estrutura de dados
    struct Cliente cliente;
    struct Personal personal;
    int entrada, sair = 0;

	//Tela Inicial
    limparTerminal();
    printf("⠀⠀⠀⠀⠀⠀⣀⣀⣀⠀⣴⣿⣿⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣷⡄⠀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠶⠿⢶⣄⠀⢸⡿⠿⠀⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡿⠿⠀⡆⠀⣤⠀\n⠀⠀⠀⠀⠀⢸⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⣾⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡿⠀⣴⠶⡶⠹⡄⢸⡇⠀⠀⡄⠀⣴⣤⡄⢠⡄⢠⡄⠀⣤⣦⠀⢸⡇⠀⠀⡄⠠⣿⠤\n⠀⠀⠀⠀⠀⢸⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠁⣸⠃⢰⡇⠀⡇⢸⡟⠛⠀⡇⢸⡇⠀⡇⢸⡇⢸⡇⢸⣇⣸⡇⢸⡟⠛⠀⡇⠀⣿⠀\n⠀⠀⠀⢸⣿⢸⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⡇⣿⡇⠀⠀⠀⠀⠀⠀⠀⢸⡄⠹⣦⠾⣀⠾⠀⢸⡇⠀⠀⡇⢸⡇⠀⡇⢸⡇⢸⡇⢸⡇⢠⡄⢸⡇⠀⠀⡇⠀⣿⠀\n⠀⠀⠀⢸⣿⢸⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⡇⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠿⣄⣀⣀⣀⠀⠀⠘⠃⠀⠀⠃⠀⠛⠛⡇⠀⠛⠙⠃⠀⠛⠛⠀⠘⠃⠀⠀⠃⠀⠛⠛\n⠀⠀⠀⠀⠀⢸⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⢸⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⢿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀Bem-vindo(a)!\n⠀⠀⠀⠀⠀⠀⠉⠉⠉⠀⠻⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⡿⠃⠀⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀Aperte enter para entrar no programa:\n");

    getchar();
    limparTerminal();
	
    while(1){
        printf("[1] Adesão\n[2] Acompanhamento\n[3] Agendamento de aula experimental\n[4] Rescisão de contrato\n[5] Clientes\n[6] Profissionais da academia\n[7] Sair\n");
        while (1) {
            if (scanf("%d", &entrada) == 1 && entrada >= 1 && entrada <= 7) {
                break;
            } else {
                printf("Opção inválida. Tente novamente.\n");
                // Limpa o buffer de entrada, caso tenha entrada de um caracter;
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
        
        switch (entrada){
            case 1:
            //sistema de Adesao
            while(1){
                while(1){
                    limparTerminal();
                    //printf("Bem vindo a @FiqueFit (:\n");
                    printf("Escolha um dos planos:\na) Natação \nb) Musculação\nc) Treinamento Funcional\nd) Plano seco: musculação + funcional\ne) Plano molhado: musculação + natação\n");
                
                    //Enquanto a entrada não ser uma das opções desejadas ele irá retornar opção inválida
                    while(1){
                        scanf (" %c",&plano);
                        if((plano == 'a' || plano == 'b' || plano == 'c' || plano == 'd' || plano == 'e')){
                            break;
                        } else {
                            printf("Opção inválida. Tente novamente.\n");
                        }
                    }
                
                    limparTerminal();

                    //processamento do input do plano
                    switch (plano){
                        case 'a':
                        strcpy(nomePlano,  "Natação");
                        break;
                        
                        case 'b':
                        strcpy(nomePlano,  "Musculação");
                        break;
                        
                        case 'c':
                        strcpy(nomePlano,  "Treinamento Funcional");
                        break;
                        
                        case 'd':
                        strcpy(nomePlano,  "Plano seco: musculação + funcional");
                        break;
                        
                        case 'e':
                        strcpy(nomePlano,  "Plano molhado: musculação + natação");
                        break;
                        
                        default:
                            printf("Opção inválida! Tente novamente.");
                            system("cls");
                            break;
                        
                    }
                
                    //entrada de dados
                    
                    //Enquanto o periodo for diferente de dia e noite ele retorna opção invalida
                    printf("Digite o período desejado (dia ou noite)\n"); 
                    while(1){
                        scanf (" %s", periodo);
                        if (strcmp(periodo, "dia") == 0 || strcmp(periodo, "noite") == 0){
                            break;
                        } else {
                            printf("Opção inválida. Tente novamente.\n");
                        }
                    }
                
                    printf("Digite o nome do cliente\n");
                    scanf ("\n%[^\n]s",nome);
                    
                    /*Como os planos 'd' e 'e' nao possuem plano mensal, ja processamos eles
                    como 'anual' aqui para economizar memória e linhas nas condicionais posteriores*/
                    if ((plano == 'd') || (plano == 'e')){
                        strcpy(tipoAdesao, "anual");
                    }else{
                        printf("Digite o tipo da adesão desejada (mensal ou anual)\n");
                        while(1){
                            scanf (" %s",tipoAdesao);
                            if (strcmp(tipoAdesao, "mensal") == 0 || strcmp(tipoAdesao, "anual") == 0){
                                break;
                            } else {
                                printf("Opção inválida. Tente novamente.\n");
                            }
                        }
                        
                    }
                
                    //calculo do valor da mensalidade, chamando a funcao valor
                    int valorMensal = valor(plano, tipoAdesao, periodo);

                    //saida de dados
                    limparTerminal();
                    printf("Cliente: %s\n", nome);
                    printf("%s ( %s )\n", nomePlano, periodo);
                    printf("Pagamento %s\n", tipoAdesao);

                    //processamento dos pagamentos baseado na escolha do tipo de adesao 
                    if (strcmp(tipoAdesao, "anual") == 0) {
                        int total = valorMensal * 12;
                        printf("12 x R$ %i\n", valorMensal);
                        printf("Total: %i\n", total);
                    }else{
                        printf("R$ %i\n", valorMensal);
                    }

                    printf("\n\n[1] Alterar dados\n[2] Salvar\n[3] Voltar ao inicio\n");
                    while (1) {
                        if (scanf("%d", &entrada) == 1 && entrada >=1 && entrada <= 3) {
                            break;
                        } else {
                            printf("Opção inválida. Tente novamente.\n");
                            // Limpa o buffer de entrada, caso tenha entrada de um caracter;
                            int c;
                            while ((c = getchar()) != '\n' && c != EOF);
                        }
                    }

                    if(entrada == 2){
                        //Inicia Arquivo para Salvamento
                        FILE *arquivo = fopen("clientes.txt", "a");

                        if (arquivo == NULL) {
                            printf("Erro ao abrir o arquivo.\n");
                            return 1;
                        }

                        // Copia os valores para a struct Cliente
                        strcpy(cliente.nome, nome);
                        strcpy(cliente.nomePlano, nomePlano);
                        strcpy(cliente.tipoAdesao, tipoAdesao);
                        strcpy(cliente.periodo, periodo);
                        cliente.valor = valorMensal;

                        // Escreve os valores da struct no arquivo
                        fprintf(arquivo, "Nome: %s\n", cliente.nome);
                        fprintf(arquivo, "Nome do Plano: %s\n", cliente.nomePlano);
                        fprintf(arquivo, "Tipo de Adesão: %s\n", cliente.tipoAdesao);
                        fprintf(arquivo, "Período: %s\n", cliente.periodo);
                        fprintf(arquivo, "Valor: %d\n", cliente.valor);
                        fprintf(arquivo, "\n"); 

                        // Fecha o arquivo
                        fclose(arquivo);
                        break;
                    } else if(entrada == 3){
                        break;
                    }
                }

                limparTerminal();
                if(entrada == 2){
                    //Cadastrar outro cliente
                    printf("Outro cliente? (sim/nao): ");
                    while(1){
                        scanf("%s", outro);
                        if (strcmp(outro, "sim") == 0 || strcmp(outro, "nao") == 0){
                            break;
                        }else{
                            printf("Opção inválida. Tente novamente.\n");
                        }
                    }

                    if (strcmp(outro, "nao") == 0){
                        break;   
                    }
                }else {
                    break;
                }
                
            }
        
            break;
            case 2:
            //sistema de Acompanhamento
            break;
            case 3:
            //sistema de Agendamento de Aula experimental
            break;
            case 4:
            //Sistema Rescisão de contrato
            break;
            case 5:
            //Sistema clientes
            break;
            case 6:
                //variaveis Locais:
                char nomePersonal[200], enderecoPersonal[200], emailPersonal[200], tipoDeContrato[50];
                int credenciamento, telefonePersonal, cpfPersonal, inicioDiaPersonal, inicioMesPersonal, inicioAnoPersonal;
                float valorPersonalHr;

                limparTerminal();
                printf("[1] Cadastrar Profisional\n[2] Alterar dados do Profissional\n[3] Ver Profissionais cadastrados\n[4] Voltar ao Inicio\n");
                while (1) {
                    if (scanf("%d", &entrada) == 1 && entrada >= 1 && entrada <= 4) {
                        break;
                    } else {
                        printf("Opção inválida. Tente novamente.\n");
                        // Limpa o buffer de entrada, caso tenha entrada de um caracter;
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF);
                        }
                }

                switch (entrada){
                    case 1:
                    //cadastrar profissionais
                        while(1){
                            limparTerminal();
                            printf("Digite o nome do professor/personal:\n");
                            scanf(" %[^\n]s", &nomePersonal);
                            printf("Digite o numero do credenciamento no CONFEF/CREFs:\n");
                            scanf("%i", &credenciamento);
                            printf("Digite o endereço do profissional:\n");
                            scanf(" %[^\n]s", &enderecoPersonal);
                            printf("Digite o telefone para contato do profissional:\n");
                            scanf("%i", &telefonePersonal);
                            printf("Digite o e-mail do profissional:\n");
                            scanf(" %[^\n]s", &emailPersonal);
                            printf("Digite o CPF do profissional:\n");
                            scanf("%i", &cpfPersonal);
                            printf("Digite o tipo de contrado do proffisional (autônomo, CLT, estágiário):\n");
                            scanf(" %s[^\n]s", &tipoDeContrato);
                            printf("Digite o valor (por hora):\n");
                            scanf("%f", &valorPersonalHr);
                            printf("Digite a data de inicio do personal (dd/mm/aaaa):\n");
                            scanf("%d/%d/%d", &inicioDiaPersonal, &inicioMesPersonal, &inicioAnoPersonal);
                            printf("\n\n[1] Alterar dados\n[2] Salvar\n[3] Voltar ao inicio\n");

                            while (1) {
                                if (scanf("%d", &entrada) == 1 && entrada >= 1 && entrada <= 4) {
                                break;
                            } else {
                                printf("Opção inválida. Tente novamente.\n");
                                // Limpa o buffer de entrada, caso tenha entrada de um caracter;
                                int c;
                                while ((c = getchar()) != '\n' && c != EOF);
                                }
                            }
                        

                            if (entrada == 2){
                                //Inicia Arquivo para Salvamento
                                FILE *arquivo = fopen("profissionais.txt", "a");

                                if (arquivo == NULL) {
                                    printf("Erro ao abrir o arquivo.\n");
                                    return 1;
                                }

                                // Copie os valores para a struct Cliente
                                strcpy(personal.nomePersonal, nomePersonal);
                                personal.credenciamento = credenciamento;
                                strcpy(personal.enderecoPersonal, enderecoPersonal);
                                personal.telefonePersonal = telefonePersonal;
                                strcpy(personal.emailPersonal, emailPersonal);
                                personal.cpfPersonal = cpfPersonal;
                                strcpy(personal.tipoDeContrado, tipoDeContrato);
                                personal.valorPersonalHr = valorPersonalHr;
                                personal.inicioDiaPersonal = inicioDiaPersonal;
                                personal.inicioMesPersonal = inicioMesPersonal;
                                personal.inicioAnoPersonal = inicioAnoPersonal;

                                // Escreve os valores da struct no arquivo
                                fprintf(arquivo, "Nome: %s\n", personal.nomePersonal);
                                fprintf(arquivo, "Credenciamento: %d\n", personal.credenciamento);
                                fprintf(arquivo, "Endereço: %s\n", personal.enderecoPersonal);
                                fprintf(arquivo, "Telefone: %d\n", personal.telefonePersonal);
                                fprintf(arquivo, "E-mail: %s\n", personal.emailPersonal);
                                fprintf(arquivo, "CPF: %d\n", personal.cpfPersonal);
                                fprintf(arquivo, "Tipo de Contrato: %s\n", personal.tipoDeContrado);
                                fprintf(arquivo, "Valor (por hora): %.2f\n", personal.valorPersonalHr);
                                fprintf(arquivo, "Data de Início: %02d/%02d/%04d\n", personal.inicioDiaPersonal, personal.inicioMesPersonal, personal.inicioAnoPersonal);
                                fprintf(arquivo, "\n"); 

                                // Fecha o arquivo
                                fclose(arquivo);
                                limparTerminal();
                                break;
                            }else if(entrada == 3){
                                limparTerminal();
                                break;
                            }

                        }
                    break;
                    case 2:
                        while(1){
                            while(1){
                                // Código para alterar dados do profissional.
                                limparTerminal();
                                printf("[0] Voltar\nDigite o nome do profissional que deseja alterar:\n");
                                char nomeProfissionalParaEditar[200];
                                scanf(" %[^\n]s", &nomeProfissionalParaEditar);
                                
                                if (strcmp(nomeProfissionalParaEditar, "0")==0){
                                    limparTerminal();
                                    sair = 0;
                                    break;
                                }else{

                                    FILE *arquivo = fopen("profissionais.txt", "r");
                                    if (arquivo == NULL) {
                                        printf("Erro ao abrir o arquivo.\n");
                                        return 1;
                                    }

                                    int encontrado = 0;
                                    char linha[300];
                                    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
                                        if (strstr(linha, "Nome:") && strstr(linha, nomeProfissionalParaEditar)) {
                                            encontrado = 1;
                                            break;
                                        }
                                    }

                                    fclose(arquivo);

                                    if (!encontrado) {
                                        printf("Profissional não encontrado.\n");
                                    }else {
                                        //Opções para alterar os campos desejados
                                        int opcaoEdicao;
                                        while (1) {
                                            limparTerminal();
                                            printf("O que deseja alterar?\n[1] Nome\n[2] Credenciamento\n[3] Endereço\n[4] Telefone\n[5] E-mail\n[6] CPF\n[7] Tipo do Contrato\n[8] Preço por hora\n[9] Data Inicio\n[0] Voltar ao menu anterior\n");
                                            sair = 0;
                                            if (scanf("%d", &opcaoEdicao) == 1) {
                                                switch (opcaoEdicao) {
                                                    case 0:
                                                        sair = 1;
                                                        break;
                                                    case 1:
                                                        // Editar o nome
                                                        printf("Digite o novo nome do profissional:\n");
                                                        scanf(" %[^\n]s", &nomePersonal);
                                                        break;

                                                    case 2:
                                                        // Editar o credenciamento
                                                        printf("Digite o novo credenciamento do profissional:\n");
                                                        scanf("%i", &credenciamento);
                                                        break;

                                                    case 3:
                                                        // Editar o endereço
                                                        printf("Digite o novo endereço do profissional:\n");
                                                        scanf(" %[^\n]s", &enderecoPersonal);
                                                        break;

                                                    case 4:
                                                        // Editar o telefone
                                                        printf("Digite o novo telefone do profissional:\n");
                                                        scanf("%i", &telefonePersonal);
                                                        break;

                                                    case 5:
                                                        // Editar o e-mail
                                                        printf("Digite o novo e-mail do profissional:\n");
                                                        scanf(" %[^\n]s", &emailPersonal);
                                                        break;

                                                    case 6:
                                                        // Editar o CPF
                                                        printf("Digite o novo CPF do profissional:\n");
                                                        scanf("%i", &cpfPersonal);
                                                        break;

                                                    case 7:
                                                        // Editar o tipo de contrato
                                                        printf("Digite o novo tipo de contrato do profissional (autônomo, CLT, estágiário):\n");
                                                        scanf(" %[^\n]s", &tipoDeContrato);
                                                        break;

                                                    case 8:
                                                        // Edit o preço por hora
                                                        printf("Digite o novo preço por hora do profissional:\n");
                                                        scanf("%f", &valorPersonalHr);
                                                        break;

                                                    case 9:
                                                        // Edita a data de início
                                                        printf("Digite a nova data de início do profissional (dd/mm/aaaa):\n");
                                                        scanf("%d/%d/%d", &inicioDiaPersonal, &inicioMesPersonal, &inicioAnoPersonal);
                                                        break;

                                                    default:
                                                        printf("Opção inválida. Tente novamente.\n");
                                                        // Limpa o buffer de entrada, caso tenha entrada de um caracter;
                                                        int c;
                                                        while ((c = getchar()) != '\n' && c != EOF);
                                                }
                                            }

                                            // Abre o arquivo novamente para salvar as alterações
                                            arquivo = fopen("profissionais.txt", "r+");
                                            if (arquivo == NULL) {
                                                printf("Erro ao abrir o arquivo.\n");
                                                return 1;
                                            }

                                            encontrado = 0;
                                            FILE *arquivoTemp = fopen("temp.txt", "w");
                                            if (arquivoTemp == NULL) {
                                                printf("Erro ao criar arquivo temporário.\n");
                                                return 1;
                                            }

                                            while (fscanf(arquivo, "Nome: %[^\n]s", nomePersonal) != EOF) {
                                                if (strcmp(nomePersonal, nomeProfissionalParaEditar) == 0) {
                                                    encontrado = 1;
                                                    // Salva as alterações no arquivo temporário
                                                    fprintf(arquivoTemp, "Nome: %s\n", nomePersonal);
                                                    fprintf(arquivoTemp, "Credenciamento: %d\n", credenciamento);
                                                    fprintf(arquivoTemp, "Endereço: %s\n", enderecoPersonal);
                                                    fprintf(arquivoTemp, "Telefone: %d\n", telefonePersonal);
                                                    fprintf(arquivoTemp, "E-mail: %s\n", emailPersonal);
                                                    fprintf(arquivoTemp, "CPF: %d\n", cpfPersonal);
                                                    fprintf(arquivoTemp, "Tipo de Contrato: %s\n", tipoDeContrato);
                                                    fprintf(arquivoTemp, "Valor (por hora): %.2f\n", valorPersonalHr);
                                                    fprintf(arquivoTemp, "Data de Início: %02d/%02d/%04d\n", inicioDiaPersonal, inicioMesPersonal, inicioAnoPersonal);
                                                    fprintf(arquivoTemp, "\n");
                                                } else {
                                                    fprintf(arquivoTemp, "Nome: %s\n", nomePersonal);
                                                }
                                            }

                                            fclose(arquivo);
                                            fclose(arquivoTemp);

                                            // Remove o arquivo original e renomeia o temporário
                                            remove("profissionais.txt");
                                            rename("temp.txt", "profissionais.txt");

                                            printf("Alterações salvas com sucesso!\n");
                                        }
                                    }
                                }
                            }
                        }
                    break;
                    case 3:
                    //Ver Profissionais cadastrados
                    break;
                    case 4:
                        limparTerminal();
                    break;

                    if (sair){
                        break;
                    }
                
                
            break;
            case 7:
            sair = 1;
            limparTerminal();
            return 0;
            }
        }
        if(sair){
            break;
        }
    } 
    return 0;
   
}
    


//função preco
int valor (char plano, char tipoAdesao[10], char periodo[8]){

    int valor, total;

    switch(plano){

        case 'a':
           if ((strcmp(tipoAdesao, "mensal") == 0) && (strcmp(periodo, "dia") == 0)) {
               valor = 220;
           }else if((strcmp(tipoAdesao, "mensal") == 0) && (strcmp(periodo, "noite") == 0)) {
               valor = 270;
           }else if(strcmp(tipoAdesao, "anual") == 0) {
               valor = 198;
           }else{
               printf("Erro!\n");
           }

           break;
        
        case 'b':
           if (strcmp(tipoAdesao, "mensal") == 0) {
               valor = 110;
           } else if (strcmp(tipoAdesao, "anual") == 0) {
               valor = 100;
           } else {
               printf("Erro!\n");
           }

           break;

       case 'c':
          if (strcmp(tipoAdesao, "mensal") == 0) {
              valor = 200;
          }else if(strcmp(tipoAdesao, "anual") == 0) {
              valor = 180;
          }else{
              printf("Erro!\n");
          }

          break;

        case 'd':
           if (strcmp(tipoAdesao, "mensal") == 0) {
               printf("Não há plano mensal para esta assinatura!");
           }else if(strcmp(tipoAdesao, "anual") == 0) {
               valor = 280;
           }else{
               printf("Erro!\n");
           }

           break;
        
        case 'e':
        
           if(strcmp(tipoAdesao, "mensal") == 0){
              printf("Não há plano mensal para esta assinatura!");
           }else if(strcmp(tipoAdesao, "anual") == 0){
              valor = 298;
           }else{
              printf("Erro\n");
	   }

           break;
        
        default:
           printf("Opção inválida! Tente novamente.\n");
       
           break;
        
    }
    
    return valor;
}
