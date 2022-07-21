# CPP_modules

## Module 00

Module 00 is all about getting acquainted with CPP basics: Namespaces, classes, member functions, stdio
streams, initialization lists, static, const, and so on.

<details><summary>:loudspeaker: Ex00 - Megaphone 	:mega:  </summary>
<p>

A really straightforward exercice to practice with the iostream library and std::cout.

</p>
</details>

<details><summary>:bookmark_tabs: Ex01 - Phonebook :phone:  </summary>
<p>

Some issues I got and ressources which helped me solve them:

### Not being able to retrieve multiples words from stdin

Example:
```cpp
std::string input;
std::cin >> input;

// If the input typed by the user is "Hello World", input will be equal to "Hello" and not "Hello World".
```
Discovering getline for strings

// WIP : to write about later:
<Using std::getline() twice>
<std::string compare but actually str == "" is the same>


<cin.fail>

<cin.eof>

<iomanip => setw, right>
<But found setfill but no really what i wanted => made my own trunc function with resizing and appending to the subject's needs>

infinite loop with cin.fail when multiples letters => 

```cpp
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
```

</p>
</details>


## Module 01

## Module 02

## Module 03

## Module 04

## Module 05

## Module 06

## Module 07

