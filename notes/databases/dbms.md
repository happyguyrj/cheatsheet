## Disadvantages of file processing systems
- Inconsistent
- Not secure
- Data redundancy
- Difficult in accessing data
- Data isolation
- Data integrity
- Concurrent access is not possible
- Limited data sharing
- Atomicity problem

## DBMS
- collection of programs that facilitates users to create and maintain a database
- provides us an interface or tool for performing different operations
- is a software in which data is stored in a more secure way as compared to the file-based system
- overcome many problems such as- data redundancy, data inconsistency, easy access, more organized and understandable, and so on
- Advantages
    - Redundancy control
    - Restriction for unauthorized access
    - Provides multiple user interfaces
    - Provides backup and recovery
    - Enforces integrity constraints
    - Ensure data consistency
    - Easy accessibility
    - Easy data extraction and data processing due to the use of queries

## Database
- a logical, consistent and organized collection of data
- databases are structured to provide the facility of creation, insertion, updating of the data efficiently and are stored in the form of a file or set of files, on the magnetic disk, tapes and another sort of secondary devices. -
- consists of the objects (tables), and tables include of the records and fields.
    - Fields are the basic units of data storage, which contain the information about a particular aspect or attribute of the entity described by the database.

## Checkpoint
The Checkpoint is a type of mechanism where all the previous logs are removed from the system and permanently stored in the storage disk.
- There are two ways which can help the DBMS in recovering and maintaining the ACID properties, and they are- maintaining the log of each transaction and maintaining shadow pages.
- So, when it comes to log based recovery system, checkpoints come into existence.
- Checkpoints are those points to which the database engine can recover after a crash as a specified minimal point from where the transaction log record can be used to recover all the committed data up to the point of the crash.
- A checkpoint is like a snapshot of the DBMS state.
- Using checkpoints, the DBMS can reduce the amount of work to be done during a restart in the event of subsequent crashes.

## Database languages
### Data Definition Language (DDL)
- e.g., CREATE, ALTER, DROP, TRUNCATE, RENAME, etc.
- All these commands are used for updating the data that?s why they are known as Data Definition Language.

### Data Manipulation Language (DML)
- e.g., SELECT, UPDATE, INSERT, DELETE, etc.
- These commands are used for the manipulation of already updated data that's why they are the part of Data Manipulation Language.

### DATA Control Language (DCL)
- e.g., GRANT and REVOKE.
- These commands are used for giving and removing the user access on the database. So, they are the part of Data Control Language.

### Transaction Control Language (TCL)
- e.g., COMMIT, ROLLBACK, and SAVEPOINT.
- These are the commands used for managing transactions in the database. TCL is used for managing the changes made by DML.

## Data abstraction in DBMS
- hiding irrelevant details from users
- levels of data abstraction
    - Physical level
        - lowest level of abstraction
        - describes how data are stored.
    - Logical level
        - next higher level of abstraction
        - describes what data are stored in the database and what the relationship among those data is.
    - View level
        - highest level of data abstraction.
        - describes only part of the entire database.

## Query optimization
- query optimization specifies an efficient execution plan for evaluating a query that has the least estimated cost
- Benefits of query optimization:
    - It reduces the time and space complexity.
    - More queries can be performed as due to optimization every query comparatively takes less time.
    - User satisfaction as it will provide output fast

## Normalization
- process of analysing the given relation schemas according to their functional dependencies.
- used to minimize redundancy and also used to minimize insertion, deletion and update distractions.
- used to avoid data redundancy, insertion anomaly, updation anomaly, deletion anomaly.
- most commonly used normal forms
    - First Normal Form(1NF)
        - Objectives
            - Every column must have atomic (single value)
            - To Remove duplicate columns from the same table
            - Create separate tables for each group of related data and identify each row with a unique column
    - Second Normal Form(2NF)
        - Conditions
            - The table is in 1NF
            - Every non-prime attribute is fully functionally dependent on the primary key, i.e., every non-key attribute should be dependent on the primary key in such a way that if any key element is deleted, then even the non_key element will still be saved in the database.
    - Third Normal Form(3NF)
        - Conditions
            - It is in second normal form.
            - There is no transitive functional dependency.
                ```
                For example: X->Z
                Where:
                X->Y
                Y does not -> X
                Y->Z so, X->Z
                ```
    - Boyce & Codd Normal Form(BCNF)
        - Conditions
            - table is in 3NF
            - For every functional dependency X->Y, X should be the super key of the table. It merely means that X cannot be a non-prime attribute if Y is a prime attribute.

## Denormalization
- boosting up database performance and adding of redundant data which helps to get rid of complex data.
- to avoid the use of complex and costly joins.

## Functional Dependency
- starting point of normalization
- exists when a relation between two attributes allow you to determine the corresponding attribute's value uniquely
- also known as database dependency and defines as the relationship which occurs when one attribute in a relation uniquely determines another attribute
- written as A->B which means B is functionally dependent on A.

