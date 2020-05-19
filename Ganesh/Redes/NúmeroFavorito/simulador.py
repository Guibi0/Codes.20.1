#################################################
# Redes Ganesh                                  #
#Programa que simula o chall do Número Favorito #
#################################################
import random

print("\n********************* Encontre o Número Favorito *********************"
      "\nHiro Batata tem um numero favorito X e hoje a sua missão eh acerta-lo"
      "\nEsse numero X esta no intervalo de 2 até um número escolhido\n"
      "\nVoce deve chutar dois numeros A e B"
	  "\n----------------------------------------"
	  "\nSe A % X > B % X, o jogo retorna Hiro"
	  "\nSe A % X <= B % X, o jogo retorna Batata"
	  "\n**********************************************************************\n"

)

modo = input("Rodar em modo teste(t) ou jogo(j)? ")
if modo == "t": modo = "TESTE"
elif modo == "j": modo = "JOGO "


print("\n************************** RODANDO {}... **************************\n".format(modo))

if modo == "TESTE":
	print("""Ações\n>Sair: s\n>Trocar favorito: t\n>Chutar dois números: c\n""")
	
	acao = "t"
	while acao != "s":
		
		if acao == "t":
			#Recebe o número favorito
			favorito = int(input("Digite o número favorito:\n"))
		
		#Recebe a ação
		acao = input("\nQual ação deseja fazer?(s/t/c) ")
		
		if acao == "c":

			#Recebe os dois números
			num1, num2 = input("Digite dois números:\n").split()
			num1 = int(num1)
			num2 = int(num2)

			#Imprime de acordo com a condição 
			if num1 % favorito > num2 % favorito :
				print(">>> Hiro")
			elif num2 % favorito >= num1 % favorito :
				print(">>> Batata")
			
elif modo == "JOGO ":
	print("Ações                      Níveis\n"
         "|>Sair: s                  |>Suave: s(favorito de 2 até 100)\n"
         "|>Chutar dois números: c   |>Maomeno: m(favorito até de 2 até 10000)\n"
         "|>Tentar responder: r      |>Fodido: f(favorito até de 2 até 1000000)\n")
		
	nivel = input("Em qual nível deseja jogar?(s/m/f) ")
	if nivel == "s": limite = 100
	elif nivel == "m": limite = 10000
	elif nivel == "f": limite = 1000000

	print("\n**************************** JOGANDO... *****************************\n")

	#Sorteia o número favorito
	favorito = random.randrange(2, limite)
		
	acao = "nada"	
	while acao != "s":
		
		#Recebe a ação
		acao = input("Qual ação deseja fazer?(s/c/r) ")
		
		if acao == "c":

			#Recebe os dois números
			num1, num2 = input("Digite dois números:\n").split()
			num1, num2 = int(num1), int(num2)

			#Imprime de acordo com a condição 
			if num1 % favorito > num2 % favorito :
				print("Hiro\n")
			elif num2 % favorito >= num1 % favorito :
				print("Batata\n")
			
		elif acao == "r":
			resposta = int(input("Digite sua resposta:\n"))

			if resposta == favorito: print("\nAcertou! Parabêns, corno!")
			else : 
				print("\nErrou, corno! Favor pensar mais antes de vir dar resposta errada!")

				acao = input("Quer desistir?(s/n)")

				if acao == "s": print("\nOBVIAMENTE, a resposta era {}\n".format(favorito))

