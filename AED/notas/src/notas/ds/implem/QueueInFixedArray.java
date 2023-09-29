package notas.ds.implem;

import notas.ds.exceptions.EmptyQueueException;
import notas.ds.exceptions.FullQueueException;
import notas.ds.interfaces.Queue;

public class QueueInFixedArray<T> implements Queue<T> {
		
		public T[] container;
		private int size,front,back;
		
		public QueueInFixedArray(int size) {
				
				this.container= (T[])new Object [size];
				this.size=0;
				this.front=0;
				this.back=0;
			
			
		}
		
		@Override
		public void enqueue(T elem) {

			if((size==container.length||back==front)&&!isEmpty()) {
				
				throw new FullQueueException();
				
			}
			container[back++]=elem;
			size++;
			if(back==container.length) {
				
				back=0;
			}
			
		}
		
		public String toString() {
			String result="[";
			for(int i=0;i<container.length;i++) {
				
				if(container[i]==null) {
					
					result+="null ";
				}
				else {
				result=result+container[i]+" ";
				}
			}
			result+="]";
			return result;
			
			
			
		}

		@Override
		public T dequeue() throws EmptyQueueException {

			if(isEmpty()) {
				
				throw new EmptyQueueException();
			}
			T result= container[front];
			container[front++]=null;
			size--;
			if(front==container.length) {
				
				front=0;
			}
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


