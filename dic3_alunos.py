# Inicialização de um dicionário de alunos
alunos = {}

# Preenchendo o dicionário usando um laço e métodos de dicionário
for id_aluno in range(1, 4):
    alunos[id_aluno] = {
        "nome": f"Aluno{id_aluno}",
        "curso": f"Curso{id_aluno}",
        "notas": [id_aluno * 2, id_aluno * 3, id_aluno * 4],
    }

# Atualizando informações de um aluno específico
alunos[2]["curso"] = "Curso Atualizado"
alunos[2]["notas"].append(10)

# Acessando e exibindo todas as informações dos alunos
for id_aluno, info in alunos.items():   
    print(
        f"ID: {id_aluno}, Nome: {info['nome']}, Curso: {info['curso']}, Notas: {info['notas']}"
    )

# Acessando e exibindo apenas os nomes dos alunos
for aluno in alunos.values():
    print(aluno["nome"])

# Adicionando um novo aluno
alunos[4] = {"nome": "Aluno4", "curso": "Curso4", "notas": [8, 9, 10]}

# Removendo um aluno
del alunos[1]

# Usando get para evitar erros ao acessar uma chave que pode não existir
nome_aluno1 = alunos.get(1, {}).get("nome", "Aluno não encontrado")
print(nome_aluno1)

# Exibindo apenas os cursos usando um laço
for id_aluno in alunos:
    print(alunos[id_aluno]["curso"])

# Demonstração do método pop
info_aluno2 = alunos.pop(2, "Aluno não encontrado")
print(f"Informações removidas do Aluno 2: {info_aluno2}")

# Limpar o dicionário
alunos.clear()
