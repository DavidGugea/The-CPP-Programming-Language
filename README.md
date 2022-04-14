# The C++ Programming Language by Bjarne Stroustrup

---

# Part I: Introductory Material

## 1. Notes to the Reader
## 2. A Tour of C++: The Basics
## 3. A Tour of C++: Abstraction Mechanisms
## 4. A Tour of C++: Containers and Algorithms
## 5. A Tour of C++: Concurrency and Utilities

# Part II: Basic Facilities

## 6. Types and Declarations
## 7. Pointers, Arrays, and References
## 8. Structures, Unions, and Enumerations
## 9. Statements
## 10. Expressions
## 11. Select Operations
## 12. Functions
## 13. Exception Handling
## 14. Namespaces
## 15. Source Files and Programs

# Part III: Abstraction Mechanisms

## 16. Classes
## 17. Construction, Cleanup, Copy, and Move
## 18. Operator Overloading
## 19. Special Operators
## 20. Derived Classes
## 21. Class Hierarchies
## 22. Run-Time Type Information
## 23. Templates
## 24. Generic Programming
## 25. Specialization
## 26. Instantiation
## 27. Templates and Hierarchies
## 28. Metaprogramming
## 29. A Matrix Design

# Part IV: The Standard Library

## 30. Standard Library Summary
## 31. STL Containers
## 32. STL Algorithms
## 33. STL Iterators
## 34. Memory and Resources
## 35. Utilities
## 36. Strings
## 37. Regular Expressions
## 38. I/O Streams
## 39. Locales
## 40. Numerics
## 41. Concurrency
## 42. Threads and Tasks
## 43. The C Standard Library
## 44. Compatibility

---

# Part II: Basic Facilities

---


# 6. Types and Declarations

## Character Types

There are many character sets and character set encodings in use. C++ provides a varierty of character types that reflect that - often bewildering - variety:

* **```char```:** The defualt character type, used for program text. A **```char```** is used for the implementation's character set and is usually 8 bits.
* **```signed char```:** Like **```char```**, but guaranteed to be signed, that is, capable of holding both positive and negative values.
* **```unsigned char```:** Like **```char```**, but guaranteed to be unsigned
* **```wchar_t```:** Provided to hold characters of a larger character set such as Unicode. The size of **```wchar_t```** is implementation-defined and large enough to hold the largest character set supported by the implementation's locale.
* **```char16_t```:** A type for holding 16-bit character sets, such as UTF-16
* **```char32_t```:** A type for holding 32-bit character sets, such as UTF-32.

A ```char``` variable can hold a character of the implementation's character set. For example:

```c++
char ch = 'a';
```

A ```char``` typically has 8 bits so it can hold 256 different values ( ```2^8``` ). The character set is a variant of ISO-646 ( like ASCII ).

Each character has an integer value in the character set used by the implementation. For example, the value ```'b'``` is ```98``` in the ASCII character set.

The notation ```int{c}``` gives the integer value for a character ```c``` ("the ```int``` wen can construct from ```c```"). The possibility of converting a ```char``` to an integer raises the question: is a ```char``` signed or unsigned? The 256 values represented by an 8-bit byte can be interpreted as the values ```0``` to ```255``` or as the values ```-127``` to ```127```. No, not ```-128``` to ```127``` as one might expect: The C++ standard leaves open the possiblity of one's-complement hardware and that eliminates one value; thus, a use of ```-128``` is non-portable. Unfortunately, the choice of signed or unsigned for a plain ```char``` is implementation-defined. C++ provides two types for which the answer is definite: ```signed char```, which can hold at least the values ```-127``` to ```127```, and ```unsigned char```, which can hold at least the values ```0``` to ```255```.

## Signed and Unsigned Characters

It is implementation-defined wheter a plain ```char``` is considered signed or unsigned. This opens the possiblity for some nasty surprises and implementation dependencies. For example:

```c++
char c = 255; // 255 is "all ones," hexadecimal 0xFF
int i = c;
```

What will be the value of ```i```? Unfortunately, the answer is undefined. On an implementation with 8-bit bytes, the answer depends on the meaning of the "all ones" ```char``` bit pattern when extended into an ```int```. On a machine where a ```char``` is unsigned, the answer is *255*. On a machine where a ```char``` is signed, the answer is ```-1```. In this case, the compiler might warn about the conversion of the literal ```255``` to the ```char``` value ```-1```. However, C++ does not offer a general mechanism for detecting this kind of problem. One solution is to avoid plan ```char``` and use the specific ```char``` types only. Unfortunately, some standard-library functions, such as ```strcmp()```, take plain ```char```s only.

## Character Literals

A *character literal* is a single character enclosed in single quotes, for example, ```'a'``` and ```'0'```. The type of a acharacter literal is ```char```. A character literal can be implicitly converted to its integer value in the character set of the machine on which the C++ program is to run. For example, if you are running on a machine using the ASCII character set, the value of ```'0'``` is ```48```. The use of character literals rather than decimal notation makes programs more portable.

A few characters have standard names that use the backslash, ```\```, as an escape character:

|Name|ASCII Name|C++ Name|
|----|----------|--------|
|Newline|NL(LF)|```\n```|
|Horizontal tab|HT|```\t```|
|Vertical tab|VT|```\v```|
|Backspace|BS|```\b```|
|Carriage return|CR|```\r```|
|Form feed|FF|```\f```|
|Alert|BEL|```\a```|
|Backslash|\\|```\\```|
|Question mark|?|```\?```|
|Single quote|'|```\'```|
|Double quote|"|```\"```|
|Octal number|```ooo```|```\ooo```|
|Hexadecimal number|```hhh```|```\hhh```|

## Integer types

Like ```char```, each integer type comes in three forms: "plain" ```int```, ```signed int```, and ```unsigned int```. In addition, integer come in four sizes: ```short int```, "plain" ```int```, ```long int```, and ```long long int```. A ```long int``` can be referred to as plain ```long```, and a ```long long int``` can be referred to as plain ```long long```. Similarly, ```short``` is a synonym for ```short int```, ```unsinged``` for ```unsigned int```, and ```signed``` for ```signed int```.

The ```unsigned``` integer types are ideal for uses that treat storage as a bit array. Using an ```unsigned``` instead of an ```int``` to gain one more bit to represent positive integers is almost never a good idea. Attempts to ensure that some values are positive by declaring variables ```unsigned``` will typically be defeated by the implicit conversion rules.

In addition to the standard integer types, an implementation may provide *extended integer types* (signed and unsigned). These types must behave like integers and are considered integer types when considering conversions and integer literal values, but they usually have greater range (occupy more space).