##  Object-Oriented Programming
- is a paradigm that provides many concepts, such as inheritance, data binding, polymorphism, etc
- everything is represented as an object
- design a program using classes and objects

## Object
Any entity that has state and behavior is known as an object
- instance of a class
- contains an address
- takes up some space in memory
- can communicate without knowing the details of each other's data or code

## Class
Collection of objects is called class
- is a logical entity.
- a blueprint from which you can create an individual object
- doesn't consume any space



## Inheritance
When one object acquires all the properties and behaviors of a parent object
- provides code reusability
- used to achieve runtime polymorphism
- represents the is-a relationship

## Polymorphism
ability of OOPs programming languages to differentiate between entities with the same name efficiently.
- In Java, we use method overloading and method overriding to achieve polymorphism
### Method Overloading
can create multiple methods of the same name in the same class

### Method Overriding
process when the subclass or a child class has the same method as declared in the parent class.

Polymorphism in java can be classified into two types:
### Static / Compile-Time Polymorphism
- is achieved through Method Overloading
- can also be achieved through Operator Overloading
    - Java does not support Operator Overloading

### Dynamic / Runtime Polymorphism
- achieved through Method Overriding.

#### Upcasting
Overriding is done by using a reference variable of the superclass. Which method to be called is determined based on the object which is being referred to by the reference variable.
Upcasting is done when the Parent class’s reference variable refers to the object of the child class.
```
For example:
class A{}
class B extends A{}
A a=new B(); //upcasting
```

## Abstraction
Hiding internal details and showing functionality
- In Java, we use abstract class and interface to achieve abstraction
### Interface
Interfaces specify what a class must do and not how. It is the blueprint of the class.
- an interface can have methods and variables
- but the methods declared in an interface are by default abstract (only method signature, no body)
- If a class implements an interface and does not provide method bodies for all functions specified in the interface, then the class must be declared abstract
- all the methods in an interface are declared with an empty body and are public
- all fields are public, static and final by default

#### Why do we use interface ?
- It is used to achieve total abstraction.
- Since java does not support multiple inheritance in case of class, but by using interface it can achieve multiple inheritance .
- It is also used to achieve loose coupling.
- Interfaces are used to implement abstraction.
    - So the question arises why use interfaces when we have abstract classes?
    - The reason is, abstract classes may contain non-final variables, whereas variables in interface are final, public and static.

#### Important points about interface:
- We can’t create instance(interface can’t be instantiated) of interface but we can make reference of it that refers to the Object of its implementing class.
- A class can implement more than one interface.
- An interface can extends another interface or interfaces (more than one interface) .
- A class that implements interface must implements all the methods in interface.
- All the methods are public and abstract. And all the fields are public, static, and final.
- It is used to achieve multiple inheritance
- It is used to achieve loose coupling
- we can have an abstract class without any abstract method
    - allows us to create classes that cannot be instantiated but can only be inherited
- Abstract classes can also have final methods (methods that cannot be overridden)
- For any abstract java class we are not allowed to create an object i.e., for abstract class instantiation is not possible.
- Similar to the interface we can define static methods in an abstract class that can be called independently without an object.

### Abstract class
- in Java, a separate keyword abstract is used to make a class abstract.
- An instance of an abstract class can not be created.
- Constructors are allowed
    - constructor of abstract class is called when an instance of an inherited class is created
- We can have an abstract class without any abstract method.
- Abstract classes can not have final methods because when you make a method final you can not override it but the abstract methods are meant for overriding.
- We are not allowed to create object for any abstract class.
- We can define static methods in an abstract class

## Encapsulation
Binding (or wrapping) code and data together into a single unit
- A java class is the example of encapsulation.
- Java bean is the fully encapsulated class because all the data members are private here.
- Data of a class is hidden from any other class and can be accessed only through any member function of own class in which they are declared.
- helps developers to follow modularity while developing software by ensuring that each object is independent of other objects by having its own methods, attributes, and functionalities

## Coupling
Coupling refers to the knowledge or information or dependency of another class.
- arises when classes are aware of each other
- If a class has the details information of another class, there is strong coupling.
- In Java, we use private, protected, and public modifiers to display the visibility level of a class, method, and field.
- You can use interfaces for the weaker coupling because there is no concrete implementation.

## Cohesion
Cohesion refers to the level of a component which performs a single well-defined task
- A single well-defined task is done by a highly cohesive method.
- The weakly cohesive method will split the task into separate parts.
- The java.io package is a highly cohesive package because it has I/O related classes and interface.
- However, the java.util package is a weakly cohesive package because it has unrelated classes and interfaces.

## Association
Association represents the relationship between the objects
- Types
    - One to One
    - One to Many
    - Many to One, and
    - Many to Many
- Association can be undirectional or bidirectional.

## Aggregation
Aggregation is a way to achieve Association
- represents the relationship where one object contains other objects as a part of its state
- represents the weak relationship between objects.
- also termed as a has-a relationship in Java

## Composition
composition is also a way to achieve Association.
- represents the relationship where one object contains other objects as a part of its state.
- strong relationship between the containing object and the dependent object
- state where containing objects do not have an independent existence
- delete the parent object, all the child objects will be deleted automatically.

