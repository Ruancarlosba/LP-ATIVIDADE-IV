#include <stdio.h>
#include <stdlib.h>


struct ContaBancaria {
    int numeroConta;
    char nome_do_Titular[50];
    float saldo;
    char tipo_da_Conta[20];
};


void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Deposito de %.2f realizado com sucesso.\n", valor);
}


void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > conta->saldo) {
        printf("Saldo insuficiente .\n");
    } else {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado.\n", valor);
    }
}


void imprimirSaldo(struct ContaBancaria conta) {
    printf("Saldo atual: %.2f\n", conta.saldo);
}

int main() {

    

    struct ContaBancaria minhaConta;
    minhaConta.numeroConta = 12345;
    strcpy(minhaConta.nome_do_Titular, "Joao da Silva");
    minhaConta.saldo = 1000.0;
    strcpy(minhaConta.tipo_da_Conta, "corrente");

    int opcao;
    float valor;

    do {
        
        printf("\nMenu:\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Verificar Saldo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o valor para depositar: ");
                scanf("%f", &valor);
                depositar(&minhaConta, valor);
                break;
            case 2:
                printf("Informe o valor para sacar: ");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;
            case 3:
                imprimirSaldo(minhaConta);
                break;
            case 0:
                printf("finalizando o   programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}