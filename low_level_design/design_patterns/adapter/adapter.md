# Adapter Pattern

## Intent
- Convert the interface of a class into another interface clients expect  
- Enable incompatible interfaces to work together  
- Act as a bridge between two mismatched components  

## Structure
- Target (interface)
  - expected by client  
- Adapter
  - implements Target  
  - wraps Adaptee  
  - translates calls  
- Adaptee
  - existing class with incompatible interface  
- Client
  - interacts with Target interface  

## When to Use
- Need to integrate a legacy or third-party class  
- Interfaces are incompatible but functionality is reusable  
- Want to reuse existing code without modifying it  
- Need to standardize multiple different interfaces  

## Core Idea
- Wrap existing class and **translate interface calls**  
- Client talks to Target → Adapter converts → Adaptee executes  

## What It Solves
- Eliminates interface incompatibility  
- Avoids rewriting existing or third-party code  
- Enables reuse of legacy components  

## SOLID principles
- Wrapper around an existing class  
- Translation layer between interfaces  
- Decoupling between client and adaptee  

## Preconditions
- Existing class provides required functionality but wrong interface  
- Cannot or should not modify adaptee (e.g., third-party)  
- A common Target interface can be defined  

## Postconditions
- Client interacts with a consistent interface  
- Adaptee is reused without modification  
- System becomes more flexible and extensible  

## Trade-offs

### Pros
- Promotes reuse of existing code  
- Decouples client from concrete implementations  
- Improves flexibility and integration  
- Follows Single Responsibility Principle (separates conversion logic)  

### Cons
- Adds extra layer of abstraction  
- Can increase complexity with many adapters  
- May introduce slight performance overhead  
- Harder to debug due to indirection  

## Subtle but Important Insight
- Shifts from:
  - "modify existing code to fit new interface"  
  - to "wrap it and translate calls externally"  

This enables:
- safe integration of legacy systems  
- minimal code changes  
- better separation of concerns  

## Variants
- Class Adapter → uses inheritance (less common, language dependent)  
- Object Adapter → uses composition (most common)  
- Two-way Adapter → supports both interfaces  

## Comparisons
- vs Decorator → adds behavior vs changes interface  
- vs Facade → simplifies interface vs converts interface  
- vs Bridge → separates abstraction vs adapts incompatibility  