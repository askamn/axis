# Contributing to axys


## For general questions


You can ask general questions by using:

-   Forum (preferred way): https://github.com/axys1/axys/discussions

## Reporting bugs

To report bugs, please use the [Issue Tracker](https://github.com/axys1/axys/issues)

Steps to report a bug:
* Open the [url](https://github.com/axys1/axys/issues/new)
* Add all the needed information to reproduce the bug, the information include
    * engine version
    * steps to reproduce the bug
    * some pseudocode
    * resources link if needed


## Submitting patches

If you want to contribute code, please follow these steps:

(If you are new to git and/or GitHub, you should read [Pro Git](http://progit.org/book/) , especially the section on [Contributing to a project:Small/Large Public Project](http://progit.org/book/ch5-2.html#public_small_project) )

-   Download the latest axys develop branch from github:

```
$ git clone git://github.com/axys1/axys.git
$ cd axys
$ git checkout dev
```

-   Apply your changes in the recently downloaded repository
-   Commit your changes in your own repository
-   Create a new branch with your patch: `$ git checkout -b my_fix_branch`
-   Push your new branch to your public repository
-   Send a “pull request” to user “axys”
-   It must be _complete_. See the definition below
-   It must follow the _Releases_ rules. See the definition below

## Only _complete_ patches will be merged

The patch must be _complete_. And by that, we mean:

-   For C++ code follow the [axys C++ Coding Style][1]
-   For Python code follow the [PEP8 guidelines][3]
-   Describe what the patch does
-   Include test cases if applicable
-   Include unit tests if applicable
-   Must be tested in all supported platforms [*]
-   Must NOT degrade the performance
-   Must NOT break existing tests cases
-   Must NOT break the Continuous Integration build
-   Must NOT break backward compatibility
-   Must compile WITHOUT warnings
-   New APIs MUST be **easy to use**, **familiar** to cocos2d-x users
-   Code MUST be **easy to extend** and **maintain**
-   Must have documentation: C++ APIs must use Doxygen strings, tools must have a README.md file that describe how to use the tool
-   Must be efficient (fast / low memory needs)
-   It must not duplicate existing code, unless the new code deprecates the old one
-   Patches that refactor key components will only be merged in the next major versions.

[*]: If you don't have access to test your code in all the supported platforms, let us know.

__TBD__: Is this applicable for big features ? What is the best way to merge big features ?
