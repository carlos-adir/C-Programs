
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
		self.turma.append(lista[2])
		self.year.append(lista[3])
		self.peri.append(lista[4])
		self.size.append(lista[5])
		self.postura.append((lista[6], lista[7]))
		self.atuacao.append((lista[8], lista[9]))
		self.autoavaliacao.append((lista[10], lista[11]))
	def imprime(self):
		print(str(self.ID) + " - " + self.name + ": ")
		print("\t        Turma: " + str(self.turma))
		print("\t          Ano: " + str(self.year))
		print("\t      Periodo: " + str(self.peri))
		print("\t   Quantidade: " + str(self.size))
		print("\t      Postura: " + str(self.postura))
		print("\t      Atuacao: " + str(self.atuacao))
		print("\tAutoAvaliacao: " + str(self.autoavaliacao))
		
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
	

diretorio = 'avaliacao_docentes/'
arquivo   = 'avaliacao_docentes.csv'

linhas = le_arquivo(diretorio+arquivo)
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


