*****************************************************************************/
    ED03_atv_04
    
    Pergunta: Utilizando a alocacao dinamica de memoria crie uma funcao 
    para criar uma nova conta bancaria. 
    
    EXPLICAÇÃO:
    Aqui utilizamos a funcao 'malloc' (memory allocation) da biblioteca <stdlib.h>.
    A funcao criarConta pede ao computador um espaco na memoria com o tamanho 
    exato da struct ContaBancaria. Se conseguir o espaco, ela define os 
    valores iniciais e retorna o ponteiro para o usuario.
    Muito importante: tudo o que eh criado com malloc deve ser destruido com free().
    
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Definicao da estrutura
typedef struct {
    int numero;
    float saldo;
} ContaBancaria;

// Funcao que cria uma conta usando alocacao dinamica (Resposta da Questao 4)
ContaBancaria* criarConta(int numero) {
    // 1. Aloca dinamicamente o espaco na memoria
    ContaBancaria *novaConta = (ContaBancaria*) malloc(sizeof(ContaBancaria));

    // 2. Verifica se a memoria foi alocada com sucesso (se nao retornou NULL)
    if (novaConta != NULL) {
        novaConta->numero = numero;
        novaConta->saldo = 0.0; // Inicializa com saldo zerado
        printf("Conta %d criada dinamicamente na memoria.\n", novaConta->numero);
    } else {
        printf("Erro: Falha na alocacao de memoria.\n");
    }

    // 3. Retorna o ponteiro para a conta criada
    return novaConta; 
}

int main() {
    printf("--- TESTE DA QUESTAO 4 ---\n");
    
    // O ponteiro recebe o endereco de memoria alocado pela nossa nova funcao
    ContaBancaria *contaDinamica = criarConta(2024);

    // Se o ponteiro for diferente de NULL, a criacao funcionou
    if (contaDinamica != NULL) {
        printf("Acessando dados via ponteiro -> Numero: %d\n", contaDinamica->numero);
        printf("Acessando dados via ponteiro -> Saldo: R$%.2f\n\n", contaDinamica->saldo);

        // BOA PRATICA E OBRIGACAO EM C: 
        // Como usamos malloc, precisamos libertar a memoria no final!
        free(contaDinamica);
        printf("Memoria da conta %d libertada com sucesso (free).\n", 2024);
    }

    return 0;
}
