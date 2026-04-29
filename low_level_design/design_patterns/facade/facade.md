# Facade Pattern (Refined Notes)

## Intent
- Provide a simplified, unified interface to a complex subsystem  
- Hide the complexity of multiple components behind a single entry point  
- Improve usability and reduce coupling with subsystem  

## Structure
- Facade
  - exposes simplified methods  
  - delegates calls to subsystem classes  
- Subsystem Classes
  - perform actual work  
  - contain complex logic and interactions  
- Client
  - interacts only with Facade  

## When to Use
- System has many interdependent classes with complex interactions  
- Want to provide a simple API for a complex system  
- Need to decouple clients from subsystem internals  
- Want to layer system architecture (e.g., API layer over core logic)  

## Core Idea
- Introduce a single entry point that **orchestrates complex interactions**  
- Client → Facade → multiple subsystem calls  

## What It Solves
- Reduces complexity exposed to client  
- Minimizes tight coupling with subsystem classes  
- Improves readability and usability of APIs  

## Connection to SOLID Principles
- **Single Responsibility Principle (SRP)**
  - Facade focuses on simplifying interaction, not implementing logic  

- **Open/Closed Principle (OCP)**
  - New subsystem features can be added without changing client code  

- **Dependency Inversion Principle (DIP)**
  - Client depends on Facade abstraction, not concrete subsystem classes  

## Preconditions
- A complex subsystem exists with multiple interacting components  
- Common usage patterns can be identified and simplified  
- Subsystem responsibilities are well-defined  

## Postconditions
- Client interacts with a simplified interface  
- Subsystem complexity is hidden  
- Coupling between client and subsystem is reduced  

## Trade-offs

### Pros
- Simplifies complex systems  
- Reduces coupling between client and subsystem  
- Improves code readability and maintainability  
- Encourages layered architecture  

### Cons
- Can become a "god object" if overloaded with responsibilities  
- May hide useful subsystem functionality from advanced clients  
- Adds an extra abstraction layer  

## Subtle but Important Insight
- Shifts from:
  - "client directly managing multiple components"  
  - to "client uses a single orchestrator"  

This enables:
- cleaner APIs  
- better separation of concerns  
- easier onboarding for new developers  

## Variants
- Layered Facade → different facades for different use cases  
- Facade + Singleton → single access point  
- Facade + Adapter → unify multiple incompatible subsystems  

## Comparisons
- vs Adapter → converts interface vs simplifies interface  
- vs Decorator → adds behavior vs hides complexity  
- vs Mediator → coordinates interactions vs provides simplified access  