/**
\class nana::label
\brief Define a label widget (can dispaly a formated text string and images). Provides the interfaces to be operational.


[A New Label](https://sourceforge.net/p/nanapro/blog/2013/12/whats-new-in-06/)

Notes
1. It is not efficient when the background mode of the label is transparent.
2. If the caption of a label contains a character '\\n', the label will hide the character and display the text string after '\\n' in a new line.
3. The format mode accepts the definition for displaying mutile-style text. For example.

			label.format(true);
			label.caption(STR("Hello, <bold=true>This is a bold text</>"));

	![](label_bold.png)

			label.caption(STR("Hello, <bold=true, color=0xff0000>This is a bold red text</>"));

	![](label_bold_red.png)

			label.caption(STR("Hello, <bold=true, color=0xff0000, font=\"Consolas\">This is a bold red Consolas text</>"));

	![](label_bold_red_consolas.png)

			label.caption(STR("Hello, <bold=true, color=0xff0000, font=\"Consolas\", url=\"http://stdex.sourceforge.net\">This is a bold red Consolas text</>"));

	The arrow mouse cursor becomes a hand when the cursor moves over the red text. Meanwhile, it is open a web browser to open the URL by clicking the red text.
	__NOTE: the url only works under Windows__

		using namespace nana::gui;

		;//void listener(label::command cmd, const nana::string& s) //C++11
		void listener(label::command::t cmd, const nana::string& s)
		{
			if(label::command::click == cmd)
			{
				msgbox mb(STR("target clicked"));
				mb << STR("the target \"") << s << "\" is clicked";
				mb();
			}
		}

		int main()
		{
			form fm;
			label lab(fm, nana::rectangle(0, 0, 100, 40));
			lab.format(true);
			lab.add_format_listener(listener);
			lab.caption(STR("Click <color=0xFF, target=\"target id\">here</>"));
			fm.show();
			exec();
		}

4. Some reserved words: *red, green, blue, white, black*. It can simplify the format text and increas it readable.

		lab.caption(STR("Click <color=0xFF target=\"target id\">here</>"));

	vs

		lab.caption(STR("Click <blue target=\"target id\">here</>"));

5. Image is supported for format mode.

		lab.caption(STR("<image=\"file.bmp\"><bold red size=20>Nana C++ Library</>"));

	As you see, the image tag has not a close-tag </>.

	Defaultly, the image is displayed with its orignal size. With specifying a size, we can get a proper size by which the image is displayed.

		label.caption(STR("<image=\"file.bmp\" size=(150,150)><bold red size=20>Nana C++ Library</>"));

	![Specifying a proper size](label_image.png)

	`size=(150,150)` means that it stretchs the image to the specified size.
	In many situations, we want to display the image as it is if it is greater than/less than a specified size. There are two reserved words can achieve it.

	`max_limited`: stretchs the image to the specified size preserving the aspect ratio when one of its edge is beyonds the specified size.

	`min_limited`: stretchs the image to the specified size preserving the aspect ratio when one of its edge is less than the specified size.

		label.caption(STR("<image=\"file.bmp\" size=(150,150) max_limited><bold red size=20>Nana C++ Library</>"));

	![A Proper Size](label_image_maxlimited.png) Specifying a proper size

6. Alignments for format mode.

	Defaulty, the alignment is baseline-aligned. The library provides 4 kinds of alignment which are: *top*, *center*, *bottom* and *baseline*. 
	They are useful tools when display texts with different size in a line.

		label.caption(STR("<size=12 top>top</><size=14 center>center<size=16 bottom>bottom</><size=30>baseline</><size=10>small font by baseline</>"));

	![Label Alignment](label_alignment.png) 
	
\example label_listener.cpp


*/