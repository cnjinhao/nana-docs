/**\example subclass.cpp
*/
/**\example notepad.cpp
*/
/**
\example calculator.cpp

Requires: C++11, Nana 0.5

In this tutorial, we will make a GUI calculator with Nana C++ Library. The calculator that we build will look like:

![Screenshot of Calculator](calculator.png)

Using nana::place which is introduced into Nana in the version of 0.5, we can create a such GUI easily.

Let's start the code.

*/
/**\example FreeMe.cpp
# [The FreeMe](http://nanapro.sourceforge.net/help/tutorials/thefreeme.htm)

![UI of The FreeMe](freeme.png)

The FreeMe is a sample of Nana under Windows, it cleans junk files on system partition. It cleans
- All files in Windows DLLCache directory.
- All files in Windows Prefetch dirctory.
- All files in Temporary Directory.
- All files in Internet Cache Directory.

What components make up the FreeMe:

form, picture, label, button, progressbar, file_iterator, thread and less than 400 lines source code. Click here to download the package that contains the source code and binrary.


*/

/**\example demo.cpp11.cpp
![Widgets Demo on Windows](widget_demo_win.jpg)
![Widgets Demo on Linux (Fedora17)](widget_demo_linux.jpg)
[Code](http://searchcode.com/codesearch/view/27847828)
*/

/**\example HelloWord.cpp
*/
/**\example clicked.cpp
*/
/**\example threading.cpp
*/
/**\example HelloWord-Quit.cpp
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

    using namespace nana::gui;

Specify the nominated namespace nana::gui can be used in `main` function block scope. 
In this example, these names `form`, `button`, `events`, `API` and `exec` are defined in the namespace nana::gui.
With this using-directive, we could use these names directly in the main function scope.

	form fm;

This is the first piece of window-system code. A `form` is created while the variable `fm` is defined.
The `form` is a window with title bar and a sizable border frame, it's fundamental that you can put 
some widgets above it. 

	fm.caption(STR("Hello World"));

Set the `form` to display the text "Hello World" in its title bar. 

	button btn(fm, nana::rectangle(20, 20, 150, 30));

After the `form`, comes a button we created. In its constructor arg-list, the first argument tells 
the btn who the parent window is, and the following arguments describe position and size of btn. 

	btn.caption(STR("Quit"));

Set the btn to display the text "Quit". 

	btn.make_event<events::click>(API::exit);

make_event() is a method that every Nana.GUI widgets provide, you can register an event callback 
by using it. We want to exit the program while a mouse clicks on the btn. Now, register a callback
function on `click` event. 

	form.show();

A form widget is never visible when you create it. You must call show() to make it visible. 

	nana::exec();

This is where the main() passes the control to Nana.GUI, and exec() will return when the 
application exists. In exec(), Nana.GUI processes the message loop and passes every event 
on to the appropriate widgets. 

	}

You should now save and compile the program.

Further

	STR("Hello World")

What is `STR`? `STR` is a macro that transforms a multi-byte string into wide-byte string 
if `NANA_UNICODE` is defined in *config.hpp*. With `STR` you can easier switch your program 
between multi-byte and wide-byte. 

	btn.events().click(nana::API::exit);

What is nana::API::exit? This is an API provided by Nana.GUI. Its prototype is
void exit(). If exit() is called, Nana.GUI destroy all the windows you've created and 
the exec() will return. Member make_event() has a template argument. The argument can be a
function or a functor with a  `const nana::eventinfo&` parameter or not. 


*/
/**\example various_events.Cpp11.cpp
*/
/**\example lambda_event.Cpp11.cpp
*/

/**\example file_explorer.cpp
*/ 

/**\example drag-button.cpp
*/ 

/**\example folder_tree_nana.cpp
*/ 
/**\example  folder_tree_std.cpp
*/ 
/**\example framework_design_1.cpp
*/ 
/**\example framework_design_3.cpp
*/ 
/**\example framework_design_2.cpp
*/ 
/**\example group.cpp
*/ 
/**\example 
*/ 
/**\example 
*/ 
/**\example  screen.cpp
*/ 
/**\example  
*/ 
/**\example 
*/ 
/**\example 
*/ 
/**\example 
*/ 
/**\example 
*/ 



/**\example MontiHall.cpp
*/
/**\example loader_1.cpp
*/
/**\example loader_2.cpp
*/
/**\example modal_form.cpp
*/
/**\example decore.cpp
*/
/**\example png.cpp
*/
/**\example mbox.cpp
*/
/**\example design_1.cpp
*/
/**\example design_2.cpp
*/
/**\example design_3.cpp
*/
/**\example categ.cpp
![Screenshot of categorize.](categorize.jpg)
*/
/**\example example_listbox.cpp
*/
/**\example example_menu.cpp
*/
/**\example window-dragger.cpp
This example sets `btn` and `adherent` to be triggers, and dragger will move the form and adherent when 
the user is dragging the trigger widgets.
*/
/**\example draw.cpp

Draw a 10 X 10 red rectangle at the point(5, 5).

*/
/**\example background-effects.cpp

![](effect_mode.png)
![](effects_bground_show.png)

\todo docs: add txt from [http://stdex.sourceforge.net/help/gui/background_effects.htm]
*/
/**\example animate-bmp.cpp
*/
/**\example filebox-txt.cpp
*/
/**\example stretch_image.cpp
# Nana provides the image processors:
+ Stretch algorithms:
    - __bilinear interoplation__ 	    It produces a reasonably realistic image.
    - __proximal interoplation__ 	    It(also known as nearest-neighbor interoplation) is fast, but produces a not realistic image.

+ Alpha Blend algorith:
    - __alpha_blend__    	            Blends two images with alpha channel that is given by source image.

+ Blend algorithm:
    - __blend__  	                    Blends two images.

+ Blur algorithm:
    - __blur__ 	                    Blurs an image.

+ Line algorithm:
    - bresenham_line 	                Draws a line.

Examples

This is an example which creates a form to display an image, and when the size of form is changed, it makes the image fit the form.
In addtion, the example also shows the way to switch the stretch image processing algorithm.

Result of application:
![bilinear interoplation - Stretch the image through bilinear interoplation](fit_window_bilinear_interoplation.png)

![proximal interoplation - Stretch the image through proximal interoplation](fit_window_proximal_interoplation.png)

*/
/**\example audio_player_simple.cpp
*/
/**\example audio_player.cpp
 Play an audio file asynchronously. Play the audio when a button is clicked, and it does not block the UI thread.

*/
/**\example thread-pool.cpp

The signal()/wait_for_signal() provide a method to wait for tasks to finish.

*/
/**\example drag-button.cpp
See [How to make widget movable by mouse the best way](https://nanapro.codeplex.com/discussions/444058)

and [How to get nana::paint::image from nana::paint::graphics](https://nanapro.codeplex.com/discussions/444621)

and [Is it possible to make event inside event handler?](https://nanapro.codeplex.com/discussions/444121)

and [nana::drawing and nana::API::update_window ](https://nanapro.codeplex.com/discussions/445024)

*/

/**\example a_group_impl.cpp	

![](groups.png)

*/

/**\example place_login.cpp
![](place_illustrate.png)

*/

/**\example inputbox.cpp
![]( )

*/

/**\example menu_debug.cpp
![]( )

*/

/**\example menu_popuper.cpp
![]( )

*/

/**\example windows-subclassing.cpp
![]( )

*/

/**\example widget_show.cpp
![]( )

*/

/**\example widget_show2.cpp
![]( )

*/
