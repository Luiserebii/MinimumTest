# Mint API

## Mint

#### Mint()

Construct an instance of Mint.

**Example**:

```cpp
Mint m;
```

---

#### void title(const std::string& title, (opt) int borderNum=2)

Print a title for a group of assertions (in other words, a test).

**Params**:

 - title `string` - Title to print
 - (optional) borderNum `int` - Number to indent title with. Default: 2

**Example**:

```cpp
m.title("Integers");
```

---

#### void assert(bool b, const std::string& title, const std::string& fail)

Test to see if an expression is true. If the test fails, the `fail` string will be printed.

**Params**:

 - b `bool` - Expression to test
 - title `string` - Title string for the assertion test
 - fail `string` - Fail string for the assertion test

**Example**:

```cpp
m.assert(1 < 2, "Larger integers are larger", "Larger integer not larger");
```

---

#### void equal(const T val, const T exp, const std::string& title)

Test to see if a value `val` is equal to `exp`. If the test fails, the `fail` string will be printed.

**Params**:

 - val `T` - Value to test against second expected value
 - exp `T` - Expected value
 - title `string` - Title string for the equality test

**Example**:

```cpp
m.equal(1, 1, "Equal integers are equal");
```
---

#### void throws(void f(), const std::string& title, const std::string& fail)

Test to see if a function `f` throws an exception. If the test fails (and the function does not throw an exception), the `fail` string will be printed.

**Params**:

 - f `void ()` - Function to run
 - title `string` - Title string for the throws test
 - fail `fail` - Fail string for the throws test

**Example**:

```cpp
#include <stdexcept>
void willThrow();

void willThrow() {
    throw std::domain_error("Error");
}

m.throws(willThrow, "willThrow() throws error", "willThrow() failed to throw error")
```

---

#### int end()

Return an exit code representing the success of the test. Necessary for using on CI/CD Integration tools like TravisCI, as they listen for this code.

**Returns**: Exit code `int`

**Example**:

```cpp
int main() {
   //...
   return m.end();
}
```

---

Note: All `string` refers to the `std::string` found in the `<string>` header of the standard library. 
