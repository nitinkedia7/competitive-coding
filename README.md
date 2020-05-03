# Description
This repository serves as the go to backup of almost all my submissions on online judges. It also contains templates and [cookbook](https://docs.google.com/document/d/1Rq94UBJdrsCAcBLyx6EWEg_4B8dM3uUv92pvAhp7VzA/).

# How to compile
## Regular compile
`g++ -Wall -O2 -std=c++17 template.cpp`

## Debug compile
`g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector template.cpp`

# How to run
Use `./a.out < test.in |& tee test.out`

# Precompiled headers
1. Go to contest folder `cd round_base`
2. Copy stdc++.h to contest folder `cp /usr/include/x86_64-linux-gnu/c++/9/bits/stdc++.h bits/`
3. Go to bits/ `cd bits`
4. Compile the header `g++ -Wall -O2 -std=c++17 stdc++.h`

Note that the header should be compiled with the same flags as the solution. 

# Links
1. [Codeforces: С++17 64bit Support](https://codeforces.com/blog/entry/75004)
2. [Catching silly mistakes with GCC](https://codeforces.com/blog/entry/15547)
3. [Competitive C++ Manifesto: A Style Guide](https://codeforces.com/blog/entry/64218)
