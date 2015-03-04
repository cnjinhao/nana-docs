/** \class nana::place
\brief Generally, an object of class place attachs to a widget, and it automatically positions and resizes widgets which are the children of the attached widget.

see http://www.nanapro.org/en-us/help/utilities/place.htm

The class place is used for layout management. 
A place divides the surface of widget into fields, and then the children widgets are inserted into a specified field for layouting. 
The field is a basic concept for place. There are 4 different types of field, each type describes how widgets are positioned. 
These types of field are:

Types     | Description
----------|----------------------------------------------------------------------
Horizontal| Widgets are positioned horizontally, such as the buttons in a toolbox.
Vertical  | Widgets are positioned vertically, such as the items in a menu.
Grid      | Widgets are positioned like a grid, such as keys on the keyboard.
Splitter  | A splitter bar is used for adjusting the size of fields on both sides of it. 

1. The definition of field manipulator:
    \code
    class field_t
    {
        public:
        virtual ~field_t() = 0;
        virtual field_t& operator<<(nana::window) = 0;
        virtual field_t& operator<<(unsigned gap) = 0;
        virtual field_t& operator<<(const implementation-specified-fixed-type&) = 0;
        virtual field_t& operator<<(const implementation-specified-percent-type&) = 0;
        virtual field_t& operator<<(const implementation-specified-room-type&) = 0;
    virtual field_t& fasten(nana::window) = 0;
    };
    \endcode

2.  The syntax of divide-text.

    The divide-text is used to divide a widget into fields to position and resize its children widgets.

    + Define a field

        <>

    + Fields can be nested.

        <<>>

    + Root field

    There is an implicit root field. All the fields defined by divide-text are children of root field.

    + Specify attributes for a field.

    __name__ : Specify an  identifier for a name of field 

    < __id_you_specified__ > :  The field is named `id_you_specified`, and we can refer to it by using: 
    `place_obj.field("id_you_specified")`.

    __vertical__ : Specify a field wich all its children fields laied out vertical. 
    If it is not specified, its children fields are laied out horizontally defaultly. For example:
    \code
    place plc(fm);

    plc.div("<abc>");
    plc.field("abc") << btn0 << btn1 << btn2 << btn3 ;
    plc.collocate();
    \endcode
    ![Place Horizontal](place_horizontal.png)

    If we replace this line:

        plc.div("<abc>");

    into

        plc.div("<vertical abc>");

    we will get

    ![Place Vertical](place_vertical.png)

    __weight__ : It stands for the width or height of a field. It depends on the type of its owner field's layout.

    Specify the weight in pixel:

        <abc><weight=200 def>

    If the width of the form is 1000px, the field `abc` is 800px and `def` is 200.

        <abc><weight=60% def><ghi>

    If the width of form is 1000px, the field `abc` is 200px, `def` is 600px and `ghi` is 200px.

    __grid [X, Y]__ : It specifies a field that lays its children widgets out as a grid.

        <grid [3, 2]>

    The field is divided a 3 X 2 grid.

        place plc(fm);
        plc.div("<grid [3, 2] abc>");
        plc.field("abc")<<btn0<<btn1<<btn2<<plc.room(btn3, 3, 1);
    ![Place Grid](place_grid.png)

    __gap__ : It specifies a gap in pixel between widgets in any field.

        <grid [3, 2] gap=5>

3. An illustration for the place.

    Let's create a user interface for login validation. The program GUI looks like:
    ![](place_illustrate.png)

    First of all, we should divide the form into fields. For this result, it may be divided like this
    ![Divided into fields](place_illustrate_divided.png)

    The divide-text of red rectangle should be:

        <><weight=80% vertical children_fields_of_red_rectangle><>

    The root field is horizontal defaultly, so these 3 fields are laied out horizontally. 
    The red rectangle in the middle takes 80% spaces, we specify its weight is 80%. 
    As you see, the children of red rectangle are laied out vertically, it should be specified by vertical.

    The divide-text of orange rectangle:

        <><weight=70% vertical children_fields_of_orange_rectangle><>

    The orange rectangle is laied out in the middle about 70% space, it also specified with vertical.

    The divide-text of green rectangle and blue rectangle:

        <vertical textboxs><weight=25 buttons>

    The widgets in green rectangle are laied out vertically, and widgets in blue rectangle are laied 
    out horizontally, so we only specify the vertical for the green rectangle. 
    And the blue rectangle manages buttons and it is horizontal, in other words, the height of 
    blue rectangle is same as buttons', so we specify its weight is 25 pixels. 
    These 2 fields we will refer to and then insert widgets into them, so a name is given for each field.

    The combination of these divide-texts:

        <><weight=80% vertical <><weight=70% vertical <vertical textboxs><weight=25 buttons>><>><>

    Let's start programming:
    \code
    #include <nana/gui/wvl.hpp>
    #include <nana/gui/place.hpp>
    #include <nana/gui/widgets/button.hpp>
    #include <nana/gui/widgets/textbox.hpp>

    int main()
    {
        using namespace nana::gui;

                 //Define widgets
        form fm;
        textbox usr(fm), pswd(fm);
        button login(fm), cancel(fm);

        usr.tip_string(STR("User:")).multi_lines(false);
        pswd.tip_string(STR("Password:")).multi_lines(false).mask('*');

        login.caption(STR("Login"));
        cancel.caption(STR("Cancel"));

                //Define a place for the form.
        place plc(fm);

                //Divide the form into fields
        plc.div("<><weight=80% vertical<><weight=70% vertical<vertical textboxs><weight=25 buttons>><>><>");

        //Insert widgets

        //The field textboxs is vertical, it automatically adjusts the widgets' top
        //and height. The usr and pswd are single-line textboxs, and we should specify
        //them with a fixed height.
        plc.field("textboxs")<<plc.fixed(usr, 25)<<10<<plc.fixed(pswd, 25);

        plc.field("buttons")<<login<<10<<cancel;

        //Finially, the widgets should be collocated.
        //Do not miss this line, otherwise the widgets are not collocated
        //until the form is resized.
        plc.collocate();

        fm.show();
        exec();
    }
    \endcode
    \example place_login.cpp
    ![](place_illustrate.png)

*/