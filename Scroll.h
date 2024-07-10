#pragma once
#include "Object.h"
#include "Spell.h"
#include "Player.h"

class Scroll :
    public Object
{
public:

    Scroll(int SpellID);
    ~Scroll();

public:

    int GetID() override;
    const char* Name() override;
    const char* Description() override;

    void Use(Player& player);

private:

    String name;
    String desc;

    bool invisible = false;

    Spell spell;
    
    int itemID = SCROLL_ID;
};