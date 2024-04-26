<p align="center">
  <br />
  <img src="./assets/gnl.png" alt="libft" width="200" height="200">
  <br/>
  <br />
  <p align="center">
<img src="https://img.shields.io/badge/c programming-blue?logo=c"/>
</p>

<br/>

[![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/colored.png)](#table-of-contents)

<br/>

# $\color{SkyBlue}{Overview}$

In this project, you will make a function that get a line. Next time you call
this function, you will get the next line. This function is really useful
actually because when you want to read a content of a file, you can get the
content so easily using this function.

# $\color{SkyBlue}{Point}$
There are some new things and I will explain how to deal with them.

## $\color{white}{Keep \space a \space value \space for \space next \space call}$
Usually, a value cannot be saved after you run the function. However, when you
declare a value using 'static', you can keep the value for next call. In this
function, you will read a file. At that time, you need to define how many
characters you will read. So if you read a string including next line content,
you need to keep it for next call.

To make it enable, you should declare a variable as a static one like this.

```
static buffer[BUFFER_SIZE];
```

## $\color{white}{memory \space leaks}$

In this project, you need to deal with many memory leaks problems. To do this,
You should be able to use a tool to detect memory leaks. I used
[valgrind](https://valgrind.org/docs/manual/quick-start.html). Also you can use
system function. As a parameter, you should write like this. The 'EXECUTABLE'
should be replaced with your executable name.

``` 
system(leaks <EXECUTABLE>);
```

After running the executable, you will see if there is memory leak.

# $\color{SkyBlue}{Difficult \space Part}$

I just thought I need to read lines one by one. But it was not that simple.

## $\color{white}{Store \space redundant \space characters}$

As I mentioned first, you need to store redundant characters when you try to
read a line. To do it correctly you need to detect newline and put it a value
to be stored. It seems so simple but it was not actually. This is because I need
to think about memory leak and edge cases.

## $\color{white}{Memory \space management}$
I need to handle errors especially caused by write() function. So every time you
print an character, you should check if there is error. To know it, I make a 
struct variable and check it every time I display a character. Usually people
check it without struct but returning a number but I thought it makes the code
more complicated so I decided to use a struct variable.
