# Mint API

## Mint

#### Mint()

Construct an instance of Mint.

---

#### void title(const std::string& title, (opt) int borderNum=2)

**Params**:

 - title `string` - Title to print
 - (optional) borderNum `int` - Number to indent title with. Default: 2

---

#### void assert(bool b, const std::string& title, const std::string& fail)

**Params**:

 - b `bool` - Expression to test
 - title `string` - Title string for the assertion test
 - fail `string` - Fail string for the assertion test

---

#### void equal(const T val, const T exp, const std::string& title)

**Params**:

 - val `T` - Value to test against second expected value
 - exp `T` - Expected value
 - title `string` - Title string for the equality test

---

#### void throws(void f(), const std::string& title, const std::string& fail)

**Params**:

 - f `void ()` - Function to run
 - title `string` - Title string for the throws test
 - fail `fail` - Fail string for the throws test

---

#### int end()

**Returns**: Exit code `int`

---

Note: All `string` refers to the `std::string` found in the `<string>` header of the standard library. 
