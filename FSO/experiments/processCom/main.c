#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
//ficheiros sao usados como meio de comunicaçao entre processos no caso de n serem concorrentes.
//signal alarm serve para garantir que um processo n demore mais do que o pretendido. É um abort
//com temporizador. Um pedido de suicidio nas urgencias de lisboa.
/*
Vamos aprender sobre pipes.
É um mecanismo de comunicação entre processos.
	- Permitem sincronizar (e partilhar memória entre) processos.
Variantes:

	- Memória comum.
	Agora...
	E se tiverem em computadores diferentes e quisermos que n interfiram?

	- Enviar packets. (Unidades indivisiveis de informaçao. Comunicação por turnos).
	(Usar send/receive)
	- Comunicar por tuneis. (Usando pipes) (Streams).
	(Read/write).
	Os  tuneis podem ser...
	- ou pipes(só partilhaveis por um processo e descendentes)
	- e sockets
	(Pode-se realizar por processos de origens diferentes e possuem um caminho)
	Um pipe é criado em C de unix a partir de 2 descritores de ficheiro: Um para leitura. Outro para escrita.
	O pipe contém os dados a serem transferidos a cada momento. É criado em RAM.

	Quando fazemos fork de um processo que tem um pipe aberto, como ambos os processos possuem ambos os canais nos seus metadados,
	Se o filho ler do canal de leitura e o pai escrever no de escrita BAM! Comunicação entre pai e filho! Amor familiar!!
	Se usarmos pipes em comandos shell (bin1 | bin2), O stdin de bin1 é ligado diretamente ao stdout de bin2.
		O pipe tem tamanho limite.
		Os processos são colocados em concorrência.
	Um pipe tem um canal de escrita e um de leitura.
*/
int main(int argc, char ** argv){




	return 0;
}
