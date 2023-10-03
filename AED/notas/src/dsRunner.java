import notas.ds.exceptions.*;
import notas.ds.implem.*;
import notas.ds.interfaces.*;
import notas.ds.interfaces.Queue;
import dataStructures.*;
import dataStructures.EmptyQueueException;

import java.io.IOException;

import notas.auxiliar.*;
public class dsRunner {

	public static void main(String[] args) throws IOException, EmptyQueueException, notas.ds.exceptions.EmptyQueueException {

		Queue<Integer> intQueue= new QueueInFixedArray<>(5);
		Integer[] nums= CollectionAlgorithms.randIntArrAux(0, 100, 3);
		
		for(int i=0;i<nums.length;i++) {
			System.out.println("Começar");
			intQueue.enqueue(nums[i]);
			System.out.println("Acabar");
			
		}
		

		System.in.read();
			
		System.out.println(intQueue);

		intQueue.enqueue(5);

		System.in.read();
			
		System.out.println(intQueue);
		

		intQueue.dequeue();
		intQueue.dequeue();
		System.in.read();
			
		
		System.out.println(intQueue);

		intQueue.enqueue(5);

		intQueue.enqueue(5);
		System.in.read();
			
		
		System.out.println(intQueue);

		intQueue.enqueue(5);
		System.in.read();
			
		
		System.out.println(intQueue);

		intQueue.dequeue();
		System.in.read();
			
		
		System.out.println(intQueue);



	}

}
