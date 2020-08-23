# Your take-home test
## Why
We need to see your code, so we can get a better understanding of your coding skills and habits. This test is one way to get there. We are happy to discuss alternatives.

## Prerequisites
This project was built and tested on MacOS and Windows using the following configurations:
* MacOS: XCode, CMake, JetBrains CLion
* Windows: MS Visual Studio 2017 Community Edition 15.9.13, CMake.
* Windows: MS Visual Studio 2019 Community Edition 16.1.3

## What
Your input data is a JSON file that contains an array of 2-D line segments. Some of the line segments may be merged: they are parallel and share an endpoint. You need to find all mergeable lines and merge them. We have provided some code to get you started.

## How
Use this code to set up a project. Be sure to create a local Git repository so your commits are tracked. Implement, push to a private repository on GitHub, BitBucket or similar and give us access to that repository. On GitHub, our usernames are nshulga-glodon and pjnadolny.

Setup and build instructions [here](BUILD.md).

The code should compile and run under a C++14 or a C++17 compliant compiler under MacOs, Windows or Linux.

Setting up the environment should take less than an hour, depending on your current setup. We suggest time-boxing the coding part of the exercise to less than a halfday. We are not looking for a perfect implementation - limit the scope to the best of your judgment. We will, however, ask you to do further work on your code during the face-to-face interview.


## What we are looking for
This test is designed, in part, to access your fit as a team member. As a team, we place significant value on well designed, properly tested, self-documented code. You will get extra points for:
* Good engineering judgment
* Clean, maintainable code
* Thoughtful test coverage
* History of commits: we'd like to see your path to the solution.
* A half-page writeup with your thoughts on the test, suggestions and concerns.

## Other
* This project was created in JetBrains CLion under MacOS. It was verified to work in MS Visual Studio Community edition under Windows 10.
* Use of CMake is intentional - we want the test to work under MacOS, Windows and Linux. The root CMakeLists.txt is pretty self-explanatory.
* When in doubt, use your judgment. If stuck or need help, ping us.

Thank you for your time. We can't wait to see your implementation.

Good luck and have fun!

#### Acknowledgments and credits
This project uses Catch2 test framework by [Martin Hořeňovský](https://github.com/catchorg/) and RapidJSON by Tencent. All 3rd party components are property of the respective owners and are used according to their licenses.


