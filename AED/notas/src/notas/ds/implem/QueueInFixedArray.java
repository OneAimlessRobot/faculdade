package notas.ds.implem;

import notas.ds.exceptions.EmptyQueueException;
import notas.ds.interfaces.Queue;

public class QueueInFixedArray<T> implements Queue<T> {
		
		private T[] container;
		private int size,front,back;
		
		public QueueInFixedArray(int size) {
				
				this.container= (T[])new Object [size];
				this.size=size;
				this.front=0;
				this.back=size-1;
			
			
		}
		
		@Override
		public void enqueue(T elem) {
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

		@Override
		public T dequeue() throws EmptyQueueException {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public void enqueue(T elem) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public T front() throws EmptyQueueException {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public T back() throws EmptyQueueException {
			// TODO Auto-generated method stub
			return null;
		}

	}

}
