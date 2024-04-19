<p align="center">
  <br />
  <img src="./assets/libft.png" alt="libft" width="200" height="200">
  <br/>
  <br />
  <p align="center">
<img src="https://img.shields.io/badge/c programming-blue?logo=c"/>
</p>

<br/>

[![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/colored.png)](#table-of-contents)

<br/>

# $\color{SkyBlue}{Overview}$

In this project, you will make a bunch of functions that are useful for other projects.Of course, you can reuse this project in another project!

The point is to get used to Makefile and learn how to link a .c file to a .o and a .a file. Also this is the first project in 42 so you should learn many rules.

# $\color{SkyBlue}{Difficult \space Part}$

There are many functions and of course it is hard to write code for each correctly but there are specially difficult ones.

## $\color{white}{Memory \space Allocation}$

I needed to allocate memory for like ft_split. To do that, you should count how much memory you should allocate and you should deal with an allocation error. This means if the allocation fails, you should free memories that you have already allocated.

## $\color{white}{Linked \space List}$
In bonus part, you should deal with linked list. This using struct and pointer so it made me crazy at first. Using struct, you can put multiple variable in a variable. Also, pointer make it easy to change value in a variable.

By the way, since I started another project like [push_swap](https://github.com/honganji/42-core/tree/main/push-swap), you should realize it is so useful. So I think it worths to try bonus part!

## $\color{white}{Overflow}$

I faced overflow problem in piscine but in this project, there are many times that I need to deal with that.

For example, when you multiple some integers, it would overflow interger max size so you should check it.

## $\color{white}{Makefile}$

I learned how to create and use makefile. In a piscine, I didn't deal with makefile so it was very hard to understand the basic rules like how to put target, prerequisite, and rule. However once I get used to it, I realize that it is so useful. I could save a bunch of time and easy mistakes thanks for makefile.

# $\color{SkyBlue}{What \space I \space learned}$

At first, I learned the basis of each function in library. For example, function strlen get the length of a string. I know what this function would do but I didn't know how this function works inside the program.

Since I coded by myself, I understood each function deeply and I got be able to use function for specific situation. Also I can find an error more easily thanks for this project. I learned really basic things and something leads an error. So after I finish this project, I became able to deal with errors faster.

Also, I learned how important it is to devide down a problem into small pieces as much as possible and deal with them one by one. By doing this, it gets much easier to find an error and fix it faster. After all conbining everything and create a function. This can be said all problems you have generally.

At last, I learned it is the best thing to plan what I should do before coding. At first, I do coding and thinking at the same time so it got messed often. However, my friend told me that it is better to plan everything at first before coding. So I tried in this project and it worked so much.