package notas.ds.implem;

import notas.ds.exceptions.EmptyQueueException;
import notas.ds.exceptions.FullQueueException;
import notas.ds.interfaces.Queue;

public class QueueInFixedArray<T> implements Queue<T> {
		
		private T[] container;
		private int size,front,back;
		
		public QueueInFixedArray(int size) {
				
				this.container= (T[])new Object [size];
				this.size=0;
				this.front=0;
				this.back=size-1;
			
			
		}
		
		@Override
		public void enqueue(T elem) {

			back++;
			size++;
			if(back==container.length) {
				
				back=0;
			}
			if(back==front) {
				
				throw new FullQueueException();
				
			}
			container[back]=elem;
			
		}

		@Override
		public T dequeue() throws EmptyQueueException {

			front++;
			size--;
			if(front==container.length) {
				
				front=0;
			}
			if(front==back) {
				
				throw new EmptyQueueException();
			}
			T result= container[front-1];
			container[front-1]=null;
			return result;
		}

		@Override
		public T front() throws EmptyQueueException {
			
			return container[front]; 
		}

		@Override
		public int size() {
			
			return size;
		}

		@Override
		public boolean isEmpty() {
			return size==0;
		}

		@Override
		public T back() throws EmptyQueueException {

			return container[back]; 
		}

	}


