# ALGORITMOS
(UFMA) Trabalho de Algoritmos e Estrutura de Dados I

Projeto feito em linguagem C.
# **🍔 Sistema de Controle de Estoque \- Lanchonete**

Um programa em **Linguagem C** pura desenvolvido para gerenciamento de estoque de salgados de uma lanchonete. O projeto foi estruturado com foco **didático**, demonstrando a aplicação prática de vetores, laços, condicionais e manipulação básica de memória no terminal.

## **📐 Como o Programa Funciona na Memória (Vetores Paralelos)**

O sistema utiliza **Vetores Paralelos**: dois vetores (precos e quantidades) vinculados pelo mesmo índice (i).

| Propriedade | Posição \[0\] | Posição \[1\] | Posição \[2\] | ... | Posição \[9\]   |
| :---- | :---: | :---: | :---: | :---: | ----- |
| **Produto Exemplo** | Coxinha | Empada | Pastel | ... | *(Vazio)* |
| **precos\[i\]** | R\$ 6.50 | R\$ 8.00 | R\$ 5.00 | ... | R\$ 0.00 |
| **quantidades\[i\]** | 12 | 3 | 20 | ... | 0 |

**📌 Capacidade Máxima:** TAM\_MAX \= 10 itens simultâneos.

### **🔄 Remoção de Itens (Reorganização de Memória)**

Ao excluir o item da posição 1, o programa desloca os elementos seguintes uma posição para a esquerda para eliminar o espaço vago:

`Antes da remoção:  [0: Coxinha] -> [1: Empada] -> [2: Pastel]`  
`Ação:               Apagar posição 1 (Empada)`  
`Deslocamento:       Pastel (índice 2) move para índice 1`  
`Depois da remoção: [0: Coxinha] -> [1: Pastel] (Total passa de 3 para 2)`

## **⚡ Melhorias e Otimizações Realizadas**

| Recurso | Versão Anterior | Versão Refatorada | Benefício Didático   |
| :---- | :---- | :---- | :---- |
| **Tamanho do Estoque** | Valor 10 espalhado no código | Constante \#define TAM\_MAX 10 | Centraliza alterações e evita números soltos. |
| **Zeramento de Vetores** | Laço while manual | Inicialização \= {0} | Recurso nativo do C para limpar memória RAM. |
| **Laços de Repetição** | Laços while com contador | Laço for (int i \= 0; i \< total; i++) | Estrutura padrão e mais limpa para iterações. |
| **Incrementos** | total \= total \+ 1 | total++ / total-- | Sintaxe idiomática e moderna da Linguagem C. |
| **Escopo de Variáveis** | Variáveis globais/no topo | Declaradas no bloco de uso | Melhora a organização e economiza memória. |

## **🎓 Conceitos de C Explicados**

### **1\. Endereço de Memória (scanf e &)**

No comando scanf("%f", \&precos\[total\]);, o operador **&** indica o **endereço de memória** onde a resposta do usuário deve ser armazenada.

### **2\. Validação de Entrada**

`if (precos[total] > 0 && quantidades[total] >= 0) { ... }`

Evita erros de dados garantindo que o preço seja positivo e a quantidade não seja negativa.

### **3\. Operadores Acumuladores (+=)**

`soma_precos += precos[i];                   // soma_precos = soma_precos + precos[i]`  
`valor_total += precos[i] * quantidades[i];  // Calcula o patrimônio em estoque`

## **🖥️ Demonstração da Interface no Terminal**

`===== ESTOQUE DA LANCHONETE =====`  
`1 - Cadastrar`  
`2 - Listar`  
`3 - Modificar`  
`4 - Apagar`  
`5 - Estatisticas`  
`0 - Sair`  
`Escolha: 1`

`Preco: 6.50`  
`Quantidade: 10`  
`Cadastrado com sucesso!`

## ⚙️ Funcionalidades do Menu

- **1 - Cadastrar:** Insere o preço e a quantidade no próximo índice livre.
- **2 - Listar:** Exibe os itens cadastrados com posições, preços e quantidades.
- **3 - Modificar:** Altera preço e quantidade de um item. Valores fora das regras mantêm os dados anteriores. Letras nos campos de novo preço e nova quantidade geram um aviso e uma nova tentativa.
- **4 - Apagar:** Remove o item e desloca os elementos seguintes para a esquerda.
- **5 - Estatísticas:** Exibe média de preços, valor total em estoque e a posição e quantidade dos itens com menos de 5 unidades.
- **0 - Sair:** Encerra o programa.

Se forem digitadas letras no menu, o programa avisa e apresenta o menu novamente.

## 🛠️ Como Compilar e Executar

Para compilar seguindo as instruções abaixo, é necessário ter o GCC instalado e disponível no terminal.
Execute os comandos na pasta do projeto.

O código C está no arquivo `Codigo em C.c`.

### Windows

Compile:

```bash
gcc -std=c11 -Wall -Wextra "Codigo em C.c" -o estoque.exe
```

Execute no PowerShell ou Prompt de Comando:

```powershell
.\estoque.exe
```

### Linux

Compile:

```bash
gcc -std=c11 -Wall -Wextra "Codigo em C.c" -o estoque
```

Execute:

```bash
./estoque
```

## **📋 Regras de Negócio e Limitações**

> * **Capacidade Fixa**: Até 10 itens simultâneos (TAM\_MAX \= 10).  
> * **Acesso por Índice**: Posições de 0 a total \- 1\.  
> * **Armazenamento Volátil**: Os dados permanecem na memória RAM enquanto o programa estiver aberto.


## Integrantes
- Weslley Romeu Rego
- Camilla Victoria Ferreira Costa
- Francinalda de Araujo Maia
