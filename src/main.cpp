
#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

using namespace geode::prelude;

class $modify(YTAutoDecoEditor, LevelEditorLayer) {
    bool init(GJGameLevel* level, bool p1) {
        if (!LevelEditorLayer::init(level, p1))
            return false;

        auto button = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_button_01.png"),
            this,
            menu_selector(YTAutoDecoEditor::onYTButton)
        );

        if (button) {
            button->setPosition({25.f, 25.f});

            auto menu = CCMenu::create();
            menu->addChild(button);
            menu->setPosition({0.f, 0.f});
            addChild(menu, 100);
        }

        return true;
    }

    void onYTButton(CCObject*) {
        FLAlertLayer::create(
            "YT Auto Deco",
            "YT Auto Deco berhasil dibuka!",
            "OK"
        )->show();
    }
};
