/** \example helloworld_demo.cpp
 *  
 *  ![Screenshot of helloworld_demo](helloworld_demo.png)
 */
 

/** \example subclass.cpp
 */

/** \example notepad.cpp

  Simple Notepad
\todo Use this in documents

\dontinclude notepad.cpp

\line _m_pick_file
We start with a private member function _m_pick_file(), this function is to tell user to select a file.

\line return (fbox.show() ? fbox.file() : std::string());

If user clicks "cancel" button or closes the dialog by clicking 'X' close button, fbox.show() returns false for no file selection.

\line _m_ask_save()
This function will have asked user to save the text to a file by the time the text is closed.

\line if(textbox_.edited())
Determines whether the text has been edited. If there are modifications to the text, then it

\line auto fs = textbox_.filename();
When the textbox opens a file or saves a text to a file, the textbox will keep the filename. If fs is empty, the program asks user to select a file to save the text.

_m_ask_save() has a return type, that is bool type. And it returns false if and only if the user cancel the selection.

\line notepad_form()
In the default of constructor, we need create the menubar and textbox, and set the layout for the form.

\line textbox_.borderless(true);
API::effects_edge_nimbus(textbox_, effects::edge_nimbus::none);

Disables the border and edge numbus effect of the textbox.

\code{.cpp}
textbox_.events().mouse_dropfiles([this](const arg_drppfiles& arg)
{
    if (arg.files.size() && _m_ask_save())
        textbox_.load(arg.files.at(0).data());
});
\endcode

Sets a Drag'n Drop event for the textbox, it allows user to open a file by dragging the file outside of the program and dropping the file inside the program. 
The call of _m_ask_save() here is to try to ask user to save the edited text.

\code{.cpp}
events().unload([this](const arg_unload& arg){
    if (!_m_ask_save())
        arg.cancel = true;
});
\endcode

Sets an unload event for the form, it enables program to ask user to save the edited text when closing the program, and if user cancels the messagebox, the program stops closing.

\line _m_make_menus()
Sets menus for the menubar.

\line int main()
Creates the form of notepad.
 */


/** \example calculator.cpp

Requires: C++11, Nana 0.5

In this tutorial, we will make a GUI calculator with Nana C++ Library. The calculator that we build will look like:

![Screenshot of Calculator](calculator.png)

Using nana::place which was introduced in Nana version 0.5, we can create such a GUI easily.

Let's start the code.
*/

/** \example freeme.cpp

[The FreeMe](http://nanapro.sourceforge.net/help/tutorials/thefreeme.htm)

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

/** \example helloword.cpp
*/

/** \example clicked.cpp
*/

/** \example threading.cpp
*/

/** \example helloword_quit.cpp
![Screenshot](Quit.jpg)
*/

/** \example various_events.cpp11.cpp
*/

/** \example lambda_event.cpp11.cpp
*/

/** \example file_explorer.cpp
*/ 

/** \example drag-button.cpp
*/ 

/** \example folder_tree_nana.cpp
*/ 

/** \example  folder_tree_std.cpp
*/ 

/** \example framework_design_1.cpp
*/ 

/** \example framework_design_3.cpp
*/ 

/** \example framework_design_2.cpp
*/ 

/** \example group.cpp
*/ 

/** \example  screen.cpp
*/ 

/** \example montihall.cpp
*/

/** \example loader_1.cpp
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

/**\example listbox_inline_widget.cpp
![Inline Widget Screenshot](http://nanapro.org/wiki_img/listbox_inline_widget/screenshot.png)

*/