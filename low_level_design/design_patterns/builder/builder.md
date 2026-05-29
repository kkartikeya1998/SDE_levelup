# Builder Pattern 

## Intent
- Separate the construction of a complex object from its representation  
- Allow the same construction process to create different representations  
- Construct objects step-by-step  

## Structure
- Product
  - complex object being built
  - private constructor hidden from client
- Builder (interface / abstract class)
  - defines construction steps
  - friend of the product  
- ConcreteBuilder
  - implements steps and assembles Product  
- Director (optional)
  - controls construction sequence  
- Client
  - chooses builder and triggers construction  

## When to Use
- Object creation involves many optional parameters  
- Construction process is complex or step-by-step  
- Want to avoid telescoping constructors  
- Need different representations of the same object  
- Want immutable objects after construction  

## Core Idea
- Separate:
  - "how object is built"  
  - from
  - "what object looks like"  

Construction happens incrementally through builder methods.

## What It Solves
- Eliminates complex constructors with many parameters  
- Improves readability of object creation  
- Encapsulates construction logic  
- Supports multiple representations using same process  

## Connection to SOLID Principles
- **Single Responsibility Principle (SRP)**
  - Product focuses on business logic  
  - Builder focuses on construction logic  

- **Open/Closed Principle (OCP)**
  - New builders can be introduced without modifying existing code  

- **Dependency Inversion Principle (DIP)**
  - Client depends on Builder abstraction, not concrete construction details  

## Preconditions
- Object construction is complex or has many configurations  
- Construction steps can be isolated cleanly  
- Partial/incremental construction is meaningful  

## Postconditions
- Complex objects are created in a controlled manner  
- Construction logic is centralized and reusable  
- Client code becomes cleaner and more expressive  

## Trade-offs

### Pros
- Cleaner and more readable object creation  
- Avoids telescoping constructor problem / constructor overloading for too many parameters
- Supports step-by-step construction  
- Construction process can be reused  
- Makes immutable object creation easier  
- Avoids scattered validation for each use of the created object

### Cons
- Increases number of classes  
- Can be overkill for simple objects  
- Slightly more verbose than direct construction  
- Director abstraction may become unnecessary in simple cases  

## Subtle but Important Insight
- Shifts from:
  - "construct object in one giant constructor call"  
  - to "progressively assemble object step-by-step"  

This enables:
- readable object creation  
- flexible configurations  
- better separation of concerns  

## Variants
- Fluent Builder → method chaining (`return this`)  
- Immutable Builder → builds immutable objects  
- Director-based Builder → standardized construction workflow  
- Nested Builder → builder class inside Product class  

## Comparisons
- vs Factory Method → single-step creation vs step-by-step construction  
- vs Abstract Factory → creates related families vs builds one complex object  
- vs Prototype → clone existing object vs construct incrementally  