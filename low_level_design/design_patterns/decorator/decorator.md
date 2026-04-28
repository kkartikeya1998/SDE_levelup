# Decorator Pattern 

## Intent
- Attach additional responsibilities to an object dynamically  
- Provide a flexible alternative to subclassing for extending behavior  

## Structure
- Component (interface)
  - defines common operations  
- ConcreteComponent
  - base object with core behavior  
- Decorator (abstract)
  - implements Component  
  - holds reference to Component  
- ConcreteDecorator
  - adds new behavior before/after delegating  

## When to Use
- Want to add behavior dynamically at runtime  
- Avoid subclass explosion due to multiple feature combinations  
- Need flexible and reusable extensions of functionality  
- Want to follow Open/Closed Principle  

## Core Idea
- Wrap objects inside other objects of the same interface  
- Each decorator adds behavior without altering original object  

## What It Solves
- Eliminates rigid inheritance hierarchies  
- Avoids modifying existing code for new features  
- Enables combinatorial feature composition  

## Connection to SOLID Principles
- **Single Responsibility Principle (SRP)**
  - Each decorator adds one specific responsibility  

- **Open/Closed Principle (OCP)**
  - Behavior extended via new decorators without modifying existing code  

- **Liskov Substitution Principle (LSP)**
  - Decorators and components share the same interface → interchangeable  

- **Dependency Inversion Principle (DIP)**
  - Depend on abstractions (Component), not concrete implementations  

## Preconditions
- Objects share a common interface  
- Behavior can be layered incrementally  
- Client can work with abstract Component type  

## Postconditions
- Behavior is extended dynamically via composition  
- Multiple decorators can be combined in different orders  
- Core object remains unchanged  

## Trade-offs

### Pros
- Highly flexible alternative to inheritance  
- Supports dynamic composition of behavior  
- Adheres strongly to SOLID principles  
- Promotes reusable and modular design  

### Cons
- Can lead to many small classes  
- Harder to debug due to deep wrapping chains  
- Order of decorators can affect behavior  
- Increases system complexity  

## Subtle but Important Insight
- Shifts from:
  - "extend behavior via subclassing"  
  - to "wrap objects to layer behavior dynamically"  

This enables:
- runtime flexibility  
- combinatorial feature composition  
- cleaner separation of concerns  

## Variants
- Transparent Decorator → preserves exact interface  
- Stateful Decorator → maintains additional state  
- Recursive/Nested Decorators → multiple layers of wrapping  

## Comparisons
- vs Adapter → changes interface vs adds behavior  
- vs Facade → simplifies interface vs enhances functionality  
- vs Strategy → changes behavior via delegation vs layering behavior  