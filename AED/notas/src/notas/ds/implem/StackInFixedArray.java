package notas.ds.implem;

import notas.ds.exceptions.EmptyStackException;
import notas.ds.exceptions.FullStackException;
import notas.ds.interfaces.Stack;

public class StackInFixedArray<T> implements Stack<T> {
	
	private T[] container;
	private int size,curr;
	
	public StackInFixedArray(int size) {
			
			this.container= (T[])new Object [size];
			this.size=size;
			this.curr=-1;
		
		
	}
	
	@Override
	public void push(T elem) {
		if(isEmpty()) {
			
			throw new FullStackException();
			
		}
		container[curr++]=elem;
		
	}

	@Override
	public T pop() throws EmptyStackException {
		if(curr==-1) {
			
			throw new EmptyStackException();
		}
		container[curr]=null;
		return container[--curr];
	}

	@Override
	public T top() throws EmptyStackException {
		
		return container[curr]; 
	}

	@Override
	public int size() {
		return curr+1;
	}

	@Override
	public boolean isEmpty() {
		return curr==size-1;
	}

}
