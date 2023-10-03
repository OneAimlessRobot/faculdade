import notas.ds.exceptions.*;
import notas.ds.implem.*;
import notas.ds.interfaces.*;

import java.io.IOException;

import notas.auxiliar.*;
public class dsRunner {

	public static void main(String[] args) throws IOException {

		QueueInFixedArray<Integer> intQueue= new QueueInFixedArray<>(3);
		Integer[] nums= CollectionAlgorithms.randIntArrAux(0, 100, 3);
		
		for(int i=0;i<nums.length;i++) {
			System.out.println("Começar");
			intQueue.enqueue(nums[i]);
			System.out.println("Acabar");
			
		}
		
		System.in.read();
			
		System.out.println(intQueue);
		while(!intQueue.isEmpty())
			try {
				System.out.printf("%d\n",intQueue.dequeue());
			} catch (EmptyQueueException e) {
				e.printStackTrace();
			}
			
		
	}

}
