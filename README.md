w3utilpp
==========
Copyright (C) 2017 SiLeader. All rights reserved.  
Licensed under Mozilla Public License 2.0.
(https://opensource.org/licenses/MPL-2.0)  

## Overview
w3utilpp is WWW utility for C++.

## Features
+ Create URI
+ Simple JSON encoder

## Create URI
### How to use
```cpp
w3utilpp::uri_creator("/:a/a/:b/b", "aaa", "bbb");
```
`/:a/a/:b/b` will convert to `/aaa/a/bbb/b`.
