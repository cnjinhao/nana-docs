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

	#include <nana/gui/wvl.hpp>
	#include <nana/gui/widgets/label.hpp>

	int main()
	{
  		using namespace nana;
  		form    fm;
  		label   lb(fm, fm.size());
 		lb.caption(STR("Hello, World"));
 		fm.show();
 		exec();
	}

Pretty easy, with understandable code. Nana brings very simple and reasonable concepts 
to keep it easy. Secondly, unlike other frameworks, that make you write stiff code due 
to name and syntax constraints, Nana can make your code more straightforward and readable. 
For example, answering an event.

	#include <nana/gui/wvl.hpp>
	#include <nana/gui/widgets/button.hpp>

	void clicked(const nana::arg_mouse&)
	{
		 //When the window  fm  is clicked, this function will be "called".
	}

	int main()
	{
 		using namespace nana;
 		form fm;
 		fm.events().click(clicked);
 		fm.show();
 		exec();
	}

The name of `clicked` function is not constrained. You can give it any other name you want. 
It is more straightforward than implementing an event handler from inheritance. 
In some situations, we don't need to care about the parameter of `clicked()` function, 
like in the example:

	void clicked() //NO parameter defined.
	{
 		//When the form is clicked, this function will be "called".
	}
	fm.events().click(clicked);    //Nana allows!

Very flexible, and keep your code simple. And this feature can be applied with function object.

What makes Nana so flexible?

Nana C++ Library does not contain any "extra compilers" to parse "special syntax", 
Nana uses 100% C++ and the template techniques make this library very powerful and 
flexible. Nana is unlike other template-based library that causes a lot of code bloat 
and requires programmers have template-skilled, it's newbie-friendly.

Nana is a complete C++ style library that compile on Visual C++ 2013/GCC 4.8 and later. 
If you are a C++ expert, Nana allows you to use lambda, a new feature of C++11, for event 
answering. Like this:

	fm.events().click( []{	//When the form is clicked, the object  	
			           			        //created by this lambda will be "called".
 						            });

or

	fm.events().click( [](const arg_mouse& ei){ 
										//When the form is clicked, the object created
 										//by this lambda will be "called", and I can
 										//read the parameter.
 								   });

Additionally, Nana would make code flexible with `std::bind` in C++11.
\subsection Threading Threading 
Nana is a thread-safe library and accessing a widget between threads is normalized. 
This is a great feature that makes programmer deliver the event answer to other thread easier.

	#include <nana/gui/wvl.hpp>
	#include <nana/threads/pool.hpp>
	void foo()
	{
	  //This function will be "called" in other thread created by thread pool.
	}
	int main()
	{
	  using namespace nana;
	  using namespace nana::threads;
 		pool thrpool;
 		form fm;
 		fm.events().click(pool_push(thrpool, foo));
 		fm.events().click(pool_push(thrpool, []{
 												  //A lambda is also allowed.
 										  }));
 		fm.show();
 		exec();
	}

\subsection RAII RAII  
This is an important feature. As shown in the above examples, as soon as a `form` object is created, 
its corresponding window is created, but the window is invisible till the `show()` is called 
for the `form` object. As soon as the `form` object is destructed, its corresponding window is 
closed: this conforms with the C++ object life-time concept.

\subsection Cross Cross-Platform Programming 
Nana C++ Library is designed to be used for cross-platform programming. 
Its first release was under Windows. Now, the library is ported to Linux(X11).

The Most Important Feature: Free

Nana C++ Library is an open-source; it's free for both commercial and non-commercial use.


\section Hello Hello World  

This lesson is indented to get you started programming with Nana.GUI. Let's read the simple HelloWorld code. 

	#include<nana/gui/wvl.hpp>
	#include <nana/gui/widgets/button.hpp>

	int main()
	 {
		 using namespace nana;

		 form fm;
		 fm.caption(STR("Hello World"));
		 button btn(fm, nana::rectangle(20, 20, 150, 30));
		 btn.caption(STR("Quit"));
		 btn.events().click(API::exit);
		 fm.show();
		 exec();
	 }

![Screenshot](Quit.jpg)

Walkthrough Line-by-line

	#include <nana/gui/wvl.hpp>

This line includes the Nana.GUI class definition. 

	#include <nana/gui/widgets/button.hpp>

This line includes the Nana.GUI.button class definition. 

	int main()
	{

The `main()` function is the entry point to the program. Almost always when using Nana.GUI, 
`main()` only needs to perform some kind of initialization before passing the control to the Nana.GUI 
library, which then tells the program about the user's actions via events.

    using namespace nana;

Specify the nominated namespace `nana` can be used in `main` function block scope. 
In this example, the names `form`, `button`, `events`, `API` and `exec` are defined in the namespace `nana`.
With this using-directive, we can use these names directly in the `main` function scope.

	form fm;

This is the first piece of window-system code. A `form` is created while the variable `fm` is defined.
The `form` is a window with title bar and a sizable border frame, it's fundamental that you can put 
some widgets above it. 

	fm.caption(STR("Hello World"));

Set the `form` to display the text "Hello World" in its title bar. 

	button btn(fm, nana::rectangle(20, 20, 150, 30));

After the `form`, a button is created. In its constructor arg-list, the first argument tells 
the `btn` who the parent window is, and the following arguments describe the position and size of `btn`. 

	btn.caption(STR("Quit"));

Set the `btn` to display the text "Quit". 

	btn.events().click(API::exit);

`event()` is a method that every Nana.GUI widgets provide, you can register an event callback 
by using it. We want to exit the program while a mouse clicks on the btn. Now, register a callback
function on `click` event. 

	form.show();

A form widget is never visible when you create it. You must call show() to make it visible. 

	::nana::exec();

This is where the main() passes the control to Nana.GUI, and exec() will return when the 
application exists. In exec(), Nana.GUI processes the message loop and passes every event 
on to the appropriate widgets. 

	}

You should now save and compile the program.

Further

	STR("Hello World")

What is `STR`? `STR` is a macro that tell your compiler a that the literal string is a  wide-byte string 
if `NANA_UNICODE` is defined in *config.hpp*, otherwise - multi-byte. With `STR` you can easier switch your program 
between multi-byte and wide-byte. 

\todo Better explain what STR() is. No run-time cost: just preprocesing, 100%. Clean and simple.

See [Use of std::string with char16_t or char32_t instead nana::string in c++11 version ](https://sourceforge.net/p/nanapro/discussion/general/thread/fc165711/)

See ...


	btn.events().click(nana::API::exit);

What is nana::API::exit? This is an API provided by Nana.GUI. Its prototype is
void exit(). If exit() is called, Nana.GUI destroy all the windows you've created and 
the exec() will return. Member event().click() has a template argument. The argument can be a
function or a functor with a  `const nana::arg_mouse&` parameter or not. 

Is it right to invoke exit() in an event callback? 

It is right because Nana.GUI guarantees a program correctnets even when an invalid GUI objects handle is accesses .









