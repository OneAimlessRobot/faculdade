package notas.ds.interfaces;

import notas.ds.exceptions.EmptyQueueException;

public interface Queue<T> {
	
	
	T dequeue() throws EmptyQueueException;
	
	void enqueue(T elem);
	
	T front() throws EmptyQueueException;
	
	
	T back() throws EmptyQueueException;
	
	boolean isEmpty();
	
	int size();

}
