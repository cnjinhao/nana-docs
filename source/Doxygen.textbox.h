/** \class nana::textbox
1. The return type of the `ext_event()` coming with `textbox`, its defined as

        struct implement-specifed
        {
           nana::fn_group<void()> first_change; 
           ;//An event for the text first change after text is been opened or stored.
        };

    An instance of `first change`
    Some text editor programs, such as *vim* or *notepad++*, when the text is being modified, the caption of the
    window will display a special character (such as * ~ +) to indicate changing of text. 
    To implement this feature, you can set a function to the first change for modifying the caption of your window.
2. The tip string is displayed when textbox is empty and the tip string will be hidden after textbox gets the focus.

*/