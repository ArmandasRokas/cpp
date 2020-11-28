### Reference vs pointer
- https://www.geeksforgeeks.org/pointers-vs-references-cpp/
- `*this`, when the function requires object reference, not pointer - https://stackoverflow.com/questions/3781049/using-the-this-pointer-in-c 
- https://stackoverflow.com/questions/18147038/passing-object-by-reference-in-c

### Lvalues and Rvalues

- Left values and right values
-  https://www.oreilly.com/library/view/c-in-a/059600298X/ch03s01.html#:~:text=Put%20simply%2C%20an%20lvalue%20is,writing%20and%20understanding%20of%20expressions.&text=An%20lvalue%20always%20has%20a,that%20is%20not%20an%20lvalue.

### Private function

- Moving private helper functions to be free functions in the `.cpp` file won't work if those functions need to access private member variables. 

### Overloaded Assignment, Copy Constructor, Destructor

- In general we should write these whenever we have a **class that has members that can reference heap space(`pointers`)**. 

### Assignment operator

- Overloaded Assignment only invoked if the object already exists! Like that:                                                                                                                                                   

```C++
Test t1,t2;
t2 = t1;
```

- Default assignment operator copies values from one object to the other, this means that both object remains in memory separately and if we change values in one, so it is not changed in other.  MUST be overloaded, if class contains a pointer to list. 

```C++
t1.value = "one"; // sets only t1 value to "one"
t2.value = "two"; // sets only t2 value two "two"
```



- Can be overloaded like this:

```C++
 Test& operator = (const Test &t) 
    { 
        this->value = t.value;
     	cout<<"Assignment operator called "<<endl; 
        return *this; 
    }  
```

[Youtube](https://www.youtube.com/watch?v=F-7Rpt2D-zo)

###  Copy constructor

- Called by 

```C++
Test t3 = t1; // Create a object t3, that doesn't exist yet, but initializes with values that exists currently in t1
```

### Destructor

- We need a destructor to delete any data that may be referenced by a member on the heap. (created with `new`)



### Debug

https://www.bgsu.edu/arts-and-sciences/computer-science/cs-documentation/using-gdb-to-find-a-run-time-error.html


### Avoid reference members
https://stackoverflow.com/questions/892133/should-i-prefer-pointers-or-references-in-member-data



### Initializer list

https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/