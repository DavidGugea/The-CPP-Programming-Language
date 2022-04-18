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

## Integer Literals

Integer literals come in three guises: decimal, octal and hexadecimal. Decimal literals are the most common used and look as you would expect them to:

```C++
7 1234 976 12345678901234567890
```

The compiler ought to warn about literals that are too long to represent, but an error is only guaranteed for ```{}``` initializers.

A literal starting with zero followed by ```x``` or ```X``` (```0x``` or ```0X```) is a hexadecimal ( base 16 ) number. A literal starting with zero but not followed by ```x``` or ```X``` is an octal ( base 8 ) number. For example:

|Decimal|Octal|Hexadecimal| is a hexadecimal ( base 16 ) number. A literal starting with zero but not followed by ```x``` or ```X``` is an octal ( base 8 ) number. For example:

|Decimal|Octal|Hexadecimal| is a hexadecimal ( base 16 ) number. A literal starting with zero but not followed by ```x``` or ```X``` is an octal ( base 8 ) number. For example:

|Decimal|Octal|Hexadecimal| is a hexadecimal ( base 16 ) number. A literal starting with zero but not followed by ```x``` or ```X``` is an octal ( base 8 ) number. For example:

|Decimal|Octal|Hexadecimal|
|-------|-----|-----------|
| |0|0x0|
|2|02|0x2|
|63|077|0x3f|
|83|0123|0x53|

The suffix ```U``` can be used to write explicitly ```unsigned``` literals. Similalry, the suffix ```L``` can be used to write explicitly ```long``` literals. For example, ```3``` is an ```int```, ```3U``` is an ```unsigned int``` and ```3L``` is a ```long int```.

Combinations of suffixes are allowed. For example:

```CPP
cout << 0xF0UL << '' << 0LU << "\n";
```

## Types of Integer Literals

In general, type type of an integer literal depends on its form, value and suffix:

* If it is decimal and has no suffix, it has the first of these types in which its value can be represented: ```int```, ```long int```, ```long long int```.
* If it is octal or hexadecimal and has no suffix, it has the first of these types in which its value can be represented: ```int```, ```unsigned int```, ```long int```, ```unsigned long int```, ```long long int```, ```unsigned long long int```.
* If it is suffixed by ```u``` or ```U```, its type is the first of these types in which its value can be represented: ```unsigned int```, ```unsigned long int```, ```unsigned long long int```.
* If it is decimal and suffixed by ```l``` or ```L```, its type is the first of these types in which its value can be represented: ```long int```, ```long long int```.
* If it is octal or hexadecimal and suffixed by ```l``` or ```L```, its type is the first of these types in which its value can be represneted: ```long int```, ```unsinged long int```, ```long long int```, ```unsigned long long int```.
* If it is suffixed by ```ul```, ```lu```, ```uL```, ```Ul```, ```UL``` or ```LU```, its type if the first of these types in which its value can be represented: ```unsinged long int```, ```unsigned long long int```.
* If it is decimal and suffixed by ```ll``` or ```LL```, its type is ```long long int```.
* If it is octal or hexadecimal and is suffixed by ```ll``` or ```LL```, its type is the first of these types in which its value can be represented: ```long long int```, ```unsigned long long int```.
* If it is suffixed by ```llu```, ```llU```, ```Ull```, ```LLu```, ```LLU```, ```uLL``` or ```ULL```, its type is ```unsigned long long int```.

## Prefixes and Suffixes

There is a minor zoo of suffixes indicating types of literals and also a few prefixes:

|Notation|*fix|Meaning|Example|
|--------|----|-------|-------|
|0|prefix|octal|0776|
|```0x```/```0X```|prefix|hexadecimal|```0xff```|
|```u```/```U```|suffix|```unsigned```|```10U```|
|```l```/```L```|suffix|```long```|```20000L```|
|```ll```/```LL```|suffix|```long long```|```20000LL```|
|```f```/```F```|suffix|```float```|```10.3f```|
|```e```/```E```|infix|```floating-point```|```10e-4```|
|```.```|infix|```floating-point```|```12.3```|
|```'```|prefix|```char```|```'c'```|
|```u'```|prefix|```char16_t```|```u'c'```|
|```U'```|prefix|```char32_t```|```U'c'```|
|```L'```|prefix|```wchar_t```|```L'c'```|
|```"```|prefix|```string```|```"mess"```|
|```R"```|prefix|raw string|```R"(\b)"```|
|```u8"```/```u8R"```|prefix|UTF-8 string|```u8"foo"```|
|```u"```/```uR"```|prefix|UTF-16 string|```u"foo"```|
|```U"```/```UR"```|prefix|UTF-32 string|```U"foo"```|
|```L"```/```LR"```|prefix|```wchar_t``` string|```L"foo"```|

