#ifndef EMENUITEM_HPP
#define EMENUITEM_HPP

#include <EToolkit>
#include <EContainer>
#include <EString>

#include "../menus/EMenuItemBase.hpp"

#include <functional>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Menu bar that serves as a navigation and organizational tool to be used in a window.
	 */
	class ETOOLKIT_API MenuItem : public MenuItemBase{
		friend class Menu;

		public:
			//Type to be used to trigger when the are keyboard key enter press or mouse left button release.
			using OnClickEvent = std::function<void()>;

			/*
			 * @description: Constructor that initializes the object with a copy of the the given 'text' and the given 'callback'.
			 * @return: None.
			 */
        	MenuItem(const String& text, const OnClickEvent& callback);

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~MenuItem();

			/*
			 * @description: Set the the click event with the given 'callback'.
			 * @return: None.
			 */
			void setCallback(const OnClickEvent& callback);

			/*
			 * @description: Get the text of the menu item.
			 * @return: Copy of text value.
			 */
			String getText();

			/*
			 * @description: Set the text of the menu page with the given 'text' value.
			 * @return: None.
			 */
			void setText(const String& text);

			static void InkoveCallback(MenuItemBase* menuItemBase, unsigned int param);

		private:
			unsigned int id;
			MenuItem::OnClickEvent callback;
	};
}

#endif /* EMENUITEM_HPP */
