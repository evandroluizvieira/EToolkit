#ifndef EMENUITEMBASE_HPP
#define EMENUITEMBASE_HPP

#include <EToolkit>
#include <EString>


/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{
	class Menu;

	/*
	 * @description: Menu generic item that serves base of MenuItem and SubMenu.
	 */
	class ETOOLKIT_API MenuItemBase{
		friend class Menu;
		friend class MenuItem;
		friend class SubMenu;

		public:
			/*
			 * @description: List of menu type objects.
			 */
			enum class Type{
				//Non defined type.
				Unknown,

				//Menu item object.
				MenuItem,

				//Sub menu object.
				SubMenu
			};

			/*
			 * @description: Default constructor.
			 * @return: None.
			 */
			MenuItemBase();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~MenuItemBase();

			/*
			 * @description: Get the menu type from 'Type' list.
			 * @return: Copy of menu type.
			 */
			Type getType() const;

		private:
			Menu* parent;
			Type type;
			String text;
	};
}

#endif /* EMENUITEMBASE_HPP */
