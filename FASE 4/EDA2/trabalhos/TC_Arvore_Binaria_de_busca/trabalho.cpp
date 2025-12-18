#include<iostream>
#include<vector>
#include<string>
#include<limits>
#include<queue>
#include<cstdlib>

using namespace std;

//Estrutura de dados
struct Arvore{
    struct Dado{
        float valor;
        //construtor
        Dado(float v) : valor(v) {}

        Dado() : valor(0) {}
    };

    struct No {
        Dado info;
        No *pai;
        No *esq;
        No *dir;

        // Contrutor 
        No(float valor) : info(valor), pai(nullptr), esq(nullptr), dir(nullptr) {}

        // Destrutor
        ~No(){}

        void print() {
            cout << info.valor << endl;
        }

        int altura(){   
            int alturaEsq = -1;
            int alturaDir = -1;
            if (esq != nullptr) alturaEsq = esq->altura();
            if (dir != nullptr) alturaDir = dir->altura();
            
            if (alturaEsq > alturaDir) return alturaEsq + 1;
            else return alturaDir + 1;
        }

        int qtFilhos(){
            int qtEsq = 0;
            int qtDir = 0;
            if (esq) qtEsq = esq->qtFilhos();
            if (dir) qtDir = dir->qtFilhos();
            return qtEsq + qtDir + 1;
        }
        
    };

    No *raiz;

    // Contrutor
    Arvore() : raiz(nullptr) {}

    // Destrutor
    ~Arvore(){
        destruir(raiz);
    }

    No *buscaNodo(float valor){
        No *alvo = raiz;
        while(alvo != nullptr && (valor != alvo->info.valor)) 
            if (valor < alvo->info.valor) alvo = alvo->esq; 
            else alvo = alvo->dir;

        return alvo;
    }

    bool inserirNodo(float valor){
        No *novo = new No(valor);

        if(raiz == nullptr) {
            raiz = novo;
            return true;    
        }

        No *aux = raiz;
        No *auxPai = nullptr;

        while(aux != nullptr){
            auxPai = aux;
            if(aux->info.valor == novo->info.valor) return false;
            
            if (novo->info.valor > aux->info.valor) aux = aux->dir;
            else aux = aux->esq;
        }

        if(novo->info.valor > auxPai->info.valor) auxPai->dir = novo;
        else auxPai->esq = novo;

        novo->pai = auxPai;

        return true;
    }

    int removerNodo(float valor){
        No *subst, *avante;  
        No *alvo = buscaNodo(valor);

        if (alvo == nullptr) return 0;  // valor não encontrado

        if(alvo->esq == nullptr && alvo->dir == nullptr){  // Caso 1: no sem filhos 
            if (alvo == raiz) raiz = nullptr;
            else if (alvo == alvo->pai->esq) alvo->pai->esq = nullptr;
            else alvo->pai->dir = nullptr;
            delete alvo;
            return 1;
        }else if (alvo->esq == nullptr || alvo->dir == nullptr){  // Caso 2: no tem um filho
            if (alvo->dir != nullptr) subst = alvo->dir;
            else subst = alvo->esq;
        }else { // Caso 3: no com dois filhos 
            subst = alvo->esq;

            while (subst->dir != nullptr) subst = subst->dir;

            if(subst->pai != alvo){
                if (subst->esq != nullptr) subst->esq->pai = subst->pai;
                subst->pai->dir = subst->esq;
                subst->esq = alvo->esq;

                if (subst->esq != nullptr) subst->esq->pai = subst;
            }

            subst->dir = alvo->dir;

            if (subst->dir != nullptr) subst->dir->pai = subst;
        }

        if (raiz == alvo) {
            raiz = subst;
            subst->pai = nullptr;    
        } else if(alvo == alvo->pai->esq) {
            alvo->pai->esq = subst;
            subst->pai = alvo->pai; 
        } else {
            alvo->pai->dir = subst;
            subst->pai = alvo->pai; 
        }

        delete alvo;
        return 1;
    }

    void preOrdem(){
        preOrdemRec(raiz);
    }

    void emOrdem(){
        emOrdemRec(raiz);
    }

    void posOrdem(){
        posOrdemRec(raiz);
    }

    int altura(){
        if (raiz != nullptr) return raiz->altura();
        else return 0;
    }

    bool vazia(){  
        if (raiz == nullptr) return true;
        else return false;
    }

    int qtNos(){
        return raiz->qtFilhos();
    }

    void larguraPorNivel(){
        if (raiz == nullptr) return;

        queue<No*> fila;
        fila.push(raiz);

        int nivel = 0;

        while (!fila.empty()){
            int largura = fila.size();

            cout << "\tNível " << nivel << ": " << largura << " nó(s)" << endl;

            for (int i = 0; i < largura; i++){
                No *atual = fila.front();   
                fila.pop();
            
                if (atual->esq != nullptr) fila.push(atual->esq);
                if (atual->dir != nullptr) fila.push(atual->dir);
            }
            nivel++;
        }
    }

    bool cheia(){
        if (raiz == nullptr) return false;
        else return cheiaRec(raiz);
    }

