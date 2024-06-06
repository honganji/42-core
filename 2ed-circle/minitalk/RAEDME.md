<p align="center">
  <br />
  <img src="./assets/minitalk.png" alt="minitalk" width="200" height="200">
  <br/>
  <br />
  <p align="center">
<img src="https://img.shields.io/badge/c programming-blue?logo=c"/>
</p>

<br/>

[![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/colored.png)](#table-of-contents)

<br/>

# $\color{SkyBlue}{Overview}$

In this project, you will make a mini chat program so that you can communicate
each other through CLI. You send a message from a client and catch it in server
and display.

# $\color{SkyBlue}{Point}$
There are some new things and I will explain how to deal with them.

## $\color{white}{Send \space string \space using \space signalfa}$
This means you don't know the number of parameters. For example, you sometimes
get one parameter like this.

```
ft_printf('I love %d', 42);
```

But sometimes the number of the parameters would be multiple.
```
ft_printf('My name is %s %s and the age is %d', Yuji, Toshihiro, 23);
```

## $\color{white}{Keep \space values \space using \space struct}$

Using struct, you can keep and change multiple values anywhere you want. You 
Just have to pass the pointer of the struct. In this project, I keep two data.
The count how many characters you print and if there is an error or not.

``` 
typedef struct state
{
	int				has_error;
	unsigned int	count;
}					t_state;
```

Most of the students returns -1 if there is an error but I thought it makes the
code redundant. And I learned struct and pointer in libft so I decided to use
them to track multiple values easily.

# $\color{SkyBlue}{Difficult \space Part}$

At first I thought I just have to deal with some cases for input parameters 
like %d, %i, etc... But I realized that there are something I should deal with.

## $\color{white}{Unknown \space size \space of \space parameters}$

One of the main purposes of this project is to use unknow size of parameters.
Usually, it shouldn't be fixed size. However in printf function, you should get 
multiple parameters and the number of them is unknown. To deal with this, you
need to use stdarg.h. This library enable you to handle them but it takes a bit
time to understand how the library works because every time I call 
va_arg() function, the function's target proceed to next one. So you should use
this just before you use the prameter.

## $\color{white}{Error \space handling}$
I need to handle errors especially caused by write() function. So every time you
print an character, you should check if there is error. To know it, I make a 
struct variable and check it every time I display a character. Usually people
check it without struct but returning a number but I thought it makes the code
more complicated so I decided to use a struct variable.

## $\color{white}{Makefile}$

When I finished libft project, I thought I should create subdirectory to make
a project readable. Also it's a bit complicated if I create all the object files
in top directory. So I decided to create all the object files in a subdirectory
and in that directory I also create subdirectory for .c files in a subdrectory.
It took time but I think this makes my project more readable and sophisticated.