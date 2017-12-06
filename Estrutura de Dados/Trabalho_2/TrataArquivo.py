# Carlos Adir Ely Murussi Leite
# 150121059

import sys


def existe_arquivo(nome):
	try:
		arquivo = open(nome, "r")
		arquivo.close()
		return True
	except:
		pass
	return False

def le_arquivo(nome):
	arquivo = open(nome, "r")
	linhas = arquivo.readlines()
	arquivo.close()
	for i in range(len(linhas)):
		linhas[i] = linhas[i].split('\n')[0]
		if '\r' in linhas[i]:
			linhas[i] = linhas[i].split('\r')[0]
	return linhas

def grava(what, where):
	arq = open(where, "w")
	if type(what) == list or type(what) == tuple:
		for i in what:
			if type(i) == list or type(i) == tuple:
				for j in i:
					arq.write(str(j)+';')
				arq.write('\n')
			else:
				arq.write(str(i) + '\n')
	else:
		arq.write(str(what))

class info():
	"""docstring for info"""
	def __init__(self, lista):
		self.ID = lista[0]
		self.name = lista[1]
		self.turma = []
		self.year = []
		self.peri = []
		self.size = []
		self.postura = []
		self.atuacao = []
		self.autoavaliacao = []
		self.add_infos(lista)
	def add_infos(self, lista):
		#if(type())
		if 1900 < lista[3] < 2100:
			if lista[4] > 0:
				if lista[5] >= 0:
					if 0 <= lista[6] <= 10 and 0 <= lista[8] <= 10 and 0 <= lista[10] <= 10:
						if 0 <= lista[7] <= 10 and 0 <= lista[9] <= 10 and 0 <= lista[11] <= 10:
							self.turma.append(lista[2])
							self.year.append(lista[3])
							self.peri.append(lista[4])
							self.size.append(lista[5])
							self.postura.append((lista[6], lista[7]))
							self.atuacao.append((lista[8], lista[9]))
							self.autoavaliacao.append((lista[10], lista[11]))
							print("Adicionado!")
							return 1
		print("Nao foi possivel adicionar a lista:")
		print(lista)

	def imprime(self):
		retorno = ""
		retorno += str(self.ID) + " - " + self.name + ": "
		retorno += "\t        Turma: " + str(self.turma)
		retorno += "\t          Ano: " + str(self.year)
		retorno += "\t      Periodo: " + str(self.peri)
		retorno += "\t   Quantidade: " + str(self.size)
		retorno += "\t      Postura: " + str(self.postura)
		retorno += "\t      Atuacao: " + str(self.atuacao)
		retorno += "\tAutoAvaliacao: " + str(self.autoavaliacao)
		print(retorno)
	def imprime2(self):
		aux = []
		name = str(self.ID) + "," + self.name + ","
		retorno = ""
		for i in range(len(self.turma)):
			aux.append("")
			aux[i] += str(self.turma[i]) + "," + str(self.year[i]) + "," + str(self.peri[i]) + ',' + str(self.size[i]) + ","
			aux[i] += str(self.postura[i][0]) + ',' + str(self.postura[i][1]) + ','
			aux[i] += str(self.atuacao[i][0]) + ',' + str(self.atuacao[i][1]) + ','
			aux[i] += str(self.autoavaliacao[i][0]) + ',' + str(self.autoavaliacao[i][1])
			retorno += name + aux[i] + '\n'
		return retorno

def trata_linhas(linhas):
	n = len(linhas)
	i = 0
	while i < n:
		try:
			linhas[i][0] = int(linhas[i][0]) # ID do professor
			linhas[i][2] = int(linhas[i][2]) # ID da turma
			linhas[i][3] = int(linhas[i][3]) # Ano
			linhas[i][4] = int(linhas[i][4]) # Periodo
			linhas[i][5] = int(linhas[i][5]) # Quantidade discentes
			linhas[i][6] = float(linhas[i][6]) # Media postura profissional
			linhas[i][7] = float(linhas[i][7]) # Desvio Padrao postura profissional
			linhas[i][8] = float(linhas[i][8]) # Media atuacao profissional
			linhas[i][9] = float(linhas[i][9]) # Desvio padrao atuacao profissional
			linhas[i][10] = float(linhas[i][10]) # Media autoavaliacao profissional
			linhas[i][11] = float(linhas[i][11]) # desvio padrao autoavaliacao profissional
			i += 1
		except:
			print("Removido: " + str(linhas[i]))
			linhas.__delitem__(i)
			n -= 1
	

arquivo   = sys.argv[1]

linhas = le_arquivo(arquivo)
for i in range(len(linhas)):
	linhas[i] = linhas[i].split(',')

trata_linhas(linhas)


professores = []
j = -1
lastID = -1
lastName = ""
for i in range(0, len(linhas)):
	if linhas[i][0] == lastID and linhas[i][1] == lastName:
		professores[j].add_infos(linhas[i])
	elif linhas[i][0] == lastID:
		print(linhas[i])
	elif linhas[i][1] == lastName:
		print(linhas[i])	
	else:
		j += 1
		#print(linhas[i])
		professores.append(info(linhas[i]))
		lastID   = linhas[i][0]
		lastName = linhas[i][1]

novo_arq = arquivo.split('.')[0] + "Tratado.csv"
saida = open(novo_arq, "w")
for professor in professores:
	saida.write(professor.imprime2())
saida.close();
