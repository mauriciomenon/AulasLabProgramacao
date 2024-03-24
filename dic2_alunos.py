#  ID de aluno como chave
datas_nascimento = {
    102: { "dia": 15, "mês": "Março", "ano": 1998 },
    103: { "dia": 22, "mês": "Julho", "ano": 1997 },
    104: { "dia": 8, "mês": "Dezembro", "ano": 1999 }
}

# Acessar data de nascimento
id_aluno = 103
data_nasc = datas_nascimento[id_aluno]  # Usando o ID do aluno para acessar sua data de nascimento
print(f"Data de Nascimento do Aluno {id_aluno}: {data_nasc['dia']}/{data_nasc['mês']}/{data_nasc['ano']}")

# Mudar ano de nascimento
datas_nascimento[103]["ano"] = 1996
print(f"Ano de nascimento atualizado do Aluno 103: {datas_nascimento[103]['ano']}")

# Nova data de nascimento
datas_nascimento[105] = { "dia": 30, "mês": "Janeiro", "ano": 2000 }
print(f"Nova data de nascimento adicionada para o Aluno 105: {datas_nascimento[105]['dia']}/{datas_nascimento[105]['mês']}/{datas_nascimento[105]['ano']}")

# Remover a data de nascimento
del datas_nascimento[102]
print("Data de nascimento do Aluno 102 removida")
