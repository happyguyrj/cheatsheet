# Queue
- functionality of the queue data structure
- extends the Collection interface
- First In, First Out

## Linkedlist Queue

### LinkedListQueue Vs ArrayDequeue
- LinkedListQueue consume more memory
- If you need add/remove of the both ends, ArrayDeque is significantly better than a linked list. Random access each element is also O(1) for a cyclic queue.
- LinkedList supports null elements, whereas ArrayDeque does not.
- The only better operation of a linked list is removing the current element during iteration.
- ArrayDequeue is "better" in some cases because you're not allocating a node for each item to insert; instead all elements are stored in a giant array, which is resized if it gets full.


## Priority Queue
A PriorityQueue is used when the objects are supposed to be processed based on the priority

- doesn’t permit null
- are unbound queues
- head of this queue is the least element
- is not thread-safe
    - java provides PriorityBlockingQueue class that implements the BlockingQueue interface to use in java multithreading environment.
- queue retrieval operations poll,  remove,  peek, and element access the element at the head of the queue
- provides O(log(n)) time for add and poll methods
- inherits methods from AbstractQueue, AbstractCollection, Collection and Object class

### Constructors:
Constructors:
Creates a PriorityQueue with the default initial capacity (11) that orders its elements according to their natural ordering.
```
PriorityQueue<E> pq = new PriorityQueue<E>();
```

Creates a PriorityQueue with the specified initial capacity that orders its elements according to their natural ordering.
```
PriorityQueue<E> pq = new PriorityQueue<E>(int initialCapacity);
```

Creates a PriorityQueue with the specified initial capacity that orders its elements according to the specified comparator.
```
PriorityQueue<E> pq = new PriorityQueue(int initialCapacity, Comparator<E> comparator);
```

Creates a PriorityQueue containing the elements in the specified collection, priority queue, and sorted set.
```
PriorityQueue<E> pq = new PriorityQueue<E>(Collection<E> c);
PriorityQueue<E> pq = new PriorityQueue(PriorityQueue<E> c);
PriorityQueue<E> pq = new PriorityQueue<E>(SortedSet<E> c);
```

#### Methods
- boolean add(E element): This method inserts the specified element into this priority queue.
- public peek(): This method retrieves, but does not remove, the head of this queue, or returns null if this queue is empty.
- public poll(): This method retrieves and removes the head of this queue, or returns null if this queue is empty.

## ArrayDequeue