## ```void```

The type ```void``` is syntactically a fundamental type. It can, however, be used ony as part of a more complicated type; there are no objects of type ```void```. It is used either to specify that a funciton does not return a value or as the base type for pointers to objects of unknown type. For example:

```CPP
void x; // error: these aer no void objects
void& r; // error: there are no references to void
void f(); // function f does not return a value
void* pv; // pointer to object of unknown type
```

## The Structure of Declarations
However, without too many radical simplifications, we can consider a declaration as having five parts ( in order ):

* Optional prefix specifiers ( e.g, ```static``` or ```virtual``` )
* A base type ( e.g, ```vector<double>``` or ```const int``` )
* A declarator optionally including a name (e.g, ```p[7]```, ```n``` or ```*(*)[]``` )
* Optional suffix function specifiers ( e.g, ```const``` or ```noexcept``` )
* An optional initializer or function body ( e.g, ```={7,5,3}``` or ```{return x;}```)

A declarator is composed of a name and optionally some declarator operators. The most common declarator operators are:

| |Declarator Operators| |
|-|--------------------|-|
|prefix|```*```|pointer|
|prefix|```*const```|constant pointer|
|prefix|```*volatile```|volatile pointer|
|prefix|```&```|lvalue reference|
|prefix|```&&```|rvalue reference|
|prefix|```auto```|function ( using suffix return type ) | 
|prefix|```[]```|array|
|prefix|```()```|function|
|prefix|```->```|returns from function|

## Declaring Multiple Names

It is possible to declare several names in a single declaration. The declaration simply contains a list of comma-separated declarators. For example, we can declarte two integers like this:

```C++
int x, y; // int x; intnt y;
```

Operators apply to individual names only - and not to any subsequent names in the same declaration. For example:

```C++
int* p,y ; // int*p; int y NOT int*y;
int x, *q; // intx; int*q;
int v[10], *pv; // int v[10]; int* pv;
```

## Scope

A declaration introduces a name into a scope; that is a name can be used only in a specific part of the program text.

* ***Local scope***: A name declareted in a function or lambda is called a *local name*. Its scope extends from its point of declaration to the end of the block in which tis declaration occurs. A *block* is a seciton of code delimited by a ```{}``` pair. Function and lambda parameter names are considered local names in a outermost block of their funciton or lambda.
* ***Clas scope***: A name is called a *member* name if it is defined in a class outside any function, lambda, class, or enum class. Its scope extends from the opening ```{``` of the class declaration to the end of the class declaration.
* ***Namespace scope***: A name is called a *namespace member name* if it is defined in a namespace outside any function, lambda, class or enum class. Its scope extends from the point of declaration to the end of its namespace. A namespace name may also be accessible from other translation units.
* ***Global scope***: A name is called a *global name* if it is defined outside any function, class, enum calss or namespace. The scope of a global name extends from the point of declaration to the end of the file in which its declaration occurs. A global name may alos be accessible from other translation units. Technically, the global namespace is considered a namespace, so a global name is an example of a namesapce member name.
* ***Statement scope***: A name is in a statement scope if it is defined within the ```()``` part of a ```for-```, ```while-```, ```if-``` or ```switch-``` statement. Its scope extends from its point of declaration to the end of its statement. All names in statement scope are local names.
* ***Function scope***: A lable is in scope throughout the body of its function.

***A declaration of a name in a block can hide a declaration in an enclosing block or a global name.*** That is, a name can be ***redefined to refer to a different entity within a block***. After exit from the block, the names resumes its previous meaning. For example:

```C++
int x; // global x

void f(){
    int x; // local x hides global x
    x = 1; // assign to local x
    {
        int x; // hides first local x
        x = 2; // assign to second local x
    }

    x = 3; // assign to first local x
}

int* p = &x; // take address of global x
```

Hiding name is unavoidable, when writing large programs. However, a huma reader can easily fail to notice that a name has been hidden ( alsk known as *shadowed* ). Because such errors are relatively rare, they can be very difficult to find. Consequently, **name hiding should be minimized**.

A hidden global name ca be referred to using ***the scope resolution operator, ```::```***. For example:

```C++
int x;

void f(){
    int x = 1; // hide global x
    ::x = 2; // assign to global x
    x = 2; // assign to local x
    //...
}
```

## Initialization

If an initializer is specified for an object, that initializer determines the initial value of an object. An initializer can use one of four syntactic styles:

```C++
X a1{v};
X a2 = {v};
X a3 = v;
X a4(v);
```

Of these, **only the first can be used every context**, and I strongly recommend its use. It is clearer and less error-prone that the alternatives.

However, ahything much more complicated than that is better done using ```{}```. Initializaiton using ```{}```, *list initialization*, does not allow narrowing. That is:

