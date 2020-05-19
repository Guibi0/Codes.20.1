Uma pessoa muito leiga em criptografia criou uma função PRG com a seguinte descrição:

A PRG recebe como entrada uma chave de 2 bytes e produz como saída uma keystream do tamanho da mensagem. Inicialmente, keystream é formada somente pela chave. Em seguida, para cada posição i >= 2 da keystream, o valor do byte da posição i é calculado pela soma dos bytes das posições (i - 1) e (i - 2) módulo 256.

Com base nisso, decripte o ciphertext abaixo utilizando a chave 2d3c. Ambos estão codificados em hexadecimal.

634907c66f93b4075089abea45bc037aaebb2b410bc86dd6abf915