## ACID
### ATOMICITY:
- all or nothing rule
- Which implies all are considered as one unit, and they either run to completion or not executed at all.

### CONSISTENCY
- refers to the uniformity of the data.
- Consistency implies that the database is consistent before and after the transaction.

### ISOLATION
- states that the number of the transaction can be executed concurrently without leading to the inconsistency of the database state.

### DURABILITY
- ensures that once the transaction is committed it will be stored in the non-volatile memory and system crash can also not affect it anymore.


## Lock
### Shared lock
- Shared lock is required for reading a data item.
- In the shared lock, many transactions may hold a lock on the same data item

### Exclusive lock
- When any transaction is about to perform the write operation
    - if we allow more than one transaction then that will lead to the inconsistency in the database.

## Keys
### Primary key
The Primary key is an attribute in a table that can uniquely identify each record in a table. It is compulsory for every table

### Candidate key
The Candidate key is an attribute or set of an attribute which can uniquely identify a tuple. The Primary key can be selected from these attributes.

### Super key
The Super key is a set of attributes which can uniquely identify a tuple. Super key is a superset of the candidate key.

### Foreign key
The Foreign key is a primary key from one table, which has a relationship with another table. It acts as a cross-reference between tables.

## Constraints
- NOT NULL - Restricts NULL value from being inserted into a column.
- CHECK - Verifies that all values in a field satisfy a condition.
- DEFAULT - Automatically assigns a default value if no value has been specified for the field.
- UNIQUE - Ensures unique values to be inserted into the field.
- INDEX - Indexes a field providing faster retrieval of records.
- PRIMARY KEY - Uniquely identifies each record in a table.
- FOREIGN KEY - Ensures referential integrity for a record in another table.

## DELETE Vs TRUNCATE
### DELETE
- DELETE command delete only those rows which are specified with the WHERE clause.
- DELETE command can be rolled back.
- DELETE command maintain a log, that's why it is slow.
- DELETE use row lock while performing DELETE function.

### TRUNCATE
- The TRUNCATE command removes all the rows from the table.
- The TRUNCATE command cannot be rolled back.
- The TRUNCATE command doesn't maintain a log. That's why it is fast.
- TRUNCATE use table log while performing the TRUNCATE function.

## Join
### (INNER) JOIN
Retrieves records that have matching values in both tables involved in the join
```
SELECT *
FROM Table_A
JOIN Table_B;
SELECT *
FROM Table_A
INNER JOIN Table_B;
```

### LEFT (OUTER) JOIN
Retrieves all the records/rows from the left and the matched records/rows from the right table.
```
SELECT *
FROM Table_A A
LEFT JOIN Table_B B
ON A.col = B.col;
```

### RIGHT (OUTER) JOIN
Retrieves all the records/rows from the right and the matched records/rows from the left table.
```
SELECT *
FROM Table_A A
RIGHT JOIN Table_B B
ON A.col = B.col;
```

### FULL (OUTER) JOIN:
Retrieves all the records where there is a match in either the left or right table
```
SELECT *
FROM Table_A A
FULL JOIN Table_B B
ON A.col = B.col;
```

## Self-Join
- A self JOIN is a case of regular join where a table is joined to itself based on some relation between its own column(s).
- Self-join uses the INNER JOIN or LEFT JOIN clause and a table alias is used to assign different names to the table within the query.
```
SELECT
    A.emp_id AS "Emp_ID",
    A.emp_name AS "Employee",
    B.emp_id AS "Sup_ID",
    B.emp_name AS "Supervisor"
FROM employee A, employee B
    WHERE A.emp_sup = B.emp_id;
```

## Cross-Join
- Cross join can be defined as a cartesian product of the two tables included in the join
- The table after join contains the same number of rows as in the cross-product of the number of rows in the two tables. If a WHERE clause is used in cross join then the query will work like an INNER JOIN.

## Index
- data structure that provides a quick lookup of data in a column or columns of a table
- enhances the speed of operations accessing data

### Unique and Non-Unique Index:
- Unique indexes are indexes that help maintain data integrity by ensuring that no two rows of data in a table have identical key values. Once a unique index has been defined for a table, uniqueness is enforced whenever keys are added or changed within the index.
- Non-unique indexes, on the other hand, are not used to enforce constraints on the tables with which they are associated. Instead, non-unique indexes are used solely to improve query performance by maintaining a sorted order of data values that are used frequently

### Clustered and Non-Clustered Index:
Clustered indexes are indexes whose order of the rows in the database corresponds to the order of the rows in the index. This is why only one clustered index can exist in a given table, whereas, multiple non-clustered indexes can exist in the table.

The only difference between clustered and non-clustered indexes is that the database manager attempts to keep the data in the database in the same order as the corresponding keys appear in the clustered index.

Clustering indexes can improve the performance of most query operations because they provide a linear-access path to data stored in the database
https://www.interviewbit.com/sql-interview-questions/#