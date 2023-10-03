package notas.ds.interfaces;

public interface ConcatenableQueue<T> extends Queue<T> {
	
	void append(ConcatenableQueue<T> addition);
}
