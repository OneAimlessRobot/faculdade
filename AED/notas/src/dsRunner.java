import notas.ds.exceptions.*;
import notas.ds.implem.*;
import notas.ds.interfaces.*;
import notas.auxiliar.*;
public class dsRunner {

	public static void main(String[] args) {

		Queue<Integer> intQueue= new QueueInFixedArray<>(5);
		Integer[] nums= CollectionAlgorithms.randIntArrAux(0, 100, 3);
		
		for(int i=0;i<nums.length;i++) {
			
			intQueue.enqueue(nums[i]);
			
		}
		
		while(!intQueue.isEmpty())
			try {
				System.out.printf("%d\n",intQueue.dequeue());
			} catch (EmptyQueueException e) {
				e.printStackTrace();
			}
			
		
	}

}
