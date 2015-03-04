/**\class nana::combox
\brief This widget is a combo box which consists of a list box combined with a textbox. The list box should drop down when the user selects the drop-down arrow next to the control.

![](combox.png)

## Notes
1. The class ext_event coming with the combox, is:

		struct ext_event_type
		{
		  nana::functor_group<void(nana::combox&)> selected; //Selects a new item.
		};

	This class provides a method to implement that a program may respond to the combox 
	special event or state. It seems like the events registered by make_event member function.
	But the answer registered by make_event is used for general-purpose, such as mouse_down, 
	mouse_move, click and so on, while the combox´ ext_event_type is used for the own 
	providing event.

2. Refer to nana::listbox for details of item_renderer.


\example example_combox.cpp
![](combox.png)

*/