* An integer cannot be converted to another integer that cannot hold its value. For example, ```char``` to ```int``` is allowed but not ```int``` to ```char```.
* A floating-point value cannot be converted to another floating-point type that cannot hold its value. For example, ```float``` to ```double``` is allowed, but not ```double``` to ```float```.
* A floating-point vavlue cannot be converted to an integer type.
* An integer value cannot be converted to a floating-point type.

There is no advantage to using ```{}``` initialization, and one trap, when using ```auto``` to get the type determined by the initializer. The trap is that if the initializer is a ```{}```-list,w e may not want its type deduced. For example:

```C++
auto z1 {99}; // z1 is an initializer_list<int>
auto z2 = 99; // z2 is an int
```

So, prefer ```{}``` initialization over alternatives unless you have a strong reason not to.
The empty initializer list, ```{}```, is used to indicate that a default value is desired. For example:

```C++
int x4 {}; // x4 becomes 0
double d4 {}; // d4 becomes 0.0
char* p{}; // p becomes nullptr
vector<int> v4{}; // v4 becomes the empty vector
string s4{}; // s4 becomes ""
```

## Dedeucing a Type: ```auto``` and ```decltype()```

The language provides two mechanisms for deducing a type from an expression:

* ```auto``` for deducing a type of an object from its initializer; the type can be the type of a variable, a ```const```, or a ```constexpr```.
* ```decltype(expr)``` for deducing the type of something that is not a simple initializer, such as the return type for a function or the type of a class member</int>

The deduction done here is very simple: ```auto``` and ```decltype()``` simply report the type of an expression already known to the compiler.

### The ```auto``` Type Specifier

When a declaration of a variable has an initializer, we don't need to explicitly specify a type. Instead, we can let the variable have the type of its initializer. Consider:

```C++
int a1 = 123;
char a2 = 123;
auto a3 = 123; // the type of a3 is "int"
```

The type of the inger literal ```123``` is ```int```, so ```a3``` is an ```int```. That is ,```auto``` is a placeholder for the type of the initializer. Using ```auto``` instead of ```int``` for an expression as simple as ```123``` doesn't help much. The harder the type is to write and the harder the type is to know, the more useful ```auto``` becomes.

If a scope is large, mentioning a type explicitly can help localize errors. That is, compared to using a specific type, using ```auto``` can delay the deteciton of type errors. For example:

```C++
void f(complex<double> d)
{
    //...
    auto max = d + 7; // fine: max is a complex<double>
    double min = d - 9; // error: we assumed that d was a scalar
    //...
}
```

If ```auto``` causes surprises, the best cure is typically to make functions smaller, which most often is a good idea anyway.

We can decorate a deduce type with specifiers and modifiers, such as ```const``` and ```&```. For example:

```C++
void f(vector<int>& v)
{
    for(const auto& x : v){ // x is a const int&
        // ...
    }
}
```

### ```auto``` and ```{}```-lists

When we explicitly mention the type of an boject we are initializing, we have two types to consider: the type of the object and the type of the initializer> For example:

```C++
char v1 = 12345; // 12345 is an int
int v2 = 'c'; // 'c' is a char
T v3 = f();
```

By using the ```{}```-initializer syntax for such definitions, we minimize the chances for unfortunate conversions:

```C++
char v1 {12345}; // error: narrowing
int v2 = {'c'}; // fine: implicit char -> int conversion
T v3 {f()}; // works if an only if the type of () can be implicitly converted to a T
```

When we use ```auto```, there is only on tyep involved, the type of the initializer, and we can safely use the ```=``` syntax:

```C++
auto v1 = 123456; // v1 is an int
auto v2 = 'c'; // v2 is a char
auto v3 = f(); // v3 is of some appropriate type
```

In fact, it can be an advantage to use the ```=``` syntax with ```auto```, because the ```{}```-list syntax might surprise someone:

```C++
auto v1 {12345}; // v1 is a list of int
auto v2 {'c'}; // v2 is a list of char
auto v3 {f()}; // v3 is alist of some appropriate type
```

### The ```decltype()``` Specifier

We can use ```auto``` whne we have a suitable initializer. But sometimes, we want to have a type deduced without defining an initialized variable. Then, we can use a declaration type specifier: ```decltype(expr)``` is the declared type of ```expr```. This is mostly useful in generic programming

## Objects and Values

We can allocate and use objects that do not have names ( e.g, created using ```new``` ) and it is possible to assign to strange-looking expressions ( e.g, ```*p[a+10]=7``` ). Consequently, we need a name for "something in memory". This is the simplest and most fundamental notion of an object. That is, an *object* is a contiguous region of storage; an *lvalue* is an expression that refers to an object. The word "lvalue" was originally coined to mean "something that ca be on the left-hand side of an assignment". However, not every lvalue may be used on the left-hand side of an assignment; an lvalue can refer to a constant. An lvalue that has not been declared ```const``` is often called a *modifiable lvalue*. The simple and low-level notion of an object should not be confused iwth the notions of class object and object of polymorphic type.

