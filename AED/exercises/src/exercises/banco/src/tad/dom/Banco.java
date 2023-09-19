package exercises.banco.src.tad.dom;

import java.util.Date;

import exercises.banco.src.tad.abstr.Iterator;

public interface Banco {

	String criar_cartao(String nome);
	String obter_nome(String numero);
	void inserir_mov(String numero,Date data, char tipo,double mont);
	Iterator<Transaction> listar_mov(String numero);
	
}
