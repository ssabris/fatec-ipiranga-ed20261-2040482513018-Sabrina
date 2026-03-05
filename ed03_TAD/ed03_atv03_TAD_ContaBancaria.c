*****************************************************************************/
    ED03_atv_03
    
    Pergunta: Crie um TAD que implemente o controle de uma conta bancaria, 
    implemente funcoes para inicializar, deposito, sacar e imprimir o saldo.       
    
    EXPLICAÇÃO:
    Neste ficheiro, implementamos o comportamento basico de um TAD. 
    A criacao da variavel eh feita de forma estatica na funcao main, 
    e passamos o endereco de memoria (&) para a funcao 'inicializar' 
    configurar o numero e o saldo inicial (zero).
 ****************************************************************************/

#include <stdio.h>

// Definicao da estrutura (TAD)
typedef struct {
    int numero;
    float saldo;
} ContaBancaria;

// Funcao para inicializar a conta
void inicializar(ContaBancaria *c, int numero) {
    c->numero = numero;
    c->saldo = 0.0;
    printf("Conta %d inicializada com sucesso.\n", c->numero);
}

// Funcao para realizar depositos
void depositar(ContaBancaria *c, float valor) {
    if (valor > 0) {
        c->saldo += valor;
        printf("Deposito de R$%.2f realizado.\n", valor);
    } else {
        printf("Valor de deposito invalido.\n");
    }
}

// Funcao para realizar saques
void sacar(ContaBancaria *c, float valor) {
    if (valor > 0 && c->saldo >= valor) {
        c->saldo -= valor;
        printf("Saque de R$%.2f realizado.\n", valor);
    } else {
        printf("Saque invalido ou saldo insuficiente.\n");
    }
}

// Funcao para imprimir o saldo atual
void imprimirSaldo(ContaBancaria *c) {
    printf("=== SALDO: Conta %d | R$%.2f ===\n\n", c->numero, c->saldo);
}

int main() {
    ContaBancaria minhaConta; // Alocacao estatica da variavel

    printf("--- TESTE DA QUESTAO 3 ---\n");
    
    inicializar(&minhaConta, 1001);
    imprimirSaldo(&minhaConta);

    depositar(&minhaConta, 300.50);
    imprimirSaldo(&minhaConta);

    sacar(&minhaConta, 100.00);
    imprimirSaldo(&minhaConta);
    
    sacar(&minhaConta, 500.00); // Tentativa de saque maior que o saldo

    return 0;
}
