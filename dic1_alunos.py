# Dicionário de alunos
alunos = {
    101: {"nome": "Ana Silva", "curso": "Engenharia"},
    102: {"nome": "João Santos", "curso": "Matemática"},
    103: {"nome": "Marta Costa", "curso": "Física"}
}

# pelo ID
id_aluno = 102
info_aluno = alunos[id_aluno]  # Usando o ID como índice para acessar informações
print(f"Aluno {id_aluno}: {info_aluno['nome']} - {info_aluno['curso']}")

# Mudar curso de um aluno 
alunos[102]["curso"] = "Ciências da Computação"
print(f"Curso atualizado do aluno 102: {alunos[102]['curso']}")

# Novo aluno
alunos[104] = {"nome": "Luiza Pereira", "curso": "Biologia"}
print(f"Novo aluno adicionado: {alunos[104]['nome']} - {alunos[104]['curso']}")

# Remover um aluno pelo ID
del alunos[101]
print("Aluno 101 removido")