### Lvalues and Rvalues

To complement the notion of an lvalue, we have the notion of an *rvalue*. Roughly, rvalue means "a value that is not an lvalue", suhc as a temporary value ( e.g., the value returned by a function ).

If you need to be more technical, you need a more refined view of lvalue and rvalue. There are two properties tthat matter for an object when it comes to addressing, copying and moving:

* *Has identity:* The program has the name of, pointer to, or reference to the object so that it is possible to determine if two objects are teh same, wheter the value of the object has changed, etc.
* *Is movable:* The object may be moved from (i.e, we can move its value to antoher location and leave the object in a valid but unspecified state, rather than copy )

For practical programming, thinking in terms of rvalue and lvalue is usually sufficient. note that every expression is either an lvalue or an rvalue, but not both.

## Lifetimes of Objects

The *lifetime* of an object starts when its constructor completes and ends when its destructor stars executing. Objects of types without a declared constructor, such as an ```int```, can be considered to have default constructors and desctructors that do nothing.

We can classify objects based on their lifetimes:

* ***Automatic:*** Unless the programmer specifies otherwise, an object declared in a function is created when its definitions is encountered and destroyed when its name goes out of scope. Such objects are sometimes called *automatic* objects. In a typical implementation, automatico bjects are allocated on the stack; each call of the function gets its own stack frame to hold its automatic objects.
* ***Static:*** Objects declared in glboal or namespace scope and ```static```s declared in functions or classes are created an initialized once ( only ) and "live" until the program terminates. Such objects are called *static* objects. A static object has the same address throughout the life os a program execution. Static objects can cause serious problems in a multi-threaded program becuase they are shared among all threads and typically require locking to avoid data races.
* ***Free store:*** Using the ```new``` and ```delete``` operators, we can create objevcts whose lifetimes are controlled directly.
* ***Temporary objects:*** (e.g., intermediate results in a computation or an boject used to hold a value for a reference to ```const``` argument): their lifetime is determined by their use. If they are bound to a reference, their lifetime is that of the reference; otherwise, they "live" until the end of the full expression of which tye are part. A *full expression* is an expression that is not part of another epxression. Typically, temporary objects are automatic.
* ***Thread-local*** objects that is, objects declared ```thread_local```: such objects are created when their thread is and destroyed when their thread is.

*Static* and *automatic* are traditionally referred to as *storage classes*.
Array elements are nonstatic class members have their lifetimes determined by the objects of which they are part.

## Type Aliases

Somestimes, we need a new name for a type. Possible reasons include:

* The original name is too long, complicated, or ugly.
* A programming technique requires different types to have the same name in a context.
* A specific type is mentioned in one place only to simplify maintenance.

For example:

```C++
using Pchar = char*; // pointer to character
using PF = int(*)(double); // pointer to function taking a double and returning an int
```

An older syntax using the keyword ```typedef``` and placing the name being declared where it would have been in a declaration of a variable can equivalently be used in many contexts. For example:

```C++
typedef int int32_t; // equivalent to "using int32_t = int;"
typedef short int16_t: // equivalent to "using int16_t = short;"
typedef void(*PtoF)(int); // equivalent to "using PtoF = void(*)(int);"
```

## Advice

1. For the final word of language definition issues, see the ISO C++ standard.
2. Avoid unspecifided and undefined behavior.
3. Isolate code that must depend on implenetation-defined behavior.
4. Avoid unnecessary assumptions about the numeric value of characters.
5. Remember that an integer starting with a ```0``` is octal.
6. Avoid "magic constants".
7. Avoid unnecessary assumptions about the size of integers.
8. Avoid unnecessary assumptions about the range and precision of floating-point types.
9. Prefer plain ```char``` over ```signed char``` and ```unsigned char```.
10. Beware of conversion between signed and unsigned type
11. Declare one name ( only ) per declaration.
12. Keep common and local names short, and keep uncommon and nonlocal names longer.
13. Avoid similar-looking names.
14. Name an object to reflect its meaning rather than its type.
15. Maintain a consistent naming style.
16. Avoid ```ALL_CAPS```` names.
17. Keep scopes small.
18. Don't use the same name in both a scope and an enclosing scope.
19. Prefer the ```{}```-initializer syntax for declarations with a named type.
20. Prefer the ```=``` syntax for the initialization in declarations using ```auto```
21. Avoid uninitialized variables.
22. Use an alias to define a meaningful name for a built-in type in cases in which the built-in type used to represent a value might change.
23. Use an alis to define synonyms fo rtypes; use enumerations and classes to define new types.