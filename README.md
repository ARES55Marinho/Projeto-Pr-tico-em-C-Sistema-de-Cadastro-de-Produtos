# Sistema de Controle de Produtos

## 📚 Turma
Turma de Programação em C – 2026

## 👥 Integrantes
- Matheus Henrique Barros da Costa
- Samuel Costa Domingues
- Hiago da Silva Marinho
- Dhavi Francisco do Vale Ferreira


## 📝 Descrição do Sistema
Este projeto implementa um **sistema de controle de produtos** utilizando a linguagem C e arquivos CSV para armazenamento dos dados.  
O sistema permite:
- Cadastrar novos produtos (nome, categoria e preço).
- Listar todos os produtos cadastrados.
- Buscar produtos por nome, categoria ou faixa de preço.
- Remover produtos de forma segura, utilizando arquivos temporários.
- Atualizar informações de produtos já existentes.
- Criar automaticamente o arquivo CSV caso ele não exista.

O objetivo é oferecer uma solução prática e organizada para manipulação de dados em arquivos texto, aplicando conceitos de **structs, funções, manipulação de strings e arquivos**.

## ⚙️ Instruções de Compilação e Execução

### Pré-requisitos
- Compilador C (ex.: GCC ou MinGW) (utilizamos o Embarcadero Dev-C++).
- Sistema operacional Windows (o código utiliza funções específicas como `system("cls")` e `system("pause")`).

### Compilação
No compilador, compile e execute o tabalho.c. **`escolhor_opções()`**
- Após execução o terminal abrirá para que possa interagir.
gcc main.c -o sistema.exe
