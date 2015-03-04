/*!   \class nana::button

Notes

1. The background image of button horizontally split into 5 parts and each part indicates one state. 
If the background of button is some area in the image, the area can be specified by using image_valid_area(). 
![Background image of button horizontally split into 5 parts](background_button.jpg)
For example. There is an image of size 520 * 70 pixels, and a button background image is just 470 * 23 pixels at position (0, 0).

		int main()
		{
		  nana::form form;
		  nana::button btn(form, 5, 5, 94, 23);
		  btn.image(STR("button_image.bmp"));
		  btn.image_valid_area(nana::arrange::horizontal, nana::rectangle(0, 0, 94 * 5, 23));
		  form.show();
		  nana::exec();
		}

The button splits the area of image into 5 parts for each state. The order of parts are 
same with the order of definition of elements of enum in type button::state.
![](btn_over.jpg)
2. An image state can be disabled by calling image_enable() method. If a state is disabled, the button would averagely 
split the area of image into parts for each enabled state.

\example example.button.cpp
![](btn_over.jpg)
\todo provide button_image.bmp


*/