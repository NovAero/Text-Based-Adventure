#pragma once
#include "Object.h"
#include "Spell.h"

#define SCROLL_ID_DM 11
#define SCROLL_ID_L 12
#define SCROLL_ID_FB 13
#define SCROLL_ID_FD 14
#define SCROLL_ID_FS 15
#define SCROLL_ID_SWA 16
#define SCROLL_ID_J 17
#define SCROLL_ID_LO 18
#define SCROLL_ID_MM 19
#define SCROLL_ID_H 20

class Scroll :
    public Object
{
public:

    Scroll(int SpellID, bool isInvisible);
    ~Scroll();

public:

    int GetID() override;
    const char* Name() override;
    const char* Description() override;
    void Interact() override;

private:

    String name;
    String desc;

    bool invisible = false;

    Spell spell;
    
    int itemID = -1;
};