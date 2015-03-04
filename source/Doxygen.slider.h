/** \class nana::slider
1. Definition of renderer.

        class renderer
        {
         public:
            typedef nana::paint::graphics & graph_reference;
            struct bar_t
            {
                bool horizontal;
                nana::rectangle r;    //the rectangle of bar
                unsigned border_size; //border size of bar
            };
            struct slider_t
            {
                bool horizontal;
                int pos;
                unsigned border;
                unsigned scale;
            };
            struct adorn_t
            {
                bool horizontal;
                nana::point bound;
                int fixedpos;
                unsigned block;
                unsigned vcur_scale; //pixels of vcur scale.
            };
            virtual ~renderer() = 0;
            virtual void background(nana::window, graph_reference, bool isglass) = 0;
            virtual void adorn(nana::window, graph_reference, const adorn_t&) = 0;
            virtual void adorn_textbox(nana::window, graph_reference, 
                                       const nana::string&, const nana::rectangle&) = 0;
            virtual void bar(nana::window, graph_reference, const bar_t&) = 0;
            virtual void slider(nana::window, graph_reference, const slider_t&) = 0;
        };

2. Definition of provider, it provides a string that used to display a tip label when user move the mouse in a slider.

        class provider
        {
            public:
            virtual ~provider() = 0;
            virtual nana::string adorn_trace(unsigned vmax, unsigned vadorn) const = 0;
        };

3. Refer to [this article](http://nanaproject.wordpress.com/2011/03/20/clone_method/) for understanding how to write a user-defined renderer.

*/
