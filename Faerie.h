#pragma once
#include "Object.h"

#define FAERIE_ID 21

class Faerie :
    public Object
{
public:
    Faerie();
    ~Faerie();

public:

    int GetID() override;
    const char* Name() override;
    const char* Description() override;

    void Interact() override;

private:

    
    String name;
    String desc;

    bool invisible;

    int itemID = FAERIE_ID;

};

