# Nana C++ library.                

[TOC]

\section WhatIs  What is Nana C++ Library? 

The Nana project is aimed at providing a software framework for cross-platform GUI programming in standard and modern C++, with components, such as graphics user interface and threads, written with Object Oriented and Generic programming.  
Being written in Standard C++ means that Nana works great with modern C++ features, such as lambdas, concurrency, the STL and so on. It will give you wonderful experiences on GUI programming with C++11.   

It also means that you will not need to use or learn any non standard extension or magic macros for obscure code generation. Only standard use of templates will make some kind of code generation. In fact no macros are used, and only a few `#define` are used **exclusively for configuration**.  

It also means that there aren't any re implementation of string or any other `std::` containers.  
Using its own widgets and drawing functions abstracted with the Nana abstract GUI system, it allows for writing portables programs on supported OS, such as Windows/Linux(X11).  

Aimed solely at GUI, Nana not pollute your executable with anything unnecessary: typical statically linked release-executables will be of few MB (1 to 3 even for non trivial application, less than 1 MB for the demos). This make Nana ideal for beginners (no need of any installation to distribute - you will not have the problem: it works only in my machine!), but also to distribute applications in many large organizations where users can run programs but not change the systems.

Nana is a free/open-source library distributed under *Boost Software License*, which is a lax, permissive non-copyleft free software license.   
Now, Nana is trying to build an active developer community to give help in using this library.

\section Install  Installation 


[Please visit the wiki](https://github.com/qPCR4vir/nana-docs/wiki/Installation)  

Is very simple. Basically you copy the source code of nana (which is tiny: 0.5 MB in zip) and tell your build system where it is. Follow the [link](https://github.com/qPCR4vir/nana-docs/wiki/Installation) for detailed information. 

When you extract the library from its zip files, you have to install the library and configurate it before using. 

\section Intro Introduction     

[(Original site)](https://sourceforge.net/p/nanapro/blog/2012/11/preliminary-study-of-nana-c-library/)

Nana is a C++ framework with provides GUI, threads and file system API. 
It provides many basic classes and functions for cross-platform programming.
Although C++ is a powerful and syntax-agile language, in fact, many programmers don't 
like to do GUI in C++, because it seems to be very difficult. Some existing C++ GUI 
frameworks define their own rule that forced you write some stiff code that always causes 
some problems, such as leaving your code in a deep inheritance hierarchy, making maintenance 
painful. Now, the Nana C++ Library is an alternative, a pure C++ library that will guide you 
in doing GUI with your immense and extensive C++ knowledge/skill/idioms. It makes a great 
progress in doing GUI in C++.

How easy is to create a Hello World program with Nana?
\include Examples\HelloWord.cpp

Pretty easy, with understandable code. Nana brings very simple and reasonable concepts 
to keep it easy. Secondly, unlike other frameworks, that make you write stiff code due 
to name and syntax constraints, Nana can make your code more straightforward and readable. 
For example, answering an event.
\include Examples\clicked.cpp

The name of `clicked` function is not constrained. You can give it any other name you want. 
It is more straightforward than implementing an event handler from inheritance. 
In some situations, we don't need to care about the parameter of `clicked()` function, 
like in the example:
\code{.cpp}
	void clicked() //NO parameter defined.
	{
 		//When the form is clicked, this function will be "called".
	}
	fm.events().click(clicked);    //Nana allows!
\endcode
Very flexible, and keep your code simple. And this feature can be applied with function object.

What makes Nana so flexible?

Nana C++ Library does not contain any "extra compilers" to parse "special syntax", 
Nana uses 100% C++ and the template techniques make this library very powerful and 
flexible. Unlike other template-based library don't causes code bloat 
and don't requires programmers to be template-skilled: it's newbie-friendly.

Nana allows you to use lambda, a feature of C++11, for event answering. Like this:
\code{.cpp}
	fm.events().click( []{	//When the form is clicked, the object  	
			           			        //created by this lambda will be "called".
 						            });
\endcode
or
\code{.cpp}
	fm.events().click( [](const arg_click& ei){ 
										//When the form is clicked, the object created
 										//by this lambda will be "called", and I can
 										//read the parameter.
 								   });
\endcode
Additionally, Nana can make use of `std::bind`.
\subsection Threading Threading 
Nana is a thread-safe library and accessing a widget between threads is normalized. 
This is a great feature that makes programmer deliver the event answer to other thread easier.
\include Examples\threading.cpp

\subsection RAII RAII  
This is an important feature. As shown in the above examples, as soon as a `form` object is created, 
its corresponding window is created, but the window is invisible till the `show()` is called 
for the `form` object. As soon as the `form` object is destructed, its corresponding window is 
closed: this conforms with the C++ object life-time concept.

\section Hello Hello World  

This lesson is indented to get you started programming with Nana.GUI. Let's read the simple HelloWorld code. 
\include Examples\helloword_quit.cpp
![Screenshot](Quit.jpg)

\dontinclude Examples\helloword_quit.cpp
Walkthrough Line-by-line

\line wvl.hpp
This line includes the Nana.GUI class definition. 

\line  button.hpp 
This line includes the Nana.GUI.button class definition. 

\skip main
\until {
The `main()` function is the entry point to the program. Almost always when using Nana.GUI, 
`main()` only needs to perform some kind of initialization before passing the control to the Nana.GUI 
library, which then tells the program about the user's actions via events.

\line  nana
Specify the nominated namespace `nana` can be used in `main` function block scope. 
In this example, the names `form`, `button`, `events`, `API` and `exec` are defined in the namespace `nana`. With this using-directive, we can use these names directly in the `main` function scope.

\line  fm 
This is the first piece of window-system code. A `form` is created while the variable `fm` is defined.
The `form` is a window with title bar and a sizeable border frame, it's fundamental that you can put 
some widgets above it. 

\line  fm.caption 
Set the `form` to display the text "Hello World" in its title bar. 

\line button 
After the `form`, a button is created. In its constructor arg-list, the first argument tells 
the `btn` who the parent window is, and the following arguments describe the position and size of `btn`. 

\line btn.caption
Set the `btn` to display the text "Quit". 

\line btn.events
`event()` is a method that every Nana.GUI widgets provide, you can register an event callback 
by using it. We want to exit the program while a mouse clicks on the btn. Now, register a callback
function on `click` event. 

\line form.show
A form widget is never visible when you create it. You must call show() to make it visible. 
\line exec
This is where the main() passes the control to Nana.GUI. exec() will return when the 
application exists. In exec(), Nana.GUI processes the message loop and passes every event 
on to the appropriate widgets. 

What is nana::API::exit? This is an API provided by Nana.GUI. Its prototype is
void exit(). If exit() is called, Nana.GUI destroy all the windows you've created and 
the exec() will return. Member `event().click()` has a template argument. The argument can be a
function or a functor with a  `const nana::arg_mouse&` parameter or not. 

Is it right to invoke exit() in an event callback? 

It is right because Nana.GUI guarantees a program correctness even when an invalid GUI objects handle is accesses .









