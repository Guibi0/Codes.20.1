Um criptógrafo inventou uma máquina capaz de automaticamente encriptar mensagens que utilizam letras do alfabeto latino. Cada letra corresponde a um número (1 para A, 2 para B, …, 26 para Z). Além disso, algumas letras fazem parte de um conjunto especial (mantido em segredo), resultando em um comportamento especial da máquina.

A máquina realiza a encriptação letra por letra, em dois passos, sendo que ambas as etapas levam o mesmo tempo (mesmo intervalo de tempo) para serem executadas:

*************************
1. Se a letra pertence ao conjunto especial, a máquina não realiza a encriptação, adiciona a letra original ao ciphertext e não executa o passo 2. Caso contrário, execute o passo 2.

2. Substitua a letra atual, associada a um número k, por uma letra y, onde y possui o mesmo resto ao dividir por 10 que k. Após isso, adicione a nova letra ao ciphertext.
*************************

A imagem em anexo mostra o tempo de encriptação de cada letra da mensagem.

Sabendo disso, decripte o seguinte ciphertext:

Zkhubyds! U fbkg oh chifjyyhckssu.
