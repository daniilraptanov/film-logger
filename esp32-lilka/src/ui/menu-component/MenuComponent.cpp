#include <menu-component/MenuComponent.h>

MenuComponent::MenuComponent() {}

void MenuComponent::drawCommonUI(lilka::Canvas *canvas) {
    canvas->fillScreen(lilka::colors::Black); // Clear display

    // Exit info
    canvas->setCursor(60, 210);
    canvas->setTextColor(lilka::colors::Graygrey);
    canvas->print(String("Start для виходу"));
}
