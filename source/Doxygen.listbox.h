/** \class nana::listbox
\brief A rectangle containing a list of strings from which the user can select. This widget contain a list of \a categories, with in turn contain \a items. 
A category is a text with can be \a selected, \a checked and \a expanded to show the items.
An item is formed by \a column-fields, each corresponding to one of the \a headers. 
An item can be \a selected and \a checked.
The user can \a drag the header to \a reisize it or to \a reorganize it. 
By \a clicking on a header the list get \a reordered, first up, and then down alternatively,

1. The resolver is used to resolute an object of the specified type for a listbox item.
2. The any_objective of listbox have a 2-Dimension indexing. The first dimension is for the category, and the second one is for the item of the specified category.

		int main()
		{
		   using namespace nana::gui;
		   form fm;
		   listbox lb(fm, nana::rectangle(10, 10, 280, 120));
		   lb.append_header(STR("Header"), 200);
		   lb.append_item(STR("int"));
		   lb.append_item(STR("double"));

		   lb.anyobj(0, 0, 10);
		   lb.anyobj(0, 1, 0.1);

		   int * pi = lb.anyobj<int>(0, 0); 	  // it returns a nullptr if there is not an int object specified.
		   double * pd = lb.anyobj<double>(0, 1); // it returns a nullptr if there is not an double object specified.

		   fm.show();
		   exec();
		 }

3. nana::listbox creates the category 0 by default. The member functions without the categ parameter operate the items that belong to category 0.

4. A sort compare is used for sorting the items. It is a strict weak ordering comparer that must meet the requirement:

		Irreflexivity (comp(x, x) returns false) 

	and 

		antisymmetry(comp(a, b) != comp(b, a) returns true)

	A simple example.

		bool sort_compare( const nana::string& s1, nana::any*, 
						   const nana::string& s2, nana::any*, bool reverse)
		{
			return (reverse ? s1 > s2 : s1 < s2);
		}

		listbox.set_sort_compare(0, sort_compare);

	The listbox supports attaching a customer's object for each item, therefore the items can be 
	sorted by comparing these customer's object.

		bool sort_compare( const nana::string&, nana::any* o1, 
						   const nana::string&, nana::any* o2, bool reverse)
		{
			if(o1 && o2) 	//some items may not attach a customer object.
			{
				int * i1 = o1->get<int>();
				int * i2 = o2->get<int>();
				return (i1 && i2 && (reverse ? *i1 > *i2 : *i1 < *i2));
 							;//some types may not be int.
			}
			return false;
		}

		listbox.anyobj(0, 0, 10); //the type of customer's object is int.
		listbox.anyobj(0, 0, 20);

\todo doc: actualize this example listbox.at(0)...

\see nana::drawerbase::listbox::cat_proxy
\see nana::drawerbase::listbox::item_proxy

\example listbox_Resolver.cpp

*/