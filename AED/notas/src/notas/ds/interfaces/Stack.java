package notas.ds.interfaces;

import notas.ds.exceptions.EmptyStackException;
import notas.ds.exceptions.FullStackException;

public interface Stack<T> {
		
	void push(T elem);
	
	T pop() throws EmptyStackException;
	
	T top() throws EmptyStackException;  
	
	int size();
	
	boolean isEmpty();

}