    bool completa() {
        if (raiz == nullptr) return false;

        queue<No*> fila;
        fila.push(raiz);
        bool encontrouIncompleto = false;

        while (!fila.empty()) {
            No* atual = fila.front();
            fila.pop();

            if (atual->esq) {
                if (encontrouIncompleto) return false;
                fila.push(atual->esq);
            } else {
                encontrouIncompleto = true;
            }

            if (atual->dir) {
                if (encontrouIncompleto) return false;
                fila.push(atual->dir);
            } else {
                encontrouIncompleto = true;
            }
        }

        return true;
    }

    private:
        void destruir(No *nodo){
            if (nodo == nullptr) return;
            destruir(nodo->esq);
            destruir(nodo->dir);
            delete nodo;
        }

        void preOrdemRec(No *nodo){
            if (nodo == nullptr) return;
            nodo->print();
            preOrdemRec(nodo->esq);
            preOrdemRec(nodo->dir);
        }

        void emOrdemRec(No *nodo){
            if (nodo == nullptr) return;
            emOrdemRec(nodo->esq);
            nodo->print();
            emOrdemRec(nodo->dir);
        }
        void posOrdemRec(No *nodo){
            if (nodo == nullptr) return;
            posOrdemRec(nodo->esq);
            posOrdemRec(nodo->dir);
            nodo->print();
        }

        bool cheiaRec(No* no) {
            if (no == nullptr) return true;

            if ((no->esq == nullptr && no->dir != nullptr) ||
                (no->esq != nullptr && no->dir == nullptr)) {
                return false;
            }

            return cheiaRec(no->esq) && cheiaRec(no->dir);
        }
};

// FUNCOES SECUNDARIAS
void limpa_tela(){ 
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

void limpa_buffer() {  // limpa buffer de entrada
    cin.clear();               
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void entrada(int ini, int fim, int *opcao){  // verifica se a entrada esta dentro do intervalo
    int a;
    cout << "Digite uma opção: ";
    cin >> a;
    while (a < ini || a > fim){
        cout << "Digite nomamente, intervalo aceito [" << ini << ',' << fim << ']' << endl;
        cout << "Digite uma opção: ";
        cin >> a;
    }
    *opcao = a;
}

int main(){
    bool continuar = true;
    int opcao;
    Arvore *arv = new Arvore();

    while(continuar){
        limpa_tela();
        float valor;
        cout << "1 - Inserir nodo" << endl
             << "2 - Remover nodo" << endl
             << "3 - Buscar nodo"  << endl
             << "4 - Listar todos os nodos" << endl
             << "5 - Exibir informações" << endl
             << "6 - Sair"  << endl;

        entrada(1, 7, &opcao);
        limpa_tela();
        switch(opcao){
            case 1:{
                cout << "Digite o valor do dado a ser inserido: ";
                cin >> valor;
                cout << endl;

                if (arv->inserirNodo(valor)) cout << "\u2714 Nodo inserido com sucesso. ";
                else cout << "\u274C Erro, nodo valor já adicionado. ";
                }
            break;
            case 2:{
                if (arv->vazia()) cout << "Árvore está vazia. ";
                else{
                    cout << "Digite o valor do nodo que deseja remover: ";
                    cin >> valor;
                    cout << endl;
                    int remove = arv->removerNodo(valor);
                    if (remove == 1) cout << "\u2714 Nodo removido com suesso. ";
                    else cout << "\u274C Nodo não encontrado. ";
                }
            }
            break;
            case 3:{
                if (arv->vazia()) cout << "Árvore está vazia. ";
                else{
                    cout << "Digite o valor do nodo que deseja buscar: ";
                    cin >> valor;
                    cout << endl;

                    Arvore::No *alvo = arv->buscaNodo(valor);
                    if (alvo != nullptr) cout << "\u2714 Nodo encontrado na árvore. " ;
                    else cout << "\u274C Nodo não encontrado na árvore. ";
                }
            }
            break;
            case 4:
                if (arv->vazia()) cout << "Árvore está vazia. ";
                else{
                    cout << "Pré ordem:" << endl;
                    arv->preOrdem();
                    cout << "Em Ordem:" << endl;
                    arv->emOrdem();
                    cout << "Pos Ordem:" << endl;
                    arv->posOrdem();
                }
            break;
            case 5:
                cout << "Informações da árvore" << endl;
                if (arv->vazia()) cout << "Árvore vazia" << endl;
                else cout << "Árvore contêm " << arv->qtNos() << " nó(s)"<< endl;
                cout << "Altura: " << arv->altura() << endl;
                if (!arv->vazia()) cout << "Largura: " <<  endl;
                arv->larguraPorNivel();
                if (arv->cheia()) cout << "Árvore é cheia" << endl;
                else cout << "Árvore não é cheia" << endl;
                if (arv->completa()) cout << "Árvore é completa" << endl;
                else cout << "Árvore não é completa" << endl;
            break;
            case 6:
                continuar = false;
            break;
        }
        
        if (continuar){
            cout << "Aperte enter para voltar.";
            cin.ignore();
            cin.get();
        }
    }

    delete arv;
}