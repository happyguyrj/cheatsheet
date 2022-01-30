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
#####
#####
#####
#####
