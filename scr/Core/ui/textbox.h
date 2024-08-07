#pragma once



#include <functional>

#include "widget.h"

namespace Core {

	namespace UI {

		class TextBox : public UI::Widget {

		private:

			Rectangle m_rect;
			Text m_text;
			Text m_label;
			std::string* m_pModString;
			
			sf::Vector2f m_position;

			bool m_isActive = false;
			bool m_isDisabled = false;

			void handleClick(sf::Event e, const sf::RenderWindow& window);
			void handleTextInput(sf::Event e);

			bool isValidCharacter(unsigned char keyCode);
			bool isBackspace(unsigned char keycode);


		public:
			TextBox(std::string& modString);

			void setLabel(const std::string& str);
			void setTexture(const sf::Texture& tex);

			void handleEvent(sf::Event e, const sf::RenderWindow& window) override;
			void render(sf::RenderTarget& renderer) override;
			void setPosition(const sf::Vector2f& pos) override;
			sf::Vector2f getSize() const override;

			void disable() override;
			void enable() override;
		};


		inline std::unique_ptr<TextBox> makeTextBox(std::string& modStr)
		{
			return std::make_unique<TextBox>(modStr);
		}
	}
}

