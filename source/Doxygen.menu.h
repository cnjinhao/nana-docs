/**
\class nana::menu
\brief  a list of items that specify options or group of options for an application.

1. The widget sets the shortkey that is a character behind the first of &-character in text for the item. e.g. "File(&F)" or "&File".
2. The type item_proxy is used for callbacking. A programmer should not take care about the object item_proxy. It is created and destroyed by menu. The definition is

		class item_proxy: nana::noncopyable
		{
		  public:
			implementation-specified constructor
			void enabled(bool); 			//Sets the enable state of the item.
			bool enabled() const; 		//Gets the enable state of the item.
			std::size_t index() const; 	//Gets the index of the item.
		  
		  private:			//Private data members...
		};

3. There is a helper for automatically popping a menu.

		class menu_popuper
		{
		  public:
					;//C++03
			menu_popuper(menu&, mouse::t = mouse::right_button);
			menu_popuper(menu&, window owner, const point& pos, 
			mouse::t =  mouse::right_button	);

					;//C++11
			menu_popuper(menu&, mouse = mouse::right_button);
			menu_popuper(menu&, window owner, const point& pos, mouse = mouse::right_button);

			void operator()(const eventinfo&);
		
		private: 			//Implemented-Specified private members
		
		};

	Now let's use it. There is a button, it popups the menu when it is clicked.

		#include <nana/gui/wvl.hpp>
		#include <nana/gui/widgets/button.hpp>
		#include <nana/gui/widgets/menu.hpp>

		void on_menu_item(nana::menu::item_proxy& ip)
		{
			 std::size_t index = ip.index(); //Get the index of the clicking item.
		}

		int main()
		{
			using namespace nana::gui;
			form fm;

			;//We need a menu object
			menu mobj;
			mobj.append ( STR("Item 0"), &on_menu_item);
			mobj.append_splitter();
			mobj.append ( STR("Item 1"), &on_menu_item);

			;//Now we need a button.
			button btn(fm, nana::rectangle(nana::point(10, 10), nana::size(100, 25)));
			btn.caption(STR("Popup Menu"));

			;//Popup the menu when right clicking the button.
			btn.make_event<events::click>(menu_popuper(mobj));

			;//Or popuping the menu with a specified coordinate when any mouse button is clicked.
			;//btn.make_event<events::click> ( menu_popuper( mobj, btn, nana::point(0, 26),
			;//                                mouse::any_button );

			fm.show();
			exec();
		}

4. The gap of menu is used to specify the interval pixels between the menu and its sub menus. 
It affects all sub menus and all sub menus of its sub menus.
	![](gap_of_menu.png)

		int main()
		{
			using namespace nana::gui;

			menu mobj;
			mobj.append(STR("Item 0"));
			mobj.append(STR("Item 1"));

			mobj.gaps(nana::point(3, -2)); //Remove this statement for default gaps.

			menu * sub = mobj.create_sub_menu(0);
			sub->append(STR("Item 0"));
			sub->append(STR("Item 1"));

			sub = sub->create_sub_menu(0);
			sub->append(STR("A sub's sub menu item"));

			form fm;
			fm.make_event<events::click>(menu_popuper(mobj));
			fm.show();
			exec();
		}

5. When a renderer is set for a menu, it affects all sub menus of the menu and all sub menus of its all sub menus.

	An example of a user-defined renderer.

	The definition of class renderer_interface.

		class renderer_interface
		{
			public:
				typedef nana::paint::graphics & graph_reference;

					;//C++03
				struct state { enum t{ normal, active}; };

					;//C++11
				enum class state { normal, active };

				struct attr
				{
						;//C++03
					state::t item_state;
						;//C++11
					state item_state;

					bool enabled;
					bool checked;
					int check_style;
				};

				virtual ~renderer_interface() = 0;
				virtual void background(graph_reference, window) = 0;
				virtual void item     (graph_reference, const nana::rectangle&, const attr&) = 0;
				virtual void item_image (graph_reference, const nana::point&, 
				const nana::paint::image&) = 0;
				virtual void item_text(graph_reference, const nana::point&, 
				const nana::string&, unsigned pixles, const attr&) = 0;
				virtual void sub_arrow(graph_reference, const nana::point&, 
				unsigned pixels, const attr&) = 0;

		};

	The implementation of the user-defined renderer. In this example, the renderer 
	only provides the drawing of background and drawing of item, so that we have to 
	employ the existing renderer of a menu for other drawing methods.

	![](renderer_of_menu.png)

		using namespace nana::gui;

		class renderer: public menu::renderer_interface
		{
		   public:
				;//My renderer employs the existing renderer of a menu.
			renderer(const nana::pat::cloneable_interface<renderer_interface> * rd)
			: rdptr_(rd->clone())
			{}

				;//The renderer is copy-constructable, therefore a deep-copy is required.
			renderer(const renderer & rd)
			: rdptr_(rd.rdptr_->clone())
			{}
			~renderer() {rdptr_->self_delete();}
		  private:
			void background(graph_reference graph, window wd)
			{
				graph.rectangle(0xFFFFFF, true);
				graph.rectangle(0x5DC1AC, false);

					;//Makes the menu transparent, it only works under Windows with #include <windows.h>
				HWND native = reinterpret_cast(API::root(wd));
				DWORD ex_style = ::GetWindowLong(native, GWL_EXSTYLE);
				::SetWindowLong(native, GWL_EXSTYLE, ex_style | 0x00080000); // WS_EX_LAYERED
				typedef BOOL (WINAPI *slwa_t)(HWND hwnd, COLORREF crKey, BYTE bAlpha, DWORD dwFlags);
				slwa_t slwa = reinterpret_cast(::GetProcAddress(::GetModuleHandleA("User32.DLL"), 
											   "SetLayeredWindowAttributes"));
				if(slwa)
					slwa(native, 0, 220, 0x00000002); // LWA_ALPHA
			}

		void item(graph_reference graph, const nana::rectangle& r, const attr & atr)
		{
			if(state::active == atr.item_state)
				graph.rectangle(r, 0x9ADCCA, true);
		}

		void item_image(graph_reference graph, const nana::point& pos, 
						const nana::paint::image& img)
		{
		   rdptr_->refer().item_image(graph, pos, img);
		}

		void item_text(graph_reference graph,    const nana::point& pos, 
					   const nana::string& text, unsigned pixels, const attr& atr)
		{
			rdptr_->refer().item_text(graph, pos, text, pixels, atr);
		}

		void sub_arrow(graph_reference graph, const nana::point& pos, 
					   unsigned pixels,       const attr & atr)
		{
		   rdptr_->refer().sub_arrow(graph, pos, pixels, atr);
		}

		  private:
			nana::pat::cloneable_interface<renderer_interface> * rdptr_;
		};

		int main()
		{
			menu mobj;
			mobj.append(STR("Item 0"));
			mobj.append(STR("Item 1"));
			mobj.create_sub_menu(1)->append(STR("A sub menu item"));

			mobj.renderer(renderer(mobj.renderer()));
			mobj.item_pixels(20);

			form fm;
			fm.make_event<events::click>(menu_popuper(mobj));
			fm.show();
			exec();
		}


\see nana::menubar.
\todo doc: create example
\todo doc: make one directory for nana.Cpp03 demo and example and other for nana.Cpp11, and set it in the Doxygen project. Also, explore conditional doc generation for each variant, and also for user / developers.

*/