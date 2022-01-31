##### Why does Java not make use of pointers?
- Java focuses on code simplicity
- security is also compromised if pointers are used because the users can directly access memory with the help of pointers
- a certain level of abstraction is furnished by not including pointers in Java
- Moreover, the usage of pointers can make the procedure of garbage collection quite slow and erroneous. Java makes use of references as these cannot be manipulated, unlike pointers.

##### What do you understand by an instance variable and a local variable?
###### Instance variables
- are accessible by all the methods in the class
- are declared outside the methods and inside the class.
- describe the properties of an object and remain bound to it at any cost
- All the objects of the class will have their copy of the variables for utilization. If any modification is done on these variables, then only that instance will be impacted by it, and all other class instances continue to remain unaffected.
```
class Athlete {
    public String athleteName;
    public double athleteSpeed;
    public int athleteAge;
}
```
###### Local variables
- present within a block, function, or constructor and can be accessed only inside them.
```
public void athlete() {
    String athleteName;
    double athleteSpeed;
    int athleteAge;
}
```
![image](https://user-images.githubusercontent.com/15718435/151692876-7aa64626-3dd7-43de-aa67-18b54ffe8339.png)

##### When can you use super keyword?
- to access hidden fields and overridden methods or attributes of the parent class
- Following are the cases when this keyword can be used:
    - Accessing data members of parent class when the member names of the class and its child subclasses are same.
    - To call the default and parameterized constructor of the parent class inside the child class.
    - Accessing the parent class methods when the child classes have overridden them

##### Can the static methods be overloaded?
Yes! There can be two or more static methods in a class with the same name but differing input parameters.

##### Can the static methods be overridden?
- No! Declaration of static methods having the same signature can be done in the subclass but run time polymorphism can not take place in such cases.
- Overriding or dynamic polymorphism occurs during the runtime, but the static methods are loaded and looked up at the compile time statically. Hence, these methods cant be overridden.

##### What is the main objective of garbage collection?
- to free up the memory space occupied by the unnecessary and unreachable objects during the Java program execution by deleting those unreachable objects.
- ensures that the memory resource is used efficiently, but it provides no guarantee that there would be sufficient memory for the program execution
- heap is cleaned in garbage collection process

##### Why are strings immutable in Java?
- String Pool: By using the String pool (a storage area in Java heap) to store the String literals. They intended to decrease the temporary String object with the help of sharing. An immutable class is needed to facilitate sharing. The sharing of the mutable structures between two unknown parties is not possible. Thus, immutable Java String helps in executing the concept of String Pool.
- Multithreading: The safety of threads regarding the String objects is an important aspect in Java. No external synchronization is required if the String objects are immutable.
- Collections: In the case of Hashtables and HashMaps, keys are String objects. If the String objects are not immutable, then it can get modified during the period when it resides in the HashMaps. Consequently, the retrieval of the desired data is not possible. Such changing states pose a lot of risks. Therefore, it is quite safe to make the string immutable

#####
#####
#####
#####
#####
#####
#####
#####
#####
#####
#####
#####
#####
#####
#####
#####
#####
#####
#####
#####
#####
