package dataStructures;

public class InvertibleQueueInList<E> implements InvertibleQueue<E> {

	/**
	 * Serial Version UID of the Class
	 */
    static final long serialVersionUID = 0L;


    /**
     * Memory of the queue: a list.
     */
    protected List<E> list;                     

    /**
     * Constructor create an empty Doubly Linked List.
     */
    public InvertibleQueueInList( )           
    {
        list = new DoubleList<E>();
    }


	@Override
	public boolean isEmpty() {
		return list.isEmpty();
	}

	@Override
	public int size() {
		return list.size();
	}

	@Override
	public void enqueue(E element) {
		list.add(0, element);

	}


	@Override
	public E dequeue() throws EmptyQueueException {

		return list.remove(list.size());
	}

	@Override
	public void invert() {
		Stack<E> stack=new StackInList<>();
		while(!this.isEmpty()) {
			
			stack.push(this.dequeue());
		}
		while(!stack.isEmpty()) {
			
			this.enqueue(stack.pop());
			
		}

	}

}
