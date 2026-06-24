# Relatorio - Sistema de Cadastro de Alunos com Arvore

## 1. Estrutura escolhida

A estrutura de dados escolhida para o desenvolvimento do sistema foi a Arvore Binaria de Busca, tambem conhecida como ABB.

Essa estrutura foi escolhida por ser uma das opcoes permitidas na atividade e por permitir armazenar os dados de forma organizada. No sistema, cada aluno e inserido na arvore utilizando o nome como chave de ordenacao.

Dessa forma, nomes menores em ordem alfabetica ficam no lado esquerdo da arvore, enquanto nomes maiores ficam no lado direito. Isso permite realizar buscas e listagens de maneira organizada.

## 2. Dados armazenados

Cada aluno cadastrado possui tres informacoes principais:

- Numero de matricula;
- Nome completo;
- Curso.

Esses dados ficam armazenados dentro de uma estrutura chamada `Aluno`. Cada no da arvore possui um aluno e dois ponteiros: um para o filho da esquerda e outro para o filho da direita.

## 3. Operacoes implementadas

Foram implementadas as seguintes operacoes no sistema:

### Insercao de aluno

A insercao recebe a matricula, o nome e o curso do aluno. O nome e comparado com os nomes ja existentes na arvore.

Se o nome for menor, o aluno e inserido na subarvore esquerda. Se for maior, e inserido na subarvore direita. Caso o nome ja exista, o sistema informa que o aluno ja esta cadastrado.

### Busca de aluno

A busca e feita pelo nome do aluno. O sistema compara o nome buscado com o nome armazenado em cada no.

Se encontrar o nome, os dados do aluno sao exibidos. Caso contrario, a busca continua pela esquerda ou pela direita, de acordo com a ordem alfabetica. Se o aluno nao for encontrado, uma mensagem e exibida ao usuario.

### Listagem em ordem alfabetica

Para exibir todos os alunos em ordem alfabetica, foi usado o percurso em ordem da arvore.

Esse percurso visita primeiro a subarvore esquerda, depois o no atual e, por fim, a subarvore direita. Como a arvore foi organizada pelo nome dos alunos, esse percurso gera a listagem em ordem crescente de nome.

### Informacoes da arvore

O sistema tambem exibe a quantidade total de alunos cadastrados e a altura da arvore.

A quantidade total e atualizada a cada novo cadastro realizado. A altura e calculada de forma recursiva, verificando a maior altura entre os lados esquerdo e direito da arvore.

## 4. Conclusao

O sistema atende aos requisitos da atividade, pois utiliza uma estrutura de arvore para armazenar alunos, permite inserir e buscar registros, exibe os alunos em ordem alfabetica por meio de percurso em arvore e apresenta informacoes sobre a quantidade de alunos e altura da estrutura.

A Arvore Binaria de Busca foi suficiente para resolver o problema proposto de forma simples e organizada.
