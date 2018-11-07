Lift
====
Lift is an attempt at creating a compile time dependency resolver framework 
in C++. It leverages some of the new features available in C++11, 
specifically tuples and parameter packs, along with a few other nice 
additions. Lift attempts to provide dependency injection for lambdas by 
using compile time inspection and TMP.  

A number of the ideas behind this framework come from IoC concepts (Spring, Angular).
The point of this framework is to provide an easy way to instantiate class
objects within C++ and provide IoC for ease of testing. 

Example
----

### Application and Factory
    
    application().create_factory(
        [=](ObjectOne objectOne, ObjectTwo objectTwo) -> ObjectThree
        {
            // maybe do something with objectOne and objectTwo
            // ...
            // ...
            
            // use objectOne and objectTwo in the ctor for an ObjectThree
            return ObjectThree(objectOne, objectTwo);
        }).run();

License
----
The MIT License (MIT)

Copyright
----
Copyright 2015 Phil Egelston (pegelston@gmail.com)
