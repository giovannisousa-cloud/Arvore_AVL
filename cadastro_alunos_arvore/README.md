# Sistema de Cadastro de Alunos com Arvore Binaria de Busca

## Descricao

Este projeto foi desenvolvido para a Atividade Avaliativa 3. O objetivo e implementar um sistema simples de cadastro de alunos utilizando uma estrutura de dados baseada em arvores.

A estrutura escolhida foi a Arvore Binaria de Busca (ABB). O nome do aluno e usado como chave de ordenacao da arvore.

## Funcionalidades

O sistema permite:

- Inserir aluno
- Buscar aluno pelo nome
- Exibir todos os alunos em ordem alfabetica
- Exibir informacoes da arvore:
  - Quantidade total de alunos cadastrados
  - Altura da arvore

## Estrutura dos dados

Cada aluno possui:

- Numero de matricula
- Nome completo
- Curso

## Arquivos do projeto

- `main.cpp`: codigo-fonte completo do sistema
- `relatorio.md`: relatorio curto em Markdown
- `relatorio.pdf`: relatorio curto em PDF
- `.gitignore`: arquivos ignorados pelo Git

## Como compilar

No terminal, dentro da pasta do projeto, execute:

```bash
g++ main.cpp -o cadastro_alunos
```

## Como executar

No Windows:

```bash
cadastro_alunos.exe
```

No Linux ou Mac:

```bash
./cadastro_alunos
```

## Exemplo de uso

Use a opcao `5 - Carregar exemplo` para cadastrar automaticamente os seguintes alunos:

| Matricula | Nome | Curso |
|---|---|---|
| 101 | John Smith | Engenharia de Software |
| 102 | Alice Johnson | Sistemas de Informacao |
| 103 | Michael Brown | Ciencia da Computacao |
| 104 | Emily Davis | Engenharia de Software |

Depois, use a opcao `3 - Listar alunos em ordem alfabetica`.

## Versionamento no GitHub

Comandos sugeridos:

```bash
git init
git add .
git commit -m "Entrega atividade avaliativa 3"
git branch -M main
git remote add origin LINK_DO_REPOSITORIO
git push -u origin main
```

## Autor

Giovanni Daniotti Becker
