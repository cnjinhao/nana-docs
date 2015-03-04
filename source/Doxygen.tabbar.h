/** \class nana::tabbar
1. The `button_container` is a member template of `tabbar`. It is used to identify a button in the tabbar. 
The buttons of toolbox are: *scrolling button*, *list button* and *close button*.
Only *scrolling button* is enabled by default. Enable the other buttons by employing the `tabbar::toolbox` member function. An example:

    typedef tabbar<int> tabbar_t;
    tabbar_object.toolbox(tabbar_t::button_container<tabbar_t::button_list, tabbar_t::button_close>(), true);

   Sets the list button and close button to be enabled.
   ![tabbar](tabbar.png)
2. The tabbar provides an `event_trigger` class for abstract event, such as selecting an item or closing an item.

         template<typename Tabbar>
        struct ext_event_type
        {
            typedef Tabbar tabbar;
            typedef typename tabbar::value_type value_type;
            nana::functor_group<void(tabbar&, value_type&)> add_tab;
            nana::functor_group<void(tabbar&, value_type&)> active;
            nana::functor_group<bool(tabbar&, value_type&)> remove;
        };

    + `add_tab()` is invoked when a new item is being created. 
    + `active()` method is invoked when selects an item. 
    + `remove()` method is invoked when closes an item and to stop closing the item by returning false.

*/