# Python Regex, Processes, and Requests

## Processes
*refer to `randomsay.py`*

Run a program and capture output with `os.popen()`\
Run a program to stdout with `os.system()`

## Requests
*refer to `zipcodes.py`*

Use `requests.get(<url>)` to "curl" a webpage (send a HTTP GET request) 
Unpack the text response with `<response>.text`

## Regex
*refer to `zipcodes.py`*

Create a raw string using `r''` to define the regex pattern

Use `re.findall(pattern, string)` to create a list of match tuples

Use `re.sub(search, replace, string)` to act as a version of __sed__ to find and replace substrings in strings